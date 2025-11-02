/*
 * Note - This file doesn't contains any of the implementation information with it , Please refer the .cc file for it
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the DEF Instruction header for the gdsl-int
#ifndef GDSL_INSTRUCTION_DEF
#define GDSL_INSTRUCTION_DEF 1
// C++ Headers
#include <string>
#include <vector>

namespace gdsl_int {
    std::string DEF(std::string name, std::string type, std::vector <std::vector <std::string>> &blocks);
}
#endif