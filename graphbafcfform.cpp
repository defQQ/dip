#include "graphbafcfform.h"
#include "ui_graphbafcfform.h"

GraphBafCFForm::GraphBafCFForm(QWidget *parent,vector<int> *data, bool flag) :
    QWidget(parent),
    ui(new Ui::GraphBafCFForm)
{
    ui->setupUi(this);

    if(flag)
        setWindowTitle("График ЦФ силовой релаксации");

    chart = new QChart();
    chart->setTitle("График ЦФ");
    chart->legend()->setVisible(false);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->verticalLayout->addWidget(chartView);

    QLineSeries *s = new QLineSeries();

    for(int i=0;i<data->size();i++){
        s->append(i+1,data->at(i));
    }

    chart->removeAllSeries();
    chart->addSeries(s);
    chart->createDefaultAxes();

    QValueAxis *axisX = new QValueAxis();
    axisX->setLabelFormat("%i");
    axisX->setTickCount(1);

    chart->setAxisX(axisX);
    s->attachAxis(axisX);

}

GraphBafCFForm::~GraphBafCFForm()
{
    delete ui;
}
