#include "dbManager.hpp"

#include <QtSql>
#include <QSqlDatabase>

//! Helper class to handle database access.
struct dbHelper {
    QSqlDatabase m_database;

public:
    explicit dbHelper();

    dbHelper(const dbHelper& other) = default;             // Copy constructor
    ~dbHelper() = default;                                 // Destructor
    dbHelper& operator=(const dbHelper& other) = default;  // Assignment operator
    dbHelper(dbHelper&& other) = default;                  // Move constructor
    dbHelper& operator=(dbHelper&& other) = default;       // Move assignment operator

public:
    QSqlQuery executeQuery(const QString& command);
};

dbHelper::dbHelper() {
    m_database = QSqlDatabase::addDatabase("QMYSQL");
    m_database.setHostName("127.0.0.1");
    m_database.setUserName("root");
    m_database.setPassword("1234");
    m_database.setDatabaseName("testing");
}

QSqlQuery dbHelper::executeQuery(const QString& command) {
    m_database.open();

    QSqlQuery query;
    query.exec(command);
    m_database.close();

    return query;
}


// ----- dbManager standard stuff -----
dbManager::dbManager() : m_dbHelper(std::make_unique<dbHelper>())
{};

dbManager::~dbManager() = default;
dbManager& dbManager::operator=(const dbManager& other) {
    if (this != &other) {
        m_dbHelper->m_database = other.m_dbHelper->m_database;
    }
    return *this;
};

dbManager::dbManager(dbManager&& other) noexcept : m_dbHelper(nullptr) {
    std::swap(m_dbHelper, other.m_dbHelper);
}

dbManager& dbManager::operator=(dbManager&& other) {
    if (this != &other) {
        std::swap(m_dbHelper, other.m_dbHelper);
    }
    return *this;
}

// ----- dbManager functions -----
std::vector<double> dbManager::getTestData() {
    const QSqlQuery query = m_dbHelper->executeQuery("SELECT * FROM testing");

    // TODO: Read result from query
    // TODO: Check how exactly a query is build in QT and improve architecture.
    return {};
}