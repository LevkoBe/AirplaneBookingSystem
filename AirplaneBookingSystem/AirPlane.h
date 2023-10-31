#pragma once
#include <iostream>
#include "Ticket.h"
#include <vector>

class AirPlane
{
private:
	std::string flights;
	int seatsTotally;
	std::vector<int> bookedSeats;
	std::string planeNumber;
public:
	AirPlane() {};
	AirPlane(const AirPlane& similarPlane) = delete;
	AirPlane(AirPlane&& newPlane) {}; // if a plane crashes all its flights should be moved to a different plane?

	bool FreeAllSeats() {};
	std::vector<int> AllAvailable() {};
	bool CheckAvailability(int seatNo) { return true; };

};

