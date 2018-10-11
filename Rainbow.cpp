//
// Created by antoine on 08/10/18.
//

#include <cmath>
#include <iostream>
#include <algorithm>
#include "Rainbow.h"

void Rainbow::load( string name ){
    cout << "TODO load file !" << endl;
};

void Rainbow::save( string name ){
    sort();
    cout << "TODO save file !" << endl;
};

void Rainbow::create( Context& ctxt, int num, int M, int T ){
    this->_M = M;
    this->_T = T;
    this->_number = num;

    //Pour chaque chaines
    for(uint i=0; i < _M; i++){
        //On va calculer le premier et dernier élément de la chaine
        Chain chain;
        chain.idx1 = ctxt.randIndex();
        cout << chain.idx1 << endl;
        uint64 tmp = chain.idx1;
        for(uint t=0; t < _T; t++){
            tmp = ctxt.i2i(tmp,t);
        }

        chain.idxT = tmp;
        cout << tmp << endl;
        _X.push_back(chain);
    }
};

void Rainbow::sort(){
    //Trier les chaines par indices de fin dans l'ordre croissant
    std::sort(_X.begin(),_X.end(),[](Chain a, Chain b){
        return a.idxT < b.idxT;
    });
};

bool Rainbow::search( uint64 idx, uint & p, uint & q ){
    bool found = false;
    int idxStart = 0, idxEnd = _X.size(), idxMiddle;
    
    while(!found && ((idx - idxStart) > 1)){
        idxMiddle = (idxStart + idxEnd) / 2;
        found = (_X[idxMiddle].idxT == idx);

        if(_X[idxMiddle].idxT > idx) 
            idxEnd = idxMiddle;
        else 
            idxStart = idxMiddle;
    }
    
    if(_X[idxStart].idxT == idx) 
    {
        p = _X[idxStart].idx1;
        q = _X[idxStart].idxT;
        return true;
    }else
        return false;
    
};