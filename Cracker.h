//
// Created by antoine on 08/10/18.
//

#ifndef TP2_INFO901_CRACKER_H
#define TP2_INFO901_CRACKER_H


#include "Rainbow.h"

class Cracker {
public:
    bool cracker( byte y[], Rainbow& rainbow, Context& context,
                  string & clear );
    bool verifyAlert( byte hashed[], Context context, vector<Chain> X, int t, int m, string& clear);
    uint getProbability(uint64 N, uint M, uint T);
};


#endif //TP2_INFO901_CRACKER_H
