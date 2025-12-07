# GDSL - Goblin's Demonic Scripting Language
`GDSL` was made as a scripting language/layer or Intermediate Representation for other interpreted/compiled programming languages. `GDSL` can be both interpreted and compiled down to a native binary, Giving you incredibly choices to run your programs in different ways without thinking about the execution process.

## What Does This Repository Features
This repository contains the official interpreter for the GDSL to run the GDSL Programs without actually making a binary file. (The Compiler's Development will start as soon as the interpreter's core development finishes, You can run the interpreter still with limited language support as of now).

## Language Features
GDSL is a really simple language to learn all you do is that you plays around the memory and perform some tasks. `GDSL` Can be blazing fast to super slow depending on the program and how was it written. It can be both interpreted and compiled.

### Macros/Instructions
`MACROS` or `Instructions` are a fundamental concept of GDSL because they tells the interpreter/compiler (What to do), Like you may want to read a file so you must use a `MACRO` to tell the interpreter / compiler that you want to read a file.

### Values To The Macros
Giving values to macro is very simple. 
 - The first value must be the `MACRO`.
 - The second value must be the value seperated by a ` ` backspace.
 - The third to any amount of values must be seperated by a `,` comma.

*Example*
```bash
MACRO VALUE1, VALUE2, VALUE3 ...
# or Just one value
MACRO VALUE1
```

### Supported MACROS (As of Now)
Bellow are all the supported macros of `GDSL` which this project `gdsl-int` supports:-
 - *DEF <typename>, <block name>*: This macro takes a type name which can either be the one of (INT, UINT, STR, FLOAT) and a block name to define that block in the memory.
 - *BLKDEF <typename>, <block name>, <size>*: This macro also defines a block in the memory but not just a single block. It defines a lot of blocks in the memory together depending on the size.
 - *MVI <block name>, <value>, <optional value index>*: This is like an assembly instruction, All this does is that this directly inserts a value into a block (The type must be the same). This can also take an optional index for the blocks defined in the memory starting from the index 0 to the size - 1, By default the *DEF* macro only defined the block with index 0 and BLKDEF from 0 to the size-1 so use carefully and refer `test/` for doubts.
 - *MOV <block name>, <block2 name>, <optional block index>, <optional block2 index>*: This is used to move the data in between blocks from the 2nd block to the first block. Optionally takes the index of both blocks if needed.
 - *INCR <block name>*: This block only increments an `INT` or `UINT` by `1`.
 - *FMOV <block name>, <block2 name>, <optional block index>, <optional block2 index>*: This is same as `MOV` but the values will be moved without checking the daat type.
 - *EXEC <command>, [arguments]*: This executes a command and takes infinite number of arguments as arguments for that command. And executes it with all those arguments, Also writes the command's `STDOUT` and `STDERR` to the `EXEC_BUFFER` block (This block is already defined by the interpreter / compiler).
 - *EXECOUT <command>, [arguments]*: Same as `EXEC` but only writes `STDOUT` to the `EXEC_BUFFER`.
 - *EXECERR <command>, [arguments]*: Same as `EXEC` but only writes `STDERR` to the `EXEC_BUFFER`.
 - *LABEL <name>*: Defined a label to later jump on.
 - *JUMP <label name>*: Jumps on that label so the execution starts from there.
 - *LOOPT <times>, <label name>*: Usually it's possible to loop over the program without using this macro but it will be slower for manual JUMPs on LABELs so that is why this isn't in the official specification but this project supports this *LOOPT* Keyword so loop x times. This will run all the instructions `<times>` times and till the `<label>` label. (Please refer `test/`

# Installation
The installation is very simple:

*Pre-requesties*:
 - *(Cook Build System)[https://github.com/darkyboys/cook] by darkyboys*

After wards the installation is really straight forward.
 - **Clone This Repository**: `git clone https://github.com/darkyboys/gdsl.git`
 - **Change Directory To The Repository**: `cd gdsl`
 - **Make The Interpreter**: `cook gdsl-int`
 - **Run The Binary**: The binary will be in the `bin` directory.

## This project is still in development! After it is finished this README.md will be updated with proper content in it.
## The contributions are welcome 😃 please refer the `CONTRIBUTING.md` for guidelines.
