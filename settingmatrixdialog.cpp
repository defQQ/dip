#include "settingmatrixdialog.h"
#include "ui_settingmatrixdialog.h"

SettingMatrixDialog::SettingMatrixDialog(QWidget *parent, vector<vector<bool>*> *mem) :
    QDialog(parent),
    ui(new Ui::SettingMatrixDialog)
{
    ui->setupUi(this);

    ui->settingMatrixTableWidget->setColumnCount(mem->size());
    ui->settingMatrixTableWidget->setRowCount(mem->at(0)->size());
    ui->settingMatrixTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->settingMatrixTableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->settingMatrixTableWidget->verticalHeader()->setStretchLastSection(true);
    ui->settingMatrixTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->settingMatrixTableWidget->horizontalHeader()->setDefaultSectionSize(30);
    ui->settingMatrixTableWidget->verticalHeader()->setDefaultSectionSize(30);

    for(int i=0;i<mem->size();i++){
        for(int j=0;j<mem->at(i)->size();j++){
            if(i!=j){
                QTableWidgetItem *item = new QTableWidgetItem();
                item->data(Qt::CheckStateRole);
                if(mem->at(i)->at(j)){
                    item->setCheckState(Qt::Checked);
                } else {
                    item->setCheckState(Qt::Unchecked);
                }
                ui->settingMatrixTableWidget->setItem(i,j, item);
            }
        }
    }
}

SettingMatrixDialog::~SettingMatrixDialog()
{
    delete ui;
}

void SettingMatrixDialog::on_selectionButtonBox_accepted()
{
    vector<vector<bool>*> *mem = new vector<vector<bool>*>();
    for(int i=0;i<ui->settingMatrixTableWidget->horizontalHeader()->count();i++){
        mem->push_back(new vector<bool>());
        for(int j=0;j<ui->settingMatrixTableWidget->verticalHeader()->count();j++){
            if(i!=j){
                if(ui->settingMatrixTableWidget->item(i,j)->checkState() == Qt::Checked){
                    mem->at(i)->push_back(true);
                }else{
                    mem->at(i)->push_back(false);
                }
            }else{
                mem->at(i)->push_back(false);
            }
        }
    }
    emit saveMatrix(mem);
    close();
}

void SettingMatrixDialog::on_settingMatrixTableWidget_cellClicked(int row, int column)
{
    ui->settingMatrixTableWidget->item(column,row)->setCheckState(ui->settingMatrixTableWidget->item(row,column)->checkState());
}
