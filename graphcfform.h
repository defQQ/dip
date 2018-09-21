#ifndef GRAPHCFFORM_H
#define GRAPHCFFORM_H

#include <QWidget>

namespace Ui {
class GraphCFForm;
}

class GraphCFForm : public QWidget
{
    Q_OBJECT

public:
    explicit GraphCFForm(QWidget *parent = 0);
    ~GraphCFForm();

private:
    Ui::GraphCFForm *ui;
};

#endif // GRAPHCFFORM_H
