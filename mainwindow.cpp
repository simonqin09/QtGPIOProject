#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GPIOSet.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->count = 0;
    this->gpio_out = 54;
    gpio_export(this->gpio_out);
    gpio_set_dir(this->gpio_out, "out");
    gpio_set_value(this->gpio_out, LOW);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button1_clicked()
{
    QString temp = "";
    if(this->count==0)
    {
        gpio_set_value(this->gpio_out, HIGH);
        temp.sprintf("GPIO-%d PIN LEVEL is %d", this->gpio_out, HIGH);
        ui->Edit1->setText(temp);
        this->count = 1;
    }
    else
    {
        gpio_set_value(this->gpio_out, LOW);
        temp.sprintf("GPIO-%d PIN LEVEL is %d", this->gpio_out, LOW);
        ui->Edit1->setText(temp);
        this->count = 0;
    }
}
