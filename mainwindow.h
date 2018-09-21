#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTime>
#include <vector>
#include <math.h>
#include "graphbafcfform.h"
#include "graphcfform.h"
#include "inputrandomalgoform.h"
#include "settingariadialog.h"
#include "settinggenalgodialog.h"
#include "settingmatrixdialog.h"
#include "aboutform.h"

namespace Ui {
class MainWindow;
}

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent* event);
    void showEvent(QShowEvent* event );

private slots:
    void on_sizeWorkAriaAction_triggered();

    void on_editMatrixAction_triggered();

    void on_genSchemeAction_triggered();

    void on_runRandomAlgoAction_triggered();

    void on_grafWorkRunRandomAlgoAction_triggered();

    void on_settingGenAlgoAction_triggered();

    void on_runAlgoAction_triggered();

    void on_grafWorkAlgoAction_triggered();

    void on_aboutAction_triggered();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    SettingAriaDialog *settingAriaDialog;
    SettingMatrixDialog *settingMatrixDialog;

    int n = 0, m = 0;
    int lastMin;

    vector<vector<bool>*> *memory;
    vector<int> *save;
    vector<int> *graphdata;

    bool flagS=false;
    bool flagZ=false;

    void saveAriaSettings(int n, int m);

    void saveMatrix(vector<vector<bool>*> *);

    void drawAria();

    void drawBlock();

    int randInt(int low, int high);

    vector<vector<bool>*> *getBoolMem(int n, int m, bool flag);

    vector<int> *getBase(bool);

    void drawLines();

    int math(int,int,vector<int> *);
    int countFullLine(vector<int> *);
};

#endif // MAINWINDOW_H
