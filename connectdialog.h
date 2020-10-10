#include "mainwindow.h"
//#include "ui_connectdialog.h"
#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ConnectDialog; }
QT_END_NAMESPACE

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    ConnectDialog(QWidget *parent = nullptr);
    ~ConnectDialog();
    QString hostname() const;

    QString db_name() const;
    int port() const;
    QString username() const;
    QString password() const;

signals:
    void sendData(QString str);
private slots:
    void on_open_clicked();
    void on_cancel_clicked();

private:
    MainWindow (*mainwin);
    Ui::ConnectDialog *ui;
    QString mHostname;
    QString mDatabase;
    int mPort;
    QString mUsername;
    QString mPassword;


};
QString ConnectDialog::hostname() const
{
    return mHostname;
}
QString ConnectDialog::db_name() const
{
    return mDatabase;
}
int ConnectDialog::port() const
{
    return mPort;
}
QString ConnectDialog::username() const
{
    return mUsername;
}
QString ConnectDialog::password() const
{
    return mPassword;
}


#endif // CONNECTDIALOG_H

