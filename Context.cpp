//
// Created by antoine on 08/10/18.
//

#include <cstring>
#include <iostream>
#include <cmath>
#include "Context.h"

void Context::h( const string& c, byte d[] ){
    byte param[c.length()];
    copy(c.begin(),c.end(),param);
    HashMD5(param,c.length(),d);
}

uint64 Context::h2i( uint64 t, const byte d[] ){
    uint64* ptr = (uint64*) d; // le tableau de caractères est vu comme un tableau de grand nombre.
    uint64    i = *ptr;        // par définition le nombre stocké dans t[0-7].
    return (i + t) % N;
}

void Context::i2c( uint64 idx, string& clear ){

    int exposant = word_length_max - 1;
    int rest = idx;
    while(exposant >= 0){
        int pos = rest / pow(nb_letters ,exposant);
        clear += letters[pos];
        rest = rest % (uint64)pow(nb_letters,exposant);
        exposant--;
    }
}

uint64 Context::randIndex(){
    unsigned long n1 = rand();
    unsigned long n2 = rand();
    uint64 n = ( (uint64) n2 )
               + ( ( (uint64) n1 ) << 32 );
    return n % N;
}

uint64 Context::i2i( uint64 idx, uint64 t ){

    //On trouve le texte clair à partir de l'indice
    string clear;
    i2c( idx, clear);
    //cout << idx << " -i2c-> " << clear;
    //On hash le clair
    byte hashed[16];
    h(clear, hashed);
    //cout << " -h-> " << md5ToString(hashed);
    //cout << " -h2i-> " << h2i(t,hashed) << endl;
    //On recupère l'indice du hashé
    return h2i(t,hashed);
}