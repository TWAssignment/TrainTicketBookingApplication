#include <iostream>

#include "TicketBookingApplication.hxx"

using namespace std;

int main()
{
	// Create a new instance of TicketBookingApplication
	TicketBookingApplication app;

	// Initialize all the stations.
	app.InitializeStations();

	// Book tickets
	app.BookTicket("Guindy", "Chennai Fort", 25);
	app.BookTicket("Kodambakkam", "Guindy", 30);
	app.BookTicket("Chennai Beach", "Tambaram", 26, true);
	app.BookTicket("Tambaram", "Chennai Fort", 26, false);
	app.BookTicket("Chennai Fort", "Chennai Park", 26);
	app.BookTicket("Chennai Park", "Chennai Fort", 26);

	return 0;
}