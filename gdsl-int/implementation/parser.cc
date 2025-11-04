/*
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the parser header for the gdsl-int
// C++ Headers
#include <components/parser.hh>
#include <cstddef>

namespace gdsl_int{
    std::vector <std::vector <std::string>> blocks = {
        {"EXEC_BUFFER", "STR", ""}, // default permenant buffer in the memory for EXEC and it's variations
        {"STDOUT_BUFFER", "STR", ""}, // default permenant buffer in the memory for STDOUT WRITES and it's variations
        {"STDERR_BUFFER", "STR", ""} // default permenant buffer in the memory for STDERR WRITES and it's variations
    };
    void parse (std::vector <std::vector <std::string>> tokens){
        for (unsigned long long i = 0;i < tokens.size();i++){
            std::string instruction = tokens[i][0]; // [i] is the token number/index and [0] refers to the exact keyword/instruction
            std::string primary_value = tokens[i][1]; // [i] is the token number/index and [1] refers to the first / primary value 
            std::string secondary_value; // [i] is the token number/index and [2] refers to the second / secondary value of the token because these 2 are mostly used
            if (tokens[i].size() > 2){
                secondary_value = tokens[i][2];
            }
            std::string err; // fill the error here
            // Match the instruction
            if (instruction == "")
                continue;
            else if (instruction == "DEF"){
                err = DEF(secondary_value, primary_value, blocks);
            }
            else if (instruction == "MVI"){
                err = MVI(primary_value, secondary_value, blocks);
            }
            else if (instruction == "MOV"){
                err = MOV(primary_value, secondary_value, blocks);
            }
            else if (instruction == "INCR"){
                err = INCR(primary_value, blocks);
            }
            else if (instruction == "EXEC"){
                std::vector <std::string> v = tokens[i];
                v.erase(v.begin(), v.begin() + 1);
                err = EXEC(v, blocks);
            }
            else if (instruction == "EXECOUT"){
                std::vector <std::string> v = tokens[i];
                v.erase(v.begin(), v.begin() + 1);
                err = EXECOUT(v, blocks);
            }
            else if (instruction == "EXECERR"){
                std::vector <std::string> v = tokens[i];
                v.erase(v.begin(), v.begin() + 1);
                err = EXECERR(v, blocks);
            }

            if (err != ""){
                err = "On line " + std::to_string(i+1) + ", " + err;
                gdsl_int::write(err, gdsl_int::WRITE_ERR);
                std::exit ( 3 );
            }

            // Always output STDOUT and STDERR
            std::cout << blocks[1][2]; // "Write the STDOUT"
            std::cerr << blocks[2][2]; // "Write the STDERR"
        }
    }
}