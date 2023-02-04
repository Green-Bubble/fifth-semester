# NEW DATA GENERATION USING CHINESE MNIST DATASET

#%%IMPORTS
from keras.datasets import mnist, fashion_mnist
from keras.layers import Dense, Flatten, GaussianNoise, Input, Reshape, Lambda, Conv2D, Dropout, UpSampling2D, MaxPooling2D, BatchNormalization
from keras.models import Model
from keras.optimizers import Adam
from keras.utils.vis_utils import plot_model
from keras import backend as K

import cv2
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
import pandas as pd

from google.colab import drive
drive.mount('/content/drive')

#%% DOWNLOADING DATASET FROM CLOUD
df = pd.read_csv("/content/drive/MyDrive/chinese_mnist.csv")

X = []
for index, row in df.iterrows():
    suite_id = row[1]
    sample_id = row[2]
    code = row[3]
    file_name = f"input_{suite_id}_{sample_id}_{code}.jpg"
    x = cv2.imread(f"/content/drive/MyDrive/data/{file_name}")
    if x is None: #Protection from files that should exist according to csv but don't
      print(file_name)
      continue
    X.append(x)
X = np.stack(X)

#%% DATA SETUP
X_temp = X.copy() #To preserve downloaded original
np.random.shuffle(X_temp) #By default it is ordered by symbols
X_train = X_temp[:8000,:,:,0]
X_test = X_temp[8000:,:,:,0]
X_train = X_train / 255 #For grayscale working in models
X_test = X_test / 255 #For grayscale working in models

#%% ----------------AUTOENCODER----------------------

#%% AUTOENCODER CREATION AND TRAINING
act_func = 'selu'

encoder_layers = [
  GaussianNoise(1),
  Flatten(),
  Dense(1024, activation=act_func),
  Dense(512, activation=act_func),
  Dense(256, activation=act_func),
  Dense(128, activation=act_func),
  Dense(32, activation=act_func),
  Dense(16, activation=act_func),
  Dense(2, activation=act_func),
]
decoder_layers = [
  Dense(2, activation=act_func),
  Dense(16, activation=act_func),
  Dense(32, activation=act_func),
  Dense(128, activation=act_func),
  Dense(256, activation=act_func),
  Dense(512, activation=act_func),
  Dense(1024, activation=act_func),
  Dense(64*64, activation="sigmoid"),
  Reshape((64,64))
]
lrng_rate = 0.0001

tensor = input_aec = input_encoder = Input(X_train.shape[1:])
for layer in encoder_layers:
  tensor = layer(tensor)
output_encoder = tensor
dec_tensor = input_decoder =Input(output_encoder.shape[1:])
for layer in decoder_layers:
  tensor = layer(tensor)
  dec_tensor = layer(dec_tensor)
output_aec = tensor
output_decoder = dec_tensor
autoencoder = Model(inputs = input_aec,outputs = output_aec)
encoder = Model(inputs = input_encoder,outputs = output_encoder)
decoder = Model(inputs = input_decoder,outputs = dec_tensor)

autoencoder.compile(optimizer=Adam(lrng_rate),loss='binary_crossentropy')
plot_model(autoencoder,show_shapes=True)

autoencoder.fit(x = X_train, y = X_train,epochs = 1000, batch_size = 256)

#%% GRAPH OF LOSS GENERATION
auto_history = autoencoder.history.history
auto_floss_train = auto_history['loss']
fig,ax = plt.subplots(1,3, figsize=(30,10))



epochs = np.arange(0, 1000)
ax[0].plot(epochs, auto_floss_train, label = 'floss_train')
ax[0].set_title('Funkcja strat autoenkodera')
ax[0].legend()

#%% MODEL TESTING
def show_pictures(arrs):
  arr_cnt = arrs.shape[0]
  fig, axes = plt.subplots(1, arr_cnt,figsize=(5*arr_cnt, arr_cnt))
  for axis, pic in zip(axes, arrs):
    axis.imshow(pic.squeeze(), cmap = 'gray')

test_photos = X_test[10:20,...].copy()
mask = np.random.randn(*test_photos.shape)
white = mask > 1
black = mask < -1
noisy_test_photos=test_photos.copy()
noisy_test_photos[white] = 1
noisy_test_photos[black] = 0

cleaned_images=autoencoder.predict(noisy_test_photos)
show_pictures(test_photos)
show_pictures(noisy_test_photos)
show_pictures(cleaned_images)

#%% GENERATING NEW DATA
num = 15
limit = 0.6
step = limit*2/num
fig, ax = plt.subplots(num, num, figsize = (20,16))
X_vals = np.arange(-limit, limit, step)
Y_vals = np.arange(-limit, limit, step)
for i, x in enumerate(X_vals):
  for j, y in enumerate(Y_vals):
    test_in = np.array([[x,y]])
    output = decoder.predict(x=test_in)
    output = np.squeeze(output)
    ax[-j-1,i].imshow(output, cmap = 'jet')
    ax[-j-1,i].axis('off')

#%%------------------GAN---------------------------

#%% DESCRIPTOR CREATION
act_f = 'relu'
descriptor_layers = [
    Lambda(lambda x: K.expand_dims(x, axis=-1)),
    Conv2D(64,(5,5),strides=(2,2),padding='same'),
    MaxPooling2D(),
    Dropout(0.3),
    Conv2D(64,(5,5),strides=(2,2),padding='same'),
    MaxPooling2D(),
    Flatten(),
    Dropout(0.5),
    Dense(1, 'sigmoid')]
descriptor_input = descriptor_output = Input(X_train.shape[1:])
for layer in descriptor_layers:
  descriptor_output = layer(descriptor_output)
descriptor = Model(inputs = descriptor_input,outputs = descriptor_output)
descriptor.compile(loss='BinaryCrossentropy',metrics='accuracy',optimizer=Adam(0.001, beta_1=0.8))

plot_model(descriptor, show_shapes=True)

#%% GENERATOR CREATION
act_f = 'selu'
hidden_dim = 100
channel_cnt = 128
generator_layers = [
  Dense(channel_cnt*8*8, activation=act_f),
  Reshape((8, 8, channel_cnt)),
  Conv2D(128,(5,5),padding='same',activation=act_f),
  UpSampling2D((2,2)),
  BatchNormalization(),
  Conv2D(64,(5,5),padding='same',activation=act_f),
  UpSampling2D((2,2)),
  BatchNormalization(),
  Conv2D(64,(5,5),padding='same',activation=act_f),
  UpSampling2D((2,2)),
  BatchNormalization(),
  Conv2D(1, kernel_size=(8,8),padding='same', activation='sigmoid'),
  Lambda(lambda x: x*255),
  Lambda(lambda x: K.squeeze(x, axis=-1))]
generator_input = generator_output = Input((hidden_dim,))
for layer in generator_layers:
  generator_output = layer(generator_output)
generator = Model(inputs = generator_input,outputs = generator_output)

plot_model(generator, show_shapes=True)

#%% GAN CREATION
gan = Model(inputs = generator.input,outputs = descriptor(generator.outputs))
descriptor.trainable = False
gan.compile(loss='BinaryCrossentropy',optimizer=Adam(0.0002, beta_1=0.8))

#%% TRAINING AND GENERATING NEW DATA
def show_pictures(arrs):
  arr_cnt = arrs.shape[0]
  fig, axes = plt.subplots(1, arr_cnt,figsize=(5*arr_cnt, arr_cnt))
  for axis, pic in zip(axes, arrs):
    axis.imshow(pic.squeeze(), cmap = 'gray')

def make_train_batch(X_train,batch_size,batch_num,hidden_dim,generator):
  noise=tf.random.normal([batch_size,hidden_dim])
  X_train_real = X_train[batch_num*batch_size:(batch_num+1)*batch_size,:].copy()
  X_train_fake = generator(noise,training=True)
  y_train_real = np.repeat(1,X_train_real.shape[0])
  y_train_fake = np.repeat(0,X_train_fake.shape[0])
  X_all = np.concatenate([X_train_real,X_train_fake])
  y_all = np.concatenate([y_train_real,y_train_fake])
  return (X_all, y_all)

def generate_images(img_cnt, hidden_dim, generator):
  noise = tf.random.normal([img_cnt,hidden_dim])
  result = generator.predict(noise)
  return result

from tqdm.notebook import tqdm
epoch_cnt = 40
img_cnt = X_train.shape[0]
batch_size = 200
for i in range(epoch_cnt):
  print(f'epoch {i+1} of {epoch_cnt}')
  for batch in tqdm(range(batch_size)):
    X_all, y_all = make_train_batch(X_train,batch_size,batch, hidden_dim, generator)
    descriptor.train_on_batch(X_all, y_all)
    X_gan = np.random.randn(batch_size*2,hidden_dim)
    y_gan = np.ones((batch_size*2,))
    gan.train_on_batch(X_gan, y_gan)
  generated_images = generate_images(20, hidden_dim,generator)
  show_pictures(generated_images)