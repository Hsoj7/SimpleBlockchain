/*
Responsibilities:

Implement the methods declared in Blockchain.h.

Handle block validation (e.g., ensuring hashes match and Proof of Work is valid).

Add new blocks to the blockchain.

Check the entire blockchain for consistency.

Example Methods:

bool isChainValid().

void addBlock(Block newBlock).
*/

#include "../include/Blockchain.h"
#include "../include/Config.h"

Blockchain::Blockchain(int diff, int bSize, double tCoins)
    : difficulty(diff), blockSize(bSize), totalCoins(tCoins), minedCoins(0), miningReward(50.0) {
    // Create genesis block
    Block genesis(0, "0", difficulty);
    chain.push_back(genesis);
}

void Blockchain::addBlock(Block newBlock) {
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
    minedCoins += miningReward;
    pendingTransactions.clear();
}

bool Blockchain::isChainValid() const {
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& current = chain[i];
        const Block& previous = chain[i - 1];
        if (current.getHash() != current.calculateHash() ||
            current.getPreviousHash() != previous.getHash()) {
            return false;
        }
    }
    return true;
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}

int Blockchain::getChainLength() const {
    return chain.size();
}

double Blockchain::getTotalMinedCoins() const {
    return minedCoins;
}

void Blockchain::addTransaction(const Transaction& tx) {
    pendingTransactions.push_back(tx);
}