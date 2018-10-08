//
// Created by antoine on 08/10/18.
//

#ifndef TP2_INFO901_CONTEXTE_H
#define TP2_INFO901_CONTEXTE_H


#include <string>
#include "typedef.h"

using namespace std;

class Contexte {
public:
    uint64 _N;              // nombre de mots
    int    _mot_taille_min; // nombre de lettres min d'un mot
    int    _mot_taille_max; // nombre de lettres max d'un mot
    uint64 _N_taille[];     // tableau, nombre de mots d'une taille donnée
    int    _nb_lettres;     // nombre de lettres possibles pour un caractère
    char   _lettres[];      // tableau des lettres de taille _nb_lettres
    // fonction de hachage
    // In: Clair c ----> Out: Empreinte (tableau de 16 octets (MD5) ou 20 octets (SHA1)
    void h( const string& c, byte d[] );
    // In: empreinte d, position t  ---> Retourne index
    uint64 h2i( uint64 t, const byte d[] );
    // In: index idx ----> Out: Clair c
    void i2c( uint64 idx, string& c );
    // In: index idx, position t ----> retourne index (la composée des précédentes)
    uint64 i2i( uint64 idx, uint64 t );
    // Retourne un indice aléatoire valide.
    uint64 randIndex();
private:
    // on peut mettre le clair dans cette donnée membre
    // (évite de créer un string à chaque fois)
    // Donner lui une taille suffisante au début ! (supérieure à _mot_taille_max)
    string _clair;
    // on peut mettre l'empreinte dans cette donnée membre
    // (évite de créer un tableau à chaque fois)
    byte   _empreinte[ 32 ];

};


#endif //TP2_INFO901_CONTEXTE_H
