#ifndef ITEM_SLOT_H
#define ITEM_SLOT_H

#include <QWidget>

#include "../core/player.h"

class QPushButton;
class QLabel;

class ItemSlot : public QWidget
{
  Q_OBJECT
public:
  explicit ItemSlot(QWidget *parent = nullptr);
  void SetItemPickup(Item_Pickup _item);
  Item_Pickup GetItemPickup();

private:
  QPushButton *button;
  QLabel *label;
  Item_Pickup item;

signals:

protected:
  void enterEvent(QEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
};

#endif // ITEM_SLOT_H