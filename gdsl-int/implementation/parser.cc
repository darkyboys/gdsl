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
    std::vector <std::vector <std::string>> labels = {}; //  store the labels in the form or label,index
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
                if (tokens[i].size() > 3){
                    err = MVI(primary_value, secondary_value, tokens[i][3], blocks);
                }
                else err = MVI(primary_value, secondary_value, "0", blocks);
            }
            else if (instruction == "MOV"){
                if (tokens[i].size() > 4){
                    err = MOV(primary_value, secondary_value, tokens[i][4], tokens[i][3], blocks);
                }
                else if (tokens[i].size() > 3){
                    err = MOV(primary_value, secondary_value, "0", tokens[i][3], blocks);
                }
                else {
                    err = MOV(primary_value, secondary_value, "0", "0", blocks);
                }
            }
            else if (instruction == "INCR"){
                if (tokens[i].size() > 2){
                    err = INCR(primary_value, secondary_value, blocks);
                }
                else err = INCR(primary_value, "0", blocks);
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
            else if (instruction == "BLKDEF"){
                if (tokens[i].size() > 3){
                    err = BLKDEF(secondary_value, primary_value, tokens[i][3], blocks);
                }
                else {
                    err = "BLKDEF Needs a size (fixable syntax BLKDEF type, name, size)";
                }
            }
            else if (instruction == "LABEL"){
                labels.push_back ({primary_value, std::to_string(i)});
            }
            else if (instruction == "JUMP"){
                bool label_found = false;
                for (std::vector <std::string> current_label : labels){
                    if (current_label[0] == primary_value){
                        i = gdsl_int::string_to_int(current_label[1]);
                        label_found = true;
                        break;
                    }
                }
                if (label_found) continue;
                // This will only reach here if no label was found previously allocated
                // So we will keep looping until we finally finds the required label
                label_found = false;
                for (unsigned long long &x = i;x < tokens.size();x++){ // Always remember that x isn't 0
                    std::string ins = tokens[i][0]; // instruction of the sandboxed token
                    std::string val = tokens[i][1]; // value of the sandboxed token
                    if (ins == "LABEL" and val == primary_value){ // label was found
                        labels.push_back ({primary_value, std::to_string(x)}); // you can also say it's i
                        label_found = true;
                        break;
                    }
                }
                if (label_found) continue;
                // This will only execute if label search was globally failed (Means the label wasn't present)
                // Throw error then
                err = "JUMP Error - Unknown label was passed.";
            }
            else if (instruction == "FMOV"){
                if (tokens[i].size() > 4){
                    err = FMOV(primary_value, secondary_value, tokens[i][4], tokens[i][3], blocks);
                }
                else if (tokens[i].size() > 3){
                    err = FMOV(primary_value, secondary_value, "0", tokens[i][3], blocks);
                }
                else {
                    err = FMOV(primary_value, secondary_value, "0", "0", blocks);
                }
            }
            else if (instruction == "LOOPT"){
                if (secondary_value == ""){
                    err = "LOOPT's LABEL Value can not be empty.";
                }
                else {
                    if (gdsl_int::is_string_integer(primary_value)){
                        unsigned long long times = gdsl_int::string_to_int(primary_value);
                        std::vector <std::vector <std::string>> subparser_tokens;
                        unsigned long long ending_point = 0;
                        for (unsigned long long subloop_index = i+1;subloop_index < tokens.size();subloop_index++){ // Read the instructions from the memory
                            if (tokens[subloop_index][0] == "LABEL" and tokens[subloop_index][1] == secondary_value){ // Always check for the label instruction to mark the ending point
                                ending_point = subloop_index; // Mark the ending point
                                break;
                            }
                            else {
                                subparser_tokens.push_back (tokens[subloop_index]);
                                // std::cerr<<"Tokens Pushing: "<<tokens[subloop_index][0]<<","<<tokens[subloop_index][1]<<"\n"; // For debugging only (Via bash with 1>/dev/null in the cli)
                            }
                        }
                        // Spawn a sub parser to parse the tokens the loop times
                        for (unsigned long long x = 1;x < times;x++){
                            // std::cout << "Iteration Number "<<x<<"\nFirst Token: "<<subparser_tokens[0][0]<<"\n"; // For debugging only
                            gdsl_int::parse (subparser_tokens);
                        }
                        i = ending_point; // Jump to the ending point
                    }
                    else {
                        err = "LOOPT's TIMES Value can not be a non integer type.";
                    }
                }
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