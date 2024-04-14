

#include <iostream>
#include <string>
#include <map>
#include <vector>

// Player 
struct Player {
    std::string name;
    float strength;
};

// Function to get the number of players in a clan by name
int GetPlayerCount(const std::string& ClanName, const std::map<std::string, std::vector<Player>>& clans) {
    auto it = clans.find(ClanName);
    if (it != clans.end()) {
        return it->second.size(); // Return the size of the vector of players for the clan
    }
    else {
        return 0; // Clan not found
    }
}

// Function to compare the total strength of two clans
int ClanFight(const std::string& FirstClanName, const std::string& SecondClanName, const std::map<std::string, std::vector<Player>>& clans) {
    float firstClanStrength = 0, secondClanStrength = 0;

    auto it1 = clans.find(FirstClanName);
    if (it1 != clans.end()) {
        for (const auto& player : it1->second) {
            firstClanStrength += player.strength;
        }
    }

    auto it2 = clans.find(SecondClanName);
    if (it2 != clans.end()) {
        for (const auto& player : it2->second) {
            secondClanStrength += player.strength;
        }
    }

    std::cout << "First Clan Strength: " << firstClanStrength << std::endl;
    std::cout << "Second Clan Strength: " << secondClanStrength << std::endl;

    if (firstClanStrength > secondClanStrength) {
        return 1; // first clan wins
    }
    else if (firstClanStrength < secondClanStrength) {
        return -1; // second clan wins
    }
    else {
        return 0; // tie
    }
}

int main() {
    std::map<std::string, std::vector<Player>> clans;

    // Read comands from the console
    while (true) {
        std::string clanName, playerName;
        float playerStrength;

        std::cout << "Enter clan name (or type 'exit' to finish): ";
        std::cin >> clanName;

        if (clanName == "exit") {
            break;
        }

        std::cout << "Enter player name: ";
        std::cin >> playerName;

        std::cout << "Enter player strength: ";
        std::cin >> playerStrength;

        // Add player to the clan
        clans[clanName].push_back({ playerName, playerStrength });
    }

    // Debug output: Print the cpntents of the clans map
    std::cout << "Clans data:\n";
    for (const auto& clan : clans) {
        std::cout << "Clan: " << clan.first << ", Players: " << clan.second.size() << std::endl;
        for (const auto& player : clan.second) {
            std::cout << "  Player: " << player.name << ", Strength: " << player.strength << std::endl;
        }
    }

    // Example of using functions
    std::string firstClan = "firstClan";
    std::string secondClan = "secondClan";

    std::cout << "Player count in " << firstClan << ": " << GetPlayerCount(firstClan, clans) << std::endl;
    std::cout << "Player count in " << secondClan << ": " << GetPlayerCount(secondClan, clans) << std::endl;

    int result = ClanFight(firstClan, secondClan, clans);
    if (result == 1) {
        std::cout << firstClan << " wins!" << std::endl;
    }
    else if (result == -1) {
        std::cout << secondClan << " wins!" << std::endl;
    }
    else {
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}
