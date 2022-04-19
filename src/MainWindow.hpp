#pragma once

#include <QWindow>

class MainWindow : public QWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWindow* parent = nullptr);
};
