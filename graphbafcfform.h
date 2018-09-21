#ifndef GRAPHBAFCFFORM_H
#define GRAPHBAFCFFORM_H

#include <QWidget>
#include <QtCharts>
#include <QVariant>
#include <vector>

using namespace std;

namespace Ui {
class GraphBafCFForm;
}

class GraphBafCFForm : public QWidget
{
    Q_OBJECT

public:
     GraphBafCFForm(QWidget *parent = 0,vector<int> *data = 0, bool flag=false);
    ~GraphBafCFForm();

private:
    Ui::GraphBafCFForm *ui;
    QChart *chart;
    QChartView *chartView;
};

#endif // GRAPHBAFCFFORM_H
