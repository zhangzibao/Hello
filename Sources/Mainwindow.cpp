//
// Created by 张自爆 on 2019/5/21.
//

#include <Headers/GameWorld.h>
#include <QtWidgets/QMdiSubWindow>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QHBoxLayout>
#include "Mainwindow.h"
#include "Ui_MainWindow.h"
#include "TrainingPanel.h"
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

