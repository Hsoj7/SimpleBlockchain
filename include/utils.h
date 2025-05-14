/*
Responsibilities:

Define helper functions for tasks like time formatting or data serialization.

Example Functions:

std::string getCurrentTimestamp().

std::string toHex(const std::string &input).
*/

#ifndef UTILS_H
#define UTILS_H

#include <string>

std::string getCurrentTimestamp();
std::string toHex(const std::string& input);

#endif