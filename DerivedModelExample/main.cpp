//#include "MainWindow.h"

#include <QtWidgets/QApplication>
#include <QTableView>
#include "ModelEx.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ModelEx modelEx;
	QTableView view;
	view.setModel(&modelEx);
	view.setWindowTitle(QObject::tr("modelEx"));
	view.resize(400, 400);
	view.show();
	/*MainWindow w;
	w.show();*/
	return a.exec();
}
