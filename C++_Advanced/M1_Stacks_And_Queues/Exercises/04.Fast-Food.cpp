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

void findTheClientWithBiggestOrder(std::queue<int> ordersQueue) {
    int biggestNumber = std::numeric_limits<int>::min();

    while (!ordersQueue.empty()) {
        int currOrder = ordersQueue.front();
        ordersQueue.pop();
        if (currOrder > biggestNumber) {
            biggestNumber = currOrder;
        }
    }

    std::cout << biggestNumber << std::endl;
}

void serveClients(std::queue<int>& orders, int totalAmountOfFood) {
    bool isFoodEnough = true;
    while (!orders.empty()) {
        int currOrder = orders.front();
        if (currOrder <= totalAmountOfFood) {
            totalAmountOfFood -= currOrder;
            orders.pop();
        } else {
            std::cout << "Orders left: ";
            while (!orders.empty()) {
                std::cout << orders.front();
                orders.pop();
                if (orders.size() > 0) {
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
}

int main() {
    int totalAmountOfFood = 0;
    std::cin >> totalAmountOfFood;
    std::cin.ignore();

    std::queue<int> ordersQueue = getInputOrders();

    findTheClientWithBiggestOrder(ordersQueue);

    serveClients(ordersQueue, totalAmountOfFood);

    return 0;
}
