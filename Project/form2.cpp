#include "form2.h"
#include "ui_form2.h"
#include <string>
#include <ui_mainwindow.h>
#include <logic.h>
using namespace std;
Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
}

Form2::Form2(string text, QWidget *parent ) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    ui->textEdit->setText(QString::fromStdString(text));
}

Form2::Form2(string text, QAction *action, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    ui->textEdit->setText(QString::fromStdString(text));
    this->action = action;

}

Form2::Form2(MainWindow *mw, string text, QAction *action, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    ui->textEdit->setText(QString::fromStdString(text));
    this->action = action;
    this->mw = mw;
}

Form2::~Form2()
{
    Logic logic;
    string title = this->windowTitle().toStdString();
    if (this->mw->fileName == title) {
        this->mw->fileName = "";
        this->mw->ui->label->setText("Файл");
        this->mw->ui->action_4->setEnabled(false);
        this->mw->ui->action_10->setEnabled(false);
    }
    if (this->mw->dictName == title) {
        this->mw->dictName = "";
        this->mw->ui->label_2->setText("Словарь");
        this->mw->ui->action_10->setEnabled(false);
    }
    if (logic.endsWith(title, ".dict")) {
        this->mw->ui->menu_4->removeAction(action);
    }
    delete ui;
}
Logic logic;
void Form2::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        this->mw->ui->menu_4->setEnabled(true);
        this->mw->fileName = this->windowTitle().toStdString();
        string text = "Файл выбран: " + this->mw->fileName;
        this->mw->ui->label->setText(QString::fromStdString(text));
        this->mw->ui->action_4->setEnabled(true);
        if (!this->mw->dictName.empty()) {
            this->mw->ui->action_10->setEnabled(true);
        }
        this->mw->file = ui->textEdit;
    }
    else if (event->button() == Qt::RightButton && logic.endsWith(this->windowTitle().toStdString(), ".dict")) {
        this->mw->ui->menu_4->setEnabled(true);
        this->mw->dictName = this->windowTitle().toStdString();
        string text = "Словарь выбран: " + this->mw->dictName;
        this->mw->ui->label_2->setText(QString::fromStdString(text));
        if (!this->mw->fileName.empty() && !this->mw->dictName.empty()) {
            this->mw->ui->action_10->setEnabled(true);
            if (!this->mw->fileName.empty()) {
                this->mw->ui->action_4->setEnabled(true);
            }
        }
        this->mw->dict = ui->textEdit;
    }
}

void Form2::windowClosed(QCloseEvent *event)
{

}



void Form2::on_Form2_destroyed()
{

}


void Form2::on_pushButton_clicked()
{

}






void Form2::on_Form2_closed()
{
    mw->ui->menu_4->removeAction(action);
}



void Form2::on_textEdit_selectionChanged()
{

}

