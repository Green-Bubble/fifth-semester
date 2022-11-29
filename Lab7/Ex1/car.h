#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QDebug>

class Car
{
public:
    QString brand;
    QString model;
    int productionYear;
    int vin;
    Car();
    Car(QString brand, QString model, int productionYear, int vin);
    const QString toString();
};

#endif // CAR_H
