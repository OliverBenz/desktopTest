#include "mainWindow.hpp"

mainWindow::mainWindow(QWidget* parent) : QWidget(parent)
{
    // Create all widgets
    m_layout = new QVBoxLayout(this);
    m_list = new QListWidget(this);
    m_edit = new QLineEdit(this);
    m_addButton = new QPushButton("Add", this);
    m_delButton = new QPushButton("Delete", this);

    // Add widgets to layout (stacks them vertically by order added)
    m_layout->addWidget(m_list);
    m_layout->addWidget(m_edit);
    m_layout->addWidget(m_addButton);
    m_layout->addWidget(m_delButton);

    setLayout(m_layout);  // add layout to MainWidget
    setConnections();     // Configure connections of this widget
}

void mainWindow::setConnections() {
    // Add item to list
    connect(m_addButton, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(m_edit, SIGNAL(returnPressed()), this, SLOT(addItem()));

    // Update clicked item
    connect(m_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(updateClicked(QListWidgetItem*)));

    // Delete Button
    connect(m_delButton, SIGNAL(clicked()), this, SLOT(deleteSelected()));
}

void mainWindow::addItem() {
    if(!m_edit->text().isEmpty()) {
        m_list->addItem(m_edit->text());
    }
    m_edit->clear();
}

void mainWindow::deleteSelected() {
    if(!m_list->selectedItems().empty()) {
        for(auto item: m_list->selectedItems())
            delete item;
    }
}

void mainWindow::updateClicked(QListWidgetItem* item) {
    Q_ASSERT(item);

    item->setText(item->text() + "+");
}

mainWindow::~mainWindow() {
    delete m_delButton;
    delete m_addButton;
    delete m_edit;
    delete m_list;
    delete m_layout;
}
