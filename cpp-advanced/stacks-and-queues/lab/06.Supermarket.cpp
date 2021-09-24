#include <iostream>
#include <string>
#include <sstream>
#include <queue>

int main() {    
    std::queue<std::string> queue;

    while (true) {
        std::string person;
        std::cin >> person;

        if (person == "Paid") {
            while (!queue.empty()) {
                std::cout << queue.front() << std::endl;
                queue.pop();
            }
        } else if (person == "End") {
            break;
        } else {
            queue.push(person);
        }
    }

    size_t queueLength = queue.size();

    std::cout << queueLength << " people remaining." << std::endl;

    return 0;
}
