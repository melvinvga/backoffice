#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QSqlQuery>

MainWindow::MainWindow(QString leNumEmpl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //recuperation du nb empl
    numEmpl=leNumEmpl;

    //recuperation du nom
    QString txtReqNomEmpl="SELECT nomEmploye, prenomEmploye, numeroTypeEmploye FROM Employe WHERE numeroEmploye='"+leNumEmpl+"'";
    qDebug()<<txtReqNomEmpl;
    QSqlQuery queryReqNomEmpl(txtReqNomEmpl);
    queryReqNomEmpl.next();
    QString nomEmpl=queryReqNomEmpl.value("nomEmploye").toString();
    QString prenomEmpl=queryReqNomEmpl.value("prenomEmploye").toString();
    QString noTypeEmpl=queryReqNomEmpl.value("numeroTypeEmploye").toString();

    //recuperation du type d'employer PRENDRE UN EXEMPLE INNER JOIN SUR AUTRE BASE
    QString txtReqTypeEmpl="SELECT TypeEmploye.libelleTypeEmploye FROM Employe INNER JOIN TypeEmploye ON Employe.numeroTypeEmploye=TypeEmploye.numeroTypeEmploye WHERE numeroEmploye='"+leNumEmpl+"'";
    qDebug()<<txtReqTypeEmpl;
    QSqlQuery queryReqTypeEmpl(txtReqTypeEmpl);
    queryReqTypeEmpl.next();
    QString TypeEmpl=queryReqTypeEmpl.value(0).toString();

    ui->labelBvn->setText("Bienvenue "+prenomEmpl+" "+nomEmpl);
    ui->labelTypeEmpl->setText("Vous êtes "+TypeEmpl);

    if (noTypeEmpl == "1")
    {
        ui->tabWidget->setTabVisible(5,0);
        ui->tabWidget->setTabVisible(6,0);
        ui->tabWidget->setTabVisible(7,0);
        ui->tabWidget->setTabVisible(8,0);
    }
    else if (noTypeEmpl == "2")
    {
        ui->tabWidget->setTabVisible(8,0);
        ui->comboBoxTypeEmploye->setVisible(0);
        ui->labelTypeEmploye->setVisible(0);
    }
    ui->labelRaisonProd->setVisible(0);
    ui->lineEditRaisonProd->setVisible(0);
    ui->pushButtonEnvoyerProd->setVisible(0);


    //----------------------------------------------------------------------------------------------------------------
    //------------------------------------------------TABLEAU DE BORD-------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------

    //recuperation du nb de nvx produit
    QString txtReqNbNvxProd="SELECT COUNT(numeroProduit) FROM Produit WHERE DATE(NOW())-dateAjout < 28";
    qDebug()<<txtReqNbNvxProd;
    QSqlQuery queryReqNbNvxProd(txtReqNbNvxProd);
    queryReqNbNvxProd.next();
    QString nbNvxProd=queryReqNbNvxProd.value("COUNT(numeroProduit)").toString();
    qDebug()<<"nbre de nvx produit"<<nbNvxProd;

    QString txtReqNbTotProd="SELECT COUNT(numeroProduit) FROM Produit";
    qDebug()<<txtReqNbTotProd;
    QSqlQuery queryReqNbTotProd(txtReqNbTotProd);
    queryReqNbTotProd.next();
    QString nbTotProd=queryReqNbTotProd.value("COUNT(numeroProduit)").toString();
    qDebug()<<"nbre de nvx produit"<<nbTotProd;

    ui->labelNbNvxProd->setText(nbNvxProd+"/"+nbTotProd);

    //recuperation du nb de nvl variete
    QString txtReqNbNvlVar="SELECT COUNT(numeroVariete) FROM Variete WHERE DATE(NOW())-dateAjout < 28";
    qDebug()<<txtReqNbNvlVar;
    QSqlQuery queryReqNbNvlVar(txtReqNbNvlVar);
    queryReqNbNvlVar.next();
    QString nbNvlVar=queryReqNbNvlVar.value("COUNT(numeroVariete)").toString();
    qDebug()<<"nbre de nvx "<<nbNvlVar;

    QString txtReqNbTotVar="SELECT COUNT(numeroVariete) FROM Variete";
    qDebug()<<txtReqNbNvlVar;
    QSqlQuery queryReqNbTotVar(txtReqNbNvlVar);
    queryReqNbTotVar.next();
    QString nbVarTot=queryReqNbTotVar.value("COUNT(numeroVariete)").toString();
    qDebug()<<"nbre de nvx "<<nbVarTot;

    ui->labelNbNvlVar->setText(nbNvlVar+"/"+nbVarTot);



    //recuperation du nb de nvl variete
    //QString txtReqNbTotLDC="SELECT COUNT(quantite) FROM LDC WHERE DATE(NOW())-dateAjout < 28";
    //qDebug()<<txtReqNbTotLDC;
    //QSqlQuery queryReqNbTotLDC(txtReqNbTotLDC);
    //queryReqNbTotLDC.next();
    //QString nbTotLDC=queryReqNbTotLDC.value("COUNT(numeroVariete)").toString();
    //qDebug()<<"nbre tot "<<nbTotLDC;

    //ui->LabelNbVarRayon->setText(nbVarRayon);

    //recuperation du nb de nvl variete
    QString txtReqNbTotLDC="SELECT COUNT(quantite) FROM LDC WHERE DATE(NOW())-dateAjout < 28";
    qDebug()<<txtReqNbTotLDC;
    QSqlQuery queryReqNbTotLDC(txtReqNbTotLDC);
    queryReqNbTotLDC.next();
    QString nbTotLDC=queryReqNbTotLDC.value("COUNT(numeroVariete)").toString();
    qDebug()<<"nbre tot "<<nbTotLDC;

    ui->labelNbLotProd->setText(nbVarTot);


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
    //----------------------------------------------------EMPLOYE-----------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------


    //Initialisation du tableau
    ui->tableWidgetClient->setRowCount(0);
    ui->tableWidgetClient->setColumnCount(7);
    ui->tableWidgetClient->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //affichage des noms de colonne
    QStringList headerClient;
    headerClient<<""<<"Numero"<<"Nom"<<"Prénom"<<"Mail"<<"Mot de passe";
    ui->tableWidgetClient->setHorizontalHeaderLabels(headerClient);

    if (noTypeEmpl == "2")
    {
        QSqlQuery queryTableClient;
        queryTableClient.exec("SELECT numeroEmploye, nomEmploye, prenomEmploye, mailEmploye, mdpEmploye, numeroTypeEmploye FROM Employe WHERE numeroTypeEmploye=1");
        while(queryTableClient.next())
        {
            ui->tableWidgetClient->insertRow(cptClient);
            QCheckBox* cocher = new QCheckBox();
            listeClient.append(cocher);
            ui->tableWidgetClient->setCellWidget(cptClient,0, cocher);
            ui->tableWidgetClient->setItem(cptClient,1,new QTableWidgetItem(queryTableClient.value("numeroEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,2,new QTableWidgetItem(queryTableClient.value("nomEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,3,new QTableWidgetItem(queryTableClient.value("prenomEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,4,new QTableWidgetItem(queryTableClient.value("mailEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,5,new QTableWidgetItem(queryTableClient.value("mdpEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,6,new QTableWidgetItem(queryTableClient.value("numeroTypeEmploye").toString()));
            cptClient++;
        }
    }
    else if (noTypeEmpl == "3")
    {
        QSqlQuery queryTableClient;
        queryTableClient.exec("SELECT numeroEmploye, nomEmploye, prenomEmploye, mailEmploye, mdpEmploye, numeroTypeEmploye FROM Employe");
        while(queryTableClient.next())
        {
            ui->tableWidgetClient->insertRow(cptClient);
            QCheckBox* cocher = new QCheckBox();
            listeClient.append(cocher);
            ui->tableWidgetClient->setCellWidget(cptClient,0, cocher);
            ui->tableWidgetClient->setItem(cptClient,1,new QTableWidgetItem(queryTableClient.value("numeroEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,2,new QTableWidgetItem(queryTableClient.value("nomEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,3,new QTableWidgetItem(queryTableClient.value("prenomEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,4,new QTableWidgetItem(queryTableClient.value("mailEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,5,new QTableWidgetItem(queryTableClient.value("mdpEmploye").toString()));
            ui->tableWidgetClient->setItem(cptClient,6,new QTableWidgetItem(queryTableClient.value("numeroTypeEmploye").toString()));
            cptClient++;
        }
    }

    //afficher combobox
    QSqlQuery queryComboTypeEmploye;
    queryComboTypeEmploye.exec("SELECT numeroTypeEmploye, libelleTypeEmploye FROM TypeEmploye");
    while(queryComboTypeEmploye.next())
    {
        ui->comboBoxTypeEmploye->addItem(queryComboTypeEmploye.value("libelleTypeEmploye").toString(),queryComboTypeEmploye.value("numeroTypeEmploye").toString());
    }


    //----------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------HISTORIQUE----------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------

    //Initialisation du tableau
    ui->tableWidgetHistorique->setRowCount(0);
    ui->tableWidgetHistorique->setColumnCount(3);
    //ui->tableWidgetHistorique->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //affichage des noms de colonne
    QStringList headerHistorique;
    headerHistorique<<"Commmande"<<"Date"<<"Heure";
    ui->tableWidgetHistorique->setHorizontalHeaderLabels(headerHistorique);


    QSqlQuery queryTableHistorique;
    queryTableHistorique.exec("SELECT nomCommande, dateCommande, HeureCommande FROM Historique");
    while(queryTableHistorique.next())
    {
        ui->tableWidgetHistorique->insertRow(cptHistorique);
        ui->tableWidgetHistorique->setItem(cptHistorique,0,new QTableWidgetItem(queryTableHistorique.value("nomCommande").toString()));
        ui->tableWidgetHistorique->setItem(cptHistorique,1,new QTableWidgetItem(queryTableHistorique.value("dateCommande").toString()));
        ui->tableWidgetHistorique->setItem(cptHistorique,2,new QTableWidgetItem(queryTableHistorique.value("HeureCommande").toString()));
        cptHistorique++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
