#include "Order.hpp"

Order MakeOrder(std::vector<Ticket> tickets){
    Order order;
    order.tickets = tickets;
    order.totalCount = 0;
    for (auto &ticket : tickets) {
        int price = CheckTicketPrice(ticket);
        order.totalCount += price;
    }
    return order;
};
int CheckSpecificTicketSales(TicketType type,Order order){
    int total = 0;
    for(auto  &ticket: order.tickets){
        if(ticket.type == type){
            total += ticket.count;
        }
    }
    return total;
};
