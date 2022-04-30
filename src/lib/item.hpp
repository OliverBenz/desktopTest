#pragma once

#include <string>

struct item {
    int id;
    std::string name;         //!< Character limit of 30.
    std::string description;
    int placementId;
    int categoryId;
};
