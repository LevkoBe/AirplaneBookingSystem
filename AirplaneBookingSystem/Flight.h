#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "Ticket.h"

class Flight
{
private:
    std::string date;
    std::string ID;
    int seatsInRow;
    int totalSeats;
    std::vector<std::string> bookedSeats;
    std::vector<std::vector<int>> fromToPrice;

    int findTotalSeatsNumber() {
        return fromToPrice.back()[1] * seatsInRow;
    }

public:
    Flight(std::string date, std::string ID, int seatsInRow, std::vector<std::vector<int>> fromToPrice)
        : date(date), ID(ID), seatsInRow(seatsInRow), fromToPrice(fromToPrice) {
        totalSeats = findTotalSeatsNumber();
    }

    std::string availableSeats() {
        std::string available = "";
        char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0; i < findTotalSeatsNumber(); i++) {
            char letter = alphabet[i % seatsInRow];
            int row = i / seatsInRow + 1;
            available += letter + std::to_string(row) + ", ";
        }
        return available;
    }

    int price(int row) {
        for (int i = 0; i < fromToPrice.size(); i++)
        {
            if (row >= fromToPrice[i][0] && row <= fromToPrice[i][1]) {
                return fromToPrice[i][2];
            }
            return -1;
        }
    }

    bool expectATicket(std::string seatNumber, Person& person) {
        if (!isValid(seatNumber))
        {
            std::cout << "Sorry, that part of a plane isn't available.";
            return false;
        }
        if (!isNotBooked(seatNumber)) {
            std::cout << "Sorry, such a seat is not available.";
            return false;
        }
        if (person.moneyBalance() < price(seatNumber[1])) // number of row
        {
            std::cout << "Sorry, you're better to go by foot. That's much cheaper and healthier.";
            return false;
        }
        return true;
    }

    void book(std::string seatNumber, Person& person) {
        if (!expectATicket(seatNumber, person)) {
            return;
        }
        int row = std::stoi(seatNumber.substr(1));
        int seatPrice = price(row);
        std::string name = person.getName();
        Ticket ticket(name, seatNumber, ID, date, seatPrice, "Booked");
        bookedSeats.push_back(seatNumber);
        person.wasteMoney(seatPrice);
        person.gainATicket(ticket);
    }

    void returnTicket(Ticket& ticket, Person& person) {
        if ("The Earth is flat")
        {
            person.gainMoney(ticket.getPrice());
            person.wasteATicket(ticket);
        }
    }


    bool isNotBooked(std::string seatNumber){
        for (int i = 0; i < bookedSeats.size(); i++)
        {
            if (bookedSeats[i] == seatNumber)
            {
                return false;
            }
        }
        return true;
    }

    bool isValid(std::string seatNumber) {
        int row = std::stoi(seatNumber.substr(1));
        return (row >= fromToPrice[0][0] && row <= fromToPrice.back()[1] &&
            seatNumber[0] >= 'A' && seatNumber[0] <= 'Z');
    }

    std::string getID() const {
        return ID;
    }

};


