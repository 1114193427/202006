#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtMath>
#include <QMessageBox>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText("要贷款买房，赶紧算算吧！\n");
    ui->radioButton->setChecked(true);
    QRegExp v2("[0-9]{0,8}[.][0-9]{1,2}");
    ui->lineEdit_5->setValidator(new QRegExpValidator(v2,ui->lineEdit_5));
    ui->lineEdit_10->setValidator(new QRegExpValidator(v2,ui->lineEdit_10));
    ui->lineEdit_13->setValidator(new QRegExpValidator(v2,ui->lineEdit_13));
    ui->lineEdit_15->setValidator(new QRegExpValidator(v2,ui->lineEdit_15));
     QRegExp v3("[0-9]{0,2}[.][0-9]{1,2}");
     ui->lineEdit_4->setValidator(new QRegExpValidator(v3,ui->lineEdit_4));
     ui->lineEdit_6->setValidator(new QRegExpValidator(v3,ui->lineEdit_6));
     ui->lineEdit_14->setValidator(new QRegExpValidator(v3,ui->lineEdit_14));
     ui->lineEdit_11->setValidator(new QRegExpValidator(v3,ui->lineEdit_11));
     ui->lineEdit_9->setValidator(new QRegExpValidator(v3,ui->lineEdit_9));
     ui->lineEdit_16->setValidator(new QRegExpValidator(v3,ui->lineEdit_16));
     QRegExp v4("[0-9]{0,5}");
     ui->lineEdit_2->setValidator(new QRegExpValidator(v4,ui->lineEdit_2));
     ui->lineEdit_7->setValidator(new QRegExpValidator(v4,ui->lineEdit_7));
     QRegExp v5("[0-9]{0,4}");
     ui->lineEdit_3->setValidator(new QRegExpValidator(v5,ui->lineEdit_3));
     ui->lineEdit_8->setValidator(new QRegExpValidator(v5,ui->lineEdit_8));


}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::fun(double a)
{
    if(a-int(a)>=0.5)a=(int)a+1;
    return a;
}


void MainWindow::on_pushButton_clicked()
{




    if(ui->comboBox->currentIndex()==0)
    {

    qDebug()<<ll;
    dk2=0;
    if(ui->comboBox_2->currentIndex()==0)
    {
        if(ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty())
        {QMessageBox::warning(this,"warning","请把信息补充完整");flag0=0;}
        else
        {flag0=1;
        fdj=ui->lineEdit_2->text().toDouble();
        mj=ui->lineEdit_3->text().toDouble();
        ll=ui->lineEdit_4->text().toDouble();ll=ll/1200;
        dk=fdj*mj*cs;
        ui->textEdit->append("计算结果");
    ui->textEdit->append("首付："+QString::number((qulonglong)fun(fdj*mj-dk))+"元");}
    }
    if(ui->comboBox_2->currentIndex()==1){
        if(ui->lineEdit_5->text().isEmpty()||ui->lineEdit_6->text().isEmpty())
        {
            QMessageBox::warning(this,"warning","请把信息补充完整");flag0=0;
        }
        else
        {flag0=1;ui->textEdit->append("计算结果");
        dk=ui->lineEdit_5->text().toDouble();dk=dk*10000;
    ll=ui->lineEdit_6->text().toDouble();ll=ll/1200;}
    }
    }
    if(ui->comboBox->currentIndex()==1)
    {
        dk2=0;
        if(ui->comboBox_9->currentIndex()==0)
        {
            if(ui->lineEdit_7->text().isEmpty()||ui->lineEdit_8->text().isEmpty()||ui->lineEdit_9->text().isEmpty())
            {
                QMessageBox::warning(this,"warning","请把信息补充完整");flag0=0;
            }
            else
            {flag0=1;ui->textEdit->append("计算结果");
            fdj=ui->lineEdit_7->text().toDouble();
                mj=ui->lineEdit_8->text().toDouble();
                ll=ui->lineEdit_9->text().toDouble();ll=ll/1200;

                dk=fdj*mj*cs;
            ui->textEdit->append("首付："+QString::number((qulonglong)fun(fdj*mj-dk))+"元");}
        }
            if(ui->comboBox_2->currentIndex()==1){
                if(ui->lineEdit_10->text().isEmpty()||ui->lineEdit_11->text().isEmpty())
                {
                    QMessageBox::warning(this,"warning","请把信息补充完整");flag0=0;
                }
                else
                {flag0=1;ui->textEdit->append("计算结果");
                dk=ui->lineEdit_10->text().toDouble();dk=dk*10000;
            ll=ui->lineEdit_11->text().toDouble();ll=ll/1200;}
            }
    }
    if(ui->comboBox->currentIndex()==2)
    {
        if(ui->lineEdit_16->text().isEmpty()||ui->lineEdit_13->text().isEmpty()||ui->lineEdit_15->text().isEmpty()||ui->lineEdit_14->text().isEmpty())
        {
            QMessageBox::warning(this,"warning","请把信息补充完整");flag0=0;
        }
        else
        {flag0=1;ui->textEdit->append("计算结果");
        dk=ui->lineEdit_13->text().toDouble();dk=dk*10000;
        dk2=ui->lineEdit_15->text().toDouble();dk2=dk2*10000;
        ll=ui->lineEdit_14->text().toDouble();ll=ll/1200;
        ll2=ui->lineEdit_16->text().toDouble();ll2=ll2/1200;
        }
    }
    if(flag0)
    {
    if(flag)
    {
    myhk=dk*ll*qPow(1+ll,qs)/(qPow(1+ll,qs)-1)+dk2*ll2*qPow(1+ll2,qs)/(qPow(1+ll2,qs)-1);
    ui->textEdit->append("每月月供："+QString::number((qulonglong) fun(myhk))+"元");
    ui->textEdit->append("贷款总额："+QString::number((qulonglong) fun(dk+dk2))+"元");
    ui->textEdit->append("支付利息："+QString::number((qulonglong) fun(myhk*qs-dk-dk2))+"元");
    ui->textEdit->append("还款总额："+QString::number((qulonglong) fun(myhk*qs))+"元");
    ui->textEdit->append("还款月数："+QString::number(qs)+"个月\n");}
    else
    {
        myhk=dk/qs+dk*ll+dk2/qs+dk2*ll2;
        dj=dk/qs*ll+dk2/qs*ll2;
        lx=((dk/qs+dk*ll)+dk/qs*(1+ll))/2*qs-dk+((dk2/qs+dk2*ll2)+dk2/qs*(1+ll2))/2*qs-dk2;
        ui->textEdit->append("首月月供："+QString::number((qulonglong) fun(myhk))+"元");
        ui->textEdit->append("每月递减："+QString::number((qulonglong) fun(dj))+"元");
        ui->textEdit->append("贷款总额："+QString::number((qulonglong) fun(dk+dk2))+"元");
        ui->textEdit->append("支付利息："+QString::number((qulonglong) fun(lx))+"元");
        ui->textEdit->append("还款总额："+QString::number((qulonglong) fun(lx+dk+dk2))+"元");
        ui->textEdit->append("还款月数："+QString::number(qs)+"个月\n");
    }
    }
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_9->setCurrentIndex(0);
    ui->comboBox_10->setCurrentIndex(3);
    ui->comboBox_6->setCurrentIndex(3);
    ui->comboBox_4->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_5->setCurrentIndex(0);
    ui->comboBox_12->setCurrentIndex(0);
    ui->comboBox_7->setCurrentIndex(0);
    ui->comboBox_13->setCurrentIndex(0);
    ui->comboBox_8->setCurrentIndex(0);
    ui->comboBox_14->setCurrentIndex(0);
    ui->comboBox_11->setCurrentIndex(0);
    ui->comboBox_15->setCurrentIndex(0);
    ui->comboBox_16->setCurrentIndex(0);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_15->clear();
    ui->lineEdit_4->setText(QString::number(4.65));
    ui->lineEdit_14->setText(QString::number(3.25));
    ui->lineEdit_6->setText(QString::number(4.65));
    ui->lineEdit_9->setText(QString::number(3.25));
    ui->lineEdit_11->setText(QString::number(3.25));
    ui->lineEdit_16->setText(QString::number(3.25));
    ui->radioButton->setChecked(true);
    cs=0.65;qs=300;flag=1;
    if(ui->comboBox->currentIndex()==0)
    {
        ll=4.65;
    }
    if(ui->comboBox->currentIndex()==1)
    {
        ll=3.25;
    }
    if(ui->comboBox->currentIndex()==2)
    {
        ll=ll2=3.25;
    }
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    ui->stackedWidget_2->setCurrentIndex(index);
}

void MainWindow::on_comboBox_9_currentIndexChanged(int index)
{
    ui->stackedWidget_3->setCurrentIndex(index);
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:ui->lineEdit_4->setText(QString::number(4.65));break;
    case 1:ui->lineEdit_4->setText(QString::number(4.9));break;
    case 2:ui->lineEdit_4->setText(QString::number(3.43));break;
    case 3:ui->lineEdit_4->setText(QString::number(5.59));break;
    case 4:ui->lineEdit_4->setText(QString::number(5.15));break;
    case 5:ui->lineEdit_4->setText(QString::number(4.17));break;
    }
}

void MainWindow::on_comboBox_12_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:ui->lineEdit_6->setText(QString::number(4.65));break;
    case 1:ui->lineEdit_6->setText(QString::number(4.9));break;
    case 2:ui->lineEdit_6->setText(QString::number(3.43));break;
    case 3:ui->lineEdit_6->setText(QString::number(5.59));break;
    case 4:ui->lineEdit_6->setText(QString::number(5.15));break;
    case 5:ui->lineEdit_6->setText(QString::number(4.17));break;
    }
}

void MainWindow::on_comboBox_10_currentIndexChanged(int index)
{
    cs=0.8-0.05*index;
}

void MainWindow::on_comboBox_4_currentIndexChanged(int index)
{
    qs=300-12*index;
}



void MainWindow::on_radioButton_clicked()
{
    flag=1;
}

void MainWindow::on_radioButton_2_clicked()
{
    flag=0;
}



void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    cs=0.8-0.05*index;
}

void MainWindow::on_comboBox_16_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:ui->lineEdit_14->setText(QString::number(3.25));break;
    case 1:ui->lineEdit_14->setText(QString::number(3.25));break;
    case 2:ui->lineEdit_14->setText(QString::number(2.28));break;
    case 3:ui->lineEdit_14->setText(QString::number(3.57));break;
    case 4:ui->lineEdit_14->setText(QString::number(3.41));break;
    case 5:ui->lineEdit_14->setText(QString::number(2.76));break;
    }
}

void MainWindow::on_comboBox_15_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:ui->lineEdit_16->setText(QString::number(3.25));break;
    case 1:ui->lineEdit_16->setText(QString::number(3.25));break;
    case 2:ui->lineEdit_16->setText(QString::number(2.28));break;
    case 3:ui->lineEdit_16->setText(QString::number(3.57));break;
    case 4:ui->lineEdit_16->setText(QString::number(3.41));break;
    case 5:ui->lineEdit_16->setText(QString::number(2.76));break;
    }
}

void MainWindow::on_comboBox_11_currentIndexChanged(int index)
{
    qs=300-12*index;
}

void MainWindow::on_pushButton_2_clicked()
{
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
    ui->textEdit->clear();
}

void MainWindow::on_comboBox_14_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:ui->lineEdit_11->setText(QString::number(3.25));break;
    case 1:ui->lineEdit_11->setText(QString::number(3.25));break;
    case 2:ui->lineEdit_11->setText(QString::number(2.28));break;
    case 3:ui->lineEdit_11->setText(QString::number(3.57));break;
    case 4:ui->lineEdit_11->setText(QString::number(3.41));break;
    case 5:ui->lineEdit_11->setText(QString::number(2.76));break;
    }
}

void MainWindow::on_comboBox_13_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:ui->lineEdit_9->setText(QString::number(3.25));break;
    case 1:ui->lineEdit_9->setText(QString::number(3.25));break;
    case 2:ui->lineEdit_9->setText(QString::number(2.28));break;
    case 3:ui->lineEdit_9->setText(QString::number(3.57));break;
    case 4:ui->lineEdit_9->setText(QString::number(3.41));break;
    case 5:ui->lineEdit_9->setText(QString::number(2.76));break;
    }
}
