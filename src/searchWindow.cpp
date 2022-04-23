#include "searchWindow.hpp"

searchWindow::searchWindow(QWidget* parent) : QWidget(parent)
{
    // Create all widgets
    m_layoutMain = new QVBoxLayout(this);
    m_layoutSrField = new QHBoxLayout(this);

    m_editName = new QLineEdit("Name", this);
    m_editId = new QLineEdit("Id", this);
    m_editLoc = new QLineEdit("Location", this);

    // Add widgets to layout (stacks them vertically by order added)
    m_layoutSrField->addWidget(m_editName);
    m_layoutSrField->addWidget(m_editId);
    m_layoutSrField->addWidget(m_editLoc);

    m_layoutMain->addLayout(m_layoutSrField);

    setLayout(m_layoutMain);
    setConnections();
}

void searchWindow::setConnections() {
    // Add item to list
    //connect(m_addButton, SIGNAL(clicked()), this, SLOT(addItem()));
    //connect(m_edit, SIGNAL(returnPressed()), this, SLOT(addItem()));

    // Update clicked item
    //connect(m_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(updateClicked(QListWidgetItem*)));

    // Delete Button
    //connect(m_delButton, SIGNAL(clicked()), this, SLOT(deleteSelected()));
}

searchWindow::~searchWindow() {
    delete m_editLoc;
    delete m_editId;
    delete m_editName;
    delete m_layoutSrField;

    delete m_layoutMain;
}
