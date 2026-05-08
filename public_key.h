#ifndef PUBLIC_KEY_H_INCLUDED
#define PUBLIC_KEY_H_INCLUDED

#include <string>


using namespace std;

namespace RSASpace{

    struct RSAKeys {
        long long e, d, n;
        //false if invalid primes were given
        bool valid;
    };

    bool isPrime(int number);
    long long modPow(long long base, long long exp, long long mod);
    long long extendedGCD(long long a, long long b, long long &x, long long &y);
    long long modInverse(long long e, long long phi);
    RSAKeys generateKeys(long long p, long long q);
    string rsaEncrypt(string text, RSAKeys keys);
    string rsaDecrypt(string ciphertext, RSAKeys keys);

}


#endif // PUBLIC_KEY_H_INCLUDED
