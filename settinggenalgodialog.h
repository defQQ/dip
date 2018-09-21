#ifndef SETTINGGENALGODIALOG_H
#define SETTINGGENALGODIALOG_H

#include <QDialog>

namespace Ui {
class SettingGenAlgoDialog;
}

class SettingGenAlgoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingGenAlgoDialog(QWidget *parent = 0);
    ~SettingGenAlgoDialog();

private:
    Ui::SettingGenAlgoDialog *ui;
};

#endif // SETTINGGENALGODIALOG_H
