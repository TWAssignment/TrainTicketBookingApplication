#include <unordered_map>
#include <map>
#include <string>

using namespace std;

class StationManager
{
private:

	unordered_map<string, int> m_stationNameToStationNumberMap;
	map<int, int> m_stationNoToDistanceMap;

	// Make constructor private
	StationManager() = default;

	// Delete the Copy constructor and Copy assignment operators
	StationManager(const StationManager& obj) = delete;
	StationManager& operator=(const StationManager& obj) = delete;


public:
	
	// GetInstance returns the singleton object reference
	static StationManager& GetInstance();

	// Adds a station
	void AddStation(const string& name, int number, int distance = 0);

	// Calculates the number of stops between given two stations.
	int CalculateNumberOfStops(const string& source, const string& destination);

	// Calculates the total number of stops
	int TotalStops() const;

	// Checks if route is available between given source and destination
	bool IsRouteAvailable(const string& source, const string& destination) const;

	// Calculate distance between stops
	int CalculateDistanceBetweenStops(const string& source, const string& destination);

	// Compute the subarray sum for all the stations
	void ComputeDistances();
};