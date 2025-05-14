/*
Responsibilities:

Implement the cryptographic hashing functions.

Use libraries like OpenSSL or a custom SHA-256 implementation.

Example Functions:

std::string sha256(const std::string &input).
*/

#include "../include/Crypto.h"
#include <sstream>
#include <iomanip>

std::string sha256(const std::string& input) {
    std::stringstream ss;
    unsigned long sum = 0;
    for (char c : input) {
        sum += static_cast<unsigned char>(c);
    }
    ss << std::hex << sum;
    return ss.str();
}