
/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * xml2ui : [description]
 *
 * filename : xml2ui.h
 * author   : tangmq(tangmq@initialsoft.com)
 * create   : 2023-01-10 02:37:14 UTC
 * modified : 2023-05-10 01:48:48 UTC
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
#include <QGroupBox>
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
#include <QButtonGroup>
#include <iostream>
#include <map>

#include "ui_navigation.h"

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Classes
/**
 * 自定义控件
 */

namespace Ui {
	class navigation;
}

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
  void setproperty(QLineEdit* edit1);

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

  /**
   * 表格控件处理
   */
  QWidget* tableView(tableDeal* table);

  /**
   * 不选择警告
   */
  void tableSelection(tableDeal* table);

  /**
   * 鼠标中键滑动事件过滤
   * @param  obj   [description]
   * @param  event [description]
   * @return       [description]
   */
  bool eventFilter(QObject* obj, QEvent* event);

 private:
  Ui::navigation* ui = nullptr;
  QButtonGroup* btnGroup = new QButtonGroup;
  QWidget* home_win = new QWidget;
  QWidget* work_win = new QWidget;
  QWidget* data_win = new QWidget;
  QWidget* setting_win = new QWidget;
  QWidget* user_win = new QWidget;
  QWidget* version_win = new QWidget;
};

////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __XML2UI_H__
////////////////////////////////// EOF /////////////////////////////////////////
