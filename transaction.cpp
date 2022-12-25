#include <iostream>
#include "transaction.h"

const char *currencyNames[] = {(char*)"USDT",(char*)"PLN"};
const char *actionNames[] = {(char*)"buy",(char*)"sell"};

//TRANSACTION
void transaction::Print() {
    std::cout << (char*)actionNames[type] << " "<< amount << " "<<(char*)currencyNames[asset] << " for "<< price << " Balance: pln:"<<pln<<" usdt:"<<usdt <<std::endl;
}

transaction::transaction() {
    this->price = 0;
    this->amount = 0;
    this->type = buy;
    this->asset = USDT;
    this->pln=0;
    this->usdt=0;
}

transaction::transaction(float p,float a,action t,currency as,float us,float pl) {
    this->price = p;
    this->amount = a;
    this->type = t;
    this->asset = as;
    this->usdt=  us;
    this->pln = pl;
}