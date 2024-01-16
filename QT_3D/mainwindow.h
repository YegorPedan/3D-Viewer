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

private slots:
    void on_Button_left_clicked();

    void on_Button_right_clicked();

    void on_Button_up_clicked();

    void on_Button_down_clicked();

    void on_Button_turnOZ_clicked();

    void on_Button_turnOX_clicked();

    void on_Button_turnOY_clicked();

    void on_Button_zoomIn_clicked();

    void on_Button_zoomOut_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
