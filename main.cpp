#include <QGuiApplication>

#include "MainWindow.hpp"

int main(int argc, char** argv){
	static constexpr int width = 1920;
	static constexpr int height = 1080;

	QGuiApplication application(argc, argv);

	MainWindow window;
	window.setTitle("Desktop Application");
	window.setHeight(height);
	window.setWidth(width);
	window.show();

	return application.exec();
}
