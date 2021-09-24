#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <limits>

std::queue<int> getInputOrders() {
    std::queue<int> orders;

    std::string line;
    getline(std::cin, line);
    std::istringstream stream(line);

    int currNumber = 0;
    while (stream >> currNumber) {
        orders.push(currNumber);
    }

    return orders;
}

void findTheClientWithBiggestOrder(std::queue<int>& ordersQueue) {
    int biggestNumber = std::numeric_limits<int>::min();

    std::queue<int> ordersQueueCopy = ordersQueue;
    while (!ordersQueueCopy.empty()) {
        int currOrder = ordersQueueCopy.front();
        ordersQueueCopy.pop();
        if (currOrder > biggestNumber) {
            biggestNumber = currOrder;
        }
    }

    std::cout << biggestNumber << std::endl;
}

int main() {
    int totalAmountOfFood = 0;
    std::cin >> totalAmountOfFood;
    std::cin.ignore();

    std::queue<int> ordersQueue = getInputOrders();

    findTheClientWithBiggestOrder(ordersQueue);

    bool isFoodEnough = true;
    while (!ordersQueue.empty()) {
        int currOrder = ordersQueue.front();
        if (currOrder <= totalAmountOfFood) {
            totalAmountOfFood -= currOrder;
            ordersQueue.pop();
        } else {
            std::cout << "Orders left: ";
            while (!ordersQueue.empty()) {
                std::cout << ordersQueue.front();
                ordersQueue.pop();
                if (ordersQueue.size() > 0) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
            isFoodEnough = false;
        }
    }

    if (isFoodEnough) {
        std::cout << "Orders complete" << std::endl;
    }

    return 0;
}
