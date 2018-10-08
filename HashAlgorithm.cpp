//
// Created by antoine on 08/10/18.
//

#include "HashAlgorithm.h"
static void HashAlgorithm::HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
    MD5(pPlain, nPlainLen, pHash);
}
static void HashAlgorithm::HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
    SHA1(pPlain, nPlainLen, pHash);
}