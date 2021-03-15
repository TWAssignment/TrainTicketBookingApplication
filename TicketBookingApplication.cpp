#include "TicketBookingApplication.hxx"

/* ------------------------------------------------------------------------------------------------------------- */
TicketBookingApplication::TicketBookingApplication()
{
	m_ticketVendor = new TicketVendor();
}

/* ------------------------------------------------------------------------------------------------------------- */
void TicketBookingApplication::BookTicket(const string& source, const string& destination, int age, bool isReturn)
{
	m_ticketVendor->BookTicket(source, destination, age, isReturn);
}

/* ------------------------------------------------------------------------------------------------------------- */
void TicketBookingApplication::InitializeStations()
{
	StationManager& stationManager = StationManager::GetInstance();
	stationManager.AddStation("Chennai Beach", 1, 0);
	stationManager.AddStation("Chennai Fort", 2, 100);
	stationManager.AddStation("Chennai Park", 3, 50);
	stationManager.AddStation("Chennai Egmore", 4, 20);
	stationManager.AddStation("Chetpet", 5, 70);
	stationManager.AddStation("Nungambakkam", 6, 10);
	stationManager.AddStation("Kodambakkam", 7, 80);
	stationManager.AddStation("Mambalam", 8, 25);
	stationManager.AddStation("Saidapet", 9, 30);
	stationManager.AddStation("Guindy", 10, 120);
	stationManager.AddStation("St. Thomas Mount", 11, 45);
	stationManager.AddStation("Pazhavanthangal", 12, 60);
	stationManager.AddStation("Meenambakkam", 13, 35);
	stationManager.AddStation("Trisulam", 14, 85);
	stationManager.AddStation("Pallavaram", 15, 110);
	stationManager.AddStation("Chromepet", 16, 15);
	stationManager.AddStation("Tambaram Sanatorium", 17, 5);
	stationManager.AddStation("Tambaram", 18, 75);
	stationManager.ComputeDistances();
}
