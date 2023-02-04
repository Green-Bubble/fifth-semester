#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addBtn_clicked()
{
    auto brand = ui->brandLE->text();
    auto model = ui->modelLE->text();
    auto productionYear = ui->productionYearSB->value();
    auto vim = ui->vimSB->value();

    if((brand == "") || (model == "") || (productionYear == 0) || (vim == 0)){
        ui->feedbackLbl->setText("Brak / Błędne dane");
    } else {
        cars.append(*(new Car(brand,model,productionYear,vim)));
        ui->feedbackLbl->setText("Dodano samochód: "+(cars.last().toString()));
        ui->carsTB->append(cars.last().toString());
    }

    showCars();
}

void MainWindow::sortCars(){
    sortCars(ui->sortTypeCB->currentIndex());
}

void MainWindow::sortCars(int index){
    switch(index){
    case 1:
        sortByYear();
        break;
    case 2:
        sortByBrand();
        break;
    }
}

void MainWindow::sortByYear(){
    std::sort(cars.begin(),cars.end(),[](Car c1, Car c2){
       return c1.productionYear > c2.productionYear;
    });
}

void MainWindow::sortByBrand(){
    std::sort(cars.begin(),cars.end(),[](Car c1, Car c2){
        return QString::compare(c2.brand,c1.brand,Qt::CaseInsensitive) > 0;
    });
}

void MainWindow::showCars(){

    sortCars();

    ui->carsTB->clear();

    QVector<Car>::iterator i;

    for(i = cars.begin(); i < cars.end(); i++){
        ui->carsTB->append((*i).toString());
    }
     updateCarsAmount();
}

void MainWindow::updateCarsAmount(){
    updateCarsAmount(ui->olderSB->value());
}

void MainWindow::updateCarsAmount(int value){
    auto olderThanGivenYear = std::count_if(cars.begin(),cars.end(),[&](Car car){
        return car.productionYear < value;
    });

    ui->carAmountLbl->setText(QString::number(olderThanGivenYear));
}

void MainWindow::on_olderSB_valueChanged(int value)
{
    updateCarsAmount(value);
}


void MainWindow::on_deleteCarBtn_clicked()
{
    auto iterator = std::remove_if(cars.begin(),cars.end(),[&](Car car){
            return car.vin == ui->deleteVIM->value();
        });

    ui->deleteFeedbackLbl->setText("Usunięto: "+QString::number(std::distance(iterator,cars.end()))+" samochodów");

    cars.erase(iterator,cars.end());
    showCars();
}

void MainWindow::on_sortTypeCB_currentIndexChanged(int index)
{
    showCars();
}
