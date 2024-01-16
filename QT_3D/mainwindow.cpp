#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_left_clicked()
{

}


void MainWindow::on_Button_right_clicked()
{

}


void MainWindow::on_Button_up_clicked()
{

}


void MainWindow::on_Button_down_clicked()
{

}


void MainWindow::on_Button_turnOZ_clicked()
{

}


void MainWindow::on_Button_turnOX_clicked()
{

}


void MainWindow::on_Button_turnOY_clicked()
{

}


void MainWindow::on_Button_zoomIn_clicked()
{

}


void MainWindow::on_Button_zoomOut_clicked()
{

}

