//
// Created by marcinskic on 11/28/22.
//

#ifndef TEST4_COKOLWIEK_H
#define TEST4_COKOLWIEK_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class cokolwiek; }
QT_END_NAMESPACE

class cokolwiek : public QWidget {
Q_OBJECT

public:
    explicit cokolwiek(QWidget *parent = nullptr);

    ~cokolwiek() override;

private:
    Ui::cokolwiek *ui;
};


#endif //TEST4_COKOLWIEK_H
