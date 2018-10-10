//
// Created by antoine on 09/10/18.
//

#include <iostream>
#include "Contexte.h"
#include "ArcEnCiel.h"

int main(int argc, char** argv){
    Contexte contexte;
    contexte._N              = 11881376; // 26^5
    contexte._mot_taille_min = 5;     // 5 lettres min
    contexte._mot_taille_max = 5;     // 5 lettres max
    contexte._N_taille     = { 11881376 }; // il n'y a que les mots de 4 lettres
    contexte._nb_lettres     = 26;    // 26 lettres de l'alphabet
    contexte._lettres      = "abcdefghijklmnopqrstuvwxyz"; // l'alphabet


    //ArcEnCiel arcEnCiel;
    //arcEnCiel.creer(contexte,0,100,50000);
    /*
    byte hashedText[16];
    contexte.h("azerty",hashedText);
    cout << md5ToString(hashedText);
     */

    /*
    string result;
    contexte.i2c(11844934,result);
    cout << "result = " << result <<endl;
    byte hash[16];
    contexte.h(result,hash);
    cout << "h() " << md5ToString(hash) << endl;
    cout << contexte.h2i(1,hash) << endl;
*/

}