//
// Created by antoine on 08/10/18.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include "Cracker.h"
using namespace std;

bool Cracker::cracker( byte y[], Rainbow& rainbow, Context& context,
                       string & clear ) {
    int nb_fausses_alertes = 0;
    for ( int t = rainbow._T - 1; t > 0; --t ) {
        // fabrication du bon indice
        uint64 idx = context.h2i( t,y);

        for (uint k = t + 1; k < rainbow._T; k++ ) {
            idx = context.i2i( idx, k,0 );
        }

        uint p = 0, q =0;
        // Recherche dans la table.
        if ( rainbow.search( idx, p, q ) ) {
            //cout << "t = " << t << " and idx=" << idx << " and p=" << p << " and q="<<q <<endl;

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

    //cout << "m = " << m << "and X.size() = " << X.size() <<endl;
    uint64 idx = X[m].idx1;
    //cout << "t = " << t << endl;

    for(int k=1; k<t; k++){
        //cout << "idx = "<< idx << endl;
        idx = context.i2i(k,idx,0);
    }
    context.i2c(idx,clear);
    byte newHashed[16];
    context.h(clear,newHashed);
    //cout << clear << endl;
    bool equals = false;


    equals = strcmp(md5ToString(newHashed).c_str(), md5ToString(hashed).c_str()) == 0;
    /*if(t==28)
    {

        cout << "equals = " << equals<<endl;
        cout << "m= " << m <<endl;
        cout << "idx1= " << X[m].idx1 <<endl;
        cout << "idxEnd= " << idx <<endl;
        string youpi = "";
        context.i2c(idx,youpi);
        cout << "clear= " << youpi <<endl;
        cout << "md5 de newHashed= " << md5ToString(newHashed) <<endl;
        cout << "hashed= " << md5ToString(hashed) <<endl;
    }*/
    /*int i=0;
    while(equals && i<16){
        equals = equals && (newHashed[i] == hashed[i]);
        i++;
    }*/

    //equals = memcmp(hashed, newHashed, 16);
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