/*
Responsibilities:

Implement the cryptographic hashing functions.

Use libraries like OpenSSL or a custom SHA-256 implementation.

Example Functions:

std::string sha256(const std::string &input).
*/

#include "../include/Crypto.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <string>

std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::string fakeSha256(const std::string& input) {
    return "0" + input; // Always valid for difficulty 1
}