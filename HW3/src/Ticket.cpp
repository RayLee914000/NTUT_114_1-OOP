#include "Ticket.hpp"
#include <stdexcept>

using namespace std;
 Ticket::Ticket(std::string dest, std::string src, int range, int trainNumber,
               TrainType type) {
     this->dest = dest;
     this->src = src;
     this->range = range;
     this -> price = 0;
     this->trainNumber = trainNumber;
     this->type = type;
}

std::string Ticket::GetDest() {
     return dest;
 }
std::string  Ticket::GetSrc() {
    return src;
}
int Ticket::GetPrice() {
    return price;
}
int  Ticket::GetTrainNumber() {
    return trainNumber;
}
TrainType Ticket::GetTrainType() {
    return type;
}
void Ticket::CalculateTicketPrice() {
     if (range < 0) throw invalid_argument("");
     price = range * 2;
     if (type == TrainType::Limited) price *= 1.2;
     if (type == TrainType::Express) price = price * 1.4 + floor(range / 100) * 25;
}