#include <vector>
using namespace std;
class ShowSeat;
class PriceCalculator { public: double calculate(const vector<ShowSeat*>& seats)const{double total=0;for(auto*s:seats)total+=s->getSeat()->getPrice();return total;} };
