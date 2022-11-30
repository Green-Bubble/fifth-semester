//
// Created by marcinskic on 11/29/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window.h" resolved

#include "window.h"


Window::Window(QWidget *parent) :
        QWidget(parent){
    setFixedSize(1000,800);

    //-----------------Projektowanie interfejsu----------------------
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

    //Usuwanie kraju
    countryToDelete = new QLineEdit(this);
    countryToDelete->setGeometry(0,30,200,20);
    countryToDelete->setPlaceholderText("Nazwa kraju do usunięcia");

    deleteCountryBtn = new QPushButton("Usuń kraj",this);
    deleteCountryBtn->setGeometry(230,30,100,20);
    connect(deleteCountryBtn,SIGNAL(clicked()),this,SLOT(deleteCountry()));

    //---------Wyświetlanie---------
    display = new QTextBrowser(this);
    display->setGeometry(0,200,200,300);

    whatToShowLbl = new QLabel("Co wyświetlać: ",this);
    whatToShowLbl->setGeometry(0,150,200,20);

    whatToShow = new QComboBox(this);
    whatToShow->setGeometry(0,170,200,20);
    whatToShow->addItem("Kraj i populacja");
    whatToShow->addItem("Kraj");
    QObject::connect(whatToShow, SIGNAL(activated(int)),this, SLOT(updateDisplay(int)));

    //Sortowanie
    sortLabel = new QLabel("Sortowanie: ",this);\
    sortLabel->setGeometry(0,70,200,20);

    sortType = new QComboBox(this);
    sortType->setGeometry(0,90,200,20);
    sortType->addItem("Domyślne");
    sortType->addItem("Populacja rosnąco");
    sortType->addItem("Populacja malejąco");
    connect(sortType,SIGNAL(activated(int)),this,SLOT(updateDisplay(int)));

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
    QVector<QPair<QString,int>> temp;

    for (auto it = countries.begin(); it != countries.end(); it++){
        if(doRange->isChecked()) {
            if (fromSB->value() > it.value() || it.value() > toSB->value()) {
                continue;
            }
        }

        temp.append(*new QPair<QString,int>(it.key(),it.value()));
    }

    sortVector(temp);

    std::for_each(temp.begin(),temp.end(),[&](auto pair){
        std::stringstream text;
        text << "Population: " << std::setw(10) << std::setfill(' ') << std::to_string(pair.second) << "    "
             << pair.first.toStdString();
        display->append(QString::fromStdString(text.str()));
    });
}

void Window::showOnlyCountries(){
    display->clear();
    QVector<QPair<QString,int>> temp;

    for (auto it = countries.begin(); it != countries.end(); it++){
        if(doRange->isChecked()){
            if(fromSB->value() > it.value() || it.value() > toSB->value()){
                continue;
            }
        }

        temp.append(*new QPair<QString,int>(it.key(),it.value()));
    }

    sortVector(temp);

    std::for_each(temp.begin(),temp.end(),[&](auto pair) {
        display->append(pair.first);
    });
}

void Window::updateDisplay() {

    updateDisplay(whatToShow->currentIndex());
}

void Window::updateDisplay(int index) {

    switch(index){
        case 0:
            showFull();
            break;
        case 1:
            showOnlyCountries();
            break;
    }
}

void Window::deleteCountry() {
    auto key = countryToDelete->text();
    countries.remove(key);
    updateDisplay();
}

void Window::sortVector(QVector<QPair<QString, int>> &vector) {
    switch (sortType->currentIndex()) {
        case 1:
            std::sort(vector.begin(),vector.end(),[](auto el1, auto el2){
                return el1.second < el2.second;
            });
            break;
        case 2:
            std::sort(vector.begin(),vector.end(),[](auto el1, auto el2){
                return el1.second > el2.second;
            });
            break;
    }
}
