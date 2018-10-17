//
// Created by antoine on 08/10/18.
//

#ifndef TP2_INFO901_ARCENCIEL_H
#define TP2_INFO901_ARCENCIEL_H

#include <vector>
#include "Context.h"

using namespace std;

struct Chain {
    uint64 idx1;    // premier indice de la chaine
    uint64 idxT;    // dernier indice de la chaine
};
class Rainbow {
    uint           _number;   // numero de la table (ici 0, mais voir "Moult tables")
    uint           _M;        // nombre de chaines dans la table
public:
    vector<Chain> _X;        // la table elle-meme
    uint           _T;        // taille de chaque chaine
    // Creer les M chaînes de taille T, dans le contexte ctxt
    void create( Context& ctxt, int num, int M, int T );
    // Tri _X suivant idxT.
    void sort();
    // Sauvegarde la table sur disque.
    bool save( string name );
    // Charge en mémoire la table à partir du disque.
    void load( string name );
    // Recherche dichotomique dans la table
    // ( p et q sont le premier/dernier trouvé )
    bool search( uint64 idx, uint & p, uint & q );
};


#endif //TP2_INFO901_ARCENCIEL_H
