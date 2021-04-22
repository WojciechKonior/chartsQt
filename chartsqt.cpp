#include "chartsqt.h"
#include "ui_chartsqt.h"

ChartsQt::ChartsQt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChartsQt)
{
    ui->setupUi(this);
}

ChartsQt::~ChartsQt()
{
    delete ui;
}

