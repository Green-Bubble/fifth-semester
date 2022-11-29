#include "car.h"

Car::Car()
{

}

Car::Car(QString brand, QString model, int productionYear, int vin){
    this->brand = brand;
    this->model = model;
    this->productionYear = productionYear;
    this->vin = vin;
}

const QString Car::toString(){
    return brand+" "+model+" "+QString::number(productionYear)+" "+QString::number(vin);
}
