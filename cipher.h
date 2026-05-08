#ifndef CIPHER_H_INCLUDED
#define CIPHER_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

namespace CipherSpace{

    string caesarEncrypt(string text,int key);
    string caesarDecrypt(string text,int key);
    void caesarDecryptForce(string text,int key);
    string vigeneraEncrypt(string text,string key);
    string vigeneraDecrypt(string text,string key);
    string vigeneraTryEncrypt(string text,string key);
    string vigeneraTryDecrypt(string text,string key);

}



#endif // CIPHER_H_INCLUDED
