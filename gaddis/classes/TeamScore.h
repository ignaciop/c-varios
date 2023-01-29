#ifndef TEAMSCORE_H
#define TEAMSCORE_H

#include <string>

class TeamScore {
    private:
        std::string teamName;
        int wins;
        int ties;
        int losses;
        
    public:
        TeamScore(std::string inputTeamName)
            : teamName(inputTeamName), wins(0), ties(0), losses(0) {};
        
        void updateWins() {
            wins += 1;
        }

        void updateTies() {
            ties += 1;
        }

        void updateLosses() {
            losses += 1;
        }

        void displayRecord();
};

#endif