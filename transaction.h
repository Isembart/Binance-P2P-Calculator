#ifndef transaction_h
#define transaction_h

enum currency {USDT,PLN};
enum action {buy, sell};

struct transaction{
    float price;
    float amount;
    action type;
    currency asset;
    void Print();
    transaction();
    transaction(float,float,action,currency,float,float);

    //variables for storing account balance
    float usdt,pln;
};

#endif