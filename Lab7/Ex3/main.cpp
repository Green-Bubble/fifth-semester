#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QTextBrowser>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QObject>

#include <QString>
#include <QMap>

#include <sstream>
#include <iomanip>
#include "window.h"




int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Window window(nullptr);
    window.show();

    return QApplication::exec();
}
