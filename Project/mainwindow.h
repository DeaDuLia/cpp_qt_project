#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmdisubwindow.h>
#include <QMouseEvent>
#include <string>
#include <myqaction.h>
#include <QTextEdit>
#include "ui_form2.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    string fileName;
    string dictName;
    QTextEdit *file;
    QTextEdit *dict;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

    void on_action_4_triggered();

public:
    Ui::MainWindow *ui;

    void loadSubWindow(QWidget *widget);
};
#endif // MAINWINDOW_H
