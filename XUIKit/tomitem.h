#ifndef TOMITEM_H
#define TOMITEM_H

#include <QQuickItem>

class TomItem : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(TomItem)

public:
    explicit TomItem(QQuickItem *parent = nullptr);
    ~TomItem() override;
};

#endif // TOMITEM_H
