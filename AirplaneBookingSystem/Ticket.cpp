#include "Ticket.h"
#include <iostream>


std::string Ticket::getAllInfo() const {
    std::string allInfo = "";
    allInfo += "Passenger name: " + passengerName + ";\n";
    allInfo += "Number of the flight: " + std::to_string(flightNo) + ";\n";
    allInfo += "Number of the seat: " + std::to_string(seatNo) + ";\n";
    allInfo += "Date: " + date + ";\n";
    allInfo += "Price: " + std::to_string(price) + ";\n";
    allInfo += "Status: " + status + ";\n";
    return allInfo;
}

