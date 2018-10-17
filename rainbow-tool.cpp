//
// Created by antoine on 15/10/18.
//

#include <iostream>
#include <cmath>
#include "Rainbow.h"

using namespace std;

int main(int argc, char** argv){

    cout << argc<<endl;
    if(argc != 5){
        cout << "Usage : ./rainbow-tool <word-length> <number-of-chains> <length-of-a-chain> <filename-ouput.txt>" << endl;
        cout << "Example : ./rainbow-tool 5 1000 100000 rainbow.txt" << endl;
        return -1;
    }

    int worldLength = atoi(argv[1]);
    int M = atoi(argv[2]);
    int T = atoi(argv[3]);
    string output = argv[4];

    cout << "worldLength = " << worldLength <<endl;
    cout << "M = " << M<<endl;
    cout << "T = " << T << endl;
    cout << "output = " << output << endl;

    Rainbow rainbow;
    Context context;

    //Initialize context
    context.N              = pow(26,worldLength); // 26^5
    context.word_length_min = worldLength;     // 5 lettres min
    context.word_length_max = worldLength;     // 5 lettres max
    context.N_length     = { context.N }; // il n'y a que les mots de 5 lettres
    context.nb_letters     = 26;    // 26 lettres de l'alphabet
    context.letters      = "abcdefghijklmnopqrstuvwxyz"; // l'alphabet


    /*
    //Test i2c
    string c = "";
    context.i2c(11844934,c);
    cout << "i2c = " << c <<endl;
     */
    //Test i2i
    uint64 idx = 400843;
    for(uint64 i=1; i<50000; i++) {
        idx = context.i2i(idx, i);
    }
    cout << "N=" << context.N << endl;
    cout << idx <<endl;
    //return 0;


    //Create rainbow table
    rainbow.create(context,0,M,T);
    //Save rainbow in ouput file
    if(rainbow.save(output)){
        cout << "Saving file finished !" << endl;
    }else{
        cout << "Unable to open file " << output << "!" << endl;
    }


    return 0;
}