//
// Created by antoine on 08/10/18.
//

#include <openssl/md5.h>
#include <openssl/sha.h>

#ifndef TP2_INFO901_HASHALGORITHM_H
#define TP2_INFO901_HASHALGORITHM_H


class HashAlgorithm {

public:
    static void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
    static void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
};


#endif //TP2_INFO901_HASHALGORITHM_H
