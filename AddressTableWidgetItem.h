#ifndef ADDRESSTABLEWIDGETITEM_H
#define ADDRESSTABLEWIDGETITEM_H

#include <QObject>
#include <QTableWidgetItem>
#include <QString>

class AddressTableWidgetItem : public QTableWidgetItem
{
public:
    AddressTableWidgetItem(QString const & text) : QTableWidgetItem(text), f_value(ipv4Toint(text)) {}


    virtual quint32 ipv4Toint(QString ipAddr)
    {
        QStringList ips = ipAddr.split(".");
        if(ips.size() == 4){
            return ips.at(3).toInt() | ips.at(2).toInt() << 8 | ips.at(1).toInt() << 16 | ips.at(0).toInt() << 24;
        }
        return 0;
    }

    bool operator < (QTableWidgetItem const & rhs) const
    {
        AddressTableWidgetItem const * r(dynamic_cast<AddressTableWidgetItem const *>(&rhs));
        if(r == nullptr)
        {
            throw std::runtime_error("mixed QTableWidgetItem types is not supported by QTableNumberItem.");
        }
        return f_value < r->f_value;
    }

private:
    quint32 f_value = 0; //无符号整型

};

#endif // ADDRESSTABLEWIDGETITEM_H
