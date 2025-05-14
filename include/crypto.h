/*
Responsibilities:

Define functions for cryptographic hashing (e.g., SHA-256).

Example Functions:

std::string sha256(const std::string &input).
*/

#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>

std::string sha256(const std::string& input);

#endif