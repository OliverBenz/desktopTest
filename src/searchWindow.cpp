#include "searchWindow.hpp"

#include <QHeaderView>

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
}

void searchWindow::setConnections() {
    // Search button clicked
    connect(m_buttonSr, SIGNAL(clicked()), this, SLOT(search()));

    // TODO: Enter pressed on input
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
