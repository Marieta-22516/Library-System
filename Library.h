#pragma once
#include <vector>
#include <string>
#include <optional>
#include <stdexcept>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

    std::optional<size_t> findBookIndex(const std::string& isbn) const {
        for (size_t i = 0; i < books.size(); ++i)
            if (books[i].getISBN() == isbn)
                return i;
        return std::nullopt;
    }

    bool hasMember(const std::string& memberId) const {
        for (const auto& m : members)
            if (m.getId() == memberId)
                return true;
        return false;
    }

public:
    Library() = default;

    void addBook(const Book& b) {
        if (hasBook(b.getISBN()))
            throw std::runtime_error("Book with this ISBN already exists!");
        books.push_back(b);
    }

    void addMember(const Member& m) {
        if (hasMember(m.getId()))
            throw std::runtime_error("Member with this ID already exists!");
        members.push_back(m);
    }

    bool hasBook(const std::string& isbn) const {
        return findBookIndex(isbn).has_value();
    }

    bool isBookAvailable(const std::string& isbn) const {
        if (!hasBook(isbn)) return false;
        for (const auto& l : loans)
            if (l.getISBN() == isbn && !l.isReturned())
                return false;
        return true;
    }

    bool loanBook(const std::string& isbn, const std::string& memberId,
                  const std::string& start, const std::string& due)
    {
        if (!hasBook(isbn) || !hasMember(memberId)) return false;
        if (!isBookAvailable(isbn)) return false;

        loans.emplace_back(isbn, memberId, start, due);
        return true;
    }

    bool returnBook(const std::string& isbn, const std::string& memberId) {
        for (auto& l : loans)
            if (l.getISBN() == isbn && l.getMemberID() == memberId && !l.isReturned()) {
                l.markReturned();
                return true;
            }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for (const auto& b : books)
            if (b.getAuthor().getName().find(authorName) != std::string::npos)
                result.push_back(b);
        return result;
    }

    std::string to_string() const {
        int activeLoans = 0;
        for (const auto& l : loans)
            if (!l.isReturned())
                ++activeLoans;

        return "Library\n"
               "Total Books: " + std::to_string(books.size()) + "\n" +
               "Total Members: " + std::to_string(members.size()) + "\n" +
               "Active Loans: " + std::to_string(activeLoans);
    }

    size_t getNumberOfBooks() const {
        return books.size();
    }

    size_t getActiveLoans() const {
        size_t count = 0;
        for (const auto& l : loans)
            if (!l.isReturned()) ++count;
        return count;
    }
};
