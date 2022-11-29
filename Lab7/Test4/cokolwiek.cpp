//
// Created by marcinskic on 11/28/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_cokolwiek.h" resolved

#include "cokolwiek.h"
#include "ui_cokolwiek.h"


cokolwiek::cokolwiek(QWidget *parent) :
        QWidget(parent), ui(new Ui::cokolwiek) {
    ui->setupUi(this);
}

cokolwiek::~cokolwiek() {
    delete ui;
}
