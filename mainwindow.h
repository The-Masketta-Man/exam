#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>


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
    void on_add_clicked();
    void on_del_clicked();
    void on_update_clicked();
    void recieveData(QString str);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase database;
};
#endif // MAINWINDOW_H
