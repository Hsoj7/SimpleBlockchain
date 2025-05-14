/*
Responsibilities:

Implement the methods declared in Transaction.h.

Serialize transaction data for inclusion in blocks.

Validate transactions (e.g., ensure amounts are non-negative).

Example Methods:

std::string serialize().

bool isValid().
*/

#include "../include/Transaction.h"
#include "../include/Utils.h"

Transaction::Transaction(const std::string& s, const std::string& r, double amt)
    : sender(s), recipient(r), amount(amt) {
    timestamp = getCurrentTimestamp();
}

std::string Transaction::serialize() const {
    return sender + recipient + std::to_string(amount) + timestamp;
}

bool Transaction::isValid() const {
    return amount >= 0 && !sender.empty() && !recipient.empty();
}