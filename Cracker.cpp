//
// Created by antoine on 08/10/18.
//

#include <iostream>
#include <cmath>
#include "Cracker.h"
using namespace std;

bool Cracker::cracker( byte y[], Rainbow& rainbow, Context& context,
                       string & clear ) {
    int nb_fausses_alertes = 0;
    for ( int t = rainbow._T - 1; t > 0; --t ) {
        // fabrication du bon indice
        uint64 idx = context.h2i( t,y);

        for (uint k = t + 1; k < rainbow._T; k++ ) {
            idx = context.i2i( idx, k);
        }

        uint p = 0, q =0;
        // Recherche dans la table.
        if ( rainbow.search( idx, p, q ) ) {

            // On vérifie chacune des alertes
            for ( unsigned int m = p; m <= q; ++m ) {
                if ( verifyAlert( y, context, rainbow._X, t, m, clear  ) )
                    return true;
                nb_fausses_alertes++;
            }
        }

    }
    cout << "Non trouve, fausses alertes = " << nb_fausses_alertes << endl;
    return false;
}

bool Cracker::verifyAlert( byte hashed[], Context context, vector<Chain> X, int t, int m, string& clear){

    uint64 idx = X[m].idx1;

    for(int k=1; k< t; k++){
        idx = context.i2i(idx,k);
    }
    context.i2c(idx,clear);
    byte newHashed[16];
    context.h(clear,newHashed);
    bool equals = true;

    for(int i=0; equals && i<16; i++){
        equals = equals && (newHashed[i] == hashed[i]);
    }

    return equals;
}

double Cracker::getProbability(uint64 N, uint M, uint T){
    double v,i,mm;
    mm = M;
    v = 1;
    for(i=1; i<T; i++){
        v *= (1 - mm / N);
        mm = N * ( 1 - exp( (-1) * mm / N ) );
    }
    return 1 - v;
}