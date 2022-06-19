#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cylinder/cylinder.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionCylinder, &QAction::triggered, this, &MainWindow::onCylinderClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCylinderClicked()
{
    Cylinder *c = new Cylinder;
    c->show();
}