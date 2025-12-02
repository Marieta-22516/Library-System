#include <iostream>
#include "Library.h"
#include "Author.h"
#include "Book.h"
#include "Member.h"
#include "Loan.h"

using namespace std;

int main() {
    try {
        Library lib;

        Author a1{"Ivan Vazov", 1850};
        Author a2{"Elin Pelin", 1877};

        Book b1{"Pod igoto", a1, 1894, 25.50, "ISBN-001"};
        Book b2{"Nema zemya", a1, 1900, 18.90, "ISBN-002"};
        Book b3{"Yan Bibiyan", a2, 1933, 12.40, "ISBN-003"};

        lib.addBook(b1);
        lib.addBook(b2);
        lib.addBook(b3);

        Member m1{"Petar Petrov", "M001", 2023};
        Member m2{"Ivan Ivanov", "M002", 2024};

        lib.addMember(m1);
        lib.addMember(m2);

        cout << lib.to_string() << "\n\n";

        if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
            cout << "Loan created for ISBN-001.\n";
        else
            cout << "Loan FAILED for ISBN-001.\n";

        cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n\n";

        if (lib.returnBook("ISBN-001", "M001"))
            cout << "Book ISBN-001 successfully returned.\n";
        else
            cout << "Return FAILED.\n";

        cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n\n";

        cout << "Books by author 'Ivan Vazov'\n";
        for (const auto& bk : lib.findByAuthor("Ivan Vazov")) {
            cout << bk.to_string() << "\n\n";
        }

        cout << "Total books alive in library: " << lib.getNumberOfBooks() << "\n";

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}