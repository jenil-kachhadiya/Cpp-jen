#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
    string title, author, dueDate;

public:
    void setDetails(string t, string a, string d) {
        title = t; author = a; dueDate = d;
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
    string isbn;

public:
    void setISBN(string i) {
        isbn = (i.size() < 5) ? "UNKNOWN" : i;
    }

    void checkOut() {
        cout << "Book '" << getTitle() << "' checked out.\n";
    }

    void returnItem() {
        cout << "Book '" << getTitle() << "' returned.\n";
    }

    void displayDetails() {
        cout << "[Book] " << getTitle()
             << " | Author: " << getAuthor()
             << " | ISBN: " << isbn
             << " | Due: " << getDueDate() << endl;
    }
};

class DVD : public LibraryItem {
    int duration;

public:
    void setDuration(int d) {
        duration = (d > 0) ? d : 0;
    }

    void checkOut() {
        cout << "DVD '" << getTitle() << "' checked out.\n";
    }

    void returnItem() {
        cout << "DVD '" << getTitle() << "' returned.\n";
    }

    void displayDetails() {
        cout << "[DVD] " << getTitle()
             << " | Author: " << getAuthor()
             << " | Duration: " << duration << " mins"
             << " | Due: " << getDueDate() << endl;
    }
};

class Magazine : public LibraryItem {
    int issue;

public:
    void setIssue(int i) {
        issue = (i > 0) ? i : 0;
    }

    void checkOut() {
        cout << "Magazine '" << getTitle() << "' checked out.\n";
    }

    void returnItem() {
        cout << "Magazine '" << getTitle() << "' returned.\n";
    }

    void displayDetails() {
        cout << "[Magazine] " << getTitle()
             << " | Author: " << getAuthor()
             << " | Issue: " << issue
             << " | Due: " << getDueDate() << endl;
    }
};

int main() {
    const int MAX = 10;
    LibraryItem* items[MAX];
    int count = 0, choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if ((choice >= 1 && choice <= 3) && count >= MAX) {
            cout << "Library is full!\n";
            continue;
        }

        if (choice == 1) {
            Book* b = new Book();
            string t, a, d, i;

            cin.ignore();
            cout << "Title: "; getline(cin, t);
            cout << "Author: "; getline(cin, a);
            cout << "Due Date: "; getline(cin, d);
            cout << "ISBN: "; getline(cin, i);

            b->setDetails(t, a, d);
            b->setISBN(i);
            items[count++] = b;
        }
        else if (choice == 2) {
            DVD* dvd = new DVD();
            string t, a, d; int dur;

            cin.ignore();
            cout << "Title: "; getline(cin, t);
            cout << "Author: "; getline(cin, a);
            cout << "Due Date: "; getline(cin, d);
            cout << "Duration (mins): "; cin >> dur;

            dvd->setDetails(t, a, d);
            dvd->setDuration(dur);
            items[count++] = dvd;
        }
        else if (choice == 3) {
            Magazine* m = new Magazine();
            string t, a, d; int issue;

            cin.ignore();
            cout << "Title: "; getline(cin, t);
            cout << "Author: "; getline(cin, a);
            cout << "Due Date: "; getline(cin, d);
            cout << "Issue No: "; cin >> issue;

            m->setDetails(t, a, d);
            m->setIssue(issue);
            items[count++] = m;
        }
        else if (choice == 4) {
            for (int i = 0; i < count; i++)
                items[i]->displayDetails();
        }
        else if (choice == 5 || choice == 6) {
            int idx;
            cout << "Enter item index (0-" << count - 1 << "): ";
            cin >> idx;

            if (idx >= 0 && idx < count) {
                if (choice == 5) items[idx]->checkOut();
                else items[idx]->returnItem();
            } else cout << "Invalid index!\n";
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete items[i];

    cout << "Exiting Library System...\n";
    return 0;
}

/*
UPDATED OUTPUT

===== Library Management System =====
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 1

Title: God of Small Things
Author: Arundhati Roy
Due Date: 15-09-2010
ISBN: 12345

===== Library Management System =====
Enter choice: 2

Title: Life
Author: Jenil
Due Date: 20-09-2007
Duration (mins): 148

===== Library Management System =====
Enter choice: 4
[Book] God of Small Things | Author: Arundhati Roy | ISBN: 12345 | Due: 15-09-2010
[DVD] Life | Author: jenil | Duration: 148 mins | Due: 20-09-2007

===== Library Management System =====
Enter choice: 5
Enter item index (0-1): 0
Book 'God of Small Things' checked out.

===== Library Management System =====
Enter choice: 6
Enter item index (0-1): 1
DVD 'Life' returned.

===== Library Management System =====
Enter choice: 0
Exiting Library System...
*/