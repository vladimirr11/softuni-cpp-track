#include <iostream>
#include <queue>

std::queue<int> getInputStack(int number) {

    std::queue<int> queue;
    for (int i = 0; i < number; i++) {
        int currNumber = 0;
        std::cin >> currNumber;
        queue.push(currNumber);
    }

    return queue;
}

std::queue<int> popNElementsFromStack(std::queue<int>& queue, int N) {

    for (int i = 0; i < N; i++) {
        queue.pop();
    }

    return queue;
}

void findTarget(std::queue<int>& queue, int target) {

    int minElem = INT16_MAX;
    bool flag = false;
    while (!queue.empty()) {
        int currNum = queue.front();
        queue.pop();

        if (currNum == target) {
            flag = true;
            break;
        } else {
            if (currNum < minElem) {
                minElem = currNum;
            }
        }
    }
    
    if (flag == true) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << minElem << std::endl;
    }

}

int main() {
    int numOfElemToPush = 0, numOfElemToPop = 0, target = 0;
    std::cin >> numOfElemToPush >> numOfElemToPop >> target;

    std::queue<int> queue = getInputStack(numOfElemToPush);

    popNElementsFromStack(queue, numOfElemToPop);

    if (queue.empty()) {
        std::cout << 0 << std::endl;
    } else {
        findTarget(queue, target);
    }

    return 0;
}
