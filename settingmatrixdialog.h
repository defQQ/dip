#ifndef SETTINGMATRIXDIALOG_H
#define SETTINGMATRIXDIALOG_H

#include <QDialog>
#include <QHeaderView>
#include <vector>

namespace Ui {
class SettingMatrixDialog;
}

using namespace std;

class SettingMatrixDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingMatrixDialog(QWidget *parent = 0, vector<vector<bool>*> *mem = NULL);
    ~SettingMatrixDialog();

private slots:
    void on_selectionButtonBox_accepted();

    void on_settingMatrixTableWidget_cellClicked(int row, int column);

private:
    Ui::SettingMatrixDialog *ui;
signals:
    void saveMatrix(vector<vector<bool>*>*);
};

#endif // SETTINGMATRIXDIALOG_H
