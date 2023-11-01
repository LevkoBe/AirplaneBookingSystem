#include <iostream>
#include <tuple>
#include "ConfigReader.h"
#include "Flight.h"
#include "Person.h"
#include "AirPlane.h"

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

    while (true) {
        std::cout << "Airplane Booking System\n";
        std::cout << "1. View available seats\n";
        std::cout << "2. Book a ticket\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Select a flight (0-" << flights.size() - 1 << "): ";
            int selectedFlight;
            std::cin >> selectedFlight;
            if (selectedFlight >= 0 && selectedFlight < flights.size()) {
                std::cout << "Available seats for Flight " << flights[selectedFlight].getID() << ":\n";
                std::cout << flights[selectedFlight].availableSeats() << "\n";
            }
            else {
                std::cout << "Invalid flight selection.\n";
            }
            break;

        case 2:
            // Book a ticket
            // Implement the ticket booking process here using Flight and Person classes
            break;

        case 3:
            return 0;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
