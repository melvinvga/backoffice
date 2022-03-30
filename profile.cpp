#include "profile.h"
#include "ui_profile.h"
#include <QSqlQuery>

Profile::Profile(QString leNumEmpl,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);

    //recuperation du nb empl
    numEmpl=leNumEmpl;

    //ajout variable
    QSqlQuery queryProfile;
    queryProfile.exec("SELECT loginEmploye, nomEmploye, prenomEmploye, mailEmploye, telephoneEmploye, mdpEmploye, rueEmploye, villeEmploye, codepostalEmploye FROM Employe WHERE numeroEmploye = '"+leNumEmpl+"'");
    while(queryProfile.next())
    {
        qDebug()<<queryProfile.value("loginEmploye").toString();
        ui->labelPrenom->setText(queryProfile.value("prenomEmploye").toString());
        ui->labelNom->setText(queryProfile.value("nomEmploye").toString());
        ui->lineEditAdresse->setText(queryProfile.value("rueEmploye").toString());
        ui->lineEditVille->setText(queryProfile.value("villeEmploye").toString());
        ui->lineEditCodepostal->setText(queryProfile.value("codepostalEmploye").toString());
        ui->lineEditMail->setText(queryProfile.value("mailEmploye").toString());
        ui->lineEditTel->setText(queryProfile.value("telephoneEmploye").toString());
        ui->lineEditLogin->setText(queryProfile.value("loginEmploye").toString());
        ui->lineEditMdp->setText(queryProfile.value("mdpEmploye").toString());
    }
}

Profile::~Profile()
{
    delete ui;
}

void Profile::on_pushButtonValider_clicked()
{
    QString numEmpl="1";

    QString loginEmpl, nomEmpl, prenomEmpl, mailEmpl,telEmpl, mdpEmpl, rueEmpl, villeEmpl, cpEmpl;
    loginEmpl=ui->lineEditLogin->text().replace("'","''");
    mailEmpl=ui->lineEditMail->text().replace("'","''");
    telEmpl=ui->lineEditTel->text().replace("'","''");
    mdpEmpl=ui->lineEditMdp->text().replace("'","''");
    rueEmpl=ui->lineEditAdresse->text().replace("'","''");
    villeEmpl=ui->lineEditVille->text().replace("'","''");
    cpEmpl=ui->lineEditCodepostal->text().replace("'","''");

    //requete d'insertion dans la base
    QString txtReqModify="UPDATE Employe SET loginEmploye = '"+loginEmpl+"', mailEmploye = '"+mailEmpl+"', telephoneEmploye = '"+telEmpl+"', mdpEmploye = '"+mdpEmpl+"', rueEmploye = '"+rueEmpl+"', villeEmploye = '"+villeEmpl+"', codepostalEmploye = '"+cpEmpl+"' WHERE numeroEmploye = '"+numEmpl+"'";
    qDebug()<<txtReqModify;
    QSqlQuery queryReqModify(txtReqModify);
    accept();
}

