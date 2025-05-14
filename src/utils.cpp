/*
Responsibilities:

Implement the helper functions declared in Utils.h.

Handle non-blockchain-specific logic to keep other files focused.
*/

#include "../include/Utils.h"
#include <ctime>
#include <sstream>
#include <iomanip>

std::string getCurrentTimestamp() {
    std::time_t now = std::time(nullptr);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::string toHex(const std::string& input) {
    std::stringstream ss;
    for (char c : input) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    return ss.str();
}