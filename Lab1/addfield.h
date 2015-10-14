#ifndef ADDFIELD_H
#define ADDFIELD_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class AddField;
}

class AddField : public QDialog
{
    Q_OBJECT

public:
    explicit AddField(QWidget *parent = 0);
    ~AddField();
    QString GetCountry();
    QString GetPopulation();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::AddField *ui;
    QString m_country = "", m_population = "";
};

#endif // ADDFIELD_H
