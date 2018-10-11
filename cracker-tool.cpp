//
// Created by antoine on 11/10/18.
//

#include <iostream>
#include "Rainbow.h"
#include "Cracker.h"

using namespace std;

int main(int argc, char** argv){

    if(argc != 3){
        cout << "Usage : ./cracker-tool <hashed> <filename>" << endl;
        return -1;
    }

    Rainbow rainbow;
    Cracker tool;
    Context context;

    //Initialize context
    context.N              = 11881376; // 26^5
    context.word_length_min = 5;     // 5 lettres min
    context.word_length_max = 5;     // 5 lettres max
    context.N_length     = { 11881376 }; // il n'y a que les mots de 4 lettres
    context.nb_letters     = 26;    // 26 lettres de l'alphabet
    context.letters      = "abcdefghijklmnopqrstuvwxyz"; // l'alphabet

    rainbow.create(context,0,100,50000);
    //Load rainbow
    rainbow.load(argv[2]);

    //Read hashed and convert to an array of byte
    const string& hashedString = argv[1];
    byte md5Hashed[hashedString.length()];
    copy(hashedString.begin(), hashedString.end(),md5Hashed);

    string clear = "";
    if(tool.cracker(md5Hashed, rainbow, context, clear))
        cout << "Crack successfull !" << endl;
    else
        cout << "Crack failed !" << endl;

    return 0;
}