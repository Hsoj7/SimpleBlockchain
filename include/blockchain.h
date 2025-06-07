/*
Responsibilities:

Define the Blockchain class.

Declare attributes such as a vector of Block objects, difficulty level, mining reward, and unconfirmed transactions.

Provide function declarations for:

Adding new blocks.

Validating the blockchain's integrity.

Managing transactions.

Retrieving the latest block.
*/
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
private:
    std::vector<Block> chain;
    int difficulty;
    int blockSize;
    double totalCoins;
    double minedCoins;
    std::vector<Transaction> pendingTransactions;
    double miningReward;

public:
    Blockchain(int diff, int bSize, double tCoins);
    void addBlock(Block newBlock);
    bool isChainValid() const;
    Block getLatestBlock() const;
    int getChainLength() const;
    double getTotalMinedCoins() const;
    void addTransaction(const Transaction& tx);

public:
    // method to print the whole history of the blockchain including all block hashes
    void printBlockchainHistory() const;
};

#endif