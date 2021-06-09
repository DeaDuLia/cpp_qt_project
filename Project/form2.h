#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include <string>
#include <mainwindow.h>
#include <QMouseEvent>
#include <QCloseEvent>


using namespace std;
namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT
public:
    QAction *action;
    MainWindow *mw;

public:
    explicit Form2(QWidget *parent = nullptr);
    explicit Form2(string text = "", QWidget *parent = nullptr);
    explicit Form2(string text = "", QAction *action = nullptr, QWidget *parent = nullptr);
    explicit Form2(MainWindow *mw, string text = "", QAction *action = nullptr, QWidget *parent = nullptr);
    ~Form2();

    void mousePressEvent(QMouseEvent *event);
    void windowClosed(QCloseEvent *event);

private slots:
    void on_Form2_destroyed();

    void on_pushButton_clicked();

    void on_Form2_closed();

    void on_textEdit_selectionChanged();

public:
    Ui::Form2 *ui;
};

#endif // FORM2_H
