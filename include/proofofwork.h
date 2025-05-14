/*
Responsibilities:

Define helper functions or classes for handling Proof of Work.

Declare the difficulty calculation logic.

Example Methods:

std::string calculateHashWithNonce(std::string data, int nonce).
*/

#ifndef PROOF_OF_WORK_H
#define PROOF_OF_WORK_H

#include <string>
#include "Block.h"

std::string calculateHashWithNonce(const std::string& data, int nonce);
void mineBlock(Block& block, int difficulty);

#endif