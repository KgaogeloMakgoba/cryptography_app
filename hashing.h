#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;

namespace HashingSpace{

    int hashPolynomial(string text);
    void fileEncryption(string key);
    void fileDecryption(string key);
    void registerUser(string usernamre,string password);
    bool verifyUser(string username, string password);



}



#endif // HASHING_H_INCLUDED
