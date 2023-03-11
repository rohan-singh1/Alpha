#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->addPermanentWidget(this->ui->label);
    QString cont = this->ui->plainTextEdit->toPlainText();
    int nochar = cont.count();

    QString numchar = QString::number(nochar);
    numchar = numchar + " characters";
    this->ui->label->setText(numchar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionWord_Wrap_triggered()
{
    if(this->ui->actionWord_Wrap->isChecked())
    {
        this->ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    }
    else
    {
        this->ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
    }
}

void MainWindow::on_actionAbout_triggered()
{
    this->ui->plainTextEdit->setPlainText("This is a clone of Notepad created by Rohan Singh. It uses Qt 5.2.1 toolkit and GCC 4.8.2 64-bit compiler.\nThis program was created in Linux.");

}

void MainWindow::on_actionNew_triggered()
{
    this->ui->plainTextEdit->setPlainText("");
}

void MainWindow::on_action_Open_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,tr("Open File"), "", tr("Text or Source Files (*.txt *.cpp)"));
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString content;
    while (!file.atEnd())
    {
        content = file.readAll();
        this->ui->plainTextEdit->setPlainText(content);
    }
}


void MainWindow::on_actionSave_triggered()
{

    QString file_name = QFileDialog::getSaveFileName(this,tr("Save file"),"",tr("Text Files (*.txt)"));
    QFile file(file_name);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString content = this->ui->plainTextEdit->toPlainText();
        QTextStream out(&file);
        out << content;
    }

    file.close();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    float value=float(position)/100;
    this->setWindowOpacity(value);
}

void MainWindow::on_actionStatus_Bar_triggered()
{
    if (!(this->ui->statusBar->isHidden()))
        this->ui->statusBar->hide();
    else
        this->ui->statusBar->show();
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QString content = this->ui->plainTextEdit->toPlainText();
    int nochar = content.count();

    QString numchar = QString::number(nochar);
    numchar = numchar + " characters";
    this->ui->label->setText(numchar);
}

void MainWindow::on_actionE_xit_triggered()
{
    exit(0);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    float val=float(value)/100;
    this->setWindowOpacity(val);
}

void MainWindow::on_actionTime_Date_triggered()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current = current_date_time.toString("dd/MM/yyyy h:m:s AP");
    this->ui->plainTextEdit->insertPlainText(current);
}
