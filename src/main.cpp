#include <QApplication>

#include "mainWindow.hpp"
#include "searchWindow.hpp"
#include "itemWindow.hpp"

int main(int argc, char** argv){
    QApplication application(argc, argv);

    // mainWindow widget;
    searchWindow widget;
    // itemWindow widget;
    widget.show();

	return application.exec();
}
