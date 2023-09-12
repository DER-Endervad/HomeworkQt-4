#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int int_bar = 10;
    ui->setupUi(this);
    ui->pBar_main->setMinimum(0);
    ui->pBar_main->setMaximum(100);
    ui->pBar_main->setValue(10);

    ui->rb_setup_on->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int status = 10;
int status2 = 0;

void MainWindow::on_pButton_main_clicked()
{
    if(ui->rb_setup_on->isChecked()) {
        ui->textEdit->clear();
        if(status < 100) {
            status = status + 10;
            ui->pBar_main->setValue(status);
        }   else {
            status = 0;
            ui->pBar_main->setValue(status);
        }
        status2 = status2 + 1;
        ui->comboBox->clear();
        ui->comboBox->addItem(QString("Количество отправок: %1").arg(status2));
    }
}

