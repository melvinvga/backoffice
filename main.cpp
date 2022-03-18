#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("newworld2");
    db.setUserName("root");
    db.setPassword("Beqjs974@");

    bool ok=db.open();
    qDebug()<<ok;

    Connexion seConnecter;
    if(seConnecter.exec()==QDialog::Accepted){
        qDebug()<<"ok2";
        MainWindow w(seConnecter.getNumEmpl());
        qDebug()<<"ok3";
        w.show();
        qDebug()<<"ok4";
        return a.exec();
        qDebug()<<"ok5";
    }
}
