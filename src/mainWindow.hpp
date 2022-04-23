#pragma once

#include <QWidget>

#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

class mainWindow : public QWidget {
	Q_OBJECT

public:
	explicit mainWindow(QWidget* parent = nullptr);
    ~mainWindow();

private:
    //! Setup which slots to use for which signals.
    void setConnections();

// When a widget sends out a signal->This signal can trigger a slot function to be called.
public slots:
    //! Add item from text field to the list.
    void addItem();

    //! Delete selected items from list.
    void deleteSelected();

    //! Add a '+' character to the clicked item in the list.
    void updateClicked(QListWidgetItem* item);

// Our widget can also send out signals->None are defined yet
signals:

private:
    QVBoxLayout* m_layout;     //!< Stacks the added widgets vertically
    QListWidget* m_list;       //!< List that coantains all text
    QLineEdit* m_edit;         //!< Text edit field
    QPushButton* m_addButton;  //!< Button to add text to list
    QPushButton* m_delButton;  //!< Button to del text from list
};
