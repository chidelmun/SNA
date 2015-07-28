#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
     ui->progressBar->setStyleSheet(safe);
    ui->progressBar->reset();
    this->setFixedSize(590,110);
    ui->pushButton->setStyleSheet("background-color:rgb(166,120,222)");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Starting.....");
    for(int i=0;i<101;++i){
        ui->progressBar->setValue(i);
        system("sleep 0.05");
        if(i==10){
            ui->label->setText("Loading plugins.....");
        }
        else if(i==20){
             ui->label->setText("Loading Databases.....");
        }

        else if(i==50){
             ui->label->setText("Loading Users.....");
        }
        else if(i==90){
             ui->label->setText("Starting modules.....");
        }
    }
    ui->label->setText("Complete");

   // QMessageBox::information(this,"Complete", "Done");
}
