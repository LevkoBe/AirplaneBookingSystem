#include "Ticket.h"
#include <iostream>


std::string Ticket::getAllInfo() const {
    std::string allInfo = "";
    allInfo += "Passenger name: " + passengerName + ";\n";
    allInfo += "Number of the flight: " + flightNo + ";\n";
    allInfo += "Number of the seat: " + seatNo + ";\n";
    allInfo += "Date: " + date + ";\n";
    allInfo += "Price: " + std::to_string(price) + ";\n";
    allInfo += "Status: " + status + ";\n";
    return allInfo;
}

