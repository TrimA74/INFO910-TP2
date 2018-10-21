//
// Created by antoine on 17/10/18.
//

#include <iostream>
#include "Cracker.h"

int main(int argc, char** argv){
    if(argc != 4) {
        cout << "Usage : ./parameters-tool N M T" << endl;
        cout << "Example : ./parameters-tool 11881376 100000 1000" << endl;
        return 0;
    }
    Cracker tool;
    uint64 N = stoull(argv[1]);
    uint M = stoul(argv[2]);
    uint T = stoul(argv[3]);
    cout << "Probability of success : " << tool.getProbability(N, M, T);
    return 0;
}