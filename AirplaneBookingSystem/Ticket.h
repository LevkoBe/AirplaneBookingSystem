#pragma once
#include <iostream>
#include <string>

class Ticket
{
public:
    Ticket() : passengerName(""), seatNo(""), flightNo(""), date(""), price(0), status("") {}
    Ticket(const std::string& passengerName, const std::string seatNo, const std::string flightNo, const std::string& date, const int price, const std::string& status)
        : passengerName(passengerName), seatNo(seatNo), flightNo(flightNo), date(date), price(price), status(status) { };
    //Ticket(Ticket&& ticketToCopyTo) = delete;

    std::string getAllInfo() const;
    const std::string& getPassengerName() const { return passengerName; }
    std::string getSeatNo() const { return seatNo; }
    std::string getFlightNo() const { return flightNo; }
    const std::string& getDate() const { return date; }
    int getPrice() const { return price; }
    const std::string& getStatus() const { return status; }

private:
    std::string passengerName;
    std::string seatNo;
    std::string flightNo;
    std::string date;
    int price;
    std::string status;
};
