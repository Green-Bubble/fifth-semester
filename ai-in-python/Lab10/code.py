#%%IMPORTS
from keras.datasets import mnist, fashion_mnist
from keras.layers import Dense, Flatten, GaussianNoise, Input, Reshape, Lambda, Conv2D, Dropout, UpSampling2D, MaxPooling2D, BatchNormalization
from keras.models import Model
from keras.optimizers import Adam
from keras.utils.vis_utils import plot_model
from keras import backend as K

import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf

#%%DATA MANIPULATION
train, test = fashion_mnist.load_data()
X_train, y_train = train[0], train[1]
X_test, y_test = test[0], test[1]
X_train = X_train/255
X_test = X_test/255

#%%DESCRIPTOR CREATION
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

#%%DESCRIPTOR INITIAL TRAINING
X_train_real = X_train.copy()
X_train_fake = tf.random.normal([60000, 28, 28])
y_train_real = np.repeat(1,X_train_real.shape[0])
y_train_fake = np.repeat(0,X_train_fake.shape[0])
X_train_desc = np.concatenate([X_train_real,X_train_fake])
y_train_desc = np.concatenate([y_train_real,y_train_fake])
descriptor.fit(X_train_desc,y_train_desc,epochs = 5)

#%% GENERATOR CREATION
act_f = 'selu'
hidden_dim = 100
channel_cnt = 128
generator_layers = [
  Dense(channel_cnt*7*7, activation=act_f),
  Reshape((7, 7, channel_cnt)),
  Conv2D(128,(5,5),padding='same',activation=act_f),
  UpSampling2D((2,2)),
  BatchNormalization(),
  Conv2D(64,(5,5),padding='same',activation=act_f),
  UpSampling2D((2,2)),
  BatchNormalization(),
  Conv2D(1, kernel_size=(7,7),padding='same', activation='sigmoid'),
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
batch_cnt = 256
batch_size = 256
for i in range(epoch_cnt):
  print(f'epoch {i+1} of {epoch_cnt}')
  for batch in tqdm(range(batch_cnt)):
    X_all, y_all = make_train_batch(X_train,batch_size,batch, hidden_dim, generator)
    descriptor.train_on_batch(X_all, y_all)
    X_gan = np.random.randn(batch_size*2,hidden_dim)
    y_gan = np.ones((batch_size*2,))
    gan.train_on_batch(X_gan, y_gan)
  generated_images = generate_images(20, hidden_dim,generator)
  show_pictures(generated_images)