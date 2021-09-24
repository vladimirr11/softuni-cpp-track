#include <iostream>
#include <vector>
#include <deque>

std::deque<std::vector<int>> getInputPetrolDistancePairs(int numStations) {
    std::deque<std::vector<int>> deque;
    for (int i = 0; i < numStations; i++) {
        int petrolAmount, distance;
        std::cin >> petrolAmount >> distance;
        std::vector<int> vec;
        vec.push_back(petrolAmount);
        vec.push_back(distance);
        deque.push_back(vec);
    }

    return deque;
}

int getTheCorrectPetrolStation(std::deque<std::vector<int>>& deque, int numStations) {

    int correctPumpIdx = 0;
    for (int i = 0; i < numStations; i++) {
        bool isValid = true;
        int fuel = 0;

        for (int j = 0; j < numStations; j++) {
            std::vector<int> currPump = deque.front();
            deque.pop_front();
            fuel += currPump[0] - currPump[1];

            if (fuel < 0) {
                isValid = false;
                fuel = 0;
            }

            deque.push_back(currPump);
        }

        if (isValid == true) {
            correctPumpIdx = i;
            break;
        }
        
        std::vector<int> pump = deque.front();
        deque.pop_front();
        deque.push_back(pump);

    }

    return correctPumpIdx;
}

int main() {
    int numStations;
    std::cin >> numStations;

    std::deque<std::vector<int>> deque = getInputPetrolDistancePairs(numStations);

    int pumpIdx = getTheCorrectPetrolStation(deque, numStations);

    std::cout << pumpIdx << std::endl;

    return 0;
}
