enum currency {USDT,PLN};
enum action {buy, sell};

char *currencyNames[] = {(char*)"USDT",(char*)"PLN"};
char *actionNames[] = {(char*)"buy",(char*)"sell"};

struct transaction{
    float price;
    float amount;
    action type;
    currency asset;
    void Print();
    transaction();
    transaction(float,float,action,currency);
};

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