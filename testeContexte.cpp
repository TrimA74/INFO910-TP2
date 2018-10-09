//
// Created by antoine on 09/10/18.
//

#include <iostream>
#include "Contexte.h"

int main(int argc, char** argv){
    Contexte contexte;
    contexte._N              = 456976; // 26^4
    contexte._mot_taille_min = 4;     // 4 lettres min
    contexte._mot_taille_max = 4;     // 4 lettres max
    contexte._N_taille     = { 456976 }; // il n'y a que les mots de 4 lettres
    contexte._nb_lettres     = 26;    // 26 lettres de l'alphabet
    contexte._lettres      = "abcdefghijklmnopqrstuvwxyz"; // l'alphabet


    /*
    byte hashedText[16];
    contexte.h("azerty",hashedText);
    cout << md5ToString(hashedText);
     */
    string result;
    contexte.i2c(16955,result);
    cout << "result = " << result <<endl;

}