//
// Created by antoine on 08/10/18.
//

#include <cstring>
#include <iostream>
#include "Context.h"

void Context::h( const string& c, byte d[] ){
    HashMD5((byte*)c.c_str(),c.length(),d);
}

uint64 Context::h2i( uint64 t, const byte d[] ){
    uint64* ptr = (uint64*) d; // le tableau de caractères est vu comme un tableau de grand nombre.
    uint64    i = *ptr;        // par définition le nombre stocké dans t[0-7].
    return (i + t) % N;
}

void Context::i2c( uint64 idx, string& clear ){
    clear.clear();
    clear.resize( word_length_max );
    for ( int i = word_length_max-1; i >= 0; --i ) {
        clear[ i ] = letters[ idx % nb_letters ];
        idx       /= nb_letters;
    }
}

uint64 Context::randIndex(){
    unsigned long n1 = rand();
    unsigned long n2 = rand();
    uint64 n = ( (uint64) n2 )
               + ( ( (uint64) n1 ) << 32 );
    return n % N;
}

uint64 Context::i2i( uint64 idx, uint64 t){

    _clear.clear();
    i2c(idx, _clear);

    byte hashed[16];
    h(_clear, hashed);

    return h2i(t,hashed);
}