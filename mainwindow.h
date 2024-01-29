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
    void PrintInfo(QString about);
private slots:
    void on_fillContainer1_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_calculateCoordinates_clicked();

    void on_calculateDerived_clicked();

    void on_fillContainer2_clicked();

    void on_selectContainer_clicked();

    void on_showContainer_clicked();

    void on_sort_clicked();

    void on_getRadiusesSum_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
