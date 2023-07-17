#ifndef ITEM_SLOT_H
#define ITEM_SLOT_H

#include <QWidget>
#include <QDrag>
#include <QMimeData>

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
  QLabel *label, *title;
  Item_Pickup item;
  bool mousePressed = false;
signals:

protected:
  void enterEvent(QEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void leaveEvent(QEvent *event) override;

};

#endif // ITEM_SLOT_H