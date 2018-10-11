//
// Created by antoine on 08/10/18.
//

#ifndef TP2_INFO901_CONTEXTE_H
#define TP2_INFO901_CONTEXTE_H


#include <string>
#include <vector>
#include "utils.h"

typedef unsigned int       uint;
typedef unsigned long long uint64;
typedef unsigned char      byte;

using namespace std;

class Context {
public:
    uint64 N;              // nombre de mots
    int    word_length_min; // nombre de lettres min d'un mot
    int    word_length_max; // nombre de lettres max d'un mot
    vector<uint64> N_length;     // tableau, nombre de mots d'une taille donnée
    int    nb_letters;     // nombre de lettres possibles pour un caractère
    string   letters;      // tableau des lettres de taille _nb_lettres
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
    string _clear;
    // on peut mettre l'empreinte dans cette donnée membre
    // (évite de créer un tableau à chaque fois)
    byte   _hashed[ 32 ];

};

inline void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
    MD5(pPlain, nPlainLen, pHash);
}
inline void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
    SHA1(pPlain, nPlainLen, pHash);
}

inline string md5ToString(byte data[]){
    string result;
    result.reserve(32);
    for(int i=0; i < 16; i++)
    {
        result += "0123456789abcdef"[data[i]/16];
        result += "0123456789abcdef"[data[i]%16];
    }
    return result;
}
#endif //TP2_INFO901_CONTEXTE_H
