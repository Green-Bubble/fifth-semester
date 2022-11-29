//
// Created by marcinskic on 11/29/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window.h" resolved

#include "window.h"


Window::Window(QWidget *parent) :
        QWidget(parent){
    setFixedSize(1000,800);

    //------Projektowanie interfejsu-----------
    //Tworzenie kraju
    countryName = new QLineEdit(this);
    countryName->setGeometry(0,0,200,20);
    countryName->setPlaceholderText("Nazwa kraju");

    populationSize = new QSpinBox(this);
    populationSize->setGeometry(220,0,100,20);
    populationSize->setMaximum(2000000000);

    addCountryBtn = new QPushButton("Dodaj kraj", this);
    addCountryBtn->setGeometry(350, 0, 100, 20);
    QObject::connect(addCountryBtn,SIGNAL(clicked()), this, SLOT(addCountry()));

    //Wyświetlanie
    display = new QTextBrowser(this);
    display->setGeometry(0,200,200,300);

    whatToShowLbl = new QLabel("Co wyświetlać: ",this);
    whatToShowLbl->setGeometry(0,150,200,20);

    whatToShow = new QComboBox(this);
    whatToShow->setGeometry(0,170,200,20);
    whatToShow->addItem("Kraj i populacja");
    whatToShow->addItem("Kraj");
    QObject::connect(whatToShow, SIGNAL(activated(int)),this, SLOT(updateDisplay(int)));

    //Zakres

    doRange = new QCheckBox(this);
    doRange->setGeometry(0,120,20,20);
    connect(doRange, SIGNAL(stateChanged(int)),this,SLOT(updateDisplay()));

    rangeLbl = new QLabel("Zakres",this);
    rangeLbl->setGeometry(30,120,50,20);

    fromSB = new QSpinBox(this);
    fromSB->setGeometry(90,120,100,20);
    fromSB->setMaximum(2000000000);

    toLbl = new QLabel("do",this);
    toLbl->setGeometry(200,120,30,20);

    toSB = new QSpinBox(this);
    toSB->setGeometry(240,120,100,20);
    toSB->setMaximum(2000000000);
}

Window::~Window() {
}

void Window::addCountry() {
    if(countryName->text() != "" || populationSize->value() != 0) {
        countries.insert(countryName->text(), populationSize->value());
    }

    updateDisplay();
}

void Window::showFull(){
    display->clear();

    for (auto it = countries.begin(); it != countries.end(); it++){
        if(doRange->isChecked()) {
            if (fromSB->value() > it.value() || it.value() > toSB->value()) {
                continue;
            }
        }

        std::stringstream text;
        text << "Population: " << std::setw(10) << std::setfill(' ') << std::to_string(it.value()) << "    "
             << it.key().toStdString();
        display->append(QString::fromStdString(text.str()));
    }
}

void Window::showOnlyCountries(){
    display->clear();

    for (auto it = countries.begin(); it != countries.end(); it++){
        if(doRange->isChecked()){
            if(fromSB->value() > it.value() || it.value() > toSB->value()){
                continue;
            }
        }
        display->append(it.key());
    }
}

void Window::updateDisplay() {

    updateDisplay(whatToShow->currentIndex());
}

void Window::updateDisplay(int index) {
    qDebug() << index;

    switch(index){
        case 0:
            showFull();
            break;
        case 1:
            showOnlyCountries();
            break;
    }
}
