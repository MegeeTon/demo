
/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * xml2ui : [description]
 *
 * filename : xml2ui.h
 * author   : tangmq(tangmq@initialsoft.com)
 * create   : 2023-01-10 02:37:14 UTC
 * modified : 2023-05-09 03:18:56 UTC
\******************************************************************************/

#ifndef __ITERFACE_H__
#define __INTERFACE_H__

////////////////////////////////////////////////////////////////////////////////
// Headers //
//
#include <windows.h>

#include <QApplication>
#include <QBuffer>
#include <QComboBox>
#include <QDateEdit>
#include <QDebug>
#include <QFormBuilder>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QMessageBox>
#include <QPluginLoader>
#include <QProcess>
#include <QPushButton>
#include <QScrollArea>
#include <QSpinBox>
#include <QSplitter>
#include <QStandardItemModel>
#include <QString>
#include <QTableView>
#include <QTextEdit>
#include <QTextStream>
#include <QThread>
#include <QTreeView>
#include <QVBoxLayout>
#include <QWidget>
#include <QWindow>
#include <QGroupBox>

#include <iostream>
#include <map>

#include "ui_tableDeal.h"

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Classes
class tableDeal : public QWidget
{
  Q_OBJECT

 public:
  tableDeal(QWidget* parent = nullptr);
  ~tableDeal();

 public:
  QPushButton* buttonAdd         = new QPushButton("增");
  QPushButton* buttonDelete      = new QPushButton("删");
  QTableView* tableview          = new QTableView;
  QStandardItemModel* tablemodel = new QStandardItemModel;
};

class Interface : public QWidget
{
  Q_OBJECT

 public:
  Interface(QWidget* parent = nullptr);
  ~Interface();

 public:
  /**
   * 通过preperty设定控件属性
   */
  void setproperty();

/**
 * 数据控件传输connect
 */
  void valueTransmit();

/**
 * 数据范围
 */
  void valueRange();

/**
 * map转QMap
 */
  void mapToQmap();

/**
 * list数据快排
 */
  void listSort();

/**
 * 控件切分
 * @param root [description]
 */
  void widgetsplit(QHBoxLayout* root);

/**
 * 滚动区控件
 * @return [description]
 */
  QWidget* scrollarea();

/**
 * xmlToUi
 * @return [description]
 */
  QWidget* genreate_widget();

  void tableView();

  void tableSelection();

  bool eventFilter(QObject* obj, QEvent* event);

 signals:
  void sendData(QString);

 public slots:
  void on_button();

 private slots:

  void receiveData(QString);

 private:
  QLineEdit* edit     = new QLineEdit;
  QLineEdit* edit1    = new QLineEdit;
  QPushButton* button = new QPushButton("send");
  QComboBox* combox   = new QComboBox;
  QSpinBox* spin      = new QSpinBox;
  tableDeal* table    = new tableDeal();
  Ui::Form ui;
};

////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __XML2UI_H__
////////////////////////////////// EOF /////////////////////////////////////////
