#include <cmath>
#include <iostream>
#include "Context.h"

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
    uint64 idxStart[11] = {1172136, 427373, 1144282, 6286051, 6839583, 7356570, 5866002, 2529175, 3285784, 3354650,442565};
    uint64 idxEnd;
    for(int i=0; i<11; i++){
        idxEnd = idxStart[i];
        cout << idxStart[i] << " -i2i(1)-> ... ";
        for(unsigned j=1; j< 50000; j++){
            idxEnd = context.i2i(idxEnd,j);
        }
        cout << "-i2i(49999)-> " << idxEnd << endl;

    }

    return true;
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
    Context context(5,5,"abcdefghijklmnopqrstuvwxyz");

    testContext(context);
    testChainCalcul(context);

    return 0;
}