/*
* hexshit.hxx
*
* BSD 3-Clause License
*
* Copyright (c) 2022, Christopher Stephen Rafuse
* All rights reserved.
*/

#ifndef HEXSHIT_HXX
#define HEXSHIT_HXX

#include <iostream>

/*
* data buffer for containing the original size and pointer to
* the original program code, could be used with any pointer
* in an active c++ program, like a homebrew game engine.
*/
typedef struct {
    void*  data { nullptr };
    std::size_t size { 0 };
} databuffer_t;

/*
* Bytecode buffer used to iterate through the bytecode
* DataBuffer's evil twin! AAAAAAAAAA
*/
typedef struct {
    std::uint8_t* data { nullptr };
    std::size_t   size { 0 };
} bytebuffer_t;


void hexshit(DataBuffer value);

#endif
