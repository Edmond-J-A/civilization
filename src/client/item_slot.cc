#include "item_slot.h"
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>

ItemSlot::ItemSlot(QWidget *parent)
    : QWidget(parent)
{
  setFixedSize(64, 74);

  button = new QPushButton(this);
  button->setStyleSheet("background-color: rgb(255, 255, 255,0);");
  button->setFixedSize(64, 64);

  label = new QLabel(this);
  label->setFixedSize(20, 20);
  label->setStyleSheet("background-color: rgb(255, 255, 255,0);"
                       "font: 500 18pt m5x7");
  label->move(37, 37);
  label->setAlignment(Qt::AlignCenter);
  title = new QLabel(this);
  title->setFixedSize(64, 20);
  title->setStyleSheet("background-color: rgb(255, 255, 255,0);"
                       "font: 500 18pt m5x7");
  title->setText(QString::fromStdString(this->item.item.GetName()));
  title->move(0,54 );
  title->setAlignment(Qt::AlignCenter);

  setAcceptDrops(true);
}

void ItemSlot::enterEvent(QEvent *event)
{
  title->setText(QString::fromStdString(this->item.item.GetName()));
}

void ItemSlot::leaveEvent(QEvent *event)
{
  title->setText("");
}

void ItemSlot::mousePressEvent(QMouseEvent *event)
{
  /*if (event->button() == Qt::LeftButton)
    label->setText(QString::number(label->text().toInt() + 2));
  event->accept();*/
}

void ItemSlot::SetItemPickup(Item_Pickup _item)
{
  if (_item.number <= 0 || _item.number > _item.item.GetMax())
  {
    return;
  }
  QString background_image = "image: url(" + QString::fromStdString(_item.item.GetPath()) + ");";
  QString style_sheet = "background-color: rgba(255, 255, 255, 0);" + background_image;
  button->setStyleSheet(style_sheet);
  label->setText(QString::number(_item.number));
  this->item = _item;
}

Item_Pickup ItemSlot::GetItemPickup()
{
  return this->item;
}