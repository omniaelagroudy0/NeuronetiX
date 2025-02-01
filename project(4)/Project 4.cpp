#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    string publicationDate;
    bool isAvailable;

public:
    Book() : isAvailable(true) {}
    Book(string t, string a, string i, string p)
        : title(t), author(a), ISBN(i), publicationDate(p), isAvailable(true) {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    string getPublicationDate() const { return publicationDate; }
    bool getStatus() const { return isAvailable; }

    // Setters
    void setStatus(bool status) { isAvailable = status; }

    void displayBookInfo() const {
        cout << "Title: " << title << "\n"
             << "Author: " << author << "\n"
             << "ISBN: " << ISBN << "\n"
             << "Published: " << publicationDate << "\n"
             << "Status: " << (isAvailable ? "Available" : "Unavailable") << "\n";
    }

    // Friend class Member to access private members
    friend class Member;
};

class Member {
private:
    string name;
    string membershipID;
    string contactInfo;
    vector<Book*> borrowedBooks;

public:
    Member(string n, string id, string c)
        : name(n), membershipID(id), contactInfo(c) {}


    string getName() const { return name; }
    string getMembershipID() const { return membershipID; }
    string getContactInfo() const { return contactInfo; }
    const vector<Book*>& getBorrowedBooks() const { return borrowedBooks; }


    void setName(const string& n) { name = n; }
    void setMembershipID(const string& id) { membershipID = id; }
    void setContactInfo(const string& c) { contactInfo = c; }


    void borrowBook(Book& book) {
        if (book.getStatus()) {
            borrowedBooks.push_back(&book);
            book.setStatus(false);
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book is not available.\n";
        }
    }

    void returnBook(Book& book) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), &book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
            book.setStatus(true);
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book not found in borrowed list.\n";
        }
    }


    static void addBook(vector<Book>& books, const Book& book) {
        books.push_back(book);
    }

    static void removeBook(vector<Book>& books, const string& ISBN) {
        auto it = remove_if(books.begin(), books.end(), [&](const Book& book) { return book.getISBN() == ISBN; });
        if (it != books.end()) {
            books.erase(it, books.end());
        } else {
            cout << "Book not found.\n";
        }
    }

    static void registerMember(vector<Member>& members, const Member& member) {
        members.push_back(member);
    }
};


class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added: " << book.getTitle() << "\n";
    }

    void removeBook(const string& ISBN) {
        auto it = remove_if(books.begin(), books.end(), [&](const Book& book) { return book.getISBN() == ISBN; });
        if (it != books.end()) {
            cout << "Book removed: " << it->getTitle() << "\n";
            books.erase(it, books.end());
        } else {
            cout << "Book not found.\n";
        }
    }

    void registerMember(const Member& member) {
        members.push_back(member);
        cout << "Member registered: " << member.getName() << "\n";
    }

    void borrowBook(const string& memberID, const string& ISBN) {
        auto member = find_if(members.begin(), members.end(), [&](const Member& m) { return m.getMembershipID() == memberID; });
        auto book = find_if(books.begin(), books.end(), [&](const Book& b) { return b.getISBN() == ISBN; });

        if (member != members.end() && book != books.end()) {
            if (book->getStatus()) {
                member->borrowedBooks.push_back(&(*book));
                book->setStatus(false);
                cout << member->getName() << " borrowed " << book->getTitle() << ".\n";
            } else {
                cout << "Book is already borrowed.\n";
            }
        } else {
            cout << "Member or Book not found.\n";
        }
    }

    void returnBook(const string& memberID, const string& ISBN) {
        auto member = find_if(members.begin(), members.end(), [&](const Member& m) { return m.getMembershipID() == memberID; });
        auto book = find_if(books.begin(), books.end(), [&](const Book& b) { return b.getISBN() == ISBN; });

        if (member != members.end() && book != books.end()) {
            auto it = find(member->borrowedBooks.begin(), member->borrowedBooks.end(), &(*book));
            if (it != member->borrowedBooks.end()) {
                member->borrowedBooks.erase(it);
                book->setStatus(true);
                cout << member->getName() << " returned " << book->getTitle() << ".\n";
            } else {
                cout << "Book not found in member's borrowed list.\n";
            }
        } else {
            cout << "Member or Book not found.\n";
        }
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in the library.\n";
        } else {
            cout << "Books in the library:\n";
            for (const auto& book : books) {
                book.displayBookInfo();
                cout << "\n";
            }
        }
    }

    void displayMembers() const {
        if (members.empty()) {
            cout << "No members registered.\n";
        } else {
            cout << "Members of the library:\n";
            for (const auto& member : members) {
                cout << "Name: " << member.getName() << ", ID: " << member.getMembershipID() << "\n";
            }
        }
    }
};

int main() {
    vector<Book> books;
    vector<Member> members;



    Book book2("To Kill a Mockingbird", "Harper Lee", "987654321", "July 11, 1960");



    Member::addBook(books, book2);



    Member member2("Bob Brown", "M002", "bob.brown.com");



    Member::registerMember(members, member2);


    if (!books.empty() && !members.empty()) {
        members[0].borrowBook(books[0]);

        members[0].returnBook(books[0]);
        books[0].displayBookInfo();
    }
Library library;

    Book book1("1984", "George Orwell", "123456789", "June 8, 1949");
    Book book2("To Kill a Mockingbird", "Harper Lee", "987654321", "July 11, 1960");
    library.addBook(book1);
    library.addBook(book2);

    Member member1("Alice Green", "M001", "alice.green@example.com");
    Member member2("Bob Brown", "M002", "bob.brown@example.com");
    library.registerMember(member1);
    library.registerMember(member2);

    library.displayMembers();
    library.displayBooks();

    library.borrowBook("M001", "123456789");
    library.borrowBook("M002", "987654321");
    library.displayBooks();

    library.returnBook("M001", "123456789");
    library.displayBooks();


    return 0;
}
