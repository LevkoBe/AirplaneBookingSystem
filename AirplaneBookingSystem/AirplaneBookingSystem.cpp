#include <iostream>
#include "AirPlane.h"
#include "Ticket.h"
#include "Person.h"

int main() {
    AirPlane airplane;

    Ticket ticket1("John Doe", 1, "Flight001", "2023-01-01", 100, "Booked");
    Ticket ticket2("Jane Smith", 2, "Flight001", "2023-01-01", 100, "Booked");

    Person person("Alice", 500);

    person.gainATicket(ticket1);
    person.gainATicket(ticket2);

    std::cout << "Money balance: $" << person.moneyBalance() << std::endl;

    bool seatAvailable = airplane.CheckAvailability(3);
    if (seatAvailable) {
        std::cout << "Seat 3 is available." << std::endl;
    }
    else {
        std::cout << "Seat 3 is already booked." << std::endl;
    }

    return 0;
}
