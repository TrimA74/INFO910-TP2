//
// Created by antoine on 08/10/18.
//

#ifndef TP2_INFO901_CRACKER_H
#define TP2_INFO901_CRACKER_H


#include "Contexte.h"
#include "ArcEnCiel.h"

class Cracker {
    bool cracker( byte y[], const ArcEnCiel& aec, const Contexte& ctxt,
                           string & clair );
};


#endif //TP2_INFO901_CRACKER_H
