#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cylinder/cylinder.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onPushbuttonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushbuttonClicked()
{
    Cylinder *c = new Cylinder;
    c->show(0, NULL);
}