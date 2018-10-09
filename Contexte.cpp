//
// Created by antoine on 08/10/18.
//

#include <cstring>
#include <iostream>
#include "Contexte.h"

void Contexte::h( const string& c, byte d[] ){
    byte param[c.length()];
    copy(c.begin(),c.end(),param);
    HashMD5(param,c.length(),d);
}

uint64 Contexte::h2i( uint64 t, const byte d[] ){
    return (d[0] + t) % _N;
}

void Contexte::i2c( uint64 idx, string& c ){

}