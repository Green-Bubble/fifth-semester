#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <algorithm>
#include <QVector>
#include <QVectorIterator>
#include "car.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addBtn_clicked();

    void on_olderSB_valueChanged(int value);
    void on_deleteCarBtn_clicked();

    void on_sortTypeCB_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QVector<Car> cars;

    int countOlderThan(int year);
    void deleteCar(int vim);
    void showCars();
    void updateCarsAmount();
    void updateCarsAmount(int value);
    void sortCars();
    void sortCars(int index);
    void sortByYear();
    void sortByBrand();
};

#endif // MAINWINDOW_H
