//
// Created by antoine on 08/10/18.
//

#include <cmath>
#include <iostream>
#include "ArcEnCiel.h"

void ArcEnCiel::creer( Contexte& ctxt, int num, int M, int T ){
    this->_M = M;
    this->_T = T;
    this->_numero = num;

    //Pour chaque chaines
    for(uint i=0; i < _M; i++){
        //On va calculer le premier et dernier élément de la chaine
        Chaine chaine;
        chaine.idx1 = ctxt.randIndex();
        cout << chaine.idx1 << endl;
        uint64 tmp = chaine.idx1;
        for(uint t=0; t < _T; t++){
            tmp = ctxt.i2i(tmp,t);
        }

        chaine.idxT = tmp;
        cout << tmp << endl;
        _X.push_back(chaine);
    }
}