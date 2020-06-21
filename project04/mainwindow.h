#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int fun(double a);

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_9_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_12_currentIndexChanged(int index);

    void on_comboBox_10_currentIndexChanged(int index);

    void on_comboBox_4_currentIndexChanged(int index);

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_lineEdit_5_editingFinished();

    void on_comboBox_5_currentIndexChanged(int index);

    void on_comboBox_16_currentIndexChanged(int index);

    void on_comboBox_15_currentIndexChanged(int index);

    void on_comboBox_11_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_comboBox_14_currentIndexChanged(int index);

    void on_comboBox_13_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    double fdj,mj,dk,dk2,ll=4.65,ll2=3.25,dj,cs=0.65,lx,myhk;int qs=300,flag=1,flag0;
};
#endif // MAINWINDOW_H
