#ifndef QNUMBERTABLEWIDGET_H
#define QNUMBERTABLEWIDGET_H

#include <QString>
#include <QTableWidgetItem>
#include <QObject>

class QNumberTableWidget : public QTableWidgetItem
{
public:

    QNumberTableWidget(QString const & text) : QTableWidgetItem(text) , f_val(numberToFloat(text)){}

    virtual float numberToFloat(QString text) {
        return text.toFloat();
    }

    bool operator < (QTableWidgetItem const & other) const {
        QNumberTableWidget const * r(dynamic_cast<QNumberTableWidget const *>(&other));
        if(r == nullptr)
        {
            throw std::runtime_error("mixed QTableWidgetItem types is not supported by QTableNumberItem.");
        }
        return f_val < r->f_val;
    }

private:
    float f_val = 0.00;
};

#endif // QNUMBERTABLEWIDGET_H
