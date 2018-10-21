//
// Created by antoine on 15/10/18.
//

#include <iostream>
#include <cmath>
#include "Rainbow.h"

using namespace std;

void setOutputName(string& output, Context context, int M, int T){
    //basename_word-length-min_word-length-max_letters.txt
    output += "_" + to_string(context.word_length_min) + "_" + to_string(context.word_length_max) + "_" + context.letters + "_" + to_string(M) + "_" + to_string(T) + ".txt";
}

int main(int argc, char** argv){

    if(argc != 7){
        cout << "Usage : ./rainbow-tool <word-length-min> <word-length-max> <letters> <number-of-chains> <length-of-a-chain> <filename-ouput.txt>" << endl;
        cout << "Example : ./rainbow-tool 5 5 a-z 100000 1000 rainbow" << endl;
        return -1;
    }

    int worldLengthMin = atoi(argv[1]);
    int worldLengthMax = atoi(argv[2]);
    string letters = argv[3];

    if(letters == "a-z")
        letters = "abcdefghijklmnopqrstuvwxyz";

    int M = atoi(argv[4]);
    int T = atoi(argv[5]);
    string output = argv[6];

    Rainbow rainbow;
    Context context(worldLengthMin, worldLengthMax,letters);

    setOutputName(output, context, M, T);

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