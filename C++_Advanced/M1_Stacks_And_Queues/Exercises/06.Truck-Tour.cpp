#include <iostream>
#include <vector>
#include <deque>

std::deque<std::pair<int, int>> getInputPetrolDistancePairs(int numStations) {
    std::deque<std::pair<int, int>> deq;
    for (int i = 0; i < numStations; i++) {
        int petrolAmount {}, distance {};
        std::cin >> petrolAmount >> distance;
        deq.push_back(std::make_pair(petrolAmount, distance));
    }

    return deq;
}

int getTheCorrectPetrolStation(std::deque<std::pair<int, int>>& deq, int numStations) {
    int correctPumpIdx {};
    for (int i = 0; i < numStations; i++) {
        bool isValid = true;

        int fuel = 0;
        for (int j = 0; j < numStations; j++) {
            std::pair<int, int> currPump = deq.front();
            deq.pop_front();

            fuel += currPump.first - currPump.second;

            if (fuel < 0) {
                isValid = false;
                fuel = 0;
            }

            deq.push_back(currPump);
        }

        if (isValid) {
            correctPumpIdx = i;
            break;
        }
        
        std::pair<int, int> pump = deq.front();
        deq.pop_front();
        deq.push_back(pump);
    }

    return correctPumpIdx;
}

int main() {
    int numStations;
    std::cin >> numStations;

    std::deque<std::pair<int, int>> deq = getInputPetrolDistancePairs(numStations);

    int pumpIdx = getTheCorrectPetrolStation(deq, numStations);

    std::cout << pumpIdx << std::endl;

    return 0;
}
