#include "searchWindow.hpp"

#include <QHeaderView>
#include <QTableWidgetItem>
#include "lib/dbManager.hpp"

searchWindow::searchWindow(QWidget* parent) : QWidget(parent)
{
    m_layoutMain = new QVBoxLayout(this);

// ----- Setup search layout -----
    m_layoutSrField = new QHBoxLayout(this);
    m_editName = new QLineEdit(this);
    m_editId = new QLineEdit(this);
    m_editLoc = new QLineEdit(this);
    m_buttonSr = new QPushButton("Search", this);

    // Add placeholder text
    m_editName->setPlaceholderText("Name");
    m_editId->setPlaceholderText("Identifier");
    m_editLoc->setPlaceholderText("Location");

    // Ad widgets to layout
    m_layoutSrField->addWidget(m_editName);
    m_layoutSrField->addWidget(m_editId);
    m_layoutSrField->addWidget(m_editLoc);
    m_layoutSrField->addWidget(m_buttonSr);

    m_layoutMain->addLayout(m_layoutSrField);

// ----- Setup list layout -----
    m_tableSrResult = new QTableWidget(0, 3, this);
    m_tableSrResult->setHorizontalHeaderLabels({"Identifier", "Name", "Location"});
    m_tableSrResult->horizontalHeader()->setStretchLastSection(true);

    m_layoutMain->addWidget(m_tableSrResult);

    setLayout(m_layoutMain);
    setConnections();

    fillTestData();
}

void searchWindow::setConnections() {
    // Search button clicked
    connect(m_buttonSr, SIGNAL(clicked()), this, SLOT(search()));

    // TODO: Enter pressed on input
}

void searchWindow::fillTestData() {
    dbManager database;
    std::vector<placement> result = database.getTestData();

    // TODO: Is table correct for this? Maybe list of items and item is custom widget with text horizontally.
    m_tableSrResult->setRowCount(3);
    for(std::size_t i = 0; i != result.size(); ++i) {
        m_tableSrResult->setItem(static_cast<int>(i), 0, new QTableWidgetItem(result[i].id));
        m_tableSrResult->setItem(static_cast<int>(i), 1, new QTableWidgetItem(result[i].name.c_str()));
        m_tableSrResult->setItem(static_cast<int>(i), 2, new QTableWidgetItem(result[i].location.c_str()));
    }
}

void searchWindow::search() {
    // TODO: Add logic
}

searchWindow::~searchWindow() {
    // Search input row
    delete m_editLoc;
    delete m_editId;
    delete m_editName;
    delete m_buttonSr;
    delete m_layoutSrField;

    // Result
    delete m_tableSrResult;

    // Main layout
    delete m_layoutMain;
}
