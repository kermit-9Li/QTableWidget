#ifndef MYTABLEWIDGETITEM_H
#define MYTABLEWIDGETITEM_H

#include <QObject>
#include <QTableWidgetItem>
#include <QDebug>
#include <QString>

class MyTableWidgetItem : public QTableWidgetItem
{
public:

    MyTableWidgetItem(QString text) : QTableWidgetItem(text) {

    }

    bool operator< (const QTableWidgetItem &other) const
    {
        quint64 ulnCurrent=0;
        QString strCurrent=this->text(); //获取当前行数据

        if(strCurrent.contains("MH/s"))//
        {
            strCurrent.remove((strCurrent.length()-5),5);
            strCurrent.replace(" ","");
            ulnCurrent=strCurrent.toFloat();

        }

        quint64 ulnOther=0;
        QString strOther=other.text(); //获取下一行内容
        if(strOther.contains("MH/s"))
        {
            strOther.remove((strOther.length()-5), 5);
            strOther.replace(" ","");
            ulnOther=strOther.toFloat();;
        }
        qDebug() << ulnOther << strOther << "  " << ulnCurrent << strCurrent;

        return (ulnCurrent < ulnOther);/*11<10*/
    }
};

#endif // MYTABLEWIDGETITEM_H
