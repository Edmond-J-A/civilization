#ifndef ITEM_SLOT_H
#define ITEM_SLOT_H

#include <QWidget>
#include <QMessageBox>
#include <QApplication>

#include "../core/player.h"

class QPushButton;
class QLabel;

class ItemSlot : public QWidget
{
  Q_OBJECT

private:
  QPushButton *button;
  QLabel *label, *title;
  Item_Pickup item;
  bool mousePressed = false, isSelected = false;

public:
  explicit ItemSlot(QWidget *parent = nullptr);
  void SetItemPickup(Item_Pickup _item);
  Item_Pickup GetItemPickup();
  bool GetPressed() { return mousePressed; }
  bool GetSelected() { return isSelected; }
  void SetSelected(bool state) { this->isSelected = state; }
  void SetPressed(bool state) { this->mousePressed = state; }

signals:
  void itemClicked(Item_Pickup item);

protected:
  void enterEvent(QEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void leaveEvent(QEvent *event) override;

public slots:
  void on_button_clicked();
};

#endif // ITEM_SLOT_H