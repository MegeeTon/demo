/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * xml2ui : [description]
 *
 * filename : xml2ui.cc
 * author   : tangmq(tangmq@initialsoft.com)
 * create   : 2023-01-10 02:37:14 UTC
 * modified : 2023-05-10 08:39:31 UTC
\******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include "interface.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Inner Scope Objects
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//

bool Interface::eventFilter(QObject* obj, QEvent* event)
{
  if (obj->inherits("QComboBox")) {
    if (event->type() == QEvent::Wheel) {
      qDebug() << "wheel";
      return true;
    }
  }
  return false;
}

Interface::Interface(QWidget* parent)
  : QWidget(parent)
    ,ui(new Ui::navigation)
{
    //侧边导航栏
    ui->setupUi(this);
    resize(2000, 1200);
    ui->stackedWidget->addWidget(home_win);
    ui->stackedWidget->addWidget(work_win);
    ui->stackedWidget->addWidget(data_win);
    ui->stackedWidget->addWidget(setting_win);
    ui->stackedWidget->addWidget(user_win);
    ui->stackedWidget->addWidget(version_win);
    btnGroup->addButton(ui->home_btn,0);
    ui->home_btn->setIcon(QIcon("../../3rd/icon/home.png"));
    btnGroup->addButton(ui->work_btn,1);
    ui->work_btn->setIcon(QIcon("../../3rd/icon/work.png"));
    btnGroup->addButton(ui->data_btn,2);
    ui->data_btn->setIcon(QIcon("../../3rd/icon/data.png"));
    btnGroup->addButton(ui->setting_btn,3);
    ui->setting_btn->setIcon(QIcon("../../3rd/icon/setting.png"));
    btnGroup->addButton(ui->user_btn,4);
    ui->user_btn->setIcon(QIcon("../../3rd/icon/user.png"));
    btnGroup->addButton(ui->version_btn,5);
    ui->version_btn->setIcon(QIcon("../../3rd/icon/version.png"));
    connect(btnGroup, static_cast<void (QButtonGroup::*)(int)
    >(&QButtonGroup::buttonClicked),
        ui->stackedWidget, &QStackedWidget::setCurrentIndex);
    //设置默认页
    btnGroup->button(0)->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);

    //home_win
    QVBoxLayout* home_lay = new  QVBoxLayout;
    home_win->setLayout(home_lay);
    //数据控件传输
    QGroupBox* group_box1 = new QGroupBox("data_send");
    QHBoxLayout* h_box1 = new QHBoxLayout;
    group_box1->setLayout(h_box1);
    QLineEdit* edit = new QLineEdit;
    QLineEdit* edit1 = new QLineEdit;
    QPushButton* button = new QPushButton("send");
    h_box1->addWidget(edit);
    h_box1->addWidget(edit1);
    h_box1->addWidget(button);
    edit->setText("sadadas");
    setproperty(edit1);
    connect(button, &QPushButton::clicked, [=]()
        { edit1->setText(edit->text()); });
    home_lay->addWidget(group_box1);
    //控件切分
    QGroupBox* group_box2 = new QGroupBox("widget_split");
    QHBoxLayout* h_box2 = new QHBoxLayout;
    group_box2->setLayout(h_box2);
    widgetsplit(h_box2);
    home_lay->addWidget(group_box2);
    //xmlToUi放在scrollarea
    QGroupBox* group_box3 = new QGroupBox("xmlToUi");
    QHBoxLayout* h_box3 = new QHBoxLayout;
    group_box3->setLayout(h_box3);
    QWidget* xml = scrollarea();
    h_box3->addWidget(xml);
    home_lay->addWidget(group_box3);

    //work_win
    QVBoxLayout* work_lay = new  QVBoxLayout;
    work_win->setLayout(work_lay);
    //eventFilter
    QGroupBox* group_box4 = new QGroupBox("eventFilter");
    QHBoxLayout* h_box4 = new QHBoxLayout;
    group_box4->setLayout(h_box4);
    QComboBox* combo = new QComboBox;
    QStringList strList;
    strList << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8";
    combo->addItems(strList);
    combo->installEventFilter(this);
    h_box4->addWidget(combo);
    work_lay->addWidget(group_box4);
    //tablewidget
    QGroupBox* group_box5 = new QGroupBox("tablewidget");
    QHBoxLayout* h_box5 = new QHBoxLayout;
    group_box5->setLayout(h_box5);
    tableDeal* table = new tableDeal();
    QWidget* tb = tableView(table);
    h_box5->addWidget(tb);
    work_lay->addWidget(group_box5);
}

Interface::~Interface() {}

////////////////////////////////////////////////////////////////////////////////
// Functions
//
void Interface::setproperty(QLineEdit* edit1)
{
  edit1->setProperty("readOnly", true);
  QVariant tmp = edit1->property("readOnly");
}

void Interface::valueRange()
{
  int length = 5;
  int max    = pow(10, length) - 1;
  int min    = 0 - max;

  QPair<QVariant, QVariant> range = {min, max};

  qDebug() << range;

  int digits = 3;

  double doublemax = pow(10, length - digits) - pow(0.1, digits);
  double doublemin = 0 - doublemax;

  range.first  = doublemin;
  range.second = doublemax;

  qDebug() << range;
}

void Interface::mapToQmap()
{
  map<int, string> a;
  a.insert(pair<int, string>(1, "2"));
  a.insert(pair<int, string>(1, "2"));
  a.insert(pair<int, string>(1, "3"));
  a.insert(pair<int, string>(2, "1"));
  a.insert(pair<int, string>(2, "2"));
  a.insert(pair<int, string>(2, "3"));

  for (map<int, string>::iterator iter = a.begin(); iter != a.end(); iter++) {
    cout << iter->second << endl;
  }

  QMap<int, QString> b;
  b.insert(1, "1");
  b.insert(1, "2");
  b.insert(1, "3");
  b.insert(2, "1");
  b.insert(2, "2");
  b.insert(2, "4");

  for (QMap<int, QString>::iterator iter = b.begin(); iter != b.end(); iter++) {
    qDebug() << iter.value();
  }
}

void Interface::listSort()
{
  QList<int> list;
  list << 1 << 2 << 3 << 4 << 5 << 2 << 3;
  qSort(list.begin(), list.end());

  if (!list.isEmpty()) { qDebug() << list; }
}

void Interface::widgetsplit(QHBoxLayout* root)
{
  auto* splitter_h = new QSplitter(this);
  auto* splitter_v = new QSplitter(Qt::Vertical, this);

  root->addWidget(splitter_h);
  QTextEdit* textedit1 = new QTextEdit;
  QTextEdit* textedit2 = new QTextEdit;
  QTextEdit* textedit3 = new QTextEdit;
  splitter_h->addWidget(textedit1);
  splitter_h->addWidget(splitter_v);
  splitter_v->addWidget(textedit2);
  splitter_v->addWidget(textedit3);
}

QWidget* Interface::scrollarea()
{
  auto* scrollarea = new QScrollArea;
  auto* button     = new QPushButton("commit");
  QWidget* w       = genreate_widget();
  QWidget* t       = new QWidget;
  auto* vbox_tmp       = new QVBoxLayout;
  scrollarea->setWidget(w);
  scrollarea->setWidgetResizable(0);
  vbox_tmp->addWidget(scrollarea);
  vbox_tmp->addWidget(button);
  t->setLayout(vbox_tmp);

  return t;
}

QWidget* Interface::genreate_widget()
{
  QFile xmlFile("1.ui");
  xmlFile.open(QIODevice::ReadOnly);
  QFormBuilder builder;
  auto* widget = builder.load(&xmlFile, nullptr);
  xmlFile.close();

  return widget;
}

QWidget* Interface::tableView(tableDeal* table)
{
  table->tablemodel->setHorizontalHeaderLabels(
    {"ID", "Name", "Num", "Pos", "vol"});

  for (int i = 0; i < 20; i++) {
    table->tablemodel->setItem(i, 0, new QStandardItem(QString::number(i)));
    table->tablemodel->setItem(i, 1, new QStandardItem(QString::number(i)));
    table->tablemodel->setItem(i, 2, new QStandardItem(QString::number(i)));
    table->tablemodel->setItem(i, 3, new QStandardItem(QString::number(i)));
    table->tablemodel->setItem(i, 4, new QStandardItem(QString::number(i)));
  }

  table->tableview->setModel(table->tablemodel);
  table->tableview->setSelectionBehavior(QAbstractItemView::SelectRows);
  table->tableview->setSelectionMode(QAbstractItemView::SingleSelection);
  connect(table->buttonDelete, &QPushButton::clicked, [=]() { tableSelection(table); });

  return table;
}

void Interface::tableSelection(tableDeal* table)
{
  auto record = table->tableview->selectionModel()->selectedIndexes();
  if (record.count() <= 0) {
    QMessageBox::warning(this, "警告", "未选择！");
    return;
  }
  auto s = record[1].data().toString().toStdString();
  cout << s << endl;
}

////////////////////////////////// EOF /////////////////////////////////////////

tableDeal::tableDeal(QWidget* parent)
{
  QHBoxLayout* hbox = new QHBoxLayout;
  hbox->addWidget(tableview);
  QVBoxLayout* vbox = new QVBoxLayout;
  vbox->addWidget(buttonAdd);
  vbox->addWidget(buttonDelete);
  hbox->addLayout(vbox);
  this->setLayout(hbox);
}

tableDeal::~tableDeal() {}
