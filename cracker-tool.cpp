//
// Created by antoine on 11/10/18.
//

#include <iostream>
#include <sstream>
#include <cstring>
#include "Rainbow.h"
#include "Cracker.h"

using namespace std;

void str2bin(const std::string& in, unsigned char out[]){

    const char* data = in.data();
    const std::string::size_type size = in.size();
    for(std::string::size_type i = 0; i < size; i+= 2) {
        unsigned int tmp;
        std::sscanf(data+i, "%02X", &tmp);
        out[i/2] = tmp;
    }
}

int main(int argc, char** argv){

    if(argc != 3){
        cout << "Usage : ./cracker-tool <hashed> <basename_word-length-min_word-length-max_letters_M_T.txt>" << endl;
        cout << "Example for azert : ./cracker-tool cdaa6716746fb685734abde87f1b08ad rainbow_5_5_abcdefghijklmnopqrstuvwxyz_100000_1000.txt" << endl;
        return -1;
    }

    //Read filename and extract data from it
    string filename = argv[2];
    istringstream iss(filename);
    string word = "";
    //skip basename
    getline(iss, word,'_');
    word.clear();

    getline(iss, word,'_');
    int word_length_min = stoi(word);
    word.clear();
    getline(iss, word,'_');
    int word_length_max = stoi(word);
    word.clear();
    getline(iss, word,'_');
    string letters = word;
    word.clear();
    getline(iss, word,'_');
    int M = stoi(word);
    word.clear();
    getline(iss, word,'_');
    int T = stoi(word.substr(0, word.length() - 4 ));

    Rainbow rainbow;
    Cracker tool;
    Context context(word_length_min,word_length_max,letters);

    //Initialize context
    /*
    context.N              = 11881376; // 26^5
    context.word_length_min = 5;     // 5 lettres min
    context.word_length_max = 5;     // 5 lettres max
    context.N_length     = { context.N }; // il n'y a que les mots de 5 lettres
    context.nb_letters     = 26;    // 26 lettres de l'alphabet
    context.letters      = "abcdefghijklmnopqrstuvwxyz"; // l'alphabet
*/
    rainbow._M = M;
    rainbow._T = T;

    //Load rainbow
    rainbow.load(argv[2]);

    //Read hashed and convert to an array of byte
    byte hashedText[16];
    str2bin(argv[1],hashedText);

    string clear = "";
    //To get 2 decimals
    double probability = round(tool.getProbability(context.N,M,T)*100*100)/100;
    cout << "Percentage of success = " << probability << "%" <<endl;
    if(tool.cracker(hashedText, rainbow, context, clear))
        cout << "Crack successfull ! clear = " << clear << endl;
    else
        cout << "Crack failed !" << endl;

    return 0;
}