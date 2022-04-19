#include <QGuiApplication>

#include "MainWindow.hpp"

int main(int argc, char** argv){
    QGuiApplication application(argc, argv);

	MainWindow window;
	window.show();

	return application.exec();
}
