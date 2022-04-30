#include "searchWindow.hpp"

#include <QHeaderView>
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

#include <QTableWidgetItem>
void searchWindow::fillTestData() {
    dbManager database;
    auto result = database.getTestData();

    struct {
        QString id;
        QString name;
        QString location;
    } values[4] = {
        {"ABB01", "Laptop", "Keller Regal 1"},
        {"ABB02", "Ladekabel", "Keller Regal 1"},
        {"ABB03", "Mikrofon", "Keller Regal 1"},
            {"ABB04", "Mikrofon Kabel langer text", "Keller Regal 1"}
    };

    // TODO: Is table correct for this? Maybe list of items and item is custom widget with text horizontally.
    m_tableSrResult->setRowCount(3);
    for(int i = 0; i < 3; ++i) {
        m_tableSrResult->setItem(i, 0, new QTableWidgetItem(values[i].id));
        m_tableSrResult->setItem(i, 1, new QTableWidgetItem(values[i].name));
        m_tableSrResult->setItem(i, 2, new QTableWidgetItem(values[i].location));
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
