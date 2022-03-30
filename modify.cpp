#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QSqlQuery>

//----------------------------------------------------------------------------------------------------------------
//-------------------------------------------------CELLCLICKED----------------------------------------------------
//----------------------------------------------------------------------------------------------------------------


void MainWindow::on_TableWidgetProduit_cellClicked(int i, int column)
{
    //recuperation des cellules
    QString no=ui->TableWidgetProduit->item(i,1)->text();
    ui->labelNumeroProduit->setText(no);
    ui->lineEditNomProduit->setText(ui->TableWidgetProduit->item(i,2)->text());
    ui->lineEditInformationProduit->setText(ui->TableWidgetProduit->item(i,3)->text());
    ui->lineEditImageProduit->setText(ui->TableWidgetProduit->item(i,4)->text());
    ui->lineEditQuantiteProduit->setText(ui->TableWidgetProduit->item(i,5)->text());
    //COMBOBOX
}


void MainWindow::on_tableWidgetVariete_cellClicked(int i, int column)
{
    //recuperation des cellules
    QString no=ui->tableWidgetVariete->item(i,1)->text();
    ui->labelNumeroVariete->setText(no);
    ui->lineEditNomVariete->setText(ui->tableWidgetVariete->item(i,2)->text());
    //COMBOBOX
}

void MainWindow::on_tableWidgetRayon_cellClicked(int i, int column)
{
    //recuperation des cellules
    QString no=ui->tableWidgetRayon->item(i,1)->text();
    ui->labelNumeroRayon->setText(no);
    ui->lineEditNomRayon->setText(ui->tableWidgetRayon->item(i,2)->text());
}



void MainWindow::on_tableWidgetProducteur_cellClicked(int i, int column)
{
    //recuperation des cellules
    QString no=ui->tableWidgetProducteur->item(i,1)->text();
    ui->labelNumeroProducteur->setText(no);
    ui->lineEditNomProducteur->setText(ui->tableWidgetProducteur->item(i,2)->text());
    ui->lineEditPrenomProducteur->setText(ui->tableWidgetProducteur->item(i,3)->text());
    ui->lineEditLoginProducteur->setText(ui->tableWidgetProducteur->item(i,4)->text());
    ui->lineEditMdpProducteur->setText(ui->tableWidgetProducteur->item(i,5)->text());
    //COMBOBOX
}

void MainWindow::on_tableWidgetClient_cellClicked(int i, int column)
{
    //recuperation des cellules
    QString no=ui->tableWidgetClient->item(i,1)->text();
    ui->labelNumeroClient->setText(no);
    ui->lineEditNomClient->setText(ui->tableWidgetClient->item(i,2)->text());
    ui->lineEditPrenomClient->setText(ui->tableWidgetClient->item(i,3)->text());
    ui->lineEditMailClient->setText(ui->tableWidgetClient->item(i,4)->text());
    ui->lineEditMdpClient->setText(ui->tableWidgetClient->item(i,5)->text());
}


//----------------------------------------------------------------------------------------------------------------
//----------------------------------------------------MODIFY------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------


void MainWindow::on_pushButtonModifierProduit_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonModifierProduit_clicked()";
    if(!ui->TableWidgetProduit->selectedItems().empty())
    {
        //mise a jour des champs du tableau
        ui->TableWidgetProduit->item(ui->TableWidgetProduit->currentRow(),2)->setText(ui->lineEditNomProduit->text());
        ui->TableWidgetProduit->item(ui->TableWidgetProduit->currentRow(),3)->setText(ui->lineEditInformationProduit->text());
        ui->TableWidgetProduit->item(ui->TableWidgetProduit->currentRow(),4)->setText(ui->lineEditImageProduit->text());
        ui->TableWidgetProduit->item(ui->TableWidgetProduit->currentRow(),5)->setText(ui->lineEditQuantiteProduit->text());
        //ui->TableWidgetProduit->item(ui->TableWidgetProduit->currentRow(),1)->setText(ui->lineEditNumeroVariete->text());

        //mise a jour de la base
        //recuperation des informations
        QString num, nom, info, img, qte, numVariete;
        num=ui->labelNumeroProduit->text().replace("'","''");
        nom=ui->lineEditNomProduit->text().replace("'","''");
        info=ui->lineEditInformationProduit->text().replace("'","''");
        img=ui->lineEditImageProduit->text().replace("'","''");
        qte=ui->lineEditQuantiteProduit->text().replace("'","''");
        numVariete="1";//COMBOBOX A CHANGER

        QString txtReqUpdateProduit="UPDATE Produit SET nomProduit = '"+nom+"', informationProduit = '"+info+"', imageProduit = '"+img+"', quantiteProduit = '"+qte+"', numeroVariete = '"+numVariete+"' WHERE numeroProduit = '"+num+"'";
        qDebug()<<txtReqUpdateProduit;
        QSqlQuery query(txtReqUpdateProduit);

        //date et heure de recup
        QString dateActuelle="2001/01/01";
        QString heureActuelle="00:00:00";

        //j'ajoute une ligne dans la tableWidgetHistorique
        int noLigne=ui->tableWidgetHistorique->rowCount();
        ui->tableWidgetHistorique->insertRow(noLigne);
        ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqUpdateProduit));
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
        QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtReqUpdateProduit+"\",'"+dateActuelle+"','"+heureActuelle+"')";
        qDebug()<<txtReqInsertionCommande;
        QSqlQuery query2(txtReqInsertionCommande);
    }
    else
    {
        ui->statusBar->showMessage("Merci de séléctionner une ligne", 3000);
    }
}

void MainWindow::on_pushButtonModifierVariete_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonModifierVariete_clicked()";
    if(!ui->tableWidgetVariete->selectedItems().empty())
    {
        //mise a jour des champs du tableau
        ui->tableWidgetVariete->item(ui->tableWidgetVariete->currentRow(),2)->setText(ui->lineEditNomVariete->text());
        //ui->tableWidgetVariete->item(ui->tableWidgetVariete->currentRow(),2)->setText(ui->lineEditNumeroRayon->text());

        //mise a jour de la base
        //recuperation des informations
        QString num, nom, numRayon;
        num=ui->labelNumeroVariete->text().replace("'","''");
        nom=ui->lineEditNomVariete->text().replace("'","''");
        numRayon="1";//COMBOBOX A CHANGER

        QString txtReqUpdateVariete="UPDATE Variete SET nomVariete = '"+nom+"', numeroRayon = '"+numRayon+"' WHERE numeroVariete = '"+num+"'";
        qDebug()<<txtReqUpdateVariete;
        QSqlQuery query(txtReqUpdateVariete);

        //date et heure de recup
        QString dateActuelle="2001/01/01";
        QString heureActuelle="00:00:00";

        //j'ajoute une ligne dans la tableWidgetHistorique
        int noLigne=ui->tableWidgetHistorique->rowCount();
        ui->tableWidgetHistorique->insertRow(noLigne);
        ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqUpdateVariete));
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
        QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtReqUpdateVariete+"\",'"+dateActuelle+"','"+heureActuelle+"')";
        qDebug()<<txtReqInsertionCommande;
        QSqlQuery query2(txtReqInsertionCommande);
    }
    else
    {
        ui->statusBar->showMessage("Merci de séléctionner une ligne", 3000);
    }
}

void MainWindow::on_pushButtonModifierRayon_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonModifierRayon_clicked()";
    if(!ui->tableWidgetRayon->selectedItems().empty())
    {
        //mise a jour des champs du tableau
        ui->tableWidgetRayon->item(ui->tableWidgetRayon->currentRow(),2)->setText(ui->lineEditNomRayon->text());

        //mise a jour de la base
        //recuperation des informations
        QString num, nom;
        num=ui->labelNumeroRayon->text().replace("'","''");
        nom=ui->lineEditNomRayon->text().replace("'","''");

        QString txtReqUpdateRayon="UPDATE Rayon SET nomRayon = '"+nom+"' WHERE numeroRayon = '"+num+"'";
        qDebug()<<txtReqUpdateRayon;
        QSqlQuery query(txtReqUpdateRayon);

        //date et heure de recup
        QString dateActuelle="2001/01/01";
        QString heureActuelle="00:00:00";

        //j'ajoute une ligne dans la tableWidgetHistorique
        int noLigne=ui->tableWidgetHistorique->rowCount();
        ui->tableWidgetHistorique->insertRow(noLigne);
        ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqUpdateRayon));
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
        QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtReqUpdateRayon+"\",'"+dateActuelle+"','"+heureActuelle+"')";
        qDebug()<<txtReqInsertionCommande;
        QSqlQuery query2(txtReqInsertionCommande);
    }
    else
    {
        ui->statusBar->showMessage("Merci de séléctionner une ligne", 3000);
    }
}

void MainWindow::on_pushButtonModifierProducteur_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonModifierProduit_clicked()";
    if(!ui->tableWidgetProducteur->selectedItems().empty())
    {
        //mise a jour des champs du tableau
        ui->tableWidgetProducteur->item(ui->tableWidgetProducteur->currentRow(),2)->setText(ui->lineEditNomProducteur->text());
        ui->tableWidgetProducteur->item(ui->tableWidgetProducteur->currentRow(),3)->setText(ui->lineEditPrenomProducteur->text());
        ui->tableWidgetProducteur->item(ui->tableWidgetProducteur->currentRow(),4)->setText(ui->lineEditLoginProducteur->text());
        ui->tableWidgetProducteur->item(ui->tableWidgetProducteur->currentRow(),5)->setText(ui->lineEditMdpProducteur->text());
        //ui->tableWidgetProducteur->item(ui->tableWidgetProducteur->currentRow(),1)->setText(ui->lineEditNumeroAbonnement->text());

        //mise a jour de la base
        //recuperation des informations
        QString num, nom, prenom, log, mdp, numAbo;
        num=ui->labelNumeroProducteur->text().replace("'","''");
        nom=ui->lineEditNomProducteur->text().replace("'","''");
        prenom=ui->lineEditPrenomProducteur->text().replace("'","''");
        log=ui->lineEditLoginProducteur->text().replace("'","''");
        mdp=ui->lineEditMdpProducteur->text().replace("'","''");
        numAbo="1";//COMBOBOX A CHANGER

        QString txtReqUpdateProducteur="UPDATE Producteur SET nomProducteur = '"+nom+"', prenomProducteur = '"+prenom+"', loginProducteur = '"+log+"', mdpProducteur = '"+mdp+"', numeroAbonnement = '"+numAbo+"' WHERE numeroProducteur = '"+num+"'";
        qDebug()<<txtReqUpdateProducteur;
        QSqlQuery query(txtReqUpdateProducteur);

        //date et heure de recup
        QString dateActuelle="2001/01/01";
        QString heureActuelle="00:00:00";

        //j'ajoute une ligne dans la tableWidgetHistorique
        int noLigne=ui->tableWidgetHistorique->rowCount();
        ui->tableWidgetHistorique->insertRow(noLigne);
        ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqUpdateProducteur));
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
        QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtReqUpdateProducteur+"\",'"+dateActuelle+"','"+heureActuelle+"')";
        qDebug()<<txtReqInsertionCommande;
        QSqlQuery query2(txtReqInsertionCommande);
    }
    else
    {
        ui->statusBar->showMessage("Merci de séléctionner une ligne", 3000);
    }
}

void MainWindow::on_pushButtonModifierClient_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonModifierClient_clicked()";
    if(!ui->tableWidgetClient->selectedItems().empty())
    {
        //mise a jour des champs du tableau
        ui->tableWidgetClient->item(ui->tableWidgetClient->currentRow(),2)->setText(ui->lineEditNomClient->text());
        ui->tableWidgetClient->item(ui->tableWidgetClient->currentRow(),3)->setText(ui->lineEditPrenomClient->text());
        ui->tableWidgetClient->item(ui->tableWidgetClient->currentRow(),4)->setText(ui->lineEditMailClient->text());
        ui->tableWidgetClient->item(ui->tableWidgetClient->currentRow(),5)->setText(ui->lineEditMdpClient->text());
        //ui->tableWidgetClient->item(ui->tableWidgetClient->currentRow(),1)->setText(ui->lineEditNumeroAbonnement->text());

        //mise a jour de la base
        //recuperation des informations
        QString num, nom, prenom, mail, mdp;
        num=ui->labelNumeroClient->text().replace("'","''");
        nom=ui->lineEditNomClient->text().replace("'","''");
        prenom=ui->lineEditPrenomClient->text().replace("'","''");
        mail=ui->lineEditMailClient->text().replace("'","''");
        mdp=ui->lineEditMdpClient->text().replace("'","''");

        QString txtReqUpdateClient="UPDATE Client SET nomClient = '"+nom+"', prenomClient = '"+prenom+"', mailClient = '"+mail+"', mdpClient = '"+mdp+"' WHERE numeroClient = '"+num+"'";
        qDebug()<<txtReqUpdateClient;
        QSqlQuery query(txtReqUpdateClient);

        //date et heure de recup
        QString dateActuelle="2001/01/01";
        QString heureActuelle="00:00:00";

        //j'ajoute une ligne dans la tableWidgetHistorique
        int noLigne=ui->tableWidgetHistorique->rowCount();
        ui->tableWidgetHistorique->insertRow(noLigne);
        ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqUpdateClient));
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
        QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtReqUpdateClient+"\",'"+dateActuelle+"','"+heureActuelle+"')";
        qDebug()<<txtReqInsertionCommande;
        QSqlQuery query2(txtReqInsertionCommande);
    }
    else
    {
        ui->statusBar->showMessage("Merci de séléctionner une ligne", 3000);
    }
}
