#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->stackedWidget->setStyleSheet("background-color: transparent;");
  Init();

  // 太丑了 要优化
  for (int i = 0; i < 10; i++)
  {
    ItemSlot *is = new ItemSlot(64, this);
    is->setBaseSize(64, 64);
    is->setObjectName(QString("bag_col0_%1").arg(i));
    ui->bag_toolbar->addWidget(is);
    bag_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 10; i++)
  {
    ItemSlot *is = new ItemSlot(64, this);
    is->setBaseSize(64, 64);
    is->setObjectName(QString("bag_col1_%1").arg(i));
    ui->bag_col1->addWidget(is);
    bag_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 10; i++)
  {
    ItemSlot *is = new ItemSlot(64, this);
    is->setBaseSize(64, 64);
    is->setObjectName(QString("bag_col2_%1").arg(i));
    ui->bag_col2->addWidget(is);
    bag_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 10; i++)
  {
    ItemSlot *is = new ItemSlot(64, this);
    is->setBaseSize(64, 64);
    is->setObjectName(QString("bag_col3_%1").arg(i));
    ui->bag_col3->addWidget(is);
    bag_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 10; i++)
  {
    ItemSlot *is = new ItemSlot(64, this);
    is->setBaseSize(64, 64);
    is->setObjectName(QString("bag_col4_%1").arg(i));
    ui->bag_col4->addWidget(is);
    bag_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 10; i++)
  {
    ItemSlot *is = new ItemSlot(64, this);
    is->setBaseSize(64, 64);
    is->setObjectName(QString("bag_col5_%1").arg(i));
    ui->bag_col5->addWidget(is);
    bag_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 10; i++)
  {
    ItemSlot *is = new ItemSlot(64, this);
    is->setBaseSize(64, 64);
    is->setObjectName(QString("toolbar_%1").arg(i));
    ui->toolbar->addWidget(is);
    toolbar_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_%1").arg(i));
    ui->chest->addWidget(is);
    chest_bag_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_2_%1").arg(i));
    ui->chest_2->addWidget(is);
    chest_bag_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_3_%1").arg(i));
    ui->chest_3->addWidget(is);
    chest_bag_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_4_%1").arg(i));
    ui->chest_4->addWidget(is);
    chest_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_5_%1").arg(i));
    ui->chest_5->addWidget(is);
    chest_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_6_%1").arg(i));
    ui->chest_6->addWidget(is);
    chest_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_8_%1").arg(i));
    ui->chest_8->addWidget(is);
    chest_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_9_%1").arg(i));
    ui->chest_9->addWidget(is);
    chest_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_10_%1").arg(i));
    ui->chest_10->addWidget(is);
    chest_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_11_%1").arg(i));
    ui->chest_11->addWidget(is);
    chest_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }
  for (int i = 0; i < 20; i++)
  {
    ItemSlot *is = new ItemSlot(32, this);
    is->setBaseSize(33, 35);
    is->setObjectName(QString("chest_12_%1").arg(i));
    ui->chest_12->addWidget(is);
    chest_button.push_back(is);
    connect(is, &ItemSlot::itemClicked, this, &MainWindow::onItemClicked);
  }

  ui->bag_ui->setVisible(false);
  pressTimer = new QTimer(this);
  pressTimer->setSingleShot(true);
  connect(pressTimer, &QTimer::timeout, this, &handleDelayedKeyRelease);

  REFRESH = startTimer(16);
  building_cursor.SetTimerID(startTimer(200));
  building_cursor.AddState("show", "./res/game/build_cursor/build_cursor_%%.png", 0, 3);

  QPixmap cursorPixmap("./res/cursor.png");
  QCursor customCursor(cursorPixmap);
  setCursor(customCursor);

  mediaPlayer = new QMediaPlayer(this);
  playlist = new QMediaPlaylist(this);
  playlist->addMedia(QUrl::fromLocalFile("./res/music/bgm.mp3"));
  playlist->setPlaybackMode(QMediaPlaylist::Loop); // 设置循环播放模式
  mediaPlayer->setPlaylist(playlist);
  mediaPlayer->setVolume(50);
  mediaPlayer->play();

  // 封面动画载入
  QMovie *movie = new QMovie("./res/start/start.gif");
  ui->start_movie->setMovie(movie);
  ui->setting_movie->setMovie(movie);
  movie->start();

  // 玩家初始化（目前不正规）
  Player *p = new Player(1, Point(MAP_WIDTH * BLOCK_SIZE / 2 - 32, MAP_HEIGHT * BLOCK_SIZE / 2 - 32));
  this->SetPlayer(p);
  p->SetTimerID(startTimer(150));
  p->AddState("idle", "./res/game/c1/c1_idel/c1_idel (%%).png", 1, 8);
  p->AddState("walk", "./res/game/c1/c1_walk/c1_walk (%%).png", 1, 8);

  p->PickUp(Item_Pickup(itemsList["wood"], 10));
  p->PickUp(Item_Pickup(itemsList["wood"], 10));
  p->PickUp(Item_Pickup(itemsList["wood"], 10));
  p->PickUp(Item_Pickup(itemsList["wood"], 10));
  p->PickUp(Item_Pickup(itemsList["wood"], 10));
  p->PickUp(Item_Pickup(itemsList["wood"], 10));
  p->PickUp(Item_Pickup(itemsList["wood"], 10));
  p->PickUp(Item_Pickup(itemsList["castle"], 1));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
  if (isplaying)
  {
    if (event->timerId() == REFRESH)
    {
      QPoint globalPos = QCursor::pos();
      mousePosition = mapFromGlobal(globalPos);
      repaint();
    }
    else if (event->timerId() == building_cursor.GetTimerID())
    {
      building_cursor.NextFrame();
    }
    for (auto it = playerList.begin(); it != playerList.end(); it++)
    {
      if (event->timerId() == (*it)->GetTimerID())
      {
        (*it)->NextFrame();
      }
    }
  }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
  Player player = *(this->me);
  Point player_location = player.GetLocation();
  int left_top_x = player_location.GetX() - DEFUALT_WIDTH / 2;
  int left_top_y = player_location.GetY() - DEFUALT_HEIGHT / 2;
  int block_x = left_top_x / BLOCK_SIZE; // 左上第一个格子横坐标序号
  int block_y = left_top_y / BLOCK_SIZE; // 左上第一个格子纵坐标序号
  int start_x = -(left_top_x % BLOCK_SIZE);
  int start_y = -(left_top_y % BLOCK_SIZE);
  int player_block_location_x = player_location.GetX() / BLOCK_SIZE;
  int player_block_location_y = player_location.GetY() / BLOCK_SIZE;
  QPainter painter(this);
  // 画地板
  for (int i = 0; i <= DEFUALT_WIDTH / BLOCK_SIZE; i++)
  {
    for (int j = 0; j <= DEFUALT_HEIGHT / BLOCK_SIZE; j++)
    {
      QPixmap p_ground("./res/game/ground.png");
      painter.drawPixmap(start_x + i * BLOCK_SIZE, start_y + j * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, p_ground);
    }
  }

  // 画装饰
  QPixmap *pix_decorate[7];
  for (int i = 0; i < 7; ++i)
  {
    QString fileName = QString("./res/game/decorate%1.png").arg(i);
    pix_decorate[i] = new QPixmap(fileName); // 从文件中加载图像
  }
  std::map<Point, int> decorates = this->GetDecorate(Point(left_top_x, left_top_y), Point(left_top_x + DEFUALT_WIDTH, left_top_y + DEFUALT_HEIGHT));
  for (auto i = decorates.begin(); i != decorates.end(); i++)
  {
    painter.drawPixmap((*i).first.GetX() - left_top_x, (*i).first.GetY() - left_top_y, DECORATE_SIZE * 2, DECORATE_SIZE * 2, *pix_decorate[(*i).second]);
  }

  // 画建筑
  QImage *image_this_player = new QImage(QString::fromStdString(player.GetNowFrame()));
  for (int i = 0; i <= DEFUALT_WIDTH / BLOCK_SIZE; i++)
  {
    for (int j = 0; j <= DEFUALT_HEIGHT / BLOCK_SIZE; j++)
    {
      if (gameMap[i + block_x][j + block_y] != NULL)
      {
        QPixmap tmp(QString::fromStdString(gameMap[i + block_x][j + block_y]->GetPath()));
        painter.drawPixmap(start_x + i * BLOCK_SIZE, start_y + j * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, tmp);
      }
      if (i == DEFUALT_WIDTH / BLOCK_SIZE / 2 + 2 && j == DEFUALT_HEIGHT / BLOCK_SIZE / 2 + 2)
      {
        // 画玩家(本机)

        painter.drawPixmap(player.GetLocation().GetX() - left_top_x - BLOCK_SIZE / 2, player.GetLocation().GetY() - left_top_y - BLOCK_SIZE / 2, BLOCK_SIZE, BLOCK_SIZE, QPixmap::fromImage(image_this_player->mirrored(player.GetTowardsHorizontal(), false)));
      }
    }
  }

  // 画建筑选框
  int cursor_block_location_x = (mousePosition.rx() + left_top_x) / BLOCK_SIZE;
  int cursor_block_location_y = (mousePosition.ry() + left_top_y) / BLOCK_SIZE;
  if (isbuilding && abs(player_block_location_x - cursor_block_location_x) < 5 && abs(player_block_location_y - cursor_block_location_y) < 5)
  {
    int b_x = cursor_block_location_x - block_x;
    int b_y = cursor_block_location_y - block_y;

    QPixmap *pix_building_cursor = new QPixmap(QString::fromStdString(building_cursor.GetNowFrame()));
    painter.drawPixmap(b_x * BLOCK_SIZE + start_x, b_y * BLOCK_SIZE + start_y, BLOCK_SIZE, BLOCK_SIZE, *pix_building_cursor);
    delete pix_building_cursor;
  }

  // 画工具栏选框
  for (int i = 0; i < toolbar_button.size(); i++)
  {
    if (toolbar_button[i]->GetSelected())
    {
      QPixmap *pix_building_cursor = new QPixmap(QString::fromStdString(building_cursor.GetNowFrame()));
      painter.drawPixmap(80 + i * 80, 560, 80, 80, *pix_building_cursor);
      break;
    }
  }

  // 画背包面板

  if (ui->bag_ui->isVisible())
  {
    if (ui->bag_ui->currentIndex() == 0)
    {
      QPixmap *pix_bag_background = new QPixmap("./res/game/bag.png");
      painter.drawPixmap(20, 20, 920, 600, *pix_bag_background);
      delete pix_bag_background;
    }
    else if (ui->bag_ui->currentIndex() == 1)
    {
      QPixmap *pix_bag_background = new QPixmap("./res/game/chest.png");
      painter.drawPixmap(20, 20, 920, 600, *pix_bag_background);
      delete pix_bag_background;
    }
  }

  // 画鼠标选中item
  QPixmap *pix_item_cursor = new QPixmap(QString::fromStdString(this->Cursor_item.item.GetPath()));
  if (this->Cursor_item.item.IsValid())
  {
    painter.drawPixmap(mousePosition.rx(), mousePosition.ry(), *pix_item_cursor);
  }

  for (int i = 0; i < 7; ++i)
  {
    delete pix_decorate[i];
  }
  delete image_this_player;
  delete pix_item_cursor;
}

void MainWindow::on_B_set_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_B_start_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
  // ui->stackedWidget->setVisible(0);
  this->isplaying = true;
}

void MainWindow::on_B_setreturn_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_B_quit_clicked()
{
  this->close();
}

void MainWindow::on_voiceSlider_valueChanged(int value)
{
  mediaPlayer->setVolume(value);
}

void MainWindow::on_B_pause_clicked()
{
  // 后期可制作游戏内设置界面
  isplaying = false;
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_voice_check_stateChanged(int state)
{
  if (state == Qt::Checked)
  {
    mediaPlayer->stop();
  }
  else if (state == Qt::Unchecked)
  {
    mediaPlayer->play();
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
  if (isplaying)
  {
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_A || event->key() == Qt::Key_D || event->key() == Qt::Key_S)
    {
      if (!pressTimer->isActive())
      {
        pressTimer->start(100);
      }
    }
    else
    {
    }
  }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
  if (isplaying)
  {
    if (event->key() == Qt::Key_W)
    {
      if (pressTimer->isActive())
      {
        pressTimer->stop();
      }
      this->me->SetState("walk");
      PlayerMove(this->me->GetID(), UP);
    }
    else if (event->key() == Qt::Key_S)
    {
      if (pressTimer->isActive())
      {
        pressTimer->stop();
      }
      this->me->SetState("walk");
      PlayerMove(this->me->GetID(), DOWN);
    }
    else if (event->key() == Qt::Key_A)
    {
      if (pressTimer->isActive())
      {
        pressTimer->stop();
      }
      this->me->SetState("walk");
      PlayerMove(this->me->GetID(), LEFT);
    }
    else if (event->key() == Qt::Key_D)
    {
      if (pressTimer->isActive())
      {
        pressTimer->stop();
      }
      this->me->SetState("walk");
      PlayerMove(this->me->GetID(), RIGHT);
    }
    else if (event->key() == Qt::Key_B)
    {
      this->isbuilding = !this->isbuilding;
    }
    else if (event->key() == Qt::Key_E)
    {
      ui->bag_ui->setCurrentIndex(0);
      ui->bag_ui->setVisible(!ui->bag_ui->isVisible());
      if (!ui->bag_ui->isVisible())
      {
        this->me->PickUp(Cursor_item);
        Item_Pickup empty;
        Cursor_item = empty;
      }
      ui->toolbar_background->setVisible(!ui->toolbar_background->isVisible());

      if (toolbar_button[0]->isVisible())
      {
        for (int i = 0; i < bag_button.size(); i++)
        {
          bag_button[i]->SetItemPickup(this->me->GetPickup(i));
        }
      }
      else
      {
        for (int i = 0; i < toolbar_button.size(); i++)
        {
          toolbar_button[i]->SetItemPickup(this->me->GetPickup(i));
        }
      }
      for (int i = 0; i < toolbar_button.size(); i++)
      {
        toolbar_button[i]->setVisible(!toolbar_button[i]->isVisible());
      }
    }
    else if (event->key() >= Qt::Key_0 && event->key() <= Qt::Key_9)
    {
      for (int i = 0; i < toolbar_button.size(); i++)
      {
        int keyIndex = event->key() - Qt::Key_0 - 1 >= 0 ? event->key() - Qt::Key_0 - 1 : 9;
        if (i == keyIndex)
        {
          toolbar_button[i]->SetSelected(!toolbar_button[i]->GetSelected());
          continue;
        }
        toolbar_button[i]->SetSelected(false);
      }
    }
    else if (event->key() >= Qt::Key_C)
    {
      ui->bag_ui->setCurrentIndex(1);
      ui->bag_ui->setVisible(!ui->bag_ui->isVisible());
      if (!ui->bag_ui->isVisible())
      {
        this->me->PickUp(Cursor_item);
        Item_Pickup empty;
        Cursor_item = empty;
      }
      ui->toolbar_background->setVisible(!ui->toolbar_background->isVisible());

      if (toolbar_button[0]->isVisible())
      {
        for (int i = 0; i < chest_bag_button.size(); i++)
        {
          chest_bag_button[i]->SetItemPickup(this->me->GetPickup(i));
        }
      }
      else
      {
        for (int i = 0; i < toolbar_button.size(); i++)
        {
          toolbar_button[i]->SetItemPickup(this->me->GetPickup(i));
        }
      }
      for (int i = 0; i < toolbar_button.size(); i++)
      {
        toolbar_button[i]->setVisible(!toolbar_button[i]->isVisible());
      }
    }
    else
    {
      // 处理其他按键事件
    }
  }
}

void MainWindow::handleDelayedKeyRelease()
{
  this->me->SetState("idle");
}

void MainWindow::Init()
{
  // 地图初始化
  gameMap.resize(MAP_WIDTH);
  for (int i = 0; i < MAP_WIDTH; i++)
  {
    gameMap[i].resize(MAP_HEIGHT);
  }

  // 坐标范围初始化
  map_x_max = MAP_WIDTH * BLOCK_SIZE;
  map_y_max = MAP_HEIGHT * BLOCK_SIZE;

  // 装饰品初始化
  srand(time(0));
  this->decorates.insert(std::pair<Point, int>(Point(MAP_WIDTH * BLOCK_SIZE / 2, MAP_HEIGHT * BLOCK_SIZE / 2), rand() % 7));
  int size = rand() % (MAP_WIDTH * MAP_HEIGHT / 4) + MAP_WIDTH;
  for (int i = 0; i < size; i++)
  {
    int x = BLOCK_SIZE + rand() % (BLOCK_SIZE * MAP_WIDTH - 2 * BLOCK_SIZE);
    int y = BLOCK_SIZE + rand() % (BLOCK_SIZE * MAP_HEIGHT - 2 * BLOCK_SIZE);
    this->decorates.insert(std::pair<Point, int>(Point(x, y), rand() % 7));
  }

  // item初始化
  this->itemsList = createItemMapFromFile();
}

void MainWindow::SetPlayer(Player *p)
{
  if (this->myID == NO_PLAYER)
  {
    this->me = p;
    this->myID = p->GetID();
    playerList.push_back(p);
  }
}

Construct *MainWindow::GetConstruct(int x, int y)
{
  if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
  {
    return this->gameMap[x][y];
  }
  else
  {
    return NULL;
  }
}

bool MainWindow::AddPlayer(Player *p)
{
  // TODO:判断重复
  this->playerList.push_back(p);
  return true;
}

void MainWindow::PlayerMove(int playerID, int direction)
{
  for (auto it = playerList.begin(); it != playerList.end(); it++)
  {
    if ((*it)->GetID() == playerID)
    {
      double speed = (*it)->GetSpeed();
      if (direction == UP)
      {
        Point new_p((*it)->GetLocation().GetX(), (*it)->GetLocation().GetY() - speed);
        if (new_p.GetY() >= map_y_min && !Block((*it)->GetLocation(), new_p))
        {
          (*it)->Move(new_p);
        }
      }
      else if (direction == DOWN)
      {
        Point new_p((*it)->GetLocation().GetX(), (*it)->GetLocation().GetY() + speed);
        if (new_p.GetY() < map_y_max && !Block((*it)->GetLocation(), new_p))
        {
          (*it)->Move(new_p);
        }
      }
      else if (direction == LEFT)
      {
        Point new_p((*it)->GetLocation().GetX() - speed, (*it)->GetLocation().GetY());
        if (new_p.GetX() >= map_x_min && !Block((*it)->GetLocation(), new_p))
        {
          (*it)->Move(new_p);
          (*it)->SetTowardsHorizontal(true);
        }
      }
      else if (direction == RIGHT)
      {
        Point new_p((*it)->GetLocation().GetX() + speed, (*it)->GetLocation().GetY());
        if (new_p.GetX() < map_x_max && !Block((*it)->GetLocation(), new_p))
        {
          (*it)->Move(new_p);
          (*it)->SetTowardsHorizontal(false);
        }
      }
      else
      {
      }
    }
  }
}

bool MainWindow::Block(Point p1, Point p2)
{
  // 目前不能斜向移动 可以先不判定 后续有需求改这
  if (p1.GetX() != p2.GetX() && p1.GetY() != p2.GetY())
  {
    return false;
  }
  else if (p1.GetX() != p2.GetX())
  {
    int min_b = std::min(p1.GetX(), p2.GetX()) / BLOCK_SIZE;
    int max_b = std::max(p1.GetX(), p2.GetX()) / BLOCK_SIZE;
    int y = p1.GetY() / BLOCK_SIZE;
    for (int i = min_b; i <= max_b; i++)
    {
      if (gameMap[i][y] != NULL && gameMap[i][y]->IsBlock())
      {
        return true;
      }
    }
    return false;
  }
  else if (p1.GetY() != p2.GetY())
  {
    int min_b = std::min(p1.GetY(), p2.GetY()) / BLOCK_SIZE;
    int max_b = std::max(p1.GetY(), p2.GetY()) / BLOCK_SIZE;
    int x = p1.GetX() / BLOCK_SIZE;
    for (int i = min_b; i <= max_b; i++)
    {
      if (gameMap[x][i] != NULL && gameMap[x][i]->IsBlock())
      {
        return true;
      }
    }
    return false;
  }
  return true;
}

std::map<Point, int> MainWindow::GetDecorate(Point left_top, Point right_down)
{
  std::map<Point, int> res;
  for (auto i = this->decorates.begin(); i != this->decorates.end(); i++)
  {
    if ((*i).first > left_top && (*i).first < right_down)
    {
      res.insert(*i);
    }
  }
  return res;
}

std::map<std::string, Item> MainWindow::createItemMapFromFile()
{
  std::map<std::string, Item> itemMap;

  std::ifstream file("./res/items.txt");
  if (!file.is_open())
  {
    std::cerr << "Failed to open file " << std::endl;
    return itemMap;
  }

  std::string line;
  while (std::getline(file, line))
  {
    std::istringstream iss(line);
    std::string name;
    int ID, maxStack;
    double durability = -1;

    if (iss >> ID >> name >> maxStack >> durability)
    {
      std::string path = "./res/game/items/" + std::to_string(ID) + "-" + name + ".png";
      Item item(ID, name, maxStack, path, durability);
      itemMap[name] = item;
    }
    else
    {
      std::cerr << "Invalid item data: " << line << std::endl;
    }
  }

  file.close();

  return itemMap;
}

void MainWindow::onItemClicked(Item_Pickup item)
{
  for (int i = 0; i < bag_button.size(); i++)
  {
    if (bag_button[i]->GetPressed())
    {
      if (item.item.GetName() == Cursor_item.item.GetName())
      {
        Cursor_item.number += item.number;
        if (Cursor_item.number > Cursor_item.item.GetMax())
        {
          item.number = Cursor_item.number - Cursor_item.item.GetMax();
          Cursor_item.number = Cursor_item.item.GetMax();
        }
      }
      this->me->SetBag(i, Cursor_item);
      bag_button[i]->SetItemPickup(Cursor_item);
      Cursor_item = item;
      return;
    }
  }

  for (int i = 0; i < chest_bag_button.size(); i++)
  {
    if (chest_bag_button[i]->GetPressed())
    {
      if (item.item.GetName() == Cursor_item.item.GetName())
      {
        Cursor_item.number += item.number;
        if (Cursor_item.number > Cursor_item.item.GetMax())
        {
          item.number = Cursor_item.number - Cursor_item.item.GetMax();
          Cursor_item.number = Cursor_item.item.GetMax();
        }
      }
      this->me->SetBag(i, Cursor_item);
      chest_bag_button[i]->SetItemPickup(Cursor_item);
      Cursor_item = item;
      return;
    }
  }

  for (int i = 0; i < toolbar_button.size(); i++)
  {
    if (toolbar_button[i]->GetPressed())
    {
      toolbar_button[i]->SetSelected(!(toolbar_button[i]->GetSelected()));
      toolbar_button[i]->SetPressed(false);
      continue;
    }
    toolbar_button[i]->SetSelected(false);
  }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
  if (isplaying)
  {
    if (event->button() == Qt::LeftButton)
    {
      Player player = *(this->me);
      Point player_location = player.GetLocation();
      int left_top_x = player_location.GetX() - DEFUALT_WIDTH / 2;
      int left_top_y = player_location.GetY() - DEFUALT_HEIGHT / 2;
      int cursor_block_location_x = (mousePosition.rx() + left_top_x) / BLOCK_SIZE;
      int cursor_block_location_y = (mousePosition.ry() + left_top_y) / BLOCK_SIZE;
      int player_block_location_x = player_location.GetX() / BLOCK_SIZE;
      int player_block_location_y = player_location.GetY() / BLOCK_SIZE;
      for (int i = 0; i < toolbar_button.size(); i++)
      {

        if (toolbar_button[i]->GetSelected())
        {

          if (abs(player_block_location_x - cursor_block_location_x) < 5 && abs(player_block_location_y - cursor_block_location_y) < 5)
          {
            if (toolbar_button[i]->GetItemPickup().item.Put(this->gameMap, cursor_block_location_x, cursor_block_location_y, this->myID))
            {
              Item_Pickup tmp = toolbar_button[i]->GetItemPickup();
              tmp.UseOne();
              toolbar_button[i]->SetItemPickup(tmp);
              this->me->Use(tmp.item.GetName());
            }
          }
          return;
        }
      }
    }
  }
}