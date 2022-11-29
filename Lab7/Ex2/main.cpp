#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QSet>
#include <QString>
#include <QChar>
#include <algorithm>

template  <typename T>
void show(T collection){
    std::for_each(collection.begin(),collection.end(),[](auto el){
        qDebug() <<el<<" ";
    });
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QString text = "The quick brown fox jumps over the lazy dog";
    QSet<QChar> latinLowerCaseChars;
    QSet<QChar> textAsSet;

    for(int i = 97; i < 123; i++){
        latinLowerCaseChars.insert(QChar(i));
    }



    std::for_each(text.begin(),text.end(),[&](QChar c){
        latinLowerCaseChars -= c;
    });

    if(latinLowerCaseChars.empty()){
        qDebug() << "To panagram";
    } else {
        qDebug() << "To nie panagram, litery których brakuje: ";

        show(latinLowerCaseChars);
    }

    return QCoreApplication::exec();
}
