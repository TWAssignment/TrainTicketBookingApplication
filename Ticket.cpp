#include <iostream>
#include <ctime>

#include "Ticket.hxx"

#include "StationManager.hxx"

/* ------------------------------------------------------------------------------------------------------------- */
double Ticket::CalculateFare()
{
	double fare = 0;
	if (m_numberOfStops == StationManager::GetInstance().TotalStops() - 1)
		fare = 20.0;
	else
	{
		fare = 10.0;
		
		int stations = m_numberOfStops;

		if (stations - 5 > 0)
		{
			stations -= 5;
			fare += (5 * ((stations / 5) + 1));
		}
	}
		
	if (m_isReturn)
		fare *= 1.75;
	return fare;
}

/* ------------------------------------------------------------------------------------------------------------- */
Ticket::Ticket(const string& source, const string& destination, bool isReturn) : m_source(source), m_destination(destination), m_numberOfStops(0), m_isReturn(isReturn), m_journeyFare(0), m_distance(0)
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	string dateTimeStamp = to_string(now->tm_mday) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_year + 1900) + "  " + to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);

	m_dateTimeStamp = dateTimeStamp;
	m_numberOfStops = StationManager::GetInstance().CalculateNumberOfStops(source, destination);
	m_journeyFare = m_numberOfStops ? CalculateFare() : 0.0;
	m_distance = StationManager::GetInstance().CalculateDistanceBetweenStops(source, destination);
}

/* ------------------------------------------------------------------------------------------------------------- */
void Ticket::SetFare(double fare)
{
	m_journeyFare = fare;
}

/* ------------------------------------------------------------------------------------------------------------- */
double Ticket::GetFare() const
{
	return m_journeyFare;
}

/* ------------------------------------------------------------------------------------------------------------- */
int Ticket::GetNumberOfStops() const
{
	return m_numberOfStops;
}

/* ------------------------------------------------------------------------------------------------------------- */
void Ticket::PrintTicket()
{
	cout << "Ticket Booked" << endl;
	cout << "\t" << m_dateTimeStamp << endl;
	cout << "\t" << m_source << endl;
	cout << "\t" << m_destination << endl;
	if (m_isReturn)
	{
		cout << "\t" << m_source << endl;
		cout << "\t" << "Number of stops : "<< m_numberOfStops * 2 << " stops" << endl;
		cout << "\t" << "Distance travelled : " << m_distance * 2 << " kms" << endl;
	}
	else
	{
		cout << "\t" << "Number of stops : " << m_numberOfStops<< " stops" << endl;
		cout << "\t" << "Distance travelled : " << m_distance << " kms" << endl;
	}
	cout << "\t" << "Journey fare : " << m_journeyFare << endl;
	cout << endl;
}
