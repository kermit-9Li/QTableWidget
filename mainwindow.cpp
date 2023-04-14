#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTabHeader();
    fillData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTabHeader()
{
    QTableWidgetItem *headerItem;
    QStringList header;
    header << "整数" << "ip地址" << "算力";
    ui->tableWidget->setColumnCount(header.count());
    for (int i = 0; i < header.count(); ++i) {
        headerItem = new QTableWidgetItem(header.at(i));
        headerItem->setTextColor(Qt::red);
        ui->tableWidget->setHorizontalHeaderItem(i, headerItem);
    }
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->horizontalHeader()->setSortIndicatorShown(true);//
    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
}

void MainWindow::sortByColumn(int n)
{
    if (!ui->tableWidget->model())
        return;
    bool ascending;
    if (sortUpDown)
    {
        ascending = (ui->tableWidget->horizontalHeader()->sortIndicatorSection()==n && ui->tableWidget->horizontalHeader()->sortIndicatorOrder()==Qt::DescendingOrder); //降序设置
        sortUpDown = false;
    } else {
        ascending = (ui->tableWidget->horizontalHeader()->sortIndicatorSection()==n && ui->tableWidget->horizontalHeader()->sortIndicatorOrder()==Qt::AscendingOrder); //升序设置
        sortUpDown = true;
    }
    Qt::SortOrder order = ascending ? Qt::AscendingOrder : Qt::DescendingOrder; //升序 or 降序选择
    ui->tableWidget->horizontalHeader()->setSortIndicator(n, order);
    ui->tableWidget->model()->sort(n, order); //排序

}

void MainWindow::fillData()
{
    QVector<float> intval;
    intval.append(2.22);
    intval.append(52.3);
    intval.append(12.103);
    intval.append(143.54);

    QVector<QString> ipAddr;
    ipAddr.append("192.168.1.13");
    ipAddr.append("192.168.12.22");
    ipAddr.append("192.168.2.28");
    ipAddr.append("192.168.15.21");

     QVector<QString> avg;
     avg.append("32.2 MH/s");
     avg.append("1132.15 MH/s");
     avg.append("512.73 MH/s");
     avg.append("60.10 MH/s");

     for (int i = 0; i < ipAddr.count(); ++i) {
         int curRow = ui->tableWidget->rowCount();
         ui->tableWidget->insertRow(curRow);
//         AddressTableWidgetItem *item(new AddressTableWidgetItem(QString("%1").arg(ipAddr[i])));
//         ui->tableWidget->setItem(curRow, 1, item);

         ui->tableWidget->setItem(curRow, 0, new QNumberTableWidget(QString("%1").arg(intval[i])));

         //地址输入
         AddressTableWidgetItem *item1(new AddressTableWidgetItem(QString("%1").arg(ipAddr[i])));
         ui->tableWidget->setItem(curRow, 1, item1);

         //算力字符串
         MyTableWidgetItem *item2(new MyTableWidgetItem(QString("%1").arg(avg[i])));
         ui->tableWidget->setItem(curRow, 2, item2);
     }
}

quint32 MainWindow::ipv4Toint(QString ipAddr)
{
    QStringList ips = ipAddr.split(".");
    if(ips.size() == 4){
        quint32 ret = ips.at(3).toInt() | ips.at(2).toInt() << 8 | ips.at(1).toInt() << 16 | ips.at(0).toInt() << 24;
        qDebug() << "ret = " << ret;
        return ret;
    }
    return 0;
}

void MainWindow::on_init_clicked()
{
    QString ip1 = "192.168.1.2";
    ipv4Toint(ip1);

}

