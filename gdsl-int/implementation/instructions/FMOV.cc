/*
 * Note - This file doesn't contains any of the implementation information with it , Please refer the .cc file for it
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the FMOV Instruction header for the gdsl-int
// C++ Headers
#include <instructions/FMOV.hh>

namespace gdsl_int {
    std::string FMOV(std::string name, std::string value, std::string index_name, std::string index_value, std::vector<std::vector<std::string>> &blocks){
        bool is_defined = false;
        bool is_defined_2 = false;
        std::string error;
        std::string *value_buffer;
        if (not gdsl_int::is_string_integer(index_name) or not gdsl_int::is_string_integer(index_value)){
            error = "MOV's index must be a valid integer value.";
            return error;
        }
        for (std::vector <std::string> &current_block : blocks){
            for (std::string current_block_name : current_block){
                if (current_block_name == name){
                    int i_index_value = gdsl_int::string_to_int(index_value);
                    if (not (current_block.size()-2 >= i_index_value+1 and i_index_value >= 0)){
                        error = "MOV's index must be in the range of the the block size.";
                        return error;
                    }
                    is_defined = true;
                    value_buffer = &current_block[2+i_index_value]; // Where the value will be stored
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
                    int i_index_name = gdsl_int::string_to_int(index_name);
                    if (not (current_block.size()-2 >= i_index_name+1 and i_index_name >= 0)){
                        error = "MOV's index must be in the range of the the block size.";
                        return error;
                    }
                    *value_buffer = current_block[2+i_index_name]; // Write the value
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