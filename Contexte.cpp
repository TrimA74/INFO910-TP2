//
// Created by antoine on 08/10/18.
//

#include <cstring>
#include "Contexte.h"
#include "HashAlgorithm.h"

void Contexte::h( const string& c, byte d[] ){
    unsigned char* clair;
    strcpy(static_cast<char*>(clair),c.c_str());
    HashAlgorithm::HashMD5(clair,c.length(),d);
}

uint64 Contexte::h2i( uint64 t, const byte d[] ){
    return (d[0] + t) % _N;
}

void Contexte::i2c( uint64 idx, string& c ){

}