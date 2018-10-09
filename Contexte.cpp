//
// Created by antoine on 08/10/18.
//

#include <cstring>
#include <iostream>
#include <cmath>
#include "Contexte.h"

void Contexte::h( const string& c, byte d[] ){
    byte param[c.length()];
    copy(c.begin(),c.end(),param);
    HashMD5(param,c.length(),d);
}

uint64 Contexte::h2i( uint64 t, const byte d[] ){
    return (d[0] + t) % _N;
}

void Contexte::i2c( uint64 idx, string& clear ){

    int exposant = _mot_taille_max - 1;
    int rest = idx;
    while(rest > 0){
        int pos = rest / pow(_nb_lettres ,exposant);
        clear += _lettres[pos];
        rest = rest % (uint64)pow(_nb_lettres,exposant);
        exposant--;
    }
    cout << endl;
}