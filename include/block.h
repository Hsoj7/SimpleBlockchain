/*
Responsibilities:

Define the Block class.

Declare attributes such as block index, timestamp, hash, previous hash, nonce, transactions, and difficulty target.

Provide function declarations for methods like:

Generating the block hash.

Validating the block's Proof of Work.

Setting transactions in the block.
*/

#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "Transaction.h"

class Block {
private:
    int index;
    std::string timestamp;
    std::string hash;
    std::string previousHash;
    int nonce;
    std::vector<Transaction> transactions;
    int difficulty;

public:
    Block(int idx, const std::string& prevHash, int diff);
    std::string getHash() const;
    std::string getPreviousHash() const;
    void mineBlock(int difficulty);
    void addTransaction(const Transaction& tx);
    std::string calculateHash() const;
};

#endif