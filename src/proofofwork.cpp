/*
Responsibilities:

Implement the mining algorithm.

Perform hash calculations using a cryptographic hashing function (e.g., SHA-256).

Adjust the nonce to meet the difficulty target.

Example Methods:

void mineBlock(Block &block, int difficulty).
*/

#include "../include/ProofOfWork.h"
#include "../include/Crypto.h"

std::string calculateHashWithNonce(const std::string& data, int nonce) {
    return sha256(data + std::to_string(nonce));
}

void mineBlock(Block& block, int difficulty) {
    block.mineBlock(difficulty);
}