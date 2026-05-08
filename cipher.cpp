#include "cipher.h"

namespace CipherSpace{

    /*
      Caesar encryption shift each letter in the string by fixed number
      It takes in the string you want to encrypt,and the value of the shift
      you want to apply to each letter in that string
    */
    string caesarEncrypt(string text, int key) {
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            //deciding if the base is an uppercase or lowercase
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + key) % 26 + base;
        }
     }
     return text;
    }

    /*
      Caesar decryption reverses the encryption by shifting each letter
      in reverse by the same fixed number
      It takes in the encrypted string,and the same value used in encryption
    */
    string caesarDecrypt(string text, int key) {
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base - key) % 26 + base;
        }
    }
    return text;
  }

   /*
     This function tries all possible shifts,and one the results will be the encrypted string
   */
   void caesarDecryptForce(string text,int key){
      do{
       for (int i = 0; i < text.size(); i++) {
          if (isalpha(text[i])) {
              char base = isupper(text[i]) ? 'A' : 'a';
              text[i] = (text[i] - base - key + 26) % 26 + base;
          }
      }

    cout << "Force decryption: " << key << " " << text << endl;

    key++;
    }while(key < 26);

  }
   /*
     The Vigenere encryption consists in applying a word to shift each character in the string
     Each letter in the key-word will apply the shift to any corresponding letter in the string
   */
   string vigeneraEncrypt(string text, string key) {
       //tracking the position of the key
      int keyIndex = 0;

      for (int i = 0; i < text.size(); i++) {
          if (isalpha(text[i])) {
              char base = isupper(text[i]) ? 'A' : 'a';
              int shift = tolower(key[keyIndex % key.size()]) - 'a';
              text[i] = (text[i] - base + shift) % 26 + base;
              keyIndex++;
          }
      }
      return text;
   }

   /*
     The Vigenere decryption reverses the string by applying the keyword shift in the opposite direction

   */
   string vigeneraDecrypt(string text,string key){
       int keyIndex = 0;

      for (int i = 0; i < text.size(); i++) {
          if (isalpha(text[i])) {
              char base = isupper(text[i]) ? 'A' : 'a';
              int shift = tolower(key[keyIndex % key.size()]) - 'a';
              text[i] = (text[i] - base - shift + 26) % 26 + base;
              keyIndex++;
          }
      }

       return text;
   }


   /*
     This function is trying to apply the shift based on each letter of the keyword
     Each key[i] will provide a a shift to the string,until all the letters have provided a shift
   */
   string vigeneraTryEncrypt(string text,string key){
      for(char k : key){
          int shift = tolower(k) - 'a';

          for (int i = 0; i < text.size(); i++) {
              if (isalpha(text[i])) {
                  char base = isupper(text[i]) ? 'A' : 'a';
                  text[i] = (text[i] - base + shift) % 26 + base;
              }
          }
      }
      return text;
  }


   /*
     This reverses the shift applied by each letter to the string
     It starts with the last letter of the keyword down to the first letter
   */
   string vigeneraTryDecrypt(string text,string key){

         for(int j = key.size() - 1; j >= 0; j--) {
            char k = key[j];
            int shift = tolower(k) - 'a';

            for (int i = 0; i < text.size(); i++) {
               if (isalpha(text[i])) {
               char base = isupper(text[i]) ? 'A' : 'a';
               text[i] = (text[i] - base - shift + 26) % 26 + base;
               }
            }
         }

       return text;
    }


}
