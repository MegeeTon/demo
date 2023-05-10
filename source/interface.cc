/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * xml2ui : [description]
 *
 * filename : xml2ui.cc
 * author   : tangmq(tangmq@initialsoft.com)
 * create   : 2023-01-10 02:37:14 UTC
 * modified : 2023-05-08 05:39:49 UTC
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
{
    //mainwindow
    QVBoxLayout* v_box = new  QVBoxLayout;
    setLayout(v_box);
    resize(1920, 1080);

    //侧边导航栏


    //数据控件传输
    QGroupBox* group_box1 = new QGroupBox("data_send");
    QHBoxLayout* h_box1 = new QHBoxLayout;
    group_box1->setLayout(h_box1);
    h_box1->addWidget(edit);
    h_box1->addWidget(edit1);
    h_box1->addWidget(button);
    edit->setText("sadadas");
    setproperty();
    valueTransmit();
    v_box->addWidget(group_box1);

    //控件切分
    QGroupBox* group_box2 = new QGroupBox("widget_split");
    QHBoxLayout* h_box2 = new QHBoxLayout;
    group_box2->setLayout(h_box2);
    widgetsplit(h_box2);
    v_box->addWidget(group_box2);

    //xmlToUi放在scrollarea
    QGroupBox* group_box3 = new QGroupBox("xmlToUi");
    QHBoxLayout* h_box3 = new QHBoxLayout;
    group_box3->setLayout(h_box3);
    QWidget* xml = scrollarea();
    h_box3->addWidget(xml);
    v_box->addWidget(group_box3);

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
    v_box->addWidget(group_box4);

    //tablewidget
    QGroupBox* group_box5 = new QGroupBox("tablewidget");
    QHBoxLayout* h_box5 = new QHBoxLayout;
    group_box5->setLayout(h_box5);
    QWidget* tb = tableView();
    h_box5->addWidget(tb);
    v_box->addWidget(group_box5);
}

Interface::~Interface() {}

////////////////////////////////////////////////////////////////////////////////
// Functions
//

void Interface::on_button()
{
  emit sendData(edit->text());
}

void Interface::receiveData(QString data)
{
  edit1->setText(data); 
}

void Interface::setproperty()
{
  edit1->setProperty("readOnly", true);
  QVariant tmp = edit1->property("readOnly");
}

void Interface::valueTransmit()
{
  /*connect(button,SIGNAL(clicked()),SLOT(on_button()));*/
  connect(button, &QPushButton::clicked, this, &Interface::on_button);
  connect(this, &Interface::sendData, this, &Interface::receiveData);
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

QWidget* Interface::tableView()
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
  connect(table->buttonDelete, &QPushButton::clicked, [=]() { tableSelection(); });

  return table;
}

void Interface::tableSelection()
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
