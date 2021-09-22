#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int getNumberOfBuses() {
    int numBuses = 0;
    std::cin >> numBuses;
    std::cin.ignore();

    return numBuses;
}

std::vector<int> getBusesArrivalTime() {

    std::vector<int> arrivalTimes;

    std::string line;
    getline(std::cin, line);
    std::istringstream stream(line);

    std::string strTime;
    while (stream >> strTime) {
        arrivalTimes.push_back(stoi(strTime));
    }

    return arrivalTimes;
}

void workOutMostConvinientBus(const std::vector<int>& busesArrivalTime, const int trainLeaveTime) {

    int minWait = INT16_MAX;
    int mostConvinientBus = 0;

    size_t numBuses = busesArrivalTime.size();

    for (size_t i = 0; i < numBuses; i++) {
        int timeToWait = trainLeaveTime - busesArrivalTime[i];
        if (timeToWait >= 0 && timeToWait < minWait) {
            minWait = timeToWait;
            mostConvinientBus = i + 1;
        }
    }

    std::cout << mostConvinientBus << std::endl;
}

int getTrainLeaveTime() {
    std::string strLeaveTime;
    std::cin >> strLeaveTime;
    std::cin.ignore();

    int leaveTime = stoi(strLeaveTime);

    return leaveTime;
}

int main() {

    int numberOfBuses = getNumberOfBuses();

    std::vector<int> busesArrivalTime = getBusesArrivalTime();

    int trainLeaveTime = getTrainLeaveTime();

    workOutMostConvinientBus(busesArrivalTime, trainLeaveTime);

    return 0;
}