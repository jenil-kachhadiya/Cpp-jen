#include <iostream>
#include <cstring>

using namespace std;

class Train
{
private:
    int number;
    char name[50];
    static int totalTrains;

public:
    Train()
    {
        number = 0;
        strcpy(name, "NULL");
        totalTrains++;
    }

    Train(int tn, const char* tname)
    {
        number = tn;
        strcpy(name, tname);
        totalTrains++;
    }

    void adddata()
    {
        cout << "Train number => ";
        cin >> number;

        cout << "Train name => ";
        cin.ignore();
        cin.getline(name, 50);
    }

    void display()
    {
        cout << "Train number Is => " << number;
        cout << "\nTrain Name Is => " << name << endl;
    }

    int trainnumber()
    {
        return number;
    }

    static void ttnumber()
    {
        cout << "\nTotal trains => " << totalTrains << endl;
    }
};

int Train::totalTrains = 0;

class System
{
    Train tr[100];
    int total;

public:
    System()
    {
        total = 0;

        tr[0] = Train(101, "Bullet Train");
        tr[1] = Train(102, "Vande Bharat");
        tr[2] = Train(103, "Indian Express");

        total = 3;
    }

    void addtrain()
    {
        if (total >= 100)
        {
            cout << "=== Full ===\n";
        }
        else
        {
            tr[total].adddata();
            total++;
            cout << "Added successfully...\n";
        }
    }

    void dis()
    {
        if (total == 0)
        {
            cout << "=== Empty ===\n";
        }
        else
        {
            for (int i = 0; i < total; i++)
            {
                tr[i].display();
            }
        }
    }

    void search(int a)
    {
        bool found = false;

        for (int i = 0; i < total; i++)
        {
            if (tr[i].trainnumber() == a)
            {
                tr[i].display();
                found = true;
            }
        }

        if (!found)
        {
            cout << "Train not found...\n";
        }
    }
};

int main()
{
    int c;
    System s;

    do
    {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Total number of trains\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> c;

        cout << "\n";

        switch (c)
        {
        case 1:
            s.addtrain();
            break;

        case 2:
            s.dis();
            break;

        case 3:
        {
            int n;
            cout << "Enter Searching number => ";
            cin >> n;
            s.search(n);
            break;
        }

        case 4:
            Train::ttnumber();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (c != 0);

    return 0;
}
