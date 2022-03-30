#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QSqlQuery>

//----------------------------------------------------------------------------------------------------------------
//----------------------------------------------------AJOUT-------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------


void MainWindow::on_pushButtonInsererProduit_clicked()
{
    //recuperation des informations
    QString nom, info, img, qte, nomVar;

    if(!ui->lineEditNomProduit->text().isEmpty())
    {
        nom=ui->lineEditNomProduit->text().replace("'","''");
        ui->lineEditNomProduit->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditNomProduit->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditInformationProduit->text().isEmpty())
    {
        info=ui->lineEditInformationProduit->text().replace("'","''");
        ui->lineEditInformationProduit->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditInformationProduit->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditImageProduit->text().isEmpty())
    {
        img=ui->lineEditImageProduit->text().replace("'","''");
        ui->lineEditImageProduit->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditImageProduit->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditQuantiteProduit->text().isEmpty())
    {
        qte=ui->lineEditQuantiteProduit->text().replace("'","''");
        ui->lineEditQuantiteProduit->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditQuantiteProduit->setStyleSheet("background-color: #ff3632;");
    }

    nomVar=ui->comboBoxVarieteProduit->currentText().replace("'","''");

    if(!nom.isEmpty() && !info.isEmpty() && !img.isEmpty() && !qte.isEmpty() && !nomVar.isEmpty())
    {
        //calcul du numero le plus haut
        QString txtReqMax="SELECT MAX(numeroProduit) FROM Produit";
        QSqlQuery queryReqMax(txtReqMax);
        queryReqMax.next();
        int noMaxProduit=queryReqMax.value(0).toInt();
        qDebug()<<noMaxProduit;
        noMaxProduit++;
        qDebug()<<noMaxProduit;

        //recuperation du numero de catégorie et du numero d'ateurs
        QString txtReqNumVariete="SELECT numeroVariete FROM Variete WHERE nomVariete='"+nomVar+"'";
        qDebug()<<txtReqNumVariete;
        QSqlQuery queryReqNumVariete(txtReqNumVariete);
        queryReqNumVariete.next();
        QString numVariete=queryReqNumVariete.value(0).toString();
        qDebug()<<numVariete;

        //requete d'insertion dans la base
        QString txtReqInsertion="INSERT INTO Produit (numeroProduit, nomProduit, informationProduit, imageProduit, quantiteProduit, numeroVariete) VALUES ('"+QString::number(noMaxProduit)+"','"+nom+"','"+info+"','"+img+"','"+qte+"','"+numVariete+"')";
        qDebug()<<txtReqInsertion;
        QSqlQuery query(txtReqInsertion);

        //j'ajoute une ligne dans la tableWidget
        int noLigneProd=ui->TableWidgetProduit->rowCount();
        ui->TableWidgetProduit->insertRow(noLigneProd);
        QCheckBox* cocher = new QCheckBox();
        listeProduit.append(cocher);
        ui->TableWidgetProduit->setCellWidget(noLigneProd,0, cocher);
        ui->TableWidgetProduit->setItem(noLigneProd,1,new QTableWidgetItem(QString::number(noMaxProduit)));
        ui->TableWidgetProduit->setItem(noLigneProd,2,new QTableWidgetItem(nom));
        ui->TableWidgetProduit->setItem(noLigneProd,3,new QTableWidgetItem(info));
        ui->TableWidgetProduit->setItem(noLigneProd,4,new QTableWidgetItem(img));
        ui->TableWidgetProduit->setItem(noLigneProd,5,new QTableWidgetItem(qte));
        ui->TableWidgetProduit->setItem(noLigneProd,6,new QTableWidgetItem(numVariete));

        //date et heure de recup
        QString dateActuelle="2001/01/01";
        QString heureActuelle="00:00:00";

        //j'ajoute une ligne dans la tableWidgetHistorique
        int noLigne=ui->tableWidgetHistorique->rowCount();
        ui->tableWidgetHistorique->insertRow(noLigne);
        ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqInsertion));
        ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
        ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

        //calcul du numero le plus haut
        QString txtMax="SELECT MAX(numeroCommande) FROM Historique";
        QSqlQuery queryMax(txtMax);
        queryMax.next();
        int noMax=queryMax.value(0).toInt();
        qDebug()<<noMax;
        noMax++;
        qDebug()<<noMax;

        //j'ajoute a la base de données la commande
        QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtReqInsertion+"\",'"+dateActuelle+"','"+heureActuelle+"')";
        qDebug()<<txtReqInsertionCommande;
        QSqlQuery query2(txtReqInsertionCommande);
    }
}

void MainWindow::on_pushButtonInsererVariete_clicked()
{
    QString nom, nomRayon;

    if(!ui->lineEditNomVariete->text().isEmpty())
    {
        nom=ui->lineEditNomVariete->text().replace("'","''");
        ui->lineEditNomVariete->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditNomVariete->setStyleSheet("background-color: #ff3632;");
    }

    nomRayon=ui->comboBoxRayonVariete->currentText().replace("'","''");

    //calcul du numero le plus haut
    QString txtReqMax="SELECT MAX(numeroVariete) FROM Variete";
    QSqlQuery queryReqMax(txtReqMax);
    queryReqMax.next();
    int noMaxVariete=queryReqMax.value(0).toInt();
    qDebug()<<noMaxVariete;
    noMaxVariete++;
    qDebug()<<noMaxVariete;

    if(!nom.isEmpty() && !nomRayon.isEmpty())
    {
        //recuperation du numero
        QString txtReqNumRayon="SELECT numeroRayon FROM Rayon WHERE nomRayon='"+nomRayon+"'";
        qDebug()<<txtReqNumRayon;
        QSqlQuery queryReqNumRayon(txtReqNumRayon);
        queryReqNumRayon.next();
        QString numRayon=queryReqNumRayon.value(0).toString();
        qDebug()<<numRayon;

        //requete d'insertion dans la base
        QString txtReqInsertion="INSERT INTO Variete (numeroVariete, nomVariete, numeroRayon) VALUES ('"+QString::number(noMaxVariete)+"','"+nom+"','"+numRayon+"')";
        qDebug()<<txtReqInsertion;
        QSqlQuery query(txtReqInsertion);

        //j'ajoute une ligne dans la tableWidget
        int noLigneVar=ui->tableWidgetVariete->rowCount();
        ui->tableWidgetVariete->insertRow(noLigneVar);
        QCheckBox* cocher = new QCheckBox();
        listeVariete.append(cocher);
        ui->tableWidgetVariete->setCellWidget(noLigneVar,0, cocher);
        ui->tableWidgetVariete->setItem(noLigneVar,1,new QTableWidgetItem(QString::number(noMaxVariete)));
        ui->tableWidgetVariete->setItem(noLigneVar,2,new QTableWidgetItem(nom));
        ui->tableWidgetVariete->setItem(noLigneVar,3,new QTableWidgetItem(numRayon));

        //date et heure de recup
        QString dateActuelle="2001/01/01";
        QString heureActuelle="00:00:00";

        //j'ajoute une ligne dans la tableWidgetHistorique
        int noLigne=ui->tableWidgetHistorique->rowCount();
        ui->tableWidgetHistorique->insertRow(noLigne);
        ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqInsertion));
        ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
        ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

        //calcul du numero le plus haut
        QString txtMax="SELECT MAX(numeroCommande) FROM Historique";
        QSqlQuery queryMax(txtMax);
        queryMax.next();
        int noMax=queryMax.value(0).toInt();
        qDebug()<<noMax;
        noMax++;
        qDebug()<<noMax;

        //j'ajoute a la base de données la commande
        QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtReqInsertion+"\",'"+dateActuelle+"','"+heureActuelle+"')";
        qDebug()<<txtReqInsertionCommande;
        QSqlQuery query2(txtReqInsertionCommande);
    }
}

void MainWindow::on_pushButtonInsererRayon_clicked()
{
    QString nom;
    if(!ui->lineEditNomRayon->text().isEmpty())
    {
        nom=ui->lineEditNomRayon->text().replace("'","''");
        ui->lineEditNomRayon->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditNomRayon->setStyleSheet("background-color: #ff3632;");
    }

    if(!nom.isEmpty())
    {
        //calcul du numero le plus haut
        QString txtReqMax="SELECT MAX(numeroRayon) FROM Rayon";
        QSqlQuery queryReqMax(txtReqMax);
        queryReqMax.next();
        int noMaxRayon=queryReqMax.value(0).toInt();
        qDebug()<<noMaxRayon;
        noMaxRayon++;
        qDebug()<<noMaxRayon;
        //requete d'insertion dans la base
        QString txtReqInsertion="INSERT INTO Rayon (numeroRayon, nomRayon) VALUES ('"+QString::number(noMaxRayon)+"','"+nom+"')";
        qDebug()<<txtReqInsertion;
        QSqlQuery query(txtReqInsertion);

        //j'ajoute une ligne dans la tableWidget
        int noLigneRay=ui->tableWidgetRayon->rowCount();
        ui->tableWidgetRayon->insertRow(noLigneRay);
        QCheckBox* cocher = new QCheckBox();
        listeRayon.append(cocher);
        ui->tableWidgetRayon->setCellWidget(noLigneRay,0, cocher);
        ui->tableWidgetRayon->setItem(noLigneRay,1,new QTableWidgetItem(QString::number(noMaxRayon)));
        ui->tableWidgetRayon->setItem(noLigneRay,2,new QTableWidgetItem(nom));

        //date et heure de recup
        QString dateActuelle="2001/01/01";
        QString heureActuelle="00:00:00";

        //j'ajoute une ligne dans la tableWidgetHistorique
        int noLigne=ui->tableWidgetHistorique->rowCount();
        ui->tableWidgetHistorique->insertRow(noLigne);
        ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqInsertion));
        ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
        ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

        //calcul du numero le plus haut
        QString txtMax="SELECT MAX(numeroCommande) FROM Historique";
        QSqlQuery queryMax(txtMax);
        queryMax.next();
        int noMax=queryMax.value(0).toInt();
        qDebug()<<noMax;
        noMax++;
        qDebug()<<noMax;

        //j'ajoute a la base de données la commande
        QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtReqInsertion+"\",'"+dateActuelle+"','"+heureActuelle+"')";
        qDebug()<<txtReqInsertionCommande;
        QSqlQuery query2(txtReqInsertionCommande);
    }
}

void MainWindow::on_pushButtonInsererProducteur_clicked()
{
    QString nom, prenom, login, mdp, numAbo;

    if(!ui->lineEditNomProducteur->text().isEmpty())
    {
        nom=ui->lineEditNomProducteur->text().replace("'","''");
        ui->lineEditNomProducteur->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditNomProducteur->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditPrenomProducteur->text().isEmpty())
    {
        prenom=ui->lineEditPrenomProducteur->text().replace("'","''");
        ui->lineEditPrenomProducteur->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditPrenomProducteur->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditLoginProducteur->text().isEmpty())
    {
        login=ui->lineEditLoginProducteur->text().replace("'","''");
        ui->lineEditLoginProducteur->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditLoginProducteur->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditMdpProducteur->text().isEmpty())
    {
        mdp=ui->lineEditMdpProducteur->text().replace("'","''");
        ui->lineEditMdpProducteur->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditMdpProducteur->setStyleSheet("background-color: #ff3632;");
    }

    bool maj=false, min=false, num=false, spe=false, mdplength = false;
    QString message="Le mot de passe est incorrect : il manque ";

    if(mdp.length()>11)
    {
        mdplength=true;
    }
    for(int i = 0; i < mdp.length(); i++)
    {
        if(mdp[i].isUpper())
        {
            maj=true;
        }
        if(mdp[i].isLower())
        {
             min=true;
        }
        if(mdp[i].isNumber())
        {
            num=true;
        }
        if((mdp[i] >= QChar(33) && mdp[i] <= QChar(47)) || (mdp[i] >= QChar(58) && mdp[i] <= QChar(64)) || (mdp[i] >= QChar(91) && mdp[i] <= QChar(96)) || (mdp[i] >= QChar(123) && mdp[i] <= QChar(126)))
        {
            qDebug()<<mdp[i];
            spe=true;
        }
    }
    if(mdplength && maj && min && num && spe)
    {
        ui->lineEditMdpProducteur->setStyleSheet("background-color: #82d682;");
        numAbo=ui->comboBoxAbonnementProducteur->currentText().replace("'","''");

        //calcul du numero le plus haut
        QString txtReqMax="SELECT MAX(numeroProducteur) FROM Producteur";
        QSqlQuery queryReqMax(txtReqMax);
        queryReqMax.next();
        int noMaxProducteur=queryReqMax.value(0).toInt();
        qDebug()<<noMaxProducteur;
        noMaxProducteur++;
        qDebug()<<noMaxProducteur;
        //requete d'insertion dans la base
        QString txtReqInsertion="INSERT INTO Producteur (numeroProducteur, nomProducteur, prenomProducteur, loginProducteur, mdpProducteur, numeroAbonnement) VALUES ('"+QString::number(noMaxProducteur)+"','"+nom+"','"+prenom+"','"+login+"','"+mdp+"','"+numAbo+"')";
        qDebug()<<txtReqInsertion;
        QSqlQuery query(txtReqInsertion);

        //j'ajoute une ligne dans la tableWidget
        int noLigneProd=ui->tableWidgetProducteur->rowCount();
        ui->tableWidgetProducteur->insertRow(noLigneProd);
        QCheckBox* cocher = new QCheckBox();
        listeProducteur.append(cocher);
        ui->tableWidgetProducteur->setCellWidget(noLigneProd,0, cocher);
        ui->tableWidgetProducteur->setItem(noLigneProd,1,new QTableWidgetItem(QString::number(noMaxProducteur)));
        ui->tableWidgetProducteur->setItem(noLigneProd,2,new QTableWidgetItem(nom));
        ui->tableWidgetProducteur->setItem(noLigneProd,3,new QTableWidgetItem(prenom));
        ui->tableWidgetProducteur->setItem(noLigneProd,4,new QTableWidgetItem(login));
        ui->tableWidgetProducteur->setItem(noLigneProd,5,new QTableWidgetItem(mdp));
        ui->tableWidgetProducteur->setItem(noLigneProd,6,new QTableWidgetItem(numAbo));

        //date et heure de recup
        QString dateActuelle="2001/01/01";
        QString heureActuelle="00:00:00";

        //j'ajoute une ligne dans la tableWidgetHistorique
        int noLigne=ui->tableWidgetHistorique->rowCount();
        ui->tableWidgetHistorique->insertRow(noLigne);
        ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqInsertion));
        ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
        ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

        //calcul du numero le plus haut
        QString txtMax="SELECT MAX(numeroCommande) FROM Historique";
        QSqlQuery queryMax(txtMax);
        queryMax.next();
        int noMax=queryMax.value(0).toInt();
        qDebug()<<noMax;
        noMax++;
        qDebug()<<noMax;

        //j'ajoute a la base de données la commande
        QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"',\""+txtReqInsertion+"\",'"+dateActuelle+"','"+heureActuelle+"')";
        qDebug()<<txtReqInsertionCommande;
        QSqlQuery query2(txtReqInsertionCommande);
    }
    else
    {
        ui->lineEditMdpProducteur->setStyleSheet("background-color: #ff3632;");
        if(!mdplength)
        {
            message+="'12 caractères minimum' ";
        }
        if(!maj)
        {
            message+="'une majuscule' ";
        }
        if(!min)
        {
            message+="'une minuscule' ";
        }
        if(!num)
        {
            message+="'un numero' ";
        }
        if(!spe)
        {
            message+="'un caratère spécial' ";
        }

        ui->statusBar->showMessage(message,3000);
    }
}

void MainWindow::on_pushButtonInsererClient_clicked()
{
    QString nom, prenom, mail, mdp;
    if(!ui->lineEditNomClient->text().isEmpty())
    {
        nom=ui->lineEditNomClient->text().replace("'","''");
        ui->lineEditNomClient->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditNomClient->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditPrenomClient->text().isEmpty())
    {
        prenom=ui->lineEditPrenomClient->text().replace("'","''");
        ui->lineEditPrenomClient->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditPrenomClient->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditMailClient->text().isEmpty())
    {
        mail=ui->lineEditMailClient->text().replace("'","''");
        ui->lineEditMailClient->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditMailClient->setStyleSheet("background-color: #ff3632;");
    }

    if(!ui->lineEditMdpClient->text().isEmpty())
    {
        mdp=ui->lineEditMdpClient->text().replace("'","''");
        ui->lineEditMdpClient->setStyleSheet("background-color: #82d682;");
    }
    else
    {
        ui->lineEditMdpClient->setStyleSheet("background-color: #ff3632;");
    }

    bool maj=false, min=false, num=false, spe=false, mdplength = false;
    QString message="Le mot de passe est incorrect : il manque ";

    if(mdp.length()>11)
    {
        mdplength=true;
    }
    for(int i = 0; i < mdp.length(); i++)
    {
        if(mdp[i].isUpper())
        {
            maj=true;
        }
        if(mdp[i].isLower())
        {
             min=true;
        }
        if(mdp[i].isNumber())
        {
            num=true;
        }
        if((mdp[i] >= QChar(33) && mdp[i] <= QChar(47)) || (mdp[i] >= QChar(58) && mdp[i] <= QChar(64)) || (mdp[i] >= QChar(91) && mdp[i] <= QChar(96)) || (mdp[i] >= QChar(123) && mdp[i] <= QChar(126)))
        {
            qDebug()<<mdp[i];
            spe=true;
        }
    }
    if(mdplength && maj && min && num && spe)
    {
        //recuperation du numero
        QString nomTypeEmploye=ui->comboBoxTypeEmploye->currentText().replace("'","''");
        QString txtReqNumTypeEmploye="SELECT numeroTypeEmploye FROM TypeEmploye WHERE libelleTypeEmploye='"+nomTypeEmploye+"'";
        qDebug()<<txtReqNumTypeEmploye;
        QSqlQuery queryReqNumTypeEmploye(txtReqNumTypeEmploye);
        queryReqNumTypeEmploye.next();
        QString numTypeEmploye=queryReqNumTypeEmploye.value(0).toString();
        qDebug()<<numTypeEmploye;

        //calcul du numero le plus haut
        QString txtReqMax="SELECT MAX(numeroEmploye) FROM Employe";
        QSqlQuery queryReqMax(txtReqMax);
        queryReqMax.next();
        int noMaxClient=queryReqMax.value(0).toInt();
        qDebug()<<noMaxClient;
        noMaxClient++;
        qDebug()<<noMaxClient;

        //recuperation du nom
        QString txtReqNomEmpl="SELECT numeroTypeEmploye FROM Employe WHERE numeroEmploye='"+numEmpl+"'";
        qDebug()<<txtReqNomEmpl;
        QSqlQuery queryReqNomEmpl(txtReqNomEmpl);
        queryReqNomEmpl.next();
        QString noTypeEmpl=queryReqNomEmpl.value("numeroTypeEmploye").toString();


        if (noTypeEmpl == "2")
        {
            //requete d'insertion dans la base
            QString txtReqInsertion="INSERT INTO Employe (numeroEmploye, nomEmploye, prenomEmploye, mailEmploye, mdpEmploye, numeroTypeEmploye) VALUES ('"+QString::number(noMaxClient)+"','"+nom+"','"+prenom+"','"+mail+"','"+mdp+"', 1)";
            qDebug()<<txtReqInsertion;
            QSqlQuery query(txtReqInsertion);

            //j'ajoute une ligne dans la tableWidget
            int noLigneCli=ui->tableWidgetClient->rowCount();
            ui->tableWidgetClient->insertRow(noLigneCli);
            QCheckBox* cocher = new QCheckBox();
            listeClient.append(cocher);
            ui->tableWidgetClient->setCellWidget(noLigneCli,0, cocher);
            ui->tableWidgetClient->setItem(noLigneCli,1,new QTableWidgetItem(QString::number(noMaxClient)));
            ui->tableWidgetClient->setItem(noLigneCli,2,new QTableWidgetItem(nom));
            ui->tableWidgetClient->setItem(noLigneCli,3,new QTableWidgetItem(prenom));
            ui->tableWidgetClient->setItem(noLigneCli,4,new QTableWidgetItem(mail));
            ui->tableWidgetClient->setItem(noLigneCli,5,new QTableWidgetItem(mdp));
            ui->tableWidgetClient->setItem(noLigneCli,6,new QTableWidgetItem(numTypeEmploye));


            //date et heure de recup
            QString dateActuelle="2001/01/01";
            QString heureActuelle="00:00:00";

            //j'ajoute une ligne dans la tableWidgetHistorique
            int noLigne=ui->tableWidgetHistorique->rowCount();
            ui->tableWidgetHistorique->insertRow(noLigne);
            ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqInsertion));
            ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
            ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

            //calcul du numero le plus haut
            QString txtMax="SELECT MAX(numeroCommande) FROM Historique";
            QSqlQuery queryMax(txtMax);
            queryMax.next();
            int noMax=queryMax.value(0).toInt();
            qDebug()<<noMax;
            noMax++;
            qDebug()<<noMax;

            //j'ajoute a la base de données la commande
            QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"','"+txtReqInsertion+"','"+"2001/01/01"+"','"+"00:00:00"+"')";

            qDebug()<<txtReqInsertionCommande;
            QSqlQuery query2(txtReqInsertionCommande);
        }
        if (noTypeEmpl == "3")
        {
            //requete d'insertion dans la base
            QString txtReqInsertion="INSERT INTO Employe (numeroEmploye, nomEmploye, prenomEmploye, mailEmploye, mdpEmploye, numeroTypeEmploye) VALUES ('"+QString::number(noMaxClient)+"','"+nom+"','"+prenom+"','"+mail+"','"+mdp+"','"+numTypeEmploye+"')";
            qDebug()<<txtReqInsertion;
            QSqlQuery query(txtReqInsertion);

            //j'ajoute une ligne dans la tableWidget
            int noLigneCli=ui->tableWidgetClient->rowCount();
            ui->tableWidgetClient->insertRow(noLigneCli);
            QCheckBox* cocher = new QCheckBox();
            listeClient.append(cocher);
            ui->tableWidgetClient->setCellWidget(noLigneCli,0, cocher);
            ui->tableWidgetClient->setItem(noLigneCli,1,new QTableWidgetItem(QString::number(noMaxClient)));
            ui->tableWidgetClient->setItem(noLigneCli,2,new QTableWidgetItem(nom));
            ui->tableWidgetClient->setItem(noLigneCli,3,new QTableWidgetItem(prenom));
            ui->tableWidgetClient->setItem(noLigneCli,4,new QTableWidgetItem(mail));
            ui->tableWidgetClient->setItem(noLigneCli,5,new QTableWidgetItem(mdp));
            ui->tableWidgetClient->setItem(noLigneCli,6,new QTableWidgetItem(numTypeEmploye));

            //date et heure de recup
            QString dateActuelle="2001/01/01";
            QString heureActuelle="00:00:00";

            //j'ajoute une ligne dans la tableWidgetHistorique
            int noLigne=ui->tableWidgetHistorique->rowCount();
            ui->tableWidgetHistorique->insertRow(noLigne);
            ui->tableWidgetHistorique->setItem(noLigne,0,new QTableWidgetItem(txtReqInsertion));
            ui->tableWidgetHistorique->setItem(noLigne,1,new QTableWidgetItem(dateActuelle));
            ui->tableWidgetHistorique->setItem(noLigne,2,new QTableWidgetItem(heureActuelle));

            //calcul du numero le plus haut
            QString txtMax="SELECT MAX(numeroCommande) FROM Historique";
            QSqlQuery queryMax(txtMax);
            queryMax.next();
            int noMax=queryMax.value(0).toInt();
            qDebug()<<noMax;
            noMax++;
            qDebug()<<noMax;

            //j'ajoute a la base de données la commande
            QString txtReqInsertionCommande="INSERT INTO Historique (numeroCommande, nomCommande, dateCommande, heureCommande) VALUES ('"+QString::number(noMax)+"','"+txtReqInsertion+"','"+"2001/01/01"+"','"+"00:00:00"+"')";

            qDebug()<<txtReqInsertionCommande;
            QSqlQuery query2(txtReqInsertionCommande);
        }
    }
    else
    {
        ui->lineEditMdpProducteur->setStyleSheet("background-color: #ff3632;");
        if(!mdplength)
        {
            message+="'12 caractères minimum' ";
        }
        if(!maj)
        {
            message+="'une majuscule' ";
        }
        if(!min)
        {
            message+="'une minuscule' ";
        }
        if(!num)
        {
            message+="'un numero' ";
        }
        if(!spe)
        {
            message+="'un caratère spécial' ";
        }

        ui->statusBar->showMessage(message,3000);
    }
}
