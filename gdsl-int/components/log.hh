/*
 * Note - This file doesn't contains any of the implementation information with it , Please refer the .cc file for it
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the log header for the gdsl-int
// C++ Headers
#ifndef GDSL_LOG
#define GDSL_LOG 1

#include <iostream>
#include <string>

namespace gdsl_int{
    const int WRITE_LOG = 1;
    const int WRITE_WARN = 2;
    const int WRITE_ERR = 3;
    
    void write(const std::string& msg, int type);
}
#endif