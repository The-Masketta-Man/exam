#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectdialog.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    database = QSqlDatabase::addDatabase("QMYSQL");
    model = new QSqlTableModel(this);
    model->setTable("t1");
    model->select();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recieveData(QString str)
{
    database.setHostName(ui->hostname->text());
    database.setDatabaseName(ui->db_name->text());
    database.setPort(QString::number(ui->port->value()));
    database.setUserName(ui->username->text());
    database.setPassword(ui->password->value());
    if (!database.open())
    {
        QMessageBox::critical(this, "Error", database.lastError().text());
        return;
    }
}
void MainWindow::on_add_clicked()
{
    model->insertRow(model->rowCount());
}

void MainWindow::on_del_clicked()
{
    model->removeRow(ui->tableView->currentIndex().row());

}

void MainWindow::on_update_clicked()
{
 model->select();
}
