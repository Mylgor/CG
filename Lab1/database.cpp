#include "database.h"
#include "ui_database.h"

using namespace std;

DataBase::DataBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataBase)
{
    ui->setupUi(this);

    m_hHeads.append("Country");
    m_hHeads.append("Population (in million)");
    m_count = 0;
    CreateTable();
}

void DataBase::CreateTable()
{
    m_model->setHorizontalHeaderLabels(m_hHeads);
    m_model->setVerticalHeaderLabels(m_vHeads);

    ui->tableView->setModel(m_model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

DataBase::~DataBase()
{
    delete ui;
    delete m_model;
    delete m_item;
}


void DataBase::on_actionNew_Table_triggered()
{
    m_model->clear();
    m_vHeads.clear();
    m_count = 0;
    CreateTable();
}

void DataBase::on_actionAdd_Field_triggered()
{
    if (m_addFieldForm.exec()){}
    else
    {
        if (m_addFieldForm.GetCountry() != "")
        {
            m_count++;
            m_vHeads.append(QString::number(m_count));

            m_item = new QStandardItem(m_addFieldForm.GetCountry());
            m_model->setItem(m_count - 1, 0, m_item);

            m_item = new QStandardItem(m_addFieldForm.GetPopulation());
            m_model->setItem(m_count - 1, 1, m_item);

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
    int Count = ui->tableView->selectionModel()->selectedRows().count();
    for (int i = 0; i < Count; i++)
    {
        ui->tableView->model()->removeRow(ui->tableView->selectionModel()->selectedRows().at(i).row(), QModelIndex());
        m_count--;
    }
}
