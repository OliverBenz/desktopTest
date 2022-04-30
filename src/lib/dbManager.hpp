#pragma once

#include <vector>
#include <memory>

struct dbHelper;

class dbManager {
public:
    explicit dbManager();                         // Default constructor
    ~dbManager();                                 // Destructor
    dbManager& operator=(const dbManager& other); // Copy assignment operator
    dbManager(dbManager&& other) noexcept;        // Move constructor
    dbManager& operator=(dbManager&& other);      // Move assignment operator

// Testing stuff
public:
    std::vector<double> getTestData();
    void setTestData();

private:
    std::unique_ptr<dbHelper> m_dbHelper;
};