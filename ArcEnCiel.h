//
// Created by antoine on 08/10/18.
//

#ifndef TP2_INFO901_ARCENCIEL_H
#define TP2_INFO901_ARCENCIEL_H

#include <vector>
#include "typedef.h"
#include "Contexte.h"

using namespace std;

struct Chaine {
    uint64 idx1;    // premier indice de la chaine
    uint64 idxT;    // dernier indice de la chaine
};
class ArcEnCiel {
    uint           _numero;   // numero de la table (ici 0, mais voir "Moult tables")
    uint           _M;        // nombre de chaines dans la table
    uint           _T;        // taille de chaque chaine
    vector<Chaine> _X;        // la table elle-meme
    // Creer les M chaînes de taille T, dans le contexte ctxt
    void creer( const Contexte& ctxt, int num, int M, int T );
    // Tri _X suivant idxT.
    void trier();
    // Sauvegarde la table sur disque.
    void save( string name );
    // Charge en mémoire la table à partir du disque.
    void load( string name );
    // Recherche dichotomique dans la table
    // ( p et q sont le premier/dernier trouvé )
    bool recherche( uint64 idx, uint & p, uint & q );
};


#endif //TP2_INFO901_ARCENCIEL_H
