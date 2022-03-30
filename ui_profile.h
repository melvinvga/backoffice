/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Profile
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *labelPrenom;
    QLabel *label_4;
    QLabel *labelNom;
    QLabel *label_9;
    QLineEdit *lineEditTel;
    QLabel *label_8;
    QLineEdit *lineEditMail;
    QLabel *label_2;
    QLabel *label_7;
    QLineEdit *lineEditAdresse;
    QLabel *label;
    QLineEdit *lineEditVille;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_5;
    QLineEdit *lineEditLogin;
    QLabel *label_6;
    QLineEdit *lineEditMdp;
    QLineEdit *lineEditCodepostal;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonValider;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Profile)
    {
        if (Profile->objectName().isEmpty())
            Profile->setObjectName(QString::fromUtf8("Profile"));
        Profile->resize(588, 349);
        verticalLayout = new QVBoxLayout(Profile);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(Profile);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        labelPrenom = new QLabel(Profile);
        labelPrenom->setObjectName(QString::fromUtf8("labelPrenom"));

        gridLayout->addWidget(labelPrenom, 0, 1, 1, 1);

        label_4 = new QLabel(Profile);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        labelNom = new QLabel(Profile);
        labelNom->setObjectName(QString::fromUtf8("labelNom"));

        gridLayout->addWidget(labelNom, 0, 3, 1, 1);

        label_9 = new QLabel(Profile);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        lineEditTel = new QLineEdit(Profile);
        lineEditTel->setObjectName(QString::fromUtf8("lineEditTel"));

        gridLayout->addWidget(lineEditTel, 1, 1, 1, 1);

        label_8 = new QLabel(Profile);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        lineEditMail = new QLineEdit(Profile);
        lineEditMail->setObjectName(QString::fromUtf8("lineEditMail"));

        gridLayout->addWidget(lineEditMail, 1, 3, 1, 1);

        label_2 = new QLabel(Profile);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_7 = new QLabel(Profile);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        lineEditAdresse = new QLineEdit(Profile);
        lineEditAdresse->setObjectName(QString::fromUtf8("lineEditAdresse"));

        gridLayout->addWidget(lineEditAdresse, 3, 1, 1, 3);

        label = new QLabel(Profile);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        lineEditVille = new QLineEdit(Profile);
        lineEditVille->setObjectName(QString::fromUtf8("lineEditVille"));

        gridLayout->addWidget(lineEditVille, 4, 1, 1, 1);

        label_11 = new QLabel(Profile);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 2, 1, 1);

        label_10 = new QLabel(Profile);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 5, 0, 1, 1);

        label_5 = new QLabel(Profile);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        lineEditLogin = new QLineEdit(Profile);
        lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));

        gridLayout->addWidget(lineEditLogin, 6, 1, 1, 1);

        label_6 = new QLabel(Profile);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 2, 1, 1);

        lineEditMdp = new QLineEdit(Profile);
        lineEditMdp->setObjectName(QString::fromUtf8("lineEditMdp"));
        lineEditMdp->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditMdp, 6, 3, 1, 1);

        lineEditCodepostal = new QLineEdit(Profile);
        lineEditCodepostal->setObjectName(QString::fromUtf8("lineEditCodepostal"));

        gridLayout->addWidget(lineEditCodepostal, 4, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButtonValider = new QPushButton(Profile);
        pushButtonValider->setObjectName(QString::fromUtf8("pushButtonValider"));

        horizontalLayout->addWidget(pushButtonValider);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Profile);

        QMetaObject::connectSlotsByName(Profile);
    } // setupUi

    void retranslateUi(QDialog *Profile)
    {
        Profile->setWindowTitle(QCoreApplication::translate("Profile", "Profile", nullptr));
        label_3->setText(QCoreApplication::translate("Profile", "Pr\303\251nom", nullptr));
        labelPrenom->setText(QCoreApplication::translate("Profile", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("Profile", "Nom", nullptr));
        labelNom->setText(QCoreApplication::translate("Profile", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("Profile", "T\303\251l\303\251phone", nullptr));
        label_8->setText(QCoreApplication::translate("Profile", "Adresse mail", nullptr));
        label_2->setText(QString());
        label_7->setText(QCoreApplication::translate("Profile", "Adresse postale", nullptr));
        label->setText(QCoreApplication::translate("Profile", "Vile", nullptr));
        label_11->setText(QCoreApplication::translate("Profile", "Code postal", nullptr));
        label_10->setText(QString());
        label_5->setText(QCoreApplication::translate("Profile", "login", nullptr));
        label_6->setText(QCoreApplication::translate("Profile", "Mot de passe", nullptr));
        pushButtonValider->setText(QCoreApplication::translate("Profile", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Profile: public Ui_Profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
