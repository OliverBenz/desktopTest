#include <QApplication>

#include "mainWindow.hpp"
#include "searchWindow.hpp"
#include "itemWindow.hpp"
#include "plotWindow.hpp"

int main(int argc, char** argv){
    QApplication application(argc, argv);

    // mainWindow widget;
    searchWindow widget;
    // itemWindow widget;
    // plotWindow widget;

    widget.show();

	return application.exec();
}
