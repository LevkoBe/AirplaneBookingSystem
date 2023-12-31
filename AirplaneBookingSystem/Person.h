#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "Ticket.h"


class Person {
private:
	std::string name;
	int age;
	int money;
	std::vector<Ticket> tickets;
public:
	Person(const std::string& name, int money, int age = 20) : name(name), money(money) {
		setAge(age); // while (!setAge(age)) {}
	}

	std::string allInfo() const {
		std::string result = "Mr(s) " + name + " is " + std::to_string(age) + " years old, and has " + std::to_string(money) + " dollars.\n" +
			"He has " + std::to_string(tickets.size()) + " tickets:\n";
		for (const auto& ticket : tickets)
		{
			result += ticket.getAllInfo() + "\n";
		}
		return result;
	}

	std::string getName() const {
		return name;
	}

	std::vector<Ticket> getTickets() const {
		return tickets;
	}

	void setAge(int a) {
		if (a > 0 && a <= 120) {
			age = a;
			return;
		}
		std::cout << "Invalid age!" << std::endl << "Write age again: ";
		std::cin >> a;
		std::cout << std::endl;
		setAge(a);
	}

	void wasteMoney(int amount) {
		money = amount > money ? 0 : money - amount;
	}

	void gainATicket(Ticket& ticket) {
		tickets.push_back(ticket);
	}

	void gainMoney(int amount) {
		money += amount;
	}

	void wasteATicket(Ticket& ticket) {
		for (auto it = tickets.begin(); it != tickets.end(); ++it) {
			if (it->getSeatNo() == ticket.getSeatNo() && it->getFlightNo() == ticket.getFlightNo()) {
				tickets.erase(it);
				return;
			}
		}
		std::cout << "Ticket not found." << std::endl;
	}


	int moneyBalance() const {
		return money;
	}
};


