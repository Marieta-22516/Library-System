#pragma once
#include <string>
#include <stdexcept>

class Member {
private:
    std::string name;
    std::string memberId;
    int yearJoined;

public:

    Member() : name("Unknown"), memberId("N/A"), yearJoined(2000) {}

    Member(const std::string& n, const std::string& id, int y)
        : name(n), memberId(id), yearJoined(y)
    {
        if (n.empty())
            throw std::invalid_argument("Member name cannot be empty.");
        if (id.empty())
            throw std::invalid_argument("Member ID cannot be empty.");
        if (y < 1900 || y > 2025)
            throw std::invalid_argument("Year joined must be between 1900 and 2025.");
    }

    const std::string& getName() const { return name; }
    const std::string& getId() const { return memberId; }
    int getYearJoined() const { return yearJoined; }

    std::string to_string() const {
        return "Member: " + name + "\n" +
               "ID: " + memberId + "\n" +
               "Joined: " + std::to_string(yearJoined);
    }
};