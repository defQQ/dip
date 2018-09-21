#include "graphcfform.h"
#include "ui_graphcfform.h"

GraphCFForm::GraphCFForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphCFForm)
{
    ui->setupUi(this);
}

GraphCFForm::~GraphCFForm()
{
    delete ui;
}
