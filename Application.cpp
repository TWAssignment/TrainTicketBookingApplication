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

/*
OUTPUT

Ticket Booked
        15-3-2021  15:14:44
        Guindy
        Chennai Fort
        Number of stops : 8 stops
        Distance travelled : 405 kms
        Journey fare : 15

Ticket Booked
        15-3-2021  15:14:44
        Kodambakkam
        Guindy
        Number of stops : 3 stops
        Distance travelled : 175 kms
        Journey fare : 10

Ticket Booked
        15-3-2021  15:14:44
        Chennai Beach
        Tambaram
        Chennai Beach
        Number of stops : 34 stops
        Distance travelled : 1870 kms
        Journey fare : 35

Ticket Booked
        15-3-2021  15:14:44
        Tambaram
        Chennai Fort
        Number of stops : 16 stops
        Distance travelled : 835 kms
        Journey fare : 25

Ticket Booked
        15-3-2021  15:14:44
        Chennai Fort
        Chennai Park
        Number of stops : 1 stops
        Distance travelled : 50 kms
        Journey fare : 10

Ticket Booked
        15-3-2021  15:14:44
        Chennai Park
        Chennai Fort
        Number of stops : 1 stops
        Distance travelled : 50 kms
        Journey fare : 10

*/
