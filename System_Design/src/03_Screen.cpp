#include <vector>
#include <memory>
#include <string>
using namespace std;
class Seat;
class Screen { private: int number; vector<unique_ptr<Seat>> seats; public: explicit Screen(int number):number(number){} int getScreenNumber()const{return number;} void addSeat(unique_ptr<Seat> seat){seats.push_back(move(seat));} const vector<unique_ptr<Seat>>& getSeats()const{return seats;} Seat* findSeat(const string& n)const; };
