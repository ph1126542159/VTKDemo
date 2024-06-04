#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	app.setFont(QFont("Arial", 14));

	MainWindow win;
	win.show();

	return app.exec();
}
