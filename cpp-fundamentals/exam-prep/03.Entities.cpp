#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<std::string> getRowContent() {
    std::vector<std::string> vec;
    std::string line;
    getline(std::cin, line);
    std::istringstream stream(line);

    std::string word;
    while (stream >> word) {
        vec.push_back(word);
    }

    return vec;
}

std::vector<std::vector<std::string>> getDataBase(size_t numberOfColumns) {

    std::vector<std::vector<std::string>> database(numberOfColumns);
    std::vector<std::string> currentRow;

    std::string delimiter = "end";
    while (true) {
        currentRow = getRowContent();
        if (currentRow[0] == delimiter) {
            break;
        }

        for (size_t i = 0; i < numberOfColumns; i++) {
            database[i].push_back(currentRow[i]);
        }
    }

    return database;
}

void printMostCommonElement(const std::vector<std::vector<std::string>>& db,
                            const std::vector<std::string>& columnNames,
                            std::string query) {

    int idx = 0;
    size_t size = columnNames.size();
    for (size_t i = 0; i < size; i++) {
        if (columnNames[i] == query) {
            idx = i;
            break;
        }
    }

    std::vector<std::string> targetColumn = db[idx];
    std::sort(targetColumn.begin(), targetColumn.end());

    int countMostCommonElement = 1;
    int currentCounter = 1;
    size_t maxCountIndx = 0;
    
    const size_t colLength = targetColumn.size();
    for (size_t i = 1; i < colLength; i++) {
        if (targetColumn[i] == targetColumn[i - 1]) {
            currentCounter++;
            if (currentCounter > countMostCommonElement) {
                countMostCommonElement = currentCounter;
                maxCountIndx = i;
            }
        } else {
            currentCounter = 1;
        }
    }

    std::cout << targetColumn[maxCountIndx] << " " << countMostCommonElement << std::endl;
}

int main() {

    const std::vector<std::string> columnNames = getRowContent();
    const std::vector<std::vector<std::string>> db = getDataBase(columnNames.size());
    const std::string query = getRowContent()[0];

    printMostCommonElement(db, columnNames, query);

    return 0;
}