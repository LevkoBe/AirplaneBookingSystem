#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<Ticket>


class Person {
private:
	std::string name;
	int age;
	std::vector<
public:
	Person(const std::string& n, int a) : name(n), age(a) {}
	// Getter method for the name
	std::string getName() const {
		return name;
	}
	// Setter method for the age
	void setAge(int a) {
		if (a >= 0 && a <= 120) {
			age = a;
		}
		else {
			std::cout << "Invalid age!" << std::endl;
		}
	}
};


