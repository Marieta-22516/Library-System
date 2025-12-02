# Проект: Мини „Библиотечна система“ (Library System)

## Описание
Това е мини библиотечна система, реализирана на C++.  
Проектът демонстрира основни обектно-ориентирани принципи:
- класове и капсулация; 
- конструктори, деструктори и Rule of 5; 
- Const-коректност и статични членове;  
- валидация на данни;
- управление на връзки между класовете: Book, Author, Member, Loan, Library;

---
  
## Структура на проекта

```
Library System/
├── Author.h
├── Book.h
├── Library.h
├── Loan.h
├── Member.h
├── README.md
├── image.png
└── main.cpp
```

## Компилация и изпълнение
Отворете терминал в директорията `Library System/` и изпълнете:
```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o main
```

След това стартирайте програмата:

```bash
./main
```

---

## Примерен изход

```
Library
Total Books: 3  
Total Members: 2
Active Loans: 0 

Loan created for ISBN-001.
Available ISBN-001? false

Book ISBN-001 successfully returned.
Available ISBN-001? true

Books by author 'Ivan Vazov'
Book: Pod igoto
Author: Ivan Vazov (1850)
Year: 1894
Price: 25.50
ISBN: ISBN-001

Book: Nema zemya
Author: Ivan Vazov (1850)
Year: 1900
Price: 18.90
ISBN: ISBN-002

Total books alive in library: 3
```

---

# Класове

##Author
Представя автор на книга.

**Членове:**
- `name` – името на автора
- `birthYear` – година на раждане

**Методи:**
- `Author()` – конструктор по подразбиране ("Unknown", 1900)
- `Author(const std::string& name, int birthYear)` – параметризиран конструктор с валидация
- `const std::string& getName() const` – връща името на автора
- `int getBirthYear() const` – връща годината на раждане
- `void setBirthYear(int)` – задава година на раждане с валидация
- `std::string to_string() const` – връща информация за автора като низ

##Book
Представя книга.

**Членове:**
- `title` – заглавие
- `author` – автор
- `year` – година на издаване
- `price` – цена
- `isbn` – уникален идентификатор
- `static totalBooks` – брояч на живите книги

**Методи:**
- Конструктори и деструктори (Rule of 5)
- Getters и setters с валидация
- `std::string to_string() const` – връща информация за книгата
- `static int getTotalBooks()` – връща броя на живите книги

##Member
Представя читател на библиотеката.

**Членове:**
- `name` – име
- `memberId` – уникален идентификатор
- `yearJoined` – година на присъединяване

**Методи:**
- Конструктори с валидация
- Getters
- `std::string to_string() const` – връща информация за члена

##Loan
Представя заем на книга.

**Членове:**
- `isbn` – ISBN на заетата книга
- `memberId` – ID на члена
- `startDate` – дата на заем
- `dueDate` – краен срок
- `returned` – дали е върната

**Методи:**
- Конструктор с валидация (`dueDate >= startDate`)
- Getters
- `void markReturned()` – маркира като върната
- `bool isOverdue(const std::string& today) const` – проверява дали е просрочен
- `std::string to_string() const` – връща информация за заема

##Library
Представя цялата библиотека.

**Членове:**
- `books` – всички книги (`std::vector<Book>`)
- `members` – всички членове (`std::vector<Member>`)
- `loans` – всички заеми (`std::vector<Loan>`)

**Методи:**
- `void addBook(const Book&)` – добавя книга
- `void addMember(const Member&)` – добавя член
- `bool hasBook(const std::string&) const` – проверява дали съществува книга
- `bool isBookAvailable(const std::string&) const` – проверява наличността на книга
- `bool loanBook(const std::string&, const std::string&, const std::string&, const std::string&)` – създава заем
- `bool returnBook(const std::string&, const std::string&)` – връща книга
- `std::vector<Book> findByAuthor(const std::string&) const` – намира книги по автор
- `std::string to_string() const` – връща обобщена информация за библиотеката
- `size_t getNumberOfBooks() const` – броя книги в библиотеката
- `size_t getActiveLoans() const` – броя активни заеми

  
## Образователни цели

Проектът има за цел да демонстрира:
- разделение между интерфейс (`.h`) и имплементация (`.cpp`);
- използване на списъци за инициализация;
- валидация и обработка на изключения;
- работа със статични членове;
- прилагане на const-коректност.

---

## Екранна снимка

![](/image.png)

---

## Автор

**Име:** _Мариета Маринова Цончева_
**Номер:** _22516_
**Курс:** _Обектно-ориентирано програмиране (C++)_
**Дата:** _02.12.2025г._
