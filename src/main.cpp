#include <QApplication>

#include "MainWidget.hpp"

int main(int argc, char** argv){
    QApplication application(argc, argv);

    static constexpr int width = 1080;
    static constexpr int height = 720;

    MainWidget widget;
    widget.resize(width, height);
	widget.show();

	return application.exec();
}
