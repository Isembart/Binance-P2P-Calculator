#include <iostream>

enum currency {USDT,PLN};
enum action {buy, sell};

char *currencyNames[] = {(char*)"USDT",(char*)"PLN"};
char *actionNames[] = {(char*)"buy",(char*)"sell"};

struct transaction{
    float price;
    float amount;
    action type;
    currency asset;
    
    void Print() {
        std::cout << (char*)actionNames[type] << " "<< amount << " "<<(char*)currencyNames[asset] << " for "<< price << std::endl;
    }

    transaction(float p=0,float a=0,action t=action{buy},currency as=currency{USDT}) {
        this->price = p;
        this->amount = a;
        this->type = t;
        this->asset = as;
    }
};

struct TransactionListNode {
    transaction* _transaction;
    TransactionListNode* prev;
    TransactionListNode* next;
    TransactionListNode(transaction* t) {
        this->_transaction = t;
        next = nullptr;
        prev = nullptr;
    }
};

struct TransactionList {
    TransactionListNode* head;

    TransactionList() {
        this->head = nullptr;
    }

    void PrintList() {
        TransactionListNode* temp = head;
        while (temp != nullptr)
        {
            temp->_transaction->Print();
            temp = temp->next;
        }
        system("pause");   
    }

    TransactionListNode* GetLast() {
        TransactionListNode* temp = head;
        TransactionListNode* temp2 = head->next;
        while (temp != nullptr)
        {
            if(temp2 == nullptr) {
                return temp;
            }
            temp = temp->next;
            temp2 = temp->next;
        }
        return nullptr;
    }

    void AddTransaction(transaction newTransaction) {
        TransactionListNode* newNode = new TransactionListNode(new transaction(newTransaction.price,newTransaction.amount,newTransaction.type,newTransaction.asset));
        if(this->head !=nullptr) {
            TransactionListNode* last = this->GetLast();
            newNode->prev = last;
            last->next = newNode;
        }
        else {
            this->head = newNode;
        }
        
    }

};