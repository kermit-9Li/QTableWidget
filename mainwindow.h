#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVector>
#include <QString>
#include "MyTableWidgetItem.h"
#include "AddressTableWidgetItem.h"
#include "QNumberTableWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initTabHeader();

    void fillData();

    quint32 ipv4Toint(QString ipAddr);

private slots:
    void on_init_clicked();

    void sortByColumn(int n);

private:
    Ui::MainWindow *ui;
    bool sortUpDown = true;
};
#endif // MAINWINDOW_H
