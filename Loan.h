#pragma once
#include <string>
#include <stdexcept>

class Loan {
private:
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

public:

    Loan() = delete;

    Loan(const std::string& i, const std::string& m,
         const std::string& start, const std::string& due)
        : isbn(i), memberId(m), startDate(start), dueDate(due), returned(false)
    {
        if (i.empty())
            throw std::invalid_argument("ISBN cannot be empty!");
        if (m.empty())
            throw std::invalid_argument("Member ID cannot be empty!");
        if (start.empty() || due.empty())
            throw std::invalid_argument("Dates cannot be empty!");
        if (due < start)
            throw std::invalid_argument("Due date must be >= start date!");
    }

    const std::string& getISBN() const { 
        return isbn; 
    }
    const std::string& getMemberID() const { 
        return memberId; 
    }
    const std::string& getStart() const { 
        return startDate; 
    }
    const std::string& getDue() const { 
        return dueDate; 
    }
    bool isReturned() const { 
        return returned; 
    }

    void markReturned() { 
        returned = true; 
    }

    bool isOverdue(const std::string& today) const {
        return !returned && dueDate < today;
    }

    std::string to_string() const {
        return "Loan:\n"
               "ISBN: " + isbn + "\n" +
               "Member ID: " + memberId + "\n" +
               "Start Date: " + startDate + "\n" +
               "Due Date: " + dueDate + "\n" +
               "Returned: " + (returned ? std::string("Yes") : "No");
    }
};