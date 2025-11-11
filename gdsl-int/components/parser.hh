/*
 * Note - This file doesn't contains any of the implementation information with it , Please refer the .cc file for it
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the parser header for the gdsl-int
#ifndef GDSL_PARSER
#define GDSL_PARSER 1
// C++ Headers
#include <iostream>
#include   <string>
#include   <vector>

// Linux Headers
#include <unistd.h>

// Instructions
#include <instructions/DEF.hh>
#include <instructions/MVI.hh>
#include <instructions/MOV.hh>
#include <instructions/INCR.hh>
#include <instructions/EXEC.hh>
#include <instructions/EXECOUT.hh>
#include <instructions/EXECERR.hh>
#include <instructions/BLKDEF.hh>
#include <instructions/FMOV.hh>

namespace gdsl_int{
    extern std::vector <std::vector <std::string>> blocks; // the blocks stored in the def are going to be stored here
    extern std::vector <std::vector <std::string>> labels; //  store the labels in the form or label,index
    void parse (std::vector <std::vector <std::string>> tokens);
}

#endif