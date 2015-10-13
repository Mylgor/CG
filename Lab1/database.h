#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QDebug>
#include <QStandardItem>
#include <QStandardItemModel>
#include "addfield.h"
#include "aboutapp.h"

namespace Ui {
class DataBase;
}

class DataBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataBase(QWidget *parent = 0);
    void CreateTable();
    ~DataBase();

private slots:
    void on_actionNew_Table_triggered();

    void on_actionAdd_Field_triggered();

    void on_actionAbout_Application_triggered();

    void on_actionEXit_triggered();

    void on_actionDelete_Field_triggered();

private:
    Ui::DataBase *ui;
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    QStringList hHeads, vHeads;
    int count;

    AddField m_addFieldForm;
    AboutApp m_aboutAppForm;
};

#endif // DATABASE_H
