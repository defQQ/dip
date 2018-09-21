#ifndef SETTINGARIADIALOG_H
#define SETTINGARIADIALOG_H

#include <QDialog>

namespace Ui {
class SettingAriaDialog;
}

class SettingAriaDialog : public QDialog
{
    Q_OBJECT

public:
     SettingAriaDialog(QWidget *parent = 0,int n = 2, int m = 2);
    ~SettingAriaDialog();

private slots:
    void on_selectionButtonBox_accepted();

private:
    Ui::SettingAriaDialog *ui;

signals:
    void save(int,int);
};

#endif // SETTINGARIADIALOG_H
