#include "database.h"
#include "ui_database.h"

using namespace std;

DataBase::DataBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataBase)
{
    ui->setupUi(this);

    hHeads.append("Country");
    hHeads.append("Population (in million)");
    count = 0;
    CreateTable();
}

void DataBase::CreateTable()
{
    model->setHorizontalHeaderLabels(hHeads);
    model->setVerticalHeaderLabels(vHeads);

    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

DataBase::~DataBase()
{
    delete ui;
    delete model;
    delete item;
}


void DataBase::on_actionNew_Table_triggered()
{
    model->clear();
    vHeads.clear();
    count = 0;
    CreateTable();
}

void DataBase::on_actionAdd_Field_triggered()
{
    if (m_addFieldForm.exec()){}
    else
    {
        if (m_addFieldForm.GetCountry() != "")
        {
            count++;
            vHeads.append(QString::number(count));

            item = new QStandardItem(m_addFieldForm.GetCountry());
            model->setItem(count - 1, 0, item);

            item = new QStandardItem(m_addFieldForm.GetPopulation());
            model->setItem(count - 1, 1, item);

            CreateTable();
        }
    }

}

void DataBase::on_actionAbout_Application_triggered()
{
    m_aboutAppForm.show();
}

void DataBase::on_actionEXit_triggered()
{
    this->close();
}

void DataBase::on_actionDelete_Field_triggered()
{
    int mCount = ui->tableView->selectionModel()->selectedRows().count();
    for (int i = 0; i < mCount; i++)
    {
        ui->tableView->model()->removeRow(ui->tableView->selectionModel()->selectedRows().at(i).row(), QModelIndex());
        count--;
    }
}
