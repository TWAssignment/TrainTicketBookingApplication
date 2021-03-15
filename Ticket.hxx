#pragma once
#include <string>

using namespace std;

class Ticket
{
private:
	string m_source;
	string m_destination;
	string m_dateTimeStamp;
	int m_numberOfStops;
	double m_journeyFare;
	bool m_isReturn;
	int m_distance;

	// Make default constructor private
	Ticket() = default;

	// Calculate fare for path between source and destination
	double CalculateFare();

public:

	// Parameterized constructor
	Ticket(const string& source, const string& destination, bool isReturn);

	// Sets the journey fare
	void SetFare(double fare);

	// Gets the journey fare
	double GetFare() const;

	// Gets the total number of stops
	int GetNumberOfStops() const;

	// Prints the ticket details
	void PrintTicket();
};