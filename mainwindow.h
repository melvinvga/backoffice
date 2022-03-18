#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString leNumEmpl, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tableWidgetRayon_cellClicked(int row, int column);

    void on_TableWidgetProduit_cellClicked(int row, int column);

    void on_tableWidgetVariete_cellClicked(int row, int column);

    void on_tableWidgetProducteur_cellClicked(int row, int column);

    void on_tableWidgetClient_cellClicked(int row, int column);

    void on_pushButtonInsererRayon_clicked();

    void on_pushButtonModifierRayon_clicked();

    void on_pushButtonModifierProduit_clicked();

    void on_pushButtonModifierVariete_clicked();

    void on_pushButtonModifierProducteur_clicked();

    void on_pushButtonModifierClient_clicked();

    void on_pushButtonInsererProduit_clicked();

    void on_pushButtonInsererVariete_clicked();

    void on_pushButtonInsererProducteur_clicked();

    void on_pushButtonInsererClient_clicked();

    void on_pushButtonSupprimerProduit_clicked();

    void on_pushButtonSupprimerVariete_clicked();

    void on_pushButtonSupprimerRayon_clicked();

    void on_pushButtonSupprimerProducteur_clicked();

    void on_pushButtonSupprimerClient_clicked();

private:
    Ui::MainWindow *ui;
    QString numEmpl;
    void afficherTable();
    int cptProduit=0, cptVariete=0, cptRayon=0, cptProducteur=0, cptClient=0;
    QList <QCheckBox *> listeProduit;
    QList <QCheckBox *> listeVariete;
    QList <QCheckBox *> listeRayon;
    QList <QCheckBox *> listeProducteur;
    QList <QCheckBox *> listeClient;
};

#endif // MAINWINDOW_H
