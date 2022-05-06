#pragma once

#include "item.hpp"
#include "placement.hpp"

#include <vector>
#include <memory>

struct dbHelper;

class dbManager {
public:
    explicit dbManager();                             // Default constructor
    ~dbManager();                                     // Destructor
    dbManager& operator=(const dbManager& other);     // Copy assignment operator
    dbManager(dbManager&& other) noexcept;            // Move constructor
    dbManager& operator=(dbManager&& other) noexcept; // Move assignment operator

// Testing stuff
public:
    std::vector<placement> getTestData();
    void setTestData();

private:
    std::unique_ptr<dbHelper> m_dbHelper;
};