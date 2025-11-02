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
#include <instructions/MOV.hh>

namespace gdsl_int {
    std::string MOV(std::string name, std::string value, std::vector <std::vector <std::string>> &blocks){
        bool is_defined = false;
        bool is_defined_2 = false;
        std::string error;
        std::string type;
        std::string *value_buffer;
        for (std::vector <std::string> &current_block : blocks){
            for (std::string current_block_name : current_block){
                if (current_block_name == name){
                    is_defined = true;
                    type = current_block[1]; // data type
                    value_buffer = &current_block[2]; // Where the value will be stored
                    break;
                }
            }
            if (is_defined){
                break;
            }
        }

        if (is_defined == false){
            error = "MOV Can not move a value to an undefined block.";
            return error;
        }

        for (std::vector <std::string> &current_block : blocks){
            for (std::string current_block_name : current_block){
                if (current_block_name == value){
                    is_defined_2 = true;
                    if (type == current_block[1]){
                        *value_buffer = current_block[2]; // Write the value
                    }
                    else {
                        error = "MOV Can not move in between to unknown data types.";
                        return error;
                    }
                    break;
                }
            }
            if (is_defined_2){
                break;
            }
        }

        if (not is_defined_2){
            error = "MOV Can not move a value to an undefined block.";
        }

        return error;
    }
}