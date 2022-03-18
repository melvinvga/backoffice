#include "connexion.h"
#include "ui_connexion.h"
#include <QSqlQuery>
#include <QDebug>

Connexion::Connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion)
{
    ui->setupUi(this);
}

Connexion::~Connexion()
{
    delete ui;
}

QString Connexion::getNumEmpl()
{
    //recuperation login
    QString login;
    login=ui->lineEditLogin->text().replace("'","''");

    //recuperation du no d'employe
    QString txtReqNumEmpl="SELECT numeroEmploye FROM Employe WHERE loginEmploye='"+login+"'";
    qDebug()<<txtReqNumEmpl;
    QSqlQuery queryReqNumEmpl(txtReqNumEmpl);
    queryReqNumEmpl.next();
    QString numEmpl=queryReqNumEmpl.value(0).toString();
    return numEmpl;
}


void Connexion::on_pushButtonOk_clicked()
{
    //recuperation mdp
    QString login, mdp;

    if(!ui->lineEditLogin->text().isEmpty())
    {
        login=ui->lineEditLogin->text().replace("'","''");
    }
    else
    {
        ui->lineEditLogin->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditMdp->text().isEmpty())
    {
        mdp=ui->lineEditMdp->text().replace("'","''");
    }
    else
    {
        ui->lineEditMdp->setStyleSheet("background-color: #ff3632;");
    }

    if(!login.isEmpty() && !mdp.isEmpty())
    {
        //recuperation du login
        QString txtReqLoginEmpl="SELECT loginEmploye FROM Employe WHERE numeroEmploye='"+QString::number(getNumEmpl().toInt())+"'";
        qDebug()<<txtReqLoginEmpl;
        QSqlQuery queryReqLoginEmpl(txtReqLoginEmpl);
        queryReqLoginEmpl.next();
        QString loginEmpl=queryReqLoginEmpl.value(0).toString();

        if (login==loginEmpl)
        {
            ui->labelValue->setText("Merci de séléctionner une ligne");

            //recuperation du login
            QString txtReqMdpEmpl="SELECT mdpEmploye FROM Employe WHERE numeroEmploye='"+QString::number(getNumEmpl().toInt())+"'";
            qDebug()<<txtReqMdpEmpl;
            QSqlQuery queryReqMdpEmpl(txtReqMdpEmpl);
            queryReqMdpEmpl.next();
            QString mdpEmpl=queryReqMdpEmpl.value(0).toString();

            if (login==loginEmpl && mdp == mdpEmpl)
            {
                ui->labelValue->setText("Connexion reussi");
                accept();
            }
            else
            {
                ui->labelValue->setText("Mot de passe incorect");
                ui->lineEditLogin->setStyleSheet("background-color: #82d682;");
            }
        }
        else
        {
            ui->labelValue->setText("identifiant inexistant");
            ui->lineEditLogin->setStyleSheet("background-color: #ff3632;");
            ui->lineEditMdp->setStyleSheet("background-color: #ff3632;");
        }
    }
}
