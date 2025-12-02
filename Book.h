#pragma once
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "Author.h"

class Book {
private:
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

    static int totalBooks;

public:

    Book() 
        : title("Unknown"), author(), year(1900), price(0.0), isbn("N/A")
    {
        ++totalBooks;
    }

    Book(const std::string& t, const Author& a, int y, double p, const std::string& i)
        : title(t), author(a), year(y), price(p), isbn(i)
    {
        if (t.empty()) throw std::invalid_argument("Title cannot be empty.");
        if (i.empty()) throw std::invalid_argument("ISBN cannot be empty.");
        if (p < 0) throw std::invalid_argument("Price cannot be negative.");
        if (y < 1500 || y > 2025) throw std::invalid_argument("Year invalid.");

        ++totalBooks;
    }

    Book(const Book& other)
        : title(other.title),
          author(other.author),
          year(other.year),
          price(other.price),
          isbn(other.isbn)
    {
        ++totalBooks;
    }

    Book(Book&& other) noexcept
        : title(std::move(other.title)),
          author(std::move(other.author)),
          year(other.year),
          price(other.price),
          isbn(std::move(other.isbn))
    {
        ++totalBooks;
    }

    Book& operator=(const Book&) = default;

    Book& operator=(Book&&) noexcept = default;

    ~Book() {
        --totalBooks;
    }

    const std::string& getTitle() const { return title; }
    const Author& getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    const std::string& getISBN() const { return isbn; }

    void setPrice(double p) {
        if (p < 0) throw std::invalid_argument("Price cannot be negative.");
        price = p;
    }

    void setYear(int y) {
        if (y < 1500 || y > 2025) throw std::invalid_argument("Year invalid.");
        year = y;
    }

    void setTitle(const std::string& t) {
        if (t.empty()) throw std::invalid_argument("Title cannot be empty.");
        title = t;
    }

    void setISBN(const std::string& i) {
        if (i.empty()) throw std::invalid_argument("ISBN cannot be empty.");
        isbn = i;
    }

    static int getTotalBooks() { return totalBooks; }

    std::string to_string() const {
        std::ostringstream oss;
        oss << "Book: " << title << "\n"
            << author.to_string() << "\n"
            << "Year: " << year << "\n"
            << "Price: " << std::fixed << std::setprecision(2) << price << "\n"
            << "ISBN: " << isbn;
        return oss.str();
    }
};

int Book::totalBooks = 0;
