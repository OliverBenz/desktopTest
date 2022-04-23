#include <QApplication>

#include "mainWindow.hpp"
#include "searchWindow.hpp"

int main(int argc, char** argv){
    QApplication application(argc, argv);

    static constexpr int width = 1080;
    static constexpr int height = 720;


    searchWindow widget;
    //mainWindow widget;
    widget.resize(width, height);
	widget.show();

	return application.exec();
}
