//
// Created by 张自爆 on 2019/5/21.
//

#ifndef HELLO_MAINWINDOW_H
#define HELLO_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};


#endif //HELLO_MAINWINDOW_H
