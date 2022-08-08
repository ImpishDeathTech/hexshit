#ifndef HEXSHIT_HXX
#define HEXSHIT_HXX

#include <iostream>
#include <cstdint>

typedef struct {
    void*  data { nullptr };
    size_t size { 0 };
} DataBuffer;

typedef struct {
    uint8_t* data { nullptr };
    size_t   size { 0 };
} ByteBuffer;


void hexshit(DataBuffer value);

#endif