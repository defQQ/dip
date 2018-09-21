#include "settinggenalgodialog.h"
#include "ui_settinggenalgodialog.h"

SettingGenAlgoDialog::SettingGenAlgoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingGenAlgoDialog)
{
    ui->setupUi(this);
}

SettingGenAlgoDialog::~SettingGenAlgoDialog()
{
    delete ui;
}
