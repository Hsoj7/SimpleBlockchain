/*
Responsibilities:

Define the Transaction class.

Declare attributes for sender, recipient, amount, and optional metadata (like a timestamp).

Provide function declarations for serialization and validation.

Example Fields:

std::string sender.

std::string recipient.

double amount.
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string sender;
    std::string recipient;
    double amount;
    std::string timestamp;

public:
    Transaction(const std::string& s, const std::string& r, double amt);
    std::string serialize() const;
    bool isValid() const;
};

#endif