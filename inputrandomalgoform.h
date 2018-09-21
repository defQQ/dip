#ifndef INPUTRANDOMALGOFORM_H
#define INPUTRANDOMALGOFORM_H

#include <QWidget>

namespace Ui {
class InputRandomAlgoForm;
}

class InputRandomAlgoForm : public QWidget
{
    Q_OBJECT

public:
     InputRandomAlgoForm(QWidget *parent = 0);
    ~InputRandomAlgoForm();

private slots:
    void on_setCountIterationPushButton_clicked();

private:
    Ui::InputRandomAlgoForm *ui;
};

#endif // INPUTRANDOMALGOFORM_H
