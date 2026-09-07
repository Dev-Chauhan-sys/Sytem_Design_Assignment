#include <iostream>
#include <iomanip>
using namespace std;
class TicketPrinter { public: void print(const Booking& b)const{auto sh=b.getShow();cout<<"\n================ TICKET ================\n"<<"Booking ID : "<<b.getBookingId()<<"\n"<<"Customer   : "<<b.getCustomer()->getName()<<"\n"<<"Movie      : "<<sh->getMovie()->getTitle()<<"\n"<<"Screen     : Screen-"<<sh->getScreen()->getScreenNumber()<<"  "<<sh->getStartTime()<<"\nSeats      : ";bool first=true;for(auto*s:b.getSeats()){if(!first)cout<<", ";cout<<s->getSeat()->getNumber();first=false;}cout<<"\nAmount     : Rs."<<fixed<<setprecision(2)<<b.getTotalAmount()<<"\nStatus     : CONFIRMED\n=========================================\n";} };
