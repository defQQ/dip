#include "inputrandomalgoform.h"
#include "ui_inputrandomalgoform.h"

InputRandomAlgoForm::InputRandomAlgoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputRandomAlgoForm)
{
    ui->setupUi(this);
}

InputRandomAlgoForm::~InputRandomAlgoForm()
{
    delete ui;
}

void InputRandomAlgoForm::on_setCountIterationPushButton_clicked()
{
    this->close();
}
