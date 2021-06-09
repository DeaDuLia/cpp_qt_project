#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include <form2.h>
#include <logic.h>
#include <QFileDialog>
#include <QCloseEvent>
#include <QEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menu_4->setEnabled(true);
    ui->action_4->setEnabled(false);
    ui->action_10->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

}


void MainWindow::loadSubWindow(QWidget *widget) {
    auto window = ui->mdiArea->addSubWindow(widget);
    window->setFixedSize(250, 350);
    window->show();
}


void MainWindow::on_pushButton_clicked()
{
    /*Logic logic;
    string fileName = "C:\\test\\dict.dict";
    string tmp = logic.readFile(fileName);
    //QString text = QString::fromStdString(tmp) ;
    Form2 *f2 = new Form2(fileName, this);
    this->loadSubWindow(f2);
    ui->menu->removeAction(ui->action_2);*/
}


void MainWindow::on_action_2_triggered()
{
    Logic logic;
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", "C:\\test\\");
    //string tmp = logic.readFile(fileName.toStdString());
    Form2 *f2;
    if (logic.endsWith(fileName.toStdString(), ".dict")) {
        QAction *act1;
        act1 = new QAction(fileName);
        ui->menu_4->addAction(act1);
        f2 = new Form2(this, "", act1, this);
    } else {
        f2 = new Form2(this, "");
    }
    logic.readFile2(f2->ui->textEdit, fileName.toStdString());
    f2->setWindowTitle(fileName);
    this->loadSubWindow(f2);

}


void MainWindow::on_action_3_triggered()
{

    /*

    Form2 *f2 = new Form2(this,  logic.getTextTranslate("sss sss sss", "C:\\test\\dict.dict"));
    this->loadSubWindow(f2);
    QAction *act1;
    act1 = new QAction("Text");
    ui->menu_3->addAction(act1);*/
    //act1->setParent(ui->action_3);
    //ui->toolBar->addAction(act1);
    //ui->menu_2->addAction(act1);
    //ui->action_3->setEnabled(false);


}

void MainWindow::on_action_9_triggered()
{
    Form2 *f2;
    f2 = new Form2(this, "");
    f2->setWindowTitle("Новый файл.txt");
    this->loadSubWindow(f2);
}


void MainWindow::on_action_10_triggered()
{
    Logic logic;
    Form2 *f3;
    string text = logic.readFile(this->fileName);
    string translate = logic.getTextTranslate(text, this->dictName);
    f3 = new Form2(this, translate);
    QString title = QString::fromStdString("Перевод слов => " + this->fileName);
    f3->setWindowTitle(title);
    this->loadSubWindow(f3);
}


void MainWindow::on_action_4_triggered()
{
    Logic logic;
    string filter;
    QString fileName;
    if (logic.endsWith(this->fileName, ".dict")) {
         fileName= QFileDialog::getSaveFileName( this, tr("Сохранить файл как"), "C:\\test\\", tr("TEXT(*.dict)"));
    } else if (logic.endsWith(this->fileName, ".txt")) {
         fileName = QFileDialog::getSaveFileName( this, tr("Сохранить файл как"), "C:\\test\\", tr("TEXT(*.txt)"));
    }

    logic.writeFile(fileName.toStdString(), this->file->toPlainText().toStdString());

}

