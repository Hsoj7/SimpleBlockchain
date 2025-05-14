/*
Responsibilities:

Parse command-line arguments (e.g., block time, block size, number of coins to mine).

Initialize the blockchain and mining parameters.

Handle the main simulation loop.

Provide options for displaying blockchain status or interacting with the system from the command line.

Example Tasks:

Load initial configuration.

Call functions to add blocks to the chain.

Print statistics or summaries.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../include/Blockchain.h" // Assumed header for Blockchain class
#include "../include/Config.h"    // Assumed header for configuration constants

// Function to display usage instructions
void printUsage() {
    std::cout << "Usage: ./blockchain_sim [options]\n"
              << "Options:\n"
              << "  --block-time <seconds>   Target block time (default: 600)\n"
              << "  --block-size <bytes>     Maximum block size (default: 1048576)\n"
              << "  --total-coins <number>   Total coins to mine (default: 21000000)\n"
              << "  --difficulty <bits>      Mining difficulty (default: 4)\n"
              << "  --help                   Show this help message\n"
              << std::endl;
}

// Function to parse command-line arguments
bool parseArguments(int argc, char* argv[], int& blockTime, int& blockSize, double& totalCoins, int& difficulty) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--block-time" && i + 1 < argc) {
            blockTime = std::stoi(argv[++i]);
            if (blockTime <= 0) {
                std::cerr << "Error: Block time must be positive.\n";
                return false;
            }
        } else if (arg == "--block-size" && i + 1 < argc) {
            blockSize = std::stoi(argv[++i]);
            if (blockSize <= 0) {
                std::cerr << "Error: Block size must be positive.\n";
                return false;
            }
        } else if (arg == "--total-coins" && i + 1 < argc) {
            totalCoins = std::stod(argv[++i]);
            if (totalCoins <= 0) {
                std::cerr << "Error: Total coins must be positive.\n";
                return false;
            }
        } else if (arg == "--difficulty" && i + 1 < argc) {
            difficulty = std::stoi(argv[++i]);
            if (difficulty <= 0) {
                std::cerr << "Error: Difficulty must be positive.\n";
                return false;
            }
        } else if (arg == "--help") {
            printUsage();
            exit(0);
        } else {
            std::cerr << "Unknown argument: " << arg << "\n";
            printUsage();
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    // Default configuration values (can be overridden by Config.h later)
    int blockTime = 10;        // 600 is 10 minutes in seconds, Bitcoin-like
    int blockSize = 1024;    // 1048576 is 1 MB, 1024 is 1 kb
    double totalCoins = 2100; // Bitcoin's total supply is 21000000
    int difficulty = 1;          // Number of leading zeros in hash

    // Parse command-line arguments
    if (!parseArguments(argc, argv, blockTime, blockSize, totalCoins, difficulty)) {
        return 1;
    }

    // Initialize the blockchain
    Blockchain blockchain(difficulty, blockSize, totalCoins); // Assumed constructor
    std::cout << "Blockchain initialized with:\n"
              << "  Block time: " << blockTime << " seconds\n"
              << "  Block size: " << blockSize << " bytes\n"
              << "  Total coins: " << totalCoins << "\n"
              << "  Difficulty: " << difficulty << " leading zeros\n"
              << std::endl;

    // Simple command-line interface for simulation
    std::string command;
    while (true) {
        std::cout << "\nCommands:\n"
                  << "  mine        - Mine a new block\n"
                  << "  status      - Display blockchain status\n"
                  << "  validate    - Validate blockchain integrity\n"
                  << "  exit        - Exit simulation\n"
                  << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "mine") {
            // Simulate mining a new block
            std::cout << "Mining new block...\n";
            Block newBlock = blockchain.getLatestBlock(); // Assumed method
            newBlock.mineBlock(difficulty);              // Assumed method
            blockchain.addBlock(newBlock);               // Assumed method
            std::cout << "Block mined and added to the chain.\n";
        } else if (command == "status") {
            // Display blockchain status
            std::cout << "Blockchain Status:\n"
                      << "  Total blocks: " << blockchain.getChainLength() // Assumed method
                      << "\n  Last block hash: " << blockchain.getLatestBlock().getHash() // Assumed method
                      << "\n  Total mined coins: " << blockchain.getTotalMinedCoins() // Assumed method
                      << "\n";
        } else if (command == "validate") {
            // Validate the blockchain
            if (blockchain.isChainValid()) { // Assumed method
                std::cout << "Blockchain is valid.\n";
            } else {
                std::cout << "Blockchain is invalid!\n";
            }
        } else if (command == "exit") {
            std::cout << "Exiting simulation.\n";
            break;
        } else {
            std::cout << "Unknown command. Try 'mine', 'status', 'validate', or 'exit'.\n";
        }
    }

    return 0;
}
