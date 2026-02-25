#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
protected:
    string accountNumber="";
    string accountHolderName="";
    int balance=0;

public:
    void setAccount(string accNum, string accHolder, int bal)
    {
        accountNumber=accNum;
        accountHolderName=accHolder;
        balance=bal;
    }

    ~BankAccount() {}

    virtual void deposit(int amount)
    {
        if(amount>0)
        {
            balance=balance+amount;
            cout<<"Deposited: "<<amount<<endl;
        }
        else
        {
            cout<<"Invalid deposit amount."<<endl;
        }
    }

    virtual void withdraw(int amount)
    {
        if(amount>0 && amount<=balance)
        {
            balance=balance-amount;
            cout<<"Withdrawn: "<<amount<<endl;
        }
        else
        {
            cout<<"Insufficient balance or invalid amount."<<endl;
        }
    }

    int getBalance()
    {
        return balance;
    }

    virtual void displayAccountInfo()
    {
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder: "<<accountHolderName<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    virtual void calculateInterest()
    {
        cout<<"No interest calculation for base account."<<endl;
    }
};

class SavingsAccount:public BankAccount
{
private:
    int interestRate=0;

public:
    void setSavings(string accNum, string accHolder, int bal, int rate)
    {
        setAccount(accNum,accHolder,bal);
        interestRate=rate;
    }

    void calculateInterest()
    {
        int interest=(balance*interestRate)/100;
        cout<<"Savings Account Interest: "<<interest<<endl;
    }
};

class CheckingAccount:public BankAccount
{
private:
    int overdraftLimit=0;

public:
    void setChecking(string accNum, string accHolder, int bal, int overdraft)
    {
        setAccount(accNum,accHolder,bal);
        overdraftLimit=overdraft;
    }

    void withdraw(int amount)
    {
        if(amount>0 && amount<=balance+overdraftLimit)
        {
            balance=balance-amount;
            cout<<"Withdrawn: "<<amount<<endl;
        }
        else
        {
            cout<<"Withdrawal exceeds overdraft limit or invalid amount."<<endl;
        }
    }
};

class FixedDepositAccount:public BankAccount
{
private:
    int term=0;
    int interestRate=0;

public:
    void setFixed(string accNum, string accHolder, int bal, int t, int rate)
    {
        setAccount(accNum,accHolder,bal);
        term=t;
        interestRate=rate;
    }

    void calculateInterest()
    {
        int interest=(balance*interestRate*term)/(12*100);
        cout<<"Fixed Deposit Interest for "<<term<<" months: "<<interest<<endl;
    }

    void withdraw(int amount)
    {
        cout<<"Withdrawals not allowed before maturity."<<endl;
    }
};

void menu()
{
    BankAccount *account=nullptr;
    int choice=0;

    do
    {
        cout<<"\nBanking System Menu:"<<endl;
        cout<<"1. Create Savings Account"<<endl;
        cout<<"2. Create Checking Account"<<endl;
        cout<<"3. Create Fixed Deposit Account"<<endl;
        cout<<"4. Deposit"<<endl;
        cout<<"5. Withdraw"<<endl;
        cout<<"6. Display Account Info"<<endl;
        cout<<"7. Calculate Interest"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        string accNum="";
        string accHolder="";
        int amount=0;
        int rate=0;
        int overdraft=0;
        int term=0;

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter Account Number: ";
                cin>>accNum;
                cout<<"Enter Account Holder Name: ";
                cin.ignore();
                getline(cin,accHolder);
                cout<<"Enter Initial Balance: ";
                cin>>amount;
                cout<<"Enter Interest Rate (%): ";
                cin>>rate;
                delete account;
                SavingsAccount *sa=new SavingsAccount();
                sa->setSavings(accNum,accHolder,amount,rate);
                account=sa;
                break;
            }
            case 2:
            {
                cout<<"Enter Account Number: ";
                cin>>accNum;
                cout<<"Enter Account Holder Name: ";
                cin.ignore();
                getline(cin,accHolder);
                cout<<"Enter Initial Balance: ";
                cin>>amount;
                cout<<"Enter Overdraft Limit: ";
                cin>>overdraft;
                delete account;
                CheckingAccount *ca=new CheckingAccount();
                ca->setChecking(accNum,accHolder,amount,overdraft);
                account=ca;
                break;
            }
            case 3:
            {
                cout<<"Enter Account Number: ";
                cin>>accNum;
                cout<<"Enter Account Holder Name: ";
                cin.ignore();
                getline(cin,accHolder);
                cout<<"Enter Initial Balance: ";
                cin>>amount;
                cout<<"Enter Term (months): ";
                cin>>term;
                cout<<"Enter Interest Rate (%): ";
                cin>>rate;
                delete account;
                FixedDepositAccount *fa=new FixedDepositAccount();
                fa->setFixed(accNum,accHolder,amount,term,rate);
                account=fa;
                break;
            }
            case 4:
            {
                if(account)
                {
                    cout<<"Enter amount to deposit: ";
                    cin>>amount;
                    account->deposit(amount);
                }
                else
                {
                    cout<<"No account created yet."<<endl;
                }
                break;
            }
            case 5:
            {
                if(account)
                {
                    cout<<"Enter amount to withdraw: ";
                    cin>>amount;
                    account->withdraw(amount);
                }
                else
                {
                    cout<<"No account created yet."<<endl;
                }
                break;
            }
            case 6:
            {
                if(account)
                {
                    account->displayAccountInfo();
                }
                else
                {
                    cout<<"No account created yet."<<endl;
                }
                break;
            }
            case 7:
            {
                if(account)
                {
                    account->calculateInterest();
                }
                else
                {
                    cout<<"No account created yet."<<endl;
                }
                break;
            }
            case 8:
            {
                break;
            }
            default:
            {
                cout<<"Invalid choice. Try again."<<endl;
            }
        }

    }while(choice!=8);

    delete account;
}

int main()
{
    menu();
    return 0;
}

/*
Output:-

Banking System Menu:
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
8. Exit
Enter your choice: 1
Enter Account Number: 101
Enter Account Holder Name: Jenil
Enter Initial Balance: 5000
Enter Interest Rate (%): 5

Banking System Menu:
Enter your choice: 4
Enter amount to deposit: 2000
Deposited: 2000

Banking System Menu:
Enter your choice: 5
Enter amount to withdraw: 1000
Withdrawn: 1000

Banking System Menu:
Enter your choice: 6
Account Number: 101
Account Holder: Ramesh
Balance: 6000

Banking System Menu:
Enter your choice: 7
Savings Account Interest: 300

Banking System Menu:
Enter your choice: 8
Exit
*/