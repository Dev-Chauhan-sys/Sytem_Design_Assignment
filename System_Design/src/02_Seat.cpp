#include <string>
using namespace std;
enum class SeatType { SILVER, GOLD, PLATINUM };
class Seat { private: string number; SeatType type; public: Seat(string number,SeatType type):number(number),type(type){} const string& getNumber()const{return number;} SeatType getType()const{return type;} int getPrice()const{constexpr int SILVER_PRICE=150,GOLD_PRICE=250,PLATINUM_PRICE=400; if(type==SeatType::SILVER)return SILVER_PRICE; if(type==SeatType::GOLD)return GOLD_PRICE; return PLATINUM_PRICE;} string typeName()const{if(type==SeatType::SILVER)return "SILVER";if(type==SeatType::GOLD)return "GOLD";return "PLATINUM";} };
