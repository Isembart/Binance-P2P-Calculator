#include "TransactionList.h"
#include <iostream>

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
    TransactionListNode* newNode = new TransactionListNode(new transaction(newTransaction.price,newTransaction.amount,newTransaction.type,newTransaction.asset,newTransaction.usdt,newTransaction.pln));
    if(this->head !=nullptr) {
        TransactionListNode* last = this->GetLast();
        newNode->prev = last;
        last->next = newNode;
    }
    else {
        this->head = newNode;
    }
        
}