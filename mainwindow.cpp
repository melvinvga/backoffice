#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QSqlQuery>
#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QString leNumEmpl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //recuperation du nom
    QString txtReqNomEmpl="SELECT nomEmploye FROM Employe WHERE numeroEmploye='"+leNumEmpl+"'";
    qDebug()<<txtReqNomEmpl;
    QSqlQuery queryReqNomEmpl(txtReqNomEmpl);
    queryReqNomEmpl.next();
    QString NomEmpl=queryReqNomEmpl.value(0).toString();

    //recuperation du type d'employer PRENDRE UN EXEMPLE INNER JOIN SUR AUTRE BASE
    QString txtReqTypeEmpl="SELECT TypeEmploye.libelleTypeEmploye FROM Employe INNER JOIN TypeEmploye ON Employe.numeroTypeEmploye=TypeEmploye.numeroTypeEmploye WHERE numeroEmploye='"+leNumEmpl+"'";
    qDebug()<<txtReqTypeEmpl;
    QSqlQuery queryReqTypeEmpl(txtReqTypeEmpl);
    queryReqTypeEmpl.next();
    QString TypeEmpl=queryReqTypeEmpl.value(0).toString();

    ui->labelBvn->setText("Bienvenue "+NomEmpl);
    ui->labelTypeEmpl->setText("Vous êtes "+TypeEmpl);

    
    //----------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------PRODUIT-----------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------

    
    //Initialisation du tableau
    ui->TableWidgetProduit->setRowCount(0);
    ui->TableWidgetProduit->setColumnCount(7);
    ui->TableWidgetProduit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //affichage des noms de colonne
    QStringList headerProduit;
    headerProduit<<""<<"Numero"<<"Nom"<<"Information"<<"Image"<<"Quantité"<<"Variété";
    ui->TableWidgetProduit->setHorizontalHeaderLabels(headerProduit);


    QSqlQuery queryTableProduit;
    queryTableProduit.exec("SELECT numeroProduit, nomProduit, informationProduit, imageProduit, quantiteProduit, numeroVariete FROM Produit");
    while(queryTableProduit.next())
    {
        ui->TableWidgetProduit->insertRow(cptProduit);
        QCheckBox* cocher = new QCheckBox();
        listeProduit.append(cocher);
        ui->TableWidgetProduit->setCellWidget(cptProduit,0, cocher);
        ui->TableWidgetProduit->setItem(cptProduit,1,new QTableWidgetItem(queryTableProduit.value("numeroProduit").toString()));
        ui->TableWidgetProduit->setItem(cptProduit,2,new QTableWidgetItem(queryTableProduit.value("nomProduit").toString()));
        ui->TableWidgetProduit->setItem(cptProduit,3,new QTableWidgetItem(queryTableProduit.value("informationProduit").toString()));
        ui->TableWidgetProduit->setItem(cptProduit,4,new QTableWidgetItem(queryTableProduit.value("imageProduit").toString()));
        ui->TableWidgetProduit->setItem(cptProduit,5,new QTableWidgetItem(queryTableProduit.value("quantiteProduit").toString()));
        ui->TableWidgetProduit->setItem(cptProduit,6,new QTableWidgetItem(queryTableProduit.value("numeroVariete").toString()));
        cptProduit++;
    }

    //afficher combobox
    QSqlQuery queryComboVarieteProduit;
    queryComboVarieteProduit.exec("SELECT numeroVariete, nomVariete FROM Variete");
    while(queryComboVarieteProduit.next())
    {
        ui->comboBoxVarieteProduit->addItem(queryComboVarieteProduit.value("nomVariete").toString(),queryComboVarieteProduit.value("numeroVariete").toString());
    }

    
    //----------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------VARIETE-----------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------

    
    //Initialisation du tableau
    ui->tableWidgetVariete->setRowCount(0);
    ui->tableWidgetVariete->setColumnCount(4);
    ui->tableWidgetVariete->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //affichage des noms de colonne
    QStringList headerVariete;
    headerVariete<<""<<"Numero"<<"Nom"<<"Rayon";
    ui->tableWidgetVariete->setHorizontalHeaderLabels(headerVariete);


    QSqlQuery queryTableVariete;
    queryTableVariete.exec("SELECT numeroVariete, nomVariete, numeroRayon FROM Variete");
    while(queryTableVariete.next())
    {
        ui->tableWidgetVariete->insertRow(cptVariete);
        QCheckBox* cocher = new QCheckBox();
        listeVariete.append(cocher);
        ui->tableWidgetVariete->setCellWidget(cptVariete,0, cocher);
        ui->tableWidgetVariete->setItem(cptVariete,1,new QTableWidgetItem(queryTableVariete.value("numeroVariete").toString()));
        ui->tableWidgetVariete->setItem(cptVariete,2,new QTableWidgetItem(queryTableVariete.value("nomVariete").toString()));
        ui->tableWidgetVariete->setItem(cptVariete,3,new QTableWidgetItem(queryTableVariete.value("numeroRayon").toString()));
        cptVariete++;
    }

    //afficher combobox
    QSqlQuery queryComboRayonVariete;
    queryComboRayonVariete.exec("SELECT numeroRayon, nomRayon FROM Rayon");
    while(queryComboRayonVariete.next())
    {
        ui->comboBoxRayonVariete->addItem(queryComboRayonVariete.value("nomRayon").toString(),queryComboRayonVariete.value("numeroRayon").toString());
    }

    
    //----------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------RAYON------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------

    
    //Initialisation du tableau
    ui->tableWidgetRayon->setRowCount(0);
    ui->tableWidgetRayon->setColumnCount(3);
    ui->tableWidgetRayon->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //affichage des noms de colonne
    QStringList headerRayon;
    headerRayon<<""<<"Numero"<<"Nom";
    ui->tableWidgetRayon->setHorizontalHeaderLabels(headerRayon);


    QSqlQuery queryTableRayon;
    queryTableRayon.exec("SELECT numeroRayon, nomRayon FROM Rayon");
    while(queryTableRayon.next())
    {
        ui->tableWidgetRayon->insertRow(cptRayon);
        QCheckBox* cocher = new QCheckBox();
        listeRayon.append(cocher);
        ui->tableWidgetRayon->setCellWidget(cptRayon,0, cocher);
        ui->tableWidgetRayon->setItem(cptRayon,1,new QTableWidgetItem(queryTableRayon.value("numeroRayon").toString()));
        ui->tableWidgetRayon->setItem(cptRayon,2,new QTableWidgetItem(queryTableRayon.value("nomRayon").toString()));
        cptRayon++;
    }

    
    //----------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------PRODUCTEUR----------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------

    
    //Initialisation du tableau
    ui->tableWidgetProducteur->setRowCount(0);
    ui->tableWidgetProducteur->setColumnCount(7);
    ui->tableWidgetProducteur->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //affichage des noms de colonne
    QStringList headerProducteur;
    headerProducteur<<""<<"Numero"<<"Nom"<<"Prenom"<<"Login"<<"Mot de passe"<<"Abonnement";
    ui->tableWidgetProducteur->setHorizontalHeaderLabels(headerProducteur);


    QSqlQuery queryTableProducteur;
    queryTableProducteur.exec("SELECT numeroProducteur, nomProducteur, PrenomProducteur, loginProducteur, mdpProducteur, numeroAbonnement FROM Producteur");
    while(queryTableProducteur.next())
    {
        ui->tableWidgetProducteur->insertRow(cptProducteur);
        QCheckBox* cocher = new QCheckBox();
        listeProducteur.append(cocher);
        ui->tableWidgetProducteur->setCellWidget(cptProducteur,0, cocher);
        ui->tableWidgetProducteur->setItem(cptProducteur,1,new QTableWidgetItem(queryTableProducteur.value("numeroProducteur").toString()));
        ui->tableWidgetProducteur->setItem(cptProducteur,2,new QTableWidgetItem(queryTableProducteur.value("nomProducteur").toString()));
        ui->tableWidgetProducteur->setItem(cptProducteur,3,new QTableWidgetItem(queryTableProducteur.value("PrenomProducteur").toString()));
        ui->tableWidgetProducteur->setItem(cptProducteur,4,new QTableWidgetItem(queryTableProducteur.value("loginProducteur").toString()));
        ui->tableWidgetProducteur->setItem(cptProducteur,5,new QTableWidgetItem(queryTableProducteur.value("mdpProducteur").toString()));
        ui->tableWidgetProducteur->setItem(cptProducteur,6,new QTableWidgetItem(queryTableProducteur.value("numeroAbonnement").toString()));
        cptProducteur++;
    }

    //afficher combobox
    QSqlQuery queryComboAbonnementProducteur;
    queryComboAbonnementProducteur.exec("SELECT numeroAbonnement FROM Abonnement");
    while(queryComboAbonnementProducteur.next())
    {
        ui->comboBoxAbonnementProducteur->addItem(queryComboAbonnementProducteur.value("numeroAbonnement").toString());
    }

    
    //----------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------CLIENT------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------

    
    //Initialisation du tableau
    ui->tableWidgetClient->setRowCount(0);
    ui->tableWidgetClient->setColumnCount(6);
    ui->tableWidgetClient->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //affichage des noms de colonne
    QStringList headerClient;
    headerClient<<""<<"Numero"<<"Nom"<<"Prénom"<<"Mail"<<"Mot de passe";
    ui->tableWidgetClient->setHorizontalHeaderLabels(headerClient);


    QSqlQuery queryTableClient;
    queryTableClient.exec("SELECT numeroClient, nomClient, prenomClient, mailClient, mdpClient FROM Client");
    while(queryTableClient.next())
    {
        ui->tableWidgetClient->insertRow(cptClient);
        QCheckBox* cocher = new QCheckBox();
        listeClient.append(cocher);
        ui->tableWidgetClient->setCellWidget(cptClient,0, cocher);
        ui->tableWidgetClient->setItem(cptClient,1,new QTableWidgetItem(queryTableClient.value("numeroClient").toString()));
        ui->tableWidgetClient->setItem(cptClient,2,new QTableWidgetItem(queryTableClient.value("nomClient").toString()));
        ui->tableWidgetClient->setItem(cptClient,3,new QTableWidgetItem(queryTableClient.value("prenomClient").toString()));
        ui->tableWidgetClient->setItem(cptClient,4,new QTableWidgetItem(queryTableClient.value("mailClient").toString()));
        ui->tableWidgetClient->setItem(cptClient,5,new QTableWidgetItem(queryTableClient.value("mdpClient").toString()));
        cptClient++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


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
    }
    else
    {
        ui->statusBar->showMessage("Merci de séléctionner une ligne", 3000);
    }
}


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
        int noLigne=ui->TableWidgetProduit->rowCount();
        ui->TableWidgetProduit->insertRow(noLigne);
        QCheckBox* cocher = new QCheckBox();
        listeProduit.append(cocher);
        ui->TableWidgetProduit->setCellWidget(noLigne,0, cocher);
        ui->TableWidgetProduit->setItem(noLigne,1,new QTableWidgetItem(QString::number(noMaxProduit)));
        ui->TableWidgetProduit->setItem(noLigne,2,new QTableWidgetItem(nom));
        ui->TableWidgetProduit->setItem(noLigne,3,new QTableWidgetItem(info));
        ui->TableWidgetProduit->setItem(noLigne,4,new QTableWidgetItem(img));
        ui->TableWidgetProduit->setItem(noLigne,5,new QTableWidgetItem(qte));
        ui->TableWidgetProduit->setItem(noLigne,6,new QTableWidgetItem(numVariete));
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
        //recuperation du numero de catégorie et du numero d'ateurs
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
        int noLigne=ui->tableWidgetVariete->rowCount();
        ui->tableWidgetVariete->insertRow(noLigne);
        QCheckBox* cocher = new QCheckBox();
        listeVariete.append(cocher);
        ui->tableWidgetVariete->setCellWidget(noLigne,0, cocher);
        ui->tableWidgetVariete->setItem(noLigne,1,new QTableWidgetItem(QString::number(noMaxVariete)));
        ui->tableWidgetVariete->setItem(noLigne,2,new QTableWidgetItem(nom));
        ui->tableWidgetVariete->setItem(noLigne,3,new QTableWidgetItem(numRayon));
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
        int noLigne=ui->tableWidgetRayon->rowCount();
        ui->tableWidgetRayon->insertRow(noLigne);
        QCheckBox* cocher = new QCheckBox();
        listeRayon.append(cocher);
        ui->tableWidgetRayon->setCellWidget(noLigne,0, cocher);
        ui->tableWidgetRayon->setItem(noLigne,1,new QTableWidgetItem(QString::number(noMaxRayon)));
        ui->tableWidgetRayon->setItem(noLigne,2,new QTableWidgetItem(nom));
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
        int noLigne=ui->tableWidgetProducteur->rowCount();
        ui->tableWidgetProducteur->insertRow(noLigne);
        QCheckBox* cocher = new QCheckBox();
        listeProducteur.append(cocher);
        ui->tableWidgetProducteur->setCellWidget(noLigne,0, cocher);
        ui->tableWidgetProducteur->setItem(noLigne,1,new QTableWidgetItem(QString::number(noMaxProducteur)));
        ui->tableWidgetProducteur->setItem(noLigne,2,new QTableWidgetItem(nom));
        ui->tableWidgetProducteur->setItem(noLigne,3,new QTableWidgetItem(prenom));
        ui->tableWidgetProducteur->setItem(noLigne,4,new QTableWidgetItem(login));
        ui->tableWidgetProducteur->setItem(noLigne,5,new QTableWidgetItem(mdp));
        ui->tableWidgetProducteur->setItem(noLigne,6,new QTableWidgetItem(numAbo));
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
        //calcul du numero le plus haut
        QString txtReqMax="SELECT MAX(numeroClient) FROM Client";
        QSqlQuery queryReqMax(txtReqMax);
        queryReqMax.next();
        int noMaxClient=queryReqMax.value(0).toInt();
        qDebug()<<noMaxClient;
        noMaxClient++;
        qDebug()<<noMaxClient;
        //requete d'insertion dans la base
        QString txtReqInsertion="INSERT INTO Client (numeroClient, nomClient, prenomClient, mailClient, mdpClient) VALUES ('"+QString::number(noMaxClient)+"','"+nom+"','"+prenom+"','"+mail+"','"+mdp+"')";
        qDebug()<<txtReqInsertion;
        QSqlQuery query(txtReqInsertion);

        //j'ajoute une ligne dans la tableWidget
        int noLigne=ui->tableWidgetClient->rowCount();
        ui->tableWidgetClient->insertRow(noLigne);
        QCheckBox* cocher = new QCheckBox();
        listeClient.append(cocher);
        ui->tableWidgetClient->setCellWidget(noLigne,0, cocher);
        ui->tableWidgetClient->setItem(noLigne,1,new QTableWidgetItem(QString::number(noMaxClient)));
        ui->tableWidgetClient->setItem(noLigne,2,new QTableWidgetItem(nom));
        ui->tableWidgetClient->setItem(noLigne,3,new QTableWidgetItem(prenom));
        ui->tableWidgetClient->setItem(noLigne,4,new QTableWidgetItem(mail));
        ui->tableWidgetClient->setItem(noLigne,5,new QTableWidgetItem(mdp));
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
        }
    }
}
