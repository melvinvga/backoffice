#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "add.cpp"
#include "delete.cpp"
#include "modify.cpp"
#include "initialize.cpp"
#include <QDebug>
#include <QDialog>
#include "profile.h"



void MainWindow::on_pushButtonProfile_clicked()
{
        Profile feneProfile(numEmpl,this);
        feneProfile.exec();
}




void MainWindow::on_pushButton_clicked()
{

}

