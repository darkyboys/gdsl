/*
 * Note - This file doesn't contains any of the implementation information with it , Please refer the .cc file for it
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the MOV Instruction header for the gdsl-int
// C++ Headers
#include <instructions/INCR.hh>

namespace gdsl_int {
   std::string INCR(std::string name, std::vector <std::vector <std::string>> &blocks){
        bool is_defined = false;
        std::string error;
        std::string type;
        for (std::vector <std::string> &current_block : blocks){
            for (std::string current_block_name : current_block){
                if (current_block_name == name){
                    is_defined = true;
                    type = current_block[1]; // data type
                    if (type == "INT" or type == "UINT"){
                        current_block[2] = std::to_string (
                            string_to_int(current_block[2])+1
                        );
                    }
                    else if (type == "FLOAT"){
                        current_block[2] = std::to_string (
                            string_to_float(current_block[2])+1.0f
                        );
                    }
                    else {
                        error = "INCR Can only increment INT , UINT and FLOAT Types not STRING.";
                    }
                    break;
                }
            }
            if (is_defined){
                break;
            }
        }

        if (is_defined == false){
            error = "INCR Can not increment a value of an undefined block.";
            return error;
        }

        return error;
    }
}