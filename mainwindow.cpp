#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphicwidget.h"

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

void MainWindow::PrintInfo(QString about)
{
    QString current_info = ui->info->text();
    current_info += ui->gW->GetInfo(about);
    ui->info->setText(current_info);
}

void MainWindow::on_fillContainer1_clicked()
{
    ui->info->setText("");
    ui->gW->FillContainer1();
    PrintInfo("fc1");
    ui->horizontalSlider->setValue(0);
    ui->gW->update();
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->gW->RotateY(value);
    ui->gW->update();
}


void MainWindow::on_calculateCoordinates_clicked()
{
    PrintInfo("4PICoords");
}


void MainWindow::on_calculateDerived_clicked()
{
    PrintInfo("4PIDers");
}


void MainWindow::on_fillContainer2_clicked()
{
    ui->gW->FillContainer2();
    PrintInfo("fc2");
    ui->horizontalSlider->setValue(0);
    ui->gW->update();
}


void MainWindow::on_selectContainer_clicked()
{
    if(ui->selectContainer->text() == "Container1")
    {
        ui->selectContainer->setText("Container2");
    }
    else{
        ui->selectContainer->setText("Container1");
    }
}


void MainWindow::on_showContainer_clicked()
{
    std::vector<Figure*> container;
    if(ui->selectContainer->text() == "Container1")
        container = ui->gW->GetContainer(1);
    else
        container = ui->gW->GetContainer(2);
    ui->gW->ExtractCoordinates(container);
    ui->gW->update();
}


void MainWindow::on_sort_clicked()
{
    ui->gW->SortContainer2();
    PrintInfo("sort2");
}


void MainWindow::on_getRadiusesSum_clicked()
{
    PrintInfo("radSum2");
}

