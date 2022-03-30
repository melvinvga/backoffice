#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QSqlQuery>

//----------------------------------------------------------------------------------------------------------------
//----------------------------------------------------SUPPR-------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------


void MainWindow::on_pushButtonSupprimerProduit_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSupprimerProduit_clicked()";
    //supprimer du tableau
    for(int noLigne=ui->TableWidgetProduit->rowCount()-1;noLigne>0;noLigne--)
    {
        if(((QCheckBox*)ui->TableWidgetProduit->cellWidget(noLigne,0))->isChecked())
        {
            QString txtSup="DELETE FROM Produit WHERE numeroProduit="+ui->TableWidgetProduit->item(noLigne,1)->text();
            qDebug()<<txtSup;
            QSqlQuery querySup(txtSup);
            ui->TableWidgetProduit->removeRow(noLigne);

            //date et heure de recup
            QString dateActuelle="2001/01/01";
            QString heureActuelle="00:00:00";

            //j'ajoute une ligne dans la tableWidgetHistorique
            int noLigne=ui->tableWidgetHistorique->rowCount();
            ui->tableWidgetHistorique->insertRow(noLigne);
            ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtSup));
            ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
            ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

            //calcul du numero le plus haut
            QString txtReqMax="SELECT MAX(numeroCommande) FROM Historique";
            QSqlQuery queryReqMax(txtReqMax);
            queryReqMax.next();
            int noMax=queryReqMax.value(0).toInt();
            qDebug()<<noMax;
            noMax++;
            qDebug()<<noMax;

            //j'ajoute a la base de données la commande
            QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtSup+"\",'"+dateActuelle+"','"+heureActuelle+"')";
            qDebug()<<txtReqInsertionCommande;
            QSqlQuery query(txtReqInsertionCommande);
        }
    }
}

void MainWindow::on_pushButtonSupprimerVariete_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSupprimerVariete_clicked()";
    //supprimer du tableau
    for(int noLigne=ui->tableWidgetVariete->rowCount()-1;noLigne>0;noLigne--)
    {
        if(((QCheckBox*)ui->tableWidgetVariete->cellWidget(noLigne,0))->isChecked())
        {
            QString txtSup="DELETE FROM Variete WHERE numeroVariete="+ui->tableWidgetVariete->item(noLigne,1)->text();
            qDebug()<<txtSup;
            QSqlQuery querySup(txtSup);
            ui->tableWidgetVariete->removeRow(noLigne);

            //date et heure de recup
            QString dateActuelle="2001/01/01";
            QString heureActuelle="00:00:00";

            //j'ajoute une ligne dans la tableWidgetHistorique
            int noLigne=ui->tableWidgetHistorique->rowCount();
            ui->tableWidgetHistorique->insertRow(noLigne);
            ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtSup));
            ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
            ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

            //calcul du numero le plus haut
            QString txtReqMax="SELECT MAX(numeroCommande) FROM Historique";
            QSqlQuery queryReqMax(txtReqMax);
            queryReqMax.next();
            int noMax=queryReqMax.value(0).toInt();
            qDebug()<<noMax;
            noMax++;
            qDebug()<<noMax;

            //j'ajoute a la base de données la commande
            QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtSup+"\",'"+dateActuelle+"','"+heureActuelle+"')";
            qDebug()<<txtReqInsertionCommande;
            QSqlQuery query(txtReqInsertionCommande);
        }
    }
}

void MainWindow::on_pushButtonSupprimerRayon_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSupprimerRayon_clicked()";
    //supprimer du tableau
    for(int noLigne=ui->tableWidgetRayon->rowCount()-1;noLigne>0;noLigne--)
    {
        if(((QCheckBox*)ui->tableWidgetRayon->cellWidget(noLigne,0))->isChecked())
        {
            QString txtSup="DELETE FROM Rayon WHERE numeroRayon="+ui->tableWidgetRayon->item(noLigne,1)->text();
            qDebug()<<txtSup;
            QSqlQuery querySup(txtSup);
            ui->tableWidgetRayon->removeRow(noLigne);

            //date et heure de recup
            QString dateActuelle="2001/01/01";
            QString heureActuelle="00:00:00";

            //j'ajoute une ligne dans la tableWidgetHistorique
            int noLigne=ui->tableWidgetHistorique->rowCount();
            ui->tableWidgetHistorique->insertRow(noLigne);
            ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtSup));
            ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
            ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

            //calcul du numero le plus haut
            QString txtReqMax="SELECT MAX(numeroCommande) FROM Historique";
            QSqlQuery queryReqMax(txtReqMax);
            queryReqMax.next();
            int noMax=queryReqMax.value(0).toInt();
            qDebug()<<noMax;
            noMax++;
            qDebug()<<noMax;

            //j'ajoute a la base de données la commande
            QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtSup+"\",'"+dateActuelle+"','"+heureActuelle+"')";
            qDebug()<<txtReqInsertionCommande;
            QSqlQuery query(txtReqInsertionCommande);
        }
    }
}

void MainWindow::on_pushButtonSupprimerProducteur_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSupprimerProducteur_clicked()";
    //supprimer du tableau
    for(int noLigne=ui->tableWidgetProducteur->rowCount()-1;noLigne>0;noLigne--)
    {
        if(((QCheckBox*)ui->tableWidgetProducteur->cellWidget(noLigne,0))->isChecked())
        {
            QString txtSup="DELETE FROM Producteur WHERE numeroProducteur="+ui->tableWidgetProducteur->item(noLigne,1)->text();
            qDebug()<<txtSup;
            QSqlQuery querySup(txtSup);
            ui->tableWidgetProducteur->removeRow(noLigne);

            //date et heure de recup
            QString dateActuelle="2001/01/01";
            QString heureActuelle="00:00:00";

            //j'ajoute une ligne dans la tableWidgetHistorique
            int noLigne=ui->tableWidgetHistorique->rowCount();
            ui->tableWidgetHistorique->insertRow(noLigne);
            ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtSup));
            ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
            ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

            //calcul du numero le plus haut
            QString txtReqMax="SELECT MAX(numeroCommande) FROM Historique";
            QSqlQuery queryReqMax(txtReqMax);
            queryReqMax.next();
            int noMax=queryReqMax.value(0).toInt();
            qDebug()<<noMax;
            noMax++;
            qDebug()<<noMax;

            //j'ajoute a la base de données la commande
            QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtSup+"\",'"+dateActuelle+"','"+heureActuelle+"')";
            qDebug()<<txtReqInsertionCommande;
            QSqlQuery query(txtReqInsertionCommande);
        }
    }
}

void MainWindow::on_pushButtonSupprimerClient_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSupprimerClient_clicked()";
    //supprimer du tableau
    for(int noLigne=ui->tableWidgetClient->rowCount()-1;noLigne>0;noLigne--)
    {
        if(((QCheckBox*)ui->tableWidgetClient->cellWidget(noLigne,0))->isChecked())
        {
            QString txtSup="DELETE FROM Client WHERE numeroClient="+ui->tableWidgetClient->item(noLigne,1)->text();
            qDebug()<<txtSup;
            QSqlQuery querySup(txtSup);
            ui->tableWidgetClient->removeRow(noLigne);

            //date et heure de recup
            QString dateActuelle="2001/01/01";
            QString heureActuelle="00:00:00";

            //j'ajoute une ligne dans la tableWidgetHistorique
            int noLigne=ui->tableWidgetHistorique->rowCount();
            ui->tableWidgetHistorique->insertRow(noLigne);
            ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtSup));
            ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
            ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

            //calcul du numero le plus haut
            QString txtReqMax="SELECT MAX(numeroCommande) FROM Historique";
            QSqlQuery queryReqMax(txtReqMax);
            queryReqMax.next();
            int noMax=queryReqMax.value(0).toInt();
            qDebug()<<noMax;
            noMax++;
            qDebug()<<noMax;

            //j'ajoute a la base de données la commande
            QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtSup+"\",'"+dateActuelle+"','"+heureActuelle+"')";
            qDebug()<<txtReqInsertionCommande;
            QSqlQuery query(txtReqInsertionCommande);
        }
    }
}
