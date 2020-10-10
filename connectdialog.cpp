#include "connectdialog.h"
#include "ui_connectdialog.h"
#include <QDialog>
#include <QSqlError>
#include <QMessageBox>

ConnectDialog::ConnectDialog(QWidget *parent):QDialog(parent), ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    MainWindow w;
    connect(this, SIGNAL(sendData(QString)), &w, SLOT(recieveData(QString)));
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::on_open_clicked()
{
    emit sendData(ui->hostname->text());
    emit sendData(ui->db_name->text());
    emit sendData(QString::number(ui->port->value()));
    emit sendData(ui->username->text());
    emit sendData(ui->password->text());
    accept();

}

void ConnectDialog::on_cancel_clicked()
{
    reject();
}
