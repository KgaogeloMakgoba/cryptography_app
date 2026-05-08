#include "hashing.h"
#include "cipher.h"

using namespace CipherSpace;

namespace HashingSpace{


    /*
      This function turns a string into a number
      It turns the string into a polynomial
      Each character in the string is raised to the power of its index
    */
    int hashPolynomial(string text){
     const int p = 31;
     const int m = 1e9 + 7;

     int hash1 = 0;
     int power = 1;

     for (int i = 0; i < text.size(); i++) {
        text[i] = toupper(text[i]);
        int value = text[i] - 'a' + 1;
        hash1 = (hash1 + value * power) % m;
        power = (power * p) % m;
    }

 return hash1;
 }


 void writeTextFile(){

 ofstream writeFile("test.txt",ios::binary);

 string text;

 cout << "Please enter a paragraph/message you want to encrypt" << endl;

 while(getline(cin,text)){
    writeFile << text << endl;
    if(text == "END")
        break;

     writeFile << text << endl;
   }

 }
 //Reading the text file
 void readTextFile(){
     ifstream readFile("test.txt",ios::binary);
     string line;

     //while there is a line in the file(test.txt)
     //store that line in string line and output that line
     while(getline(readFile,line)){
        cout << line << endl;
     }

 }


 void fileEncryption(string key){

     writeTextFile();
     //Reads the file in Binary mode(raw bytes)
     ifstream readFile("test.txt",ios::binary);
     //Creates a file that will be wrotten in binary mode
     ofstream writeFile("encrypted.txt", ios::binary);

     char byte;
     int keyIndex = 0;

     while (readFile.get(byte)) {
     //XOR each byte with key
     byte = byte ^ key[keyIndex % key.size()];
     writeFile.put(byte);
     keyIndex++;
     }

     readFile.close();
     writeFile.close();

 }

 void fileDecryption(string key){
     ifstream readFile("encrypted.txt",ios::binary);
     ofstream writeFile("decrypted.txt", ios::binary);

     char byte;
     int keyIndex = 0;

     while (readFile.get(byte)) {
     //XOR each byte with key
     byte = byte ^ key[keyIndex % key.size()];
     writeFile.put(byte);
     keyIndex++;
     }

     readFile.close();
     writeFile.close();

 }

 void registerUser(string username,string password){
     ifstream readFile("register.txt");
     string storedUser;
     int storedHash;
     while (readFile >> storedUser >> storedHash) {
        if (storedUser == username) {
            cout << "Username already taken." << endl;
            readFile.close();
            return;
        }
    }
    readFile.close();

    //If username is free we write it
    ofstream writeFile("register.txt", ios::app);
    //the password is then hashed
    int inputHash = hashPolynomial(password);
    writeFile << username << " " << inputHash << endl;
    writeFile.close();
    cout << "Successfully registered" << endl;

 }


 bool verifyUser(string username, string password) {
    ifstream readFile("register.txt");

    string storedUser;
    int storedHash;
    int inputHash = hashPolynomial(password);

    while (readFile >> storedUser >> storedHash) {
        if (storedUser == username && storedHash == inputHash) {
            cout << "Verified successfully" << endl;
            return true;
        }
    }
    cout << "Could not be verified,please enter the correct username and password" << endl;
    return false;
}




}
