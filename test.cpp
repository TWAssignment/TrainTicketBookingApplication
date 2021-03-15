#include "pch.h"
#include "TicketBookingApplication.hxx"
#include "InfantFareCalculator.hxx"
#include "ChildFareCalculator.hxx"
#include "AdultFareCalculator.hxx"

/* --------------------------------------------------------------------------------------------------
										Station Manager Suite
---------------------------------------------------------------------------------------------------- */
TEST(StationManagerSuite, CheckAddStopsApi) 
{
	auto& stationMgr = StationManager::GetInstance();
	int totalStops = stationMgr.TotalStops();

	// Initially since there are no stations, total stops should be 0;
	EXPECT_EQ(totalStops, 0);
	EXPECT_TRUE(true);

	// Add 1 station
	stationMgr.AddStation("Pune", 1, 0);
	totalStops = stationMgr.TotalStops();
	// Total stops should return 1
	EXPECT_EQ(totalStops, 1);
	EXPECT_TRUE(true);

}

TEST(StationManagerSuite, CheckNumberOfStopsApi)
{
	auto& stationMgr = StationManager::GetInstance();
	stationMgr.AddStation("Goa", 2, 300);
	stationMgr.AddStation("Banglore", 3, 800);
	stationMgr.AddStation("Coimbtore", 4, 2000);

	int numberOfStops = stationMgr.CalculateNumberOfStops("Pune", "Banglore");
	// Total stops between Pune and Banglore should be 2
	EXPECT_EQ(numberOfStops, 2);
	EXPECT_TRUE(true);

	numberOfStops = stationMgr.CalculateNumberOfStops("Coimbtore", "Pune");
	// Total stops between Coimbtore and Pune should be 3
	EXPECT_EQ(numberOfStops, 3);
	EXPECT_TRUE(true);
}

TEST(StationManagerSuite, CheckDistanceCalculationApi)
{
	auto& stationMgr = StationManager::GetInstance();
	stationMgr.ComputeDistances();

	int distance = stationMgr.CalculateDistanceBetweenStops("Goa", "Coimbtore");
	// Distance between Goa and Coimbtore should be 2800
	EXPECT_EQ(distance, 2800);
	EXPECT_TRUE(true);

	distance = stationMgr.CalculateDistanceBetweenStops("Banglore", "Pune");
	// Distance between Banglore and Pune should be 1100
	EXPECT_EQ(distance, 1100);
	EXPECT_TRUE(true);
}

/* --------------------------------------------------------------------------------------------------
									Ticket Suite
---------------------------------------------------------------------------------------------------- */
TEST(TicketSuite, ValidateTicket)
{
	Ticket t("Goa", "Coimbtore", false);

	int numberOfStops = t.GetNumberOfStops();
	// Number of stops between Goa and Coimbtore should be 2
	EXPECT_EQ(numberOfStops, 2);
	EXPECT_TRUE(true);

	double fare = t.GetFare();
	// Basic fare should be 10
	EXPECT_DOUBLE_EQ(fare, 10.0);
	EXPECT_TRUE(true);

}

/* --------------------------------------------------------------------------------------------------
									Fare Calculator Suite
---------------------------------------------------------------------------------------------------- */
TEST(FareCalculatorSuite, CheckInfantFareCalculator)
{
	Ticket t("Goa", "Coimbtore", false);
	
	double fare = t.GetFare();
	// Basic fare should be 10
	EXPECT_DOUBLE_EQ(fare, 10.0);
	EXPECT_TRUE(true);

	InfantFareCalculator* infant = new InfantFareCalculator;
	infant->CalculateFare(&t);
	fare = t.GetFare();
	// Fare should be expemted
	EXPECT_DOUBLE_EQ(fare, 0.0);
	EXPECT_TRUE(true);
}

TEST(FareCalculatorSuite, CheckChildFareCalculator)
{
	Ticket t("Goa", "Coimbtore", false);

	double fare = t.GetFare();
	// Basic fare should be 10
	EXPECT_DOUBLE_EQ(fare, 10.0);
	EXPECT_TRUE(true);

	ChildFareCalculator* child = new ChildFareCalculator;
	child->CalculateFare(&t);
	fare = t.GetFare();
	// Fare should be 0.75 times basic fare i.e. 7.5
	EXPECT_DOUBLE_EQ(fare, 7.5);
	EXPECT_TRUE(true);
}

TEST(FareCalculatorSuite, CheckAdultFareCalculator)
{
	Ticket t("Goa", "Coimbtore", false);

	double fare = t.GetFare();
	// Basic fare should be 10
	EXPECT_DOUBLE_EQ(fare, 10.0);
	EXPECT_TRUE(true);

	AdultFareCalculator* adult = new AdultFareCalculator;
	adult->CalculateFare(&t);
	fare = t.GetFare();
	// No exemptions for adults
	EXPECT_DOUBLE_EQ(fare, 10.0);
	EXPECT_TRUE(true);
}

/*
OUTPUT

Running main() from c:\a\_work\32\s\thirdparty\googletest\googletest\src\gtest_main.cc
[==========] Running 7 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from StationManagerSuite
[ RUN      ] StationManagerSuite.CheckAddStopsApi
[       OK ] StationManagerSuite.CheckAddStopsApi (0 ms)
[ RUN      ] StationManagerSuite.CheckNumberOfStopsApi
[       OK ] StationManagerSuite.CheckNumberOfStopsApi (0 ms)
[ RUN      ] StationManagerSuite.CheckDistanceCalculationApi
[       OK ] StationManagerSuite.CheckDistanceCalculationApi (0 ms)
[----------] 3 tests from StationManagerSuite (1 ms total)

[----------] 1 test from TicketSuite
[ RUN      ] TicketSuite.ValidateTicket
[       OK ] TicketSuite.ValidateTicket (0 ms)
[----------] 1 test from TicketSuite (1 ms total)

[----------] 3 tests from FareCalculatorSuite
[ RUN      ] FareCalculatorSuite.CheckInfantFareCalculator
[       OK ] FareCalculatorSuite.CheckInfantFareCalculator (0 ms)
[ RUN      ] FareCalculatorSuite.CheckChildFareCalculator
[       OK ] FareCalculatorSuite.CheckChildFareCalculator (0 ms)
[ RUN      ] FareCalculatorSuite.CheckAdultFareCalculator
[       OK ] FareCalculatorSuite.CheckAdultFareCalculator (0 ms)
[----------] 3 tests from FareCalculatorSuite (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 3 test cases ran. (4 ms total)
[  PASSED  ] 7 tests.

*/
