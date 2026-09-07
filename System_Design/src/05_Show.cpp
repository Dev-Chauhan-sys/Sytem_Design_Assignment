#include <vector>
#include <memory>
#include <string>
using namespace std;
class Movie; class Screen; class ShowSeat;
class Show { private: Movie* movie; Screen* screen; string time; vector<unique_ptr<ShowSeat>> seats; public: Show(Movie*m,Screen*s,string t):movie(m),screen(s),time(move(t)){} Movie* getMovie()const{return movie;} Screen* getScreen()const{return screen;} const string& getStartTime()const{return time;} void createShowSeats(); ShowSeat* findShowSeat(const string&)const; const vector<unique_ptr<ShowSeat>>& getShowSeats()const{return seats;} };
