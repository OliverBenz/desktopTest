#pragma once

#include <QWidget>

#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

class searchWindow : public QWidget {
	Q_OBJECT

public:
	explicit searchWindow(QWidget* parent = nullptr);
    ~searchWindow();

private:
    //! Setup which slots to use for which signals.
    void setConnections();

// When a widget sends out a signal->This signal can trigger a slot function to be called.mainWindow
public slots:

// Our widget can also send out signals->None are defined yet
signals:

private:
    QVBoxLayout* m_layoutMain;    //!< Stacks the added widgets vertically

    // Search bar
    QHBoxLayout* m_layoutSrField; //!< Layout of the search fields.
    QLineEdit* m_editName;  //!< Input for object name.
    QLineEdit* m_editId;    //!< Input for object id.
    QLineEdit* m_editLoc;   //!< Input for object location.

};
