#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionWord_Wrap_triggered();

    void on_actionAbout_triggered();

    void on_actionNew_triggered();

    void on_action_Open_triggered();

    void on_actionSave_triggered();

    void on_horizontalSlider_sliderMoved(int position);

    void on_actionStatus_Bar_triggered();

    void on_plainTextEdit_textChanged();

    void on_actionE_xit_triggered();

    void on_horizontalSlider_valueChanged(int value);

    void on_actionTime_Date_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
