#include "StationManager.hxx"

/* ------------------------------------------------------------------------------------------------------------- */
void StationManager::ComputeDistances()
{
    auto prevItr = m_stationNoToDistanceMap.begin();
    for (auto itr = m_stationNoToDistanceMap.begin(); itr != m_stationNoToDistanceMap.end(); ++itr)
    {
        if (itr == m_stationNoToDistanceMap.begin())
            continue;
        itr->second += prevItr->second;
        prevItr = itr;
    }
}

/* ------------------------------------------------------------------------------------------------------------- */
StationManager& StationManager::GetInstance()
{
    static StationManager stationManager;
    return stationManager;
}

/* ------------------------------------------------------------------------------------------------------------- */
void StationManager::AddStation(const string& name, int number, int distance)
{
    m_stationNameToStationNumberMap[name] = number;
    m_stationNoToDistanceMap[number] = distance;
}

/* ------------------------------------------------------------------------------------------------------------- */
int StationManager::CalculateNumberOfStops(const string& source, const string& destination)
{
    if(m_stationNameToStationNumberMap.count(source) == 0 || m_stationNameToStationNumberMap.count(destination) == 0)
        return 0;
    return abs(m_stationNameToStationNumberMap[source] - m_stationNameToStationNumberMap[destination]);
}

/* ------------------------------------------------------------------------------------------------------------- */
int StationManager::TotalStops() const
{
    return m_stationNameToStationNumberMap.size();
}

/* ------------------------------------------------------------------------------------------------------------- */
bool StationManager::IsRouteAvailable(const string& source, const string& destination) const
{
    return m_stationNameToStationNumberMap.count(source) != 0 && m_stationNameToStationNumberMap.count(destination) != 0;
}

/* ------------------------------------------------------------------------------------------------------------- */
int StationManager::CalculateDistanceBetweenStops(const string& source, const string& destination)
{
    int sourceNumber = m_stationNameToStationNumberMap[source];
    int destinationNumber = m_stationNameToStationNumberMap[destination];
    int distance = sourceNumber < destinationNumber ? m_stationNoToDistanceMap[destinationNumber] - m_stationNoToDistanceMap[sourceNumber] : m_stationNoToDistanceMap[sourceNumber] - m_stationNoToDistanceMap[destinationNumber];
    return distance;
}
