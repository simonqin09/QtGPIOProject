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
    void on_Button1_clicked();

private:
    Ui::MainWindow *ui;

    int count;
    int gpio_out;
    int gpio_in;

};

#endif // MAINWINDOW_H
