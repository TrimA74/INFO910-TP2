//
// Created by antoine on 08/10/18.
//

#ifndef TP2_INFO901_CRACKER_H
#define TP2_INFO901_CRACKER_H


#include "Rainbow.h"

class Cracker {
public:
    bool cracker( byte y[], const Rainbow& rainbow, const Context& context,
                  string & clear );
};


#endif //TP2_INFO901_CRACKER_H
