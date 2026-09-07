class Seat;
enum class SeatStatus { AVAILABLE, BOOKED };
class ShowSeat { private: Seat* seat; SeatStatus status; public: explicit ShowSeat(Seat*s):seat(s),status(SeatStatus::AVAILABLE){} Seat* getSeat()const{return seat;} bool isAvailable()const{return status==SeatStatus::AVAILABLE;} bool book(){if(!isAvailable())return false;status=SeatStatus::BOOKED;return true;} void release(){status=SeatStatus::AVAILABLE;} };
