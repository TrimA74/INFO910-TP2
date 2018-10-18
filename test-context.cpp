#include <cmath>
#include <iostream>
#include "Context.h"

bool assert(uint a, uint b){
    return a == b;
}

void testContext(Context context){
    cout << "-------------------------------------------------------------------" << endl;
    cout << "taille   = 5"<<endl;
    cout << "alphabet = abcdefghijklmnopqrstuvwxyz" << endl;
    cout << "nblettres= 26"<< endl;
    cout << "N = 11881376" << endl;
    cout << "T = 50000" << endl;
    cout << "M = 100" << endl;

    cout << endl;
    cout << "-------- Exemples de calcul des fonctions i2c, h, c2i(t) ----------" << endl;
    uint64 idxStart[10] = {11844934, 11444147, 6723391, 4442476, 5431405, 2374699, 6220699, 5604454, 11769570, 9018072};
    string clear;
    byte hashed[16];
    uint64 idxEnd;

    for(int i=0; i<10; i++){
        context.i2c(idxStart[i],clear);
        context.h(clear,hashed);
        idxEnd = context.h2i(1,hashed);
        cout << idxStart[i] << " -i2c-> " << clear << " -h-> " << md5ToString(hashed) << " -h2i(1)->"<< idxEnd << endl;
        cout << idxStart[i] << " -i2i(1)-> " << context.i2i(idxStart[i], 1) << endl;
    }
}

bool testChainCalcul(Context context){
    cout << "-------- Exemples de calcul de chaînes de longueur T=50000 ----------" << endl;
    uint64 idxStart[10] = {1172136, 427373, 1144282, 6286051, 6839583, 7356570, 5866002, 2529175, 3285784, 3354650};
    uint64 idxEnd;
    for(int i=0; i<10; i++){
        idxEnd = idxStart[i];
        cout << idxStart[i] << " -i2i(1)-> ... ";
        for(uint64 j=1; j<50000; j++){
            idxEnd = context.i2i(idxEnd,j);
        }
        cout << "-i2i(49999)-> " << idxEnd << endl;

    }
}

bool testh2i(Context context){
    bool result = true;
    //Test i2c
    string c = "";
    context.i2c(11844934,c);
    cout << "i2c = " << c <<endl;
    return result;
}

bool testi2i(Context context){
    bool result = true;
    //Test i2c
    string c = "";
    context.i2c(11844934,c);
    cout << "i2c = " << c <<endl;
    return result;
}

int main(int argc, char** argv){
    Context context;

    //Initialize context
    context.N              = 11881376; // 26^5
    context.word_length_min = 5;     // 5 lettres min
    context.word_length_max = 5;     // 5 lettres max
    context.N_length     = { context.N }; // il n'y a que les mots de 5 lettres
    context.nb_letters     = 26;    // 26 lettres de l'alphabet
    context.letters      = "abcdefghijklmnopqrstuvwxyz"; // l'alphabet

    testContext(context);
    testChainCalcul(context);




    /*
    //Test i2i
    uint64 idx = 400843;
    for(uint64 i=1; i<50000; i++) {
        idx = context.i2i(idx, i);
    }
    cout << "N=" << context.N << endl;
    cout << idx <<endl;
    *///return 0;
}

/*#include <iostream>
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


    byte hashedText[16];
    contexte.h("azerty",hashedText);
    cout << md5ToString(hashedText);



    string result;
    contexte.i2c(11844934,result);
    cout << "result = " << result <<endl;
    byte hash[16];
    contexte.h(result,hash);
    cout << "h() " << md5ToString(hash) << endl;
    cout << contexte.h2i(1,hash) << endl;


}*/