#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>

namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(QString leNumEmpl, QWidget *parent = nullptr);
    ~Profile();

private slots:
    void on_pushButtonValider_clicked();

private:
    Ui::Profile *ui;
    QString numEmpl;
};

#endif // PROFILE_H
