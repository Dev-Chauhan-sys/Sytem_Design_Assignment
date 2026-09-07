#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <limits>
using namespace std;
#include "src/01_Movie.cpp"
#include "src/02_Seat.cpp"
#include "src/03_Screen.cpp"
#include "src/04_Cinema.cpp"
#include "src/06_ShowSeat.cpp"
#include "src/05_Show.cpp"
#include "src/07_Customer.cpp"
#include "src/08_Booking.cpp"
#include "src/09_Payment.cpp"
#include "src/10_PaymentTypes.cpp"
#include "src/11_PriceCalculator.cpp"
#include "src/12_TicketPrinter.cpp"
#include "src/13_BookingService.cpp"

Seat* Screen::findSeat(const string& n)const{for(auto& s:seats)if(s->getNumber()==n)return s.get();return nullptr;}
Screen* Cinema::getScreen(int n)const{for(auto& s:screens)if(s->getScreenNumber()==n)return s.get();return nullptr;}
void Show::createShowSeats(){for(auto& s:screen->getSeats())seats.push_back(make_unique<ShowSeat>(s.get()));}
ShowSeat* Show::findShowSeat(const string& n)const{for(auto& s:seats)if(s->getSeat()->getNumber()==n)return s.get();return nullptr;}

static void addSeats(Screen& s){s.addSeat(make_unique<Seat>("A1",SeatType::SILVER));s.addSeat(make_unique<Seat>("A2",SeatType::SILVER));s.addSeat(make_unique<Seat>("A3",SeatType::SILVER));s.addSeat(make_unique<Seat>("A4",SeatType::SILVER));s.addSeat(make_unique<Seat>("B1",SeatType::GOLD));s.addSeat(make_unique<Seat>("B2",SeatType::GOLD));s.addSeat(make_unique<Seat>("B3",SeatType::GOLD));s.addSeat(make_unique<Seat>("B4",SeatType::GOLD));s.addSeat(make_unique<Seat>("C1",SeatType::PLATINUM));s.addSeat(make_unique<Seat>("C2",SeatType::PLATINUM));}
int main(){Cinema cinema("PVR Cinema");auto s1=make_unique<Screen>(1);addSeats(*s1);cinema.addScreen(move(s1));auto s2=make_unique<Screen>(2);addSeats(*s2);cinema.addScreen(move(s2));vector<unique_ptr<Movie>> movies;movies.push_back(make_unique<Movie>("3 Idiots","Hindi",170));movies.push_back(make_unique<Movie>("Interstellar","English",169));vector<unique_ptr<Show>> shows;shows.push_back(make_unique<Show>(movies[0].get(),cinema.getScreen(1),"06:00 PM"));shows.push_back(make_unique<Show>(movies[0].get(),cinema.getScreen(2),"09:00 PM"));shows.push_back(make_unique<Show>(movies[1].get(),cinema.getScreen(1),"07:30 PM"));for(auto& s:shows)s->createShowSeats();Customer customer("Badal Singh","9999999999");BookingService service;vector<Booking*> bookings;while(true){cout<<"\n===== MOVIE TICKET BOOKING =====\n1. Movies  2. Book  3. Cancel  4. My tickets  0. Exit\nChoose: ";int ch;if(!(cin>>ch)){cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');cout<<"Invalid menu choice.\n";continue;}cin.ignore(numeric_limits<streamsize>::max(),'\n');if(ch==0)break;if(ch==1){for(size_t i=0;i<movies.size();++i)cout<<"["<<i+1<<"] "<<movies[i]->getTitle()<<" | "<<movies[i]->getLanguage()<<" | "<<movies[i]->getDuration()<<" min\n";}else if(ch==2){cout<<"[1] 3 Idiots\n[2] Interstellar\nChoose movie: ";int m;cin>>m;cin.ignore(numeric_limits<streamsize>::max(),'\n');if(m<1||m>(int)movies.size()){cout<<"Invalid movie choice.\n";continue;}vector<Show*> ms;for(auto& s:shows)if(s->getMovie()==movies[m-1].get()){ms.push_back(s.get());cout<<"["<<ms.size()<<"] Screen-"<<s->getScreen()->getScreenNumber()<<" "<<s->getStartTime()<<"\n";}cout<<"Choose show: ";int si;cin>>si;cin.ignore(numeric_limits<streamsize>::max(),'\n');if(si<1||si>(int)ms.size()){cout<<"Invalid show choice.\n";continue;}cout<<"Seats: A1,A2,B1,B2,C1,C2 (available initially)\nSeats: ";string input;getline(cin,input);cout<<"Pay by: 1.UPI 2.Card 3.Cash: ";int p;cin>>p;cin.ignore(numeric_limits<streamsize>::max(),'\n');unique_ptr<Payment> pay;if(p==1)pay=make_unique<UpiPayment>();else if(p==2)pay=make_unique<CardPayment>();else if(p==3)pay=make_unique<CashPayment>();else{cout<<"Invalid payment choice.\n";continue;}Booking* b=service.book(customer,*ms[si-1],input,*pay);if(b)bookings.push_back(b);}else if(ch==3){if(bookings.empty()){cout<<"No bookings.\n";continue;}cout<<"Booking number: ";int bi;cin>>bi;cin.ignore(numeric_limits<streamsize>::max(),'\n');if(bi<1||bi>(int)bookings.size()){cout<<"Invalid booking choice.\n";continue;}service.cancel(bookings[bi-1]);}else if(ch==4){for(auto*b:bookings)if(b->getStatus()==BookingStatus::CONFIRMED)TicketPrinter().print(*b);}else cout<<"Invalid menu choice.\n";}for(auto*b:bookings)delete b;return 0;}
