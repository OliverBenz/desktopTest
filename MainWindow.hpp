#pragma once

#include <QWindow>

class MainWindow : public QWindow {
	Q_OBJECT

public:
	MainWindow(QWindow* parent = nullptr);
};
