#include <iostream>
#include <string>
#include <tuple>
#include "ConfigReader.h"
#include "Flight.h"
#include "Person.h"

int main() {

    ConfigReader configReader;
    std::string configFileContent = configReader.ReadFile("configs.txt");

    std::istringstream contentStream(configFileContent);
    std::string configString;
    std::vector<Flight> flights;

    while (std::getline(contentStream, configString)) {
        auto configData = configReader.ParseConfiguration(configString);
        std::string date;
        std::string ID;
        int seatsInRow;
        std::vector<std::vector<int>> fromToPrice;

        std::tie(date, ID, seatsInRow, fromToPrice) = configData;

        Flight flight(date, ID, seatsInRow, fromToPrice);
        flights.push_back(flight);
    }

    std::vector<Person> people;

    std::string command;
    while (true) {
        std::cout << "Enter a command (e.g., 'person John 1000', 'book John FQ12 A1', 'return John FQ12 A1', 'info ticket A1', 'info person John', '-'): \n";
        std::cin >> command;

        if (command == "person") {
            std::string name;
            int money;
            std::cin >> name >> money;

            bool personExists = false;
            for (auto& person : people) {
                if (person.getName() == name) {
                    personExists = true;
                    if (money > 0) {
                        person.gainMoney(money);
                        std::cout << "+\n";
                    }
                    else {
                        person.wasteMoney(-money);
                        std::cout << "-\n";
                    }
                    break;
                }
            }

            if (!personExists) {
                Person newPerson(name, money);
                people.push_back(newPerson);
                std::cout << "++\n";
            }
        }

        else if (command == "book") {
            std::string name, flightID, seatNumber;
            std::cin >> name >> flightID >> seatNumber;

            Person* personToBook = nullptr;
            for (auto& person : people) {
                if (person.getName() == name) {
                    personToBook = &person;
                    break;
                }
            }

            Flight* flightToBook = nullptr;
            for (auto& flight : flights) {
                if (flight.getID() == flightID) {
                    flightToBook = &flight;
                    break;
                }
            }

            if (personToBook && flightToBook) {
                flightToBook->book(seatNumber, *personToBook);
            }
            else {
                std::cout << "Person or flight not found. Please check the name and flight ID." << std::endl;
            }
        }

        else if (command == "return") {
            std::string name, flightID, seatNumber;
            std::cin >> name >> flightID >> seatNumber;

            Person* personToReturn = nullptr;
            for (auto& person : people) {
                if (person.getName() == name) {
                    personToReturn = &person;
                    break;
                }
            }

            Flight* flightToReturn = nullptr;
            for (auto& flight : flights) {
                if (flight.getID() == flightID) {
                    flightToReturn = &flight;
                    break;
                }
            }

            if (personToReturn && flightToReturn) {
                Ticket ticketToReturn;
                for (auto& ticket : personToReturn->getTickets()) {
                    if (ticket.getFlightNo() == flightID && ticket.getSeatNo() == seatNumber) {
                        ticketToReturn = ticket;
                        break;
                    }
                }

                if (ticketToReturn.getSeatNo() == seatNumber) {
                    flightToReturn->returnTicket(ticketToReturn, *personToReturn);
                }
                else {
                    std::cout << "Ticket not found for the provided seat number and flight ID." << std::endl;
                }
            }
            else {
                std::cout << "Person or flight not found. Please check the name and flight ID." << std::endl;
            }
        }
        else if (command == "info") {
            std::cin >> command;
            if (command == "person") {
                std::string name;
                std::cin >> name;

                Person* personToCheck = nullptr;
                for (auto& person : people) {
                    if (person.getName() == name) {
                        personToCheck = &person;
                        break;
                    }
                }
                std::cout << personToCheck->allInfo();
            }
            else if (command == "ticket") {
                std::string seatNumber;
                std::cin >> seatNumber;

                for (const auto& person : people) {
                    for (const auto& ticket : person.getTickets()) {
                        if (ticket.getSeatNo() == seatNumber) {
                            std::cout << ticket.getAllInfo() << std::endl;
                            break;
                        }
                    }
                }
            }
        }
        else if (command[0] == '-')
        {
            return 0;
        }
        else {
            std::cout << "Invalid command. Please enter a valid command." << std::endl;
        }

    }

    return 0;
}
