//
// Created by antoine on 08/10/18.
//

#include <cmath>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <sstream>
#include "Rainbow.h"

void Rainbow::load( string name ){
    string line;
    string word = "";
    ifstream myfile(name);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            istringstream iss(line);

            Chain chain;
            getline(iss, word,';');
            chain.idx1 = stoull(word);
            word.clear();
            getline(iss, word,';');
            chain.idxT = stoull(word);
            word.clear();
            _X.push_back(chain);
        }
        myfile.close();
    }

    else cout << "Unable to open file";
};

bool Rainbow::save( string name ){
    sort();
    ofstream myfile;
    myfile.open(name);

    if(myfile.is_open()) {
        for (uint i = 0; i < _M; i++) {
            myfile << _X[i].idx1 << ";" << _X[i].idxT << "\n";
        }
        myfile.close();
        return true;
    } else{
        return false;
    }


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
        //cout << chain.idx1 << endl;
        uint64 tmp = chain.idx1;
        //cout << "_T" << _T << endl;
        for(uint t=1; t < _T; t++){
            tmp = ctxt.i2i(tmp,t, i);
        }

        chain.idxT = tmp;
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
    int idxStart = 0, idxEnd = _M, idxMiddle;

    while(!found && ((idxEnd - idxStart) > 1)){
        idxMiddle = (idxStart + idxEnd) / 2;
        found = (_X[idxMiddle].idxT == idx);

        if(_X[idxMiddle].idxT > idx) 
            idxEnd = idxMiddle;
        else 
            idxStart = idxMiddle;
    }

    if(_X[idxStart].idxT == idx) 
    {
        p = idxStart;
        q = idxStart;
        while(p>0 && (_X[p].idxT == _X[p-1].idxT))
            p--;
        p++;
        //S'il y a des lignes successives qui ont le même idxT
        while(q<_M && _X[q].idxT == _X[p].idxT)
            q++;
        q--;
        return true;
    }else
        return false;
    
};