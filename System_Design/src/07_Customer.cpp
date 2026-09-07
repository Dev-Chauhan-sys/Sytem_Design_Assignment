#include <string>
using namespace std;
class Customer { private: string name,phone; public: Customer(string name,string phone):name(move(name)),phone(move(phone)){} const string& getName()const{return name;} const string& getPhone()const{return phone;} };
