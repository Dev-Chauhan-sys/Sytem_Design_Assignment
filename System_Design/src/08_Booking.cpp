#include <string>
#include <vector>
using namespace std;
class Customer; class Show; class ShowSeat;
enum class BookingStatus { PENDING, CONFIRMED, FAILED, CANCELLED };
class Booking { private: static int nextId; string id; Customer* customer; Show* show; vector<ShowSeat*> seats; double total; BookingStatus status; public: Booking(Customer*c,Show*s,vector<ShowSeat*> seats,double total):customer(c),show(s),seats(move(seats)),total(total),status(BookingStatus::PENDING){id="BK"+to_string(++nextId);} const string& getBookingId()const{return id;} Customer* getCustomer()const{return customer;} Show* getShow()const{return show;} const vector<ShowSeat*>& getSeats()const{return seats;} double getTotalAmount()const{return total;} BookingStatus getStatus()const{return status;} void confirm(){status=BookingStatus::CONFIRMED;} void fail(){status=BookingStatus::FAILED;} void cancel(){status=BookingStatus::CANCELLED;} };
int Booking::nextId=1000;
