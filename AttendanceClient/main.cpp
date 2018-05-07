#include "AttendanceClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AttendanceClient w;
	w.show();
	return a.exec();
}
