#include <iostream>
#include "database_types.h"

const char *currencyNames[] = {(char*)"USDT",(char*)"PLN"};
const char *actionNames[] = {(char*)"buy",(char*)"sell"};

//TRANSACTION
inline void transaction::Print() {
    std::cout << (char*)actionNames[type] << " "<< amount << " "<<(char*)currencyNames[asset] << " for "<< price << std::endl;
}

transaction::transaction() {
    this->price = 0;
    this->amount = 0;
    this->type = buy;
    this->asset = USDT;
}

transaction::transaction(float p,float a,action t,currency as) {
    this->price = p;
    this->amount = a;
    this->type = t;
    this->asset = as;
}

//NODE
TransactionListNode::TransactionListNode(transaction* t) {
    this->_transaction = t;
    next = nullptr;
    prev = nullptr;
}
    

//TRANSACTIONLIST
TransactionList::TransactionList() {
    this->head = nullptr;
}

void TransactionList::PrintList() {
    TransactionListNode* temp = this->head;
    while (temp != nullptr)
    {
        temp->_transaction->Print();
        temp = temp->next;
    }
    system("pause");   
}

TransactionListNode* TransactionList::GetLast() {
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

void TransactionList::AddTransaction(transaction newTransaction) {
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