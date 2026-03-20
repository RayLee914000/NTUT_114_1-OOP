#include "Ticket.hpp"
#include <stdexcept>

Ticket MakeTicketOrder(TicketType type){
    Ticket ticket;
    ticket.type = type;
    
    switch (type){
        case TicketType::First:
            ticket.count = 450;
            break;
        case TicketType::Business:
            ticket.count = 325;
            break;
        case TicketType::Economy:
            ticket.count = 200;
            break;
    }
     
    return ticket;
};
int CheckTicketPrice(Ticket ticket){
    int count = 0;
    switch (ticket.type){
        case TicketType::First:
            count = 450;
            break;
        case TicketType::Business:
            count = 325;
            break;
        case TicketType::Economy:
            count = 200;
            break;
        default:
            throw std::invalid_argument("Error");
    }
    if(ticket.count != count){
        throw std::invalid_argument("Error");
    }
    return count;
};
