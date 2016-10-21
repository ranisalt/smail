#include "chancevariable.h"
#include "mainwindow.h"
#include "system.h"
#include "ui_mainwindow.h"

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

void MainWindow::updateLocalLocalCount(int count)
{
    ui->LLCount->setText(QString::number(count));
}

void MainWindow::updateLocalRemoteCount(int count)
{
    ui->LRCount->setText(QString::number(count));
}

void MainWindow::updateRemoteLocalCount(int count)
{
    ui->RLCount->setText(QString::number(count));
}

void MainWindow::updateRemoteRemoteCount(int count)
{
    ui->RRCount->setText(QString::number(count));
}

void MainWindow::on_btnConfigurarVariavel_clicked()
{
    ChanceVariable chanceVariable;
    chanceVariable.setModal(true);
    chanceVariable.exec();
}

void MainWindow::on_btnStart_clicked()
{
    System::paused = false;
}
