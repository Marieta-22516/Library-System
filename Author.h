#pragma once
#include <string>
#include <stdexcept>

class Author {
private:
    std::string name;
    int birthYear;

public:

    Author() : name("Unknown"), birthYear(1900) {}

    Author(const std::string& n, int y)
        : name(n), birthYear(y)
    {
        if (n.empty())
            throw std::invalid_argument("Author name cannot be empty!");
        if (y < 1850 || y > 2025)
            throw std::invalid_argument("Birth year must be 1850–2025.");
    }

    const std::string& getName() const { return name; }
    int getBirthYear() const { return birthYear; }

    void setBirthYear(int y) {
        if (y < 1850 || y > 2025)
            throw std::invalid_argument("Birth year must be 1850–2025.");
        birthYear = y;
    }

    std::string to_string() const {
        return "Author: " + name + " (" + std::to_string(birthYear) + ")";
    }
};