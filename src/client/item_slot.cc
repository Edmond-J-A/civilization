#include "item_slot.h"
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>

ItemSlot::ItemSlot(QWidget *parent)
    : QWidget(parent)
{
  setFixedSize(64, 74);
  setMouseTracking(true); // 启用鼠标跟踪功能
  button = new QPushButton(this);
  button->setStyleSheet("background-color: rgb(255, 255, 255,0);"
                        "border-radius: 32px;");
  button->setFixedSize(64, 64);
  button->setObjectName("button");
  connect(button, &QPushButton::clicked, this, &ItemSlot::on_button_clicked);
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
  title->move(0, 54);
  title->setAlignment(Qt::AlignCenter);

  setAcceptDrops(true);
}

void ItemSlot::enterEvent(QEvent *event)
{
  title->setText(QString::fromStdString(this->item.item.GetName()));
  QString style = button->styleSheet();
  QString background_image = "image: url(" + QString::fromStdString(item.item.GetPath()) + ");";
  QString style_sheet = "background-color: rgba(255, 255, 255, 0);" + background_image + "border-radius: 32px;" + "border: 3px solid gold;";
  button->setStyleSheet(style_sheet);
}

void ItemSlot::leaveEvent(QEvent *event)
{
  title->setText("");
  QString background_image = "image: url(" + QString::fromStdString(item.item.GetPath()) + ");";
  QString style_sheet = "background-color: rgba(255, 255, 255, 0);" + background_image + "border-radius: 32px;";
  button->setStyleSheet(style_sheet);
}

void ItemSlot::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    this->mousePressed = true;
    emit itemClicked(item); // 发送信号并传递item数据
  }
  event->accept();
}

void ItemSlot::SetItemPickup(Item_Pickup _item)
{
  this->mousePressed = false;
  if (_item.number > _item.item.GetMax())
  {
    return;
  }
  this->item = _item;
  if (_item.number <= 0)
  {
    QString style_sheet = "background-color: rgba(255, 255, 255, 0);border-radius: 32px;";
    button->setStyleSheet(style_sheet);
    label->setText("");
    Item_Pickup i;
    this->item = i;
    return;
  }

  QString background_image = "image: url(" + QString::fromStdString(_item.item.GetPath()) + ");";
  QString style_sheet = "background-color: rgba(255, 255, 255, 0);" + background_image + "border-radius: 32px;";
  button->setStyleSheet(style_sheet);
  label->setText(QString::number(_item.number));
}

Item_Pickup ItemSlot::GetItemPickup()
{
  return this->item;
}

void ItemSlot::on_button_clicked()
{
  QMouseEvent *event = new QMouseEvent(QEvent::MouseButtonPress, button->mapToGlobal(QPoint()), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
  QApplication::postEvent(this, event);
}