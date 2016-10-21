#include "chancevariable.h"
#include "ui_chancevariable.h"

ChanceVariable::ChanceVariable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChanceVariable)
{
    ui->setupUi(this);
    //ui->comboBox->addActions(Qlist <QAction> actions);
}

//ChanceVariable::calcTriangular(){

//}

ChanceVariable::~ChanceVariable()
{
    delete ui;
}


void ChanceVariable::on_Configurar_windowTitleChanged(const QString &title)
{

}

void ChanceVariable::on_pushButton_clicked()
{

}

void ChanceVariable::on_serverCountL_textChanged(const QString &arg1)
{
    System::serverCountL = arg1.toInt();
}

void ChanceVariable::on_serverCountR_textChanged(const QString &arg1)
{
    System::serverCountR = arg1.toInt();
}

void ChanceVariable::on_tempoLocal_textChanged(const QString &arg1)
{
    System::tecLocal = arg1.toDouble();
}

void ChanceVariable::on_tempoRemoto_textChanged(const QString &arg1)
{
    System::tecRemote = arg1.toDouble();
}
