
#include <iostream>
#include <random>
#include <string>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    
    std::string choices[] = {"Rock", "Paper", "Scissors"};
    std::string player_choice;
    bool playing = true;
    
    while (playing) {
        std::cout << "\nLet's play Rock Paper Scissors!\n";
        std::cout << "Enter your choice (Rock/Paper/Scissors) or 'quit' to exit: ";
        std::getline(std::cin, player_choice);
        
        // Convert first character to uppercase, rest to lowercase
        if (!player_choice.empty()) {
            player_choice[0] = std::toupper(player_choice[0]);
            for (size_t i = 1; i < player_choice.length(); i++) {
                player_choice[i] = std::tolower(player_choice[i]);
            }
        }
        
        if (player_choice == "Quit") {
            playing = false;
            continue;
        }
        
        if (player_choice != "Rock" && player_choice != "Paper" && player_choice != "Scissors") {
            std::cout << "Invalid choice! Please try again.\n";
            continue;
        }
        
        int computer_idx = dis(gen);
        std::string computer_choice = choices[computer_idx];
        
        std::cout << "Computer chose: " << computer_choice << "\n";
        
        if (player_choice == computer_choice) {
            std::cout << "It's a tie!\n";
        } else if ((player_choice == "Rock" && computer_choice == "Scissors") ||
                   (player_choice == "Paper" && computer_choice == "Rock") ||
                   (player_choice == "Scissors" && computer_choice == "Paper")) {
            std::cout << "You win!\n";
        } else {
            std::cout << "Computer wins!\n";
        }
    }
    
    std::cout << "Thanks for playing!\n";
    return 0;
}
