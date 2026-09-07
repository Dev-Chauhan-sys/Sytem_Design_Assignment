#include <iostream>
using namespace std;
class UpiPayment:public Payment { public: bool pay(double amount)override{this->amount=amount;cout<<"[UPI] Payment successful.\n";return true;} };
class CardPayment:public Payment { public: bool pay(double amount)override{this->amount=amount;cout<<"[CARD] Payment successful.\n";return true;} };
class CashPayment:public Payment { public: bool pay(double amount)override{this->amount=amount;cout<<"[CASH] Payment successful.\n";return true;} };
