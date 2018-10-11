//
// Created by antoine on 08/10/18.
//

#include <iostream>
#include "Cracker.h"
using namespace std;

bool Cracker::cracker( byte y[], const Rainbow& rainbow, const Context& context,
                  string & clear ) {
    cout << "TODO cracker !" << endl;
    /*
        int nb_fausses_alertes = 0;
        for ( int t = T - 1; t > 0; --t ) {
            // fabrication du bon indice
            uint64 idx = ctxt.h2i( y, t );
            for ( int k = t + 1; k <= T - 1; ++k ) {
                idx = ctxt.i2i( idx, k );
            }
            // Recherche dans la table.
            if ( aec.recherche( idx, p, q ) ) {
                // On vérifie chacune des alertes
                for ( int m = p; m <= q; ++m ) {
                    if ( VerifieAlerte( y, aec._X, t, m, clair ) )
                        return true;
                    nb_fausses_alertes++;
                }
            }
        }
        cout << "Non trouve, fausses alertes = " << nb_fausses_alertes;
        return false;
    }
     */
    return false;
}