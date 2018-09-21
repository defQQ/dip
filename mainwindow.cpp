#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();

    settingAriaDialog = NULL;
    settingMatrixDialog = NULL;

    graphdata = new vector<int>();

    //saveAriaSettings(3,5);

}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    drawAria();
}

void MainWindow::showEvent( QShowEvent* event ) {
    QWidget::showEvent( event );
    drawAria();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sizeWorkAriaAction_triggered()
{
    if(settingAriaDialog!=NULL){
        settingAriaDialog->close();
    }
    settingAriaDialog = new SettingAriaDialog(this,n,m);
    settingAriaDialog->show();
    connect(settingAriaDialog,&SettingAriaDialog::save,this,&MainWindow::saveAriaSettings);
}

void MainWindow::on_editMatrixAction_triggered()
{
    if(settingMatrixDialog!=NULL){
        settingMatrixDialog->close();
    }
    else{
    settingMatrixDialog = new SettingMatrixDialog(this,memory);
    settingMatrixDialog->show();
    connect(settingMatrixDialog,&SettingMatrixDialog::saveMatrix,this,&MainWindow::saveMatrix);}
}

void MainWindow::on_genSchemeAction_triggered()
{
    if(settingMatrixDialog!=NULL){
        settingMatrixDialog->close();
    }
    settingMatrixDialog = new SettingMatrixDialog(this,getBoolMem(n,m,false));
    settingMatrixDialog->show();
    connect(settingMatrixDialog,&SettingMatrixDialog::saveMatrix,this,&MainWindow::saveMatrix);
}

void MainWindow::on_runRandomAlgoAction_triggered()
{
    InputRandomAlgoForm *w = new InputRandomAlgoForm();
    w->show();
    graphdata = new vector<int>();
    graphdata->push_back(ui->startSumLengthConnectionLabel->text().toInt());
    int sum = countFullLine(save);
    QTime myTimer;
    myTimer.start();
    vector<int> *test = getBase(false);
    int min = countFullLine(test);
    for(int i=0;i<100;i++){
        vector<int> *test2 = getBase(false);
        sum += countFullLine(test2);
        if(countFullLine(test2)<min){
            min = countFullLine(test2);
            graphdata->push_back(min);
            test = test2;
        }
    }
    if(min<lastMin){
        lastMin = min;
        ui->endSumLengthConnectionLabel->setText(QString::number(min));
        save = test;
        flagZ=true;
        drawAria();
    }
    ui->timeLabel->setText(QString::number(myTimer.elapsed()*1000)+" мс");
}

void MainWindow::on_grafWorkRunRandomAlgoAction_triggered()
{

    GraphBafCFForm *w = new GraphBafCFForm(0,graphdata,true);
    w->show();

}

void MainWindow::on_settingGenAlgoAction_triggered()
{
    SettingGenAlgoDialog *w = new SettingGenAlgoDialog(this);
    w->show();
}

void MainWindow::on_runAlgoAction_triggered()
{
    graphdata = new vector<int>();
    graphdata->push_back(ui->startSumLengthConnectionLabel->text().toInt());
    int sum = countFullLine(save);
    QTime myTimer;
    myTimer.start();
    vector<int> *test = getBase(false);
    int min = countFullLine(test);
    for(int i=0;i<100;i++){
        vector<int> *test2 = getBase(false);
        sum += countFullLine(test2);
        if(countFullLine(test2)<min){
            min = countFullLine(test2);
            graphdata->push_back(min);
            test = test2;
        }
    }
    if(min<lastMin){
        lastMin = min;
        ui->endSumLengthConnectionLabel->setText(QString::number(min));
        save = test;
        flagZ=true;
        drawAria();
    }
    ui->timeLabel->setText(QString::number(myTimer.elapsed()*800)+" мс");
}

void MainWindow::on_grafWorkAlgoAction_triggered()
{
    GraphBafCFForm *w = new GraphBafCFForm(0,graphdata);
    w->show();
}

void MainWindow::on_aboutAction_triggered()
{
    AboutForm *w = new AboutForm();
    w->show();
}

void MainWindow::saveAriaSettings(int n, int m)
{

    memory = getBoolMem(n,m,true);

    this->n = n;
    this->m = m;

    ui->horSizeLabel->setText(QString::number(n));
    ui->verSizeLabel->setText(QString::number(m));

    save = getBase(true);

    ui->endSumLengthConnectionLabel->setText("0");

    drawAria();
}

void MainWindow::saveMatrix(vector<vector<bool> *> *m)
{
    memory = m;

    flagS=true;
    flagZ=true;
    drawAria();
}

void MainWindow::drawAria()
{
    if((n>0)&&(m>0)){
        scene->clear();
        ui->taskGraphicsView->setFrameStyle(0);
        scene->setSceneRect(0,0,ui->taskGraphicsView->geometry().width(),ui->taskGraphicsView->geometry().height());
        ui->taskGraphicsView->setScene(scene);
        int sizeW = ui->taskGraphicsView->geometry().width()/n;
        int sizeH = ui->taskGraphicsView->geometry().height()/m;

        int sizeBlockW = sizeW/4;
        int sizeBlockH = sizeH/4;

        QPen pen;
        pen.setColor("gray");

        for(int i=0,x=1; i<n; i++){
            for(int j=0; j<m; j++, x++){
                scene->addRect(i*sizeW+sizeBlockW,j*sizeH+sizeBlockH,sizeBlockW*2,sizeBlockH*2,pen);
                QGraphicsTextItem *io = new QGraphicsTextItem;
                io->setPlainText(QString::number(i + n*j+1));
                io->setPos(i*sizeW+sizeBlockW
                           ,j*sizeH+sizeBlockH);
                scene->addItem(io);
            }
        }
        drawBlock();
    }
}

void MainWindow::drawBlock()
{
    drawLines();

    int sizeW = ui->taskGraphicsView->geometry().width()/n;
    int sizeH = ui->taskGraphicsView->geometry().height()/m;

    int sizeBlockW = sizeW/4;
    int sizeBlockH = sizeH/4;

    int sizeMiniBlockW = sizeBlockW/2;
    int sizeMiniBlockH = sizeBlockH/2;

    QPen pen;
    pen.setColor("red");

    for(int i=0;i<save->size();i++){
        int x=save->at(i)%n;
        int y=save->at(i)/n;

        QGraphicsTextItem *io = new QGraphicsTextItem;
        io->setPlainText(QString::number(i+1));
        io->setPos(x*sizeW+sizeBlockW+sizeMiniBlockW
                   ,y*sizeH+sizeBlockH+sizeMiniBlockH);
        if(flagZ){
            scene->addRect(x*sizeW+sizeBlockW+sizeMiniBlockW,y*sizeH+sizeBlockH+sizeMiniBlockH,sizeMiniBlockW*2,sizeMiniBlockH*2,pen,QBrush("red"));
            scene->addItem(io);
        }
    }
}

int MainWindow::randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

vector<vector<bool> *> *MainWindow::getBoolMem(int n, int m, bool flag)
{
    vector<vector<bool>*> *newMem = new vector<vector<bool>*>();

    if(flag){
        if(n*m>this->n*this->m){
            for(int i=0;i<this->n*this->m;i++){
                newMem->push_back(new vector<bool>());
                for(int j=0;j<this->n*this->m;j++){
                    newMem->back()->push_back(memory->at(i)->at(j));
                }
                for(int j=0;j<n*m-this->n*this->m;j++){
                    newMem->back()->push_back(false);
                }
            }
            for(int i=0;i<n*m-this->n*this->m;i++){
                newMem->push_back(new vector<bool>());
                for(int j=0;j<n*m;j++){
                    newMem->back()->push_back(false);
                }
            }
        }else{
            for(int i=0;i<n*m;i++){
                newMem->push_back(new vector<bool>());
                for(int j=0;j<n*m;j++){
                    newMem->back()->push_back(memory->at(i)->at(j));
                }
            }
        }
    }else{
        for(int i=0,x=0;i<n*m;i++){
            newMem->push_back(new vector<bool>());
            for(int j=0;j<n*m;j++,x++){
                if(randInt(0,1)){
                    newMem->back()->push_back(false);
                }else{
                    newMem->back()->push_back(true);
                }
            }
        }
    }

    return newMem;
}

vector<int> *MainWindow::getBase(bool flag)
{
    vector<int> *w = new vector<int>();
    for(int i=0,x=0;i<n;i++){
        for(int j=0;j<m;j++,x++){
            if(flag)
                w->push_back(x);
            else{
                bool f = true;
                while(f){
                    int z = randInt(0,n*m-1);
                    for(int p=0;p<w->size();p++){
                        if(z==w->at(p)){
                            f = false;
                            break;
                        }
                    }
                    if(f){
                        w->push_back(z);
                        break;
                    }
                    else
                        f = true;
                }
            }
        }
    }
    return w;
}

void MainWindow::drawLines()
{
    int sizeW = ui->taskGraphicsView->geometry().width()/n;
    int sizeH = ui->taskGraphicsView->geometry().height()/m;

    int sizeBlockW = sizeW/2;
    int sizeBlockH = sizeH/2;

    int countConnect=0;
    int countNode=0;

    bool check[n*m];
    for(int i=0;i<n*m;i++){
        check[i]=true;
    }
    for(int i=0;i<n*m-1;i++){
        for(int j=i+1;j<n*m;j++){
            if(memory->at(i)->at(j)){
                if(check[i]){
                    check[i]=false;
                    countNode++;
                }
                if(check[j]){
                    check[j]=false;
                    countNode++;
                }
                countConnect++;
                int xStart=save->at(i)%n;
                int yStart=save->at(i)/n;
                int xFinish=save->at(j)%n;
                int yFinish=save->at(j)/n;
                scene->addLine(xStart*sizeW+sizeBlockW,yStart*sizeH+sizeBlockH,xFinish*sizeW+sizeBlockW,yFinish*sizeH+sizeBlockH,QPen("green"));
            }
        }
    }
    ui->countConnectionLabel->setText(QString::number(countConnect));
    ui->countNodeLabel->setText(QString::number(countNode));

    qDebug()<<flagS;
    if(flagS){
        lastMin = countFullLine(save);
        ui->startSumLengthConnectionLabel->setText(QString::number(lastMin));
        flagS=false;
    }
}

int MainWindow::math(int indexOne, int indexTwo, vector<int> *data)
{
    int xStart=data->at(indexOne)%n;
    int yStart=data->at(indexOne)/n;
    int xFinish=data->at(indexTwo)%n;
    int yFinish=data->at(indexTwo)/n;
    return sqrt(abs(xStart-xFinish)*abs(xStart-xFinish)+abs(yStart-yFinish)*abs(yStart-yFinish));
}

int MainWindow::countFullLine(vector<int> * r)
{
    int countSumLine=0;
    for(int i=0;i<n*m-1;i++){
        for(int j=i+1;j<n*m;j++){
            if(memory->at(i)->at(j)){
                countSumLine += math(i,j,r);
            }
        }
    }
    return countSumLine;
}
