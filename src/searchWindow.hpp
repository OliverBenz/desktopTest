#pragma once

#include <QWidget>

#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>

class searchWindow : public QWidget {
	Q_OBJECT

public:
	explicit searchWindow(QWidget* parent = nullptr);
    ~searchWindow();

private:
    //! Setup which slots to use widget signals.
    void setConnections();

    void fillTestData();

public slots:
    //! Start search for items.
    void search();

private:
    QVBoxLayout* m_layoutMain;    //!< Stacks the added widgets vertically

    // Search bar
    QHBoxLayout* m_layoutSrField; //!< Layout of the search fields.
    QLineEdit* m_editName;        //!< Input for object name.
    QLineEdit* m_editId;          //!< Input for object id.
    QLineEdit* m_editLoc;         //!< Input for object location.
    QPushButton* m_buttonSr;      //!< Button to start searching.

    QTableWidget* m_tableSrResult;  //!< Table that display the search result.

};
