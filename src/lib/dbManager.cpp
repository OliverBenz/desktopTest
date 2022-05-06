#include "dbManager.hpp"

#include <QtSql>
#include <QSqlDatabase>


// Queries
const QString postItem = R"(INSERT INTO items VALUES (0, "{}", "{}", {}, {});)";
const QString getLocations = "SELECT id, locationId, name, description FROM placement";

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
    // TODO: Set admin user in DB to update categories etc in the database..
    // TODO: User oliver only has access to the specific items and cannot manage locations etc.

    m_database = QSqlDatabase::addDatabase("QMYSQL");
    m_database.setHostName("127.0.0.1");
    m_database.setUserName("oliver");
    m_database.setPassword("1234");
    m_database.setDatabaseName("inventory");
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

dbManager& dbManager::operator=(dbManager&& other) noexcept {
    if (this != &other) {
        std::swap(m_dbHelper, other.m_dbHelper);
    }
    return *this;
}

// ----- dbManager functions -----
std::vector<double> dbManager::getTestData() {
    //const QSqlResult* result = m_dbHelper->executeQuery(getLocations);
    //if(result->size() != -1) {}
    // TODO: Read result from query
    // TODO: Check how exactly a query is build in QT and improve architecture.
    return {};
}


void dbManager::setTestData() {
    // Continue instructions
    //  - Write this test data to item/category/placement structs
    //  - test insert statement on vector of this data
    //  - Where to store data? We dont want to copy large amounts of data all the time..

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

    // TODO: Get all data from testItems
    // TODO: Some queries are already in https://github.com/OliverBenz/Inventory_Desktop/blob/master/Desktop/lib/dbHelper.cpp#L83

    // TODO: Data has to be sanitized
    // TODO: Do inserts etc in sql transactions.
    // Insert test data to databases
    for(std::size_t i = 0; i < 4; i++)
        const QSqlQuery query = m_dbHelper->executeQuery(std::format(postItem, values[i].name, values[i].description, values[i].placementId, values[i].categoryId);

}
