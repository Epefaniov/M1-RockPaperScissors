#include <iostream>
#include <random>
#include <string>

// Function to prompt human player for their choice
std::string getHumanChoice() {
    std::string choice;
    while (true) {
        std::cout << "Enter your choice (rock, paper, scissors, quit): ";
        std::cin >> choice;
        if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit") {
            return choice;
        }
        std::cout << "Invalid choice. Please choose 'rock', 'paper', 'scissors', or 'quit'.\n";
    }
}

// Function to determine the winner of a round
std::string determineWinner(const std::string& computerChoice, const std::string& humanChoice) {
    if (computerChoice == humanChoice) {
        return "draw";
    }
    if ((computerChoice == "rock" && humanChoice == "scissors") ||
        (computerChoice == "scissors" && humanChoice == "paper") ||
        (computerChoice == "paper" && humanChoice == "rock")) {
        return "computer";
    }
    return "human";
}

// Function to update the score based on the winner
void updateScore(std::string winner, int& computerScore, int& humanScore) {
    if (winner == "computer") {
        computerScore++;
    } else if (winner == "human") {
        humanScore++;
    }
}

// Function to display the tournament winner
void declareWinner(int computerScore, int humanScore) {
    std::cout << "Final Score:\n";
    std::cout << "Computer: " << computerScore << "\n";
    std::cout << "Human: " << humanScore << "\n";
    if (computerScore > humanScore) {
        std::cout << "Computer wins the tournament!\n";
    } else if (humanScore > computerScore) {
        std::cout << "Human wins the tournament!\n";
    } else {
        std::cout << "The tournament ends in a draw!\n";
    }
}

int main() {
    int computerScore = 0, humanScore = 0;
    std::string humanChoice;

    // Random number generator for computer's choice
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 3);

    while (true) {
        // Generate random computer choice
        int computerChoiceNum = distrib(gen);
        std::string computerChoice;
        if (computerChoiceNum == 1) {
            computerChoice = "rock";
        } else if (computerChoiceNum == 2) {
            computerChoice = "paper";
        } else {
            computerChoice = "scissors";
        }

        // Get human's choice
        humanChoice = getHumanChoice();

        // Check if human wants to quit the tournament
        if (humanChoice == "quit") {
            break;
        }

        // Display the computer's choice
        std::cout << "Computer chose: " << computerChoice << "\n";

        // Determine the winner of the round
        std::string roundWinner = determineWinner(computerChoice, humanChoice);

        // Update the scores
        updateScore(roundWinner, computerScore, humanScore);

        // Display the round result
        if (roundWinner == "draw") {
            std::cout << "This round is a draw.\n";
        } else {
            std::cout << roundWinner << " wins this round.\n";
        }

        // Display current scores
        std::cout << "Current Score: Computer " << computerScore << " - " << humanScore << " Human\n";
    }

    // Declare the tournament winner
    declareWinner(computerScore, humanScore);

    return 0;
}