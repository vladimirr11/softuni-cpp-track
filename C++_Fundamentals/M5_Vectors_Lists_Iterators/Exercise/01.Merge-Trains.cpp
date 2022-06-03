#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include <algorithm>

std::vector<int> getInputTrain() {
    std::vector<int> train;

    std::string line;
    getline(std::cin, line);
    std::istringstream stream(line);

    int currentNumber = 0;
    while (stream >> currentNumber) {
        train.push_back(currentNumber);
    }
    
    return train;
}

void handleFirstTrainIsEmpty(std::vector<int>& secondTrain, std::list<int>& mergedTrain,
                             std::string& trainSeq) {
    mergedTrain.push_front(secondTrain.back());
    trainSeq.push_back('B');       
    secondTrain.pop_back();                     
}

void handleSecondTrainIsEmpty(std::vector<int>& firstTrain, std::list<int>& mergedTrain,
                                std::string& trainSeq) {
    mergedTrain.push_front(firstTrain.back());
    trainSeq.push_back('A');                            
    firstTrain.pop_back();
}

void handleBothTrainsNotEmpty(std::vector<int>& firstTrain, std::vector<int>& secondTrain, 
                              std::list<int>& mergedTrain, std::string& trainSeq) {
    const int firstTrainElement = firstTrain.back();
    const int secondTrainElement = secondTrain.back();

    if (firstTrainElement < secondTrainElement) {
        mergedTrain.push_front(firstTrainElement);
        trainSeq.push_back('A');                            
        firstTrain.pop_back(); 
    } else {
        mergedTrain.push_front(secondTrainElement);
        trainSeq.push_back('B');                            
        secondTrain.pop_back();  
    }
}

void mergeTrains(std::vector<int>& firstTrain, std::vector<int>& secondTrain, 
                 std::list<int>& mergedTrain, std::string& trainSeq) {
    while (true) {
        bool firstTrainEmpty = firstTrain.empty();
        bool secondTrainEmpty = secondTrain.empty();

        if (firstTrainEmpty && secondTrainEmpty) {
            break;
        }

        if (firstTrainEmpty) {
            handleFirstTrainIsEmpty(secondTrain, mergedTrain, trainSeq);
            continue;
        }

        if (secondTrainEmpty) {
            handleSecondTrainIsEmpty(firstTrain, mergedTrain, trainSeq);
            continue;
        }

        handleBothTrainsNotEmpty(firstTrain, secondTrain, mergedTrain, trainSeq);
    }
}

void printResult(const std::list<int>& mergedTrain, const std::string& trainSeq) {
    std::cout << trainSeq << std::endl;
    for (const int railcar: mergedTrain) {
        std::cout << railcar << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> firstTrain = getInputTrain();
    std::vector<int> secondTrain = getInputTrain();

    std::list<int> mergedTrain;
    std::string trainSequence;

    mergeTrains(firstTrain, secondTrain, mergedTrain, trainSequence);

    printResult(mergedTrain, trainSequence);

    return 0;
}
