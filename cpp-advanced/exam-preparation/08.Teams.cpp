#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

std::map<std::string, std::vector<std::string>> readInputTeams() {
    int numTeams = 0;
    std::cin >> numTeams;

    std::map<std::string, std::vector<std::string>> teamsMap {};

    for (int i = 0; i < numTeams; i++) {
        std::string currTeamName;
        int numPlayers = 0;
        std::cin >> currTeamName >> numPlayers;

        for (int j = 0; j < numPlayers; j++) {
            std::string currPlayerName;
            std::cin >> currPlayerName;
            teamsMap[currTeamName].push_back(currPlayerName);
        }   
    }

    return teamsMap;
}

std::vector<std::string> readWinnerTeams() {
    int numWins = 0;
    std::cin >> numWins;

    std::vector<std::string> winnersVec {};

    for (int i = 0; i < numWins; i++) {
        std::string winner;
        std::cin >> winner;

        winnersVec.push_back(winner);
    }
    
    return winnersVec;
}

std::map<std::string, int> makePlayersMap(std::map<std::string, std::vector<std::string>>& teamsMap) {
    
    std::map<std::string, int> playersMap {};
     for (const auto& team : teamsMap) {
        for (const auto& player : team.second) {
            playersMap[player] = 0;
        }
    }

    return playersMap;
}

void prepareSolutionAndPrintResult(std::map<std::string, std::vector<std::string>>& teamsMap, 
                                   std::vector<std::string>& winnersVec, 
                                   std::map<std::string, int>& playersMap) {
                    
    for (const auto winner : winnersVec) {
        for (auto player : teamsMap[winner]) {
            playersMap[player]++;
        }
    }

    for (const auto pl : playersMap) {
        std::cout << pl.second << " ";
    }
    std::cout << std::endl;

}

int main() {
    std::map<std::string, std::vector<std::string>> teamsMap = readInputTeams();

    std::vector<std::string> winnersVec = readWinnerTeams();

    std::map<std::string, int> playersMap = makePlayersMap(teamsMap);

    prepareSolutionAndPrintResult(teamsMap, winnersVec, playersMap);

    return 0;
}
