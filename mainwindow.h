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

    void updateLocalLocalCount(int count);
    void updateLocalRemoteCount(int count);
    void updateRemoteLocalCount(int count);
    void updateRemoteRemoteCount(int count);

private slots:
    void on_btnConfigurarVariavel_clicked();
    void on_btnStart_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
