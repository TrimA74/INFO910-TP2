//
// Created by antoine on 09/10/18.
//

#include <iostream>
#include "Context.h"
#include "Rainbow.h"

int main(int argc, char** argv){
    Context context;
    context.N               = 11881376; // 26^5
    context.word_length_min = 5;     // 5 lettres min
    context.word_length_max = 5;     // 5 lettres max
    context.N_length        = { 11881376 }; // il n'y a que les mots de 4 lettres
    context.nb_letters      = 26;    // 26 lettres de l'alphabet
    context.letters         = "abcdefghijklmnopqrstuvwxyz"; // l'alphabet

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