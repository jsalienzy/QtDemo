//#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QDirModel model;
	QTreeView tree;
	QTableView table;
	QListView list;
	tree.setModel(&model);
	table.setModel(&model);
	list.setModel(&model);
	tree.setSelectionMode(QAbstractItemView::ExtendedSelection);
	table.setSelectionModel(tree.selectionModel());
	list.setSelectionModel(tree.selectionModel());
	QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &list, SLOT(setRootIndex(QModelIndex)));
	QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &table, SLOT(setRootIndex(QModelIndex)));
	QSplitter *splitter = new QSplitter;
	splitter->addWidget(&tree);
	splitter->addWidget(&list);
	splitter->addWidget(&table);
	splitter->setWindowTitle(QObject::tr("Model/View"));
	splitter->show();
	//MainWindow w;
	//w.show();
	return a.exec();
}
