#include "addfield.h"
#include "ui_addfield.h"

AddField::AddField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddField)
{
    ui->setupUi(this);
}

AddField::~AddField()
{
    delete ui;
}

QString AddField::GetCountry()
{
    return m_country;
}

QString AddField::GetPopulation()
{
    return m_population;
}

void AddField::on_pushButton_clicked()
{
    if ((ui->lineEdit->text().size() > 0) && (ui->spinBox->text() != "0"))
    {
        m_country = ui->lineEdit->text();
        m_population = ui->spinBox->text();
        this->close();
    }
    else
    {
        ui->label_3->setText("Fill the lines");
    }
}

void AddField::on_pushButton_2_clicked()
{
    m_country = "";
    m_population = "";
    this->close();
}
