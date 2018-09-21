#include "settingariadialog.h"
#include "ui_settingariadialog.h"

SettingAriaDialog::SettingAriaDialog(QWidget *parent,int n, int m) :
    QDialog(parent),
    ui(new Ui::SettingAriaDialog)
{
    ui->setupUi(this);
    if((n>0)&&(m>0)){
        ui->horInputSpinBox->setValue(n);
        ui->verInputSpinBox->setValue(m);
    }
}

SettingAriaDialog::~SettingAriaDialog()
{
    delete ui;
}

void SettingAriaDialog::on_selectionButtonBox_accepted()
{
    emit save(ui->horInputSpinBox->value(),ui->verInputSpinBox->value());
    close();
}
