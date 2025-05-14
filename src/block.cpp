/*
Responsibilities:

Implement the methods declared in Block.h.

Handle hashing of block data.

Implement Proof of Work logic (e.g., iterating a nonce until a valid hash is found).

Serialize block data for hash generation.

Example Methods:

std::string calculateHash().

void mineBlock(int difficulty).
*/

#include "../include/Block.h"
#include "../include/Crypto.h"
#include "../include/Utils.h"
#include <sstream>

Block::Block(int idx, const std::string& prevHash, int diff)
    : index(idx), previousHash(prevHash), nonce(0), difficulty(diff) {
    timestamp = getCurrentTimestamp();
    hash = calculateHash();
}

std::string Block::getHash() const {
    return hash;
}

std::string Block::getPreviousHash() const {
    return previousHash;
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
}

void Block::addTransaction(const Transaction& tx) {
    transactions.push_back(tx);
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << timestamp << previousHash << nonce;
    for (const auto& tx : transactions) {
        ss << tx.serialize();
    }
    return sha256(ss.str());
}