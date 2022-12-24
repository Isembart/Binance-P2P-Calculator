#include <iostream>
#include "database_types.cpp"

using namespace std;
void setBalance();
void printBalance();
void addTransaction();

//N is the number of possible options
const int N = 4;

//BalanceVariables
float bPLN,bUSDT;

TransactionList List;

string options[N] = {"Change balance","Add new transaction", "Print Transaction List","Exit"};

int main (){
    List = TransactionList();
//Hierarchy
    //Balance
    //USDT/PLN
    //Earnings this session

    //Change balance
    //Add new transactoin
        //Buy
        //Sell


    int choice = 0;
    while(1) {
        printBalance();
        //print options
        for (int i = 0; i < N; i++)
        {
            cout << i+1 << ". " << options[i] << endl;
        }
        cin >> choice;
        switch (choice)
        {
        case 1:
            setBalance();
            break;
        case 2:
            addTransaction();
        case 3:
            List.PrintList();
        case 4:
        default:
            return 0;
        } 
        system("cls");
    }
    return 0;
}

void printBalance() {
    cout << "PLN:" << bPLN << "  " << "USDT:"<<bUSDT <<endl;
}

void setBalance() {
    cout << "PLN:";
    cin >> bPLN;
    cout << "USDT:";
    cin >> bUSDT;
}

void addTransaction () {
    int choice;
    transaction newTransaction = transaction();

    //TYPE
    system("cls");
    cout << "1. Buy\n2. Sell\nSelect type: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            newTransaction.type = buy;
            break;
        
        case 2:
            newTransaction.type = sell;
            break;

        default:
            cout << "Wrong choice, returning!" << endl;
            return;
        }

    //ASSET
    system("cls");
    cout << "1. USDT\n2. PLN\nSelect: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            newTransaction.asset = USDT;
            break;
        
        case 2:
            newTransaction.asset = PLN;
            break;

        default:
            cout << "Wrong choice, returning!" << endl;
            return;
        }
    
    //AMOUNT
    cout << "Amount:";
    cin >> newTransaction.amount;

    //Price
    cout << "Price:";
    cin >> newTransaction.price;

    List.AddTransaction(newTransaction);
}