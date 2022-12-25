#ifndef TransactionList_H
#define TransactionList_H
#include "transaction.h"


struct TransactionListNode {
    transaction* _transaction;
    TransactionListNode* prev;
    TransactionListNode* next;
    TransactionListNode(transaction*);
};

struct TransactionList {
    TransactionListNode* head;
    TransactionList();
    void PrintList();
    TransactionListNode* GetLast();
    void AddTransaction(transaction);
    
};
#endif