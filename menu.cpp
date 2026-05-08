#include "hashing.h"
#include "cipher.h"
#include "menu.h"
#include "public_key.h"


using namespace HashingSpace;
using namespace CipherSpace;
using namespace RSASpace;


namespace MenuSpace{

    void mainMenu(){

        cout << "Please select one of the following encryption method" << endl;
        cout << "1)Classical ciphers" << endl;
        cout << "2)File Encryption/Decryption" << endl;
        cout << "3)RSA-Public Key Encryption/Decryption" << endl;

        int choice;
        cin >> choice;



        switch(choice){
            case 1:
                printMenuOne();
                break;

            case 2:
                printMenuTwo();
                break;

            case 3:
                rsaMenu();
                break;

            default:
                cerr << "Invalid input" << endl;
        }
    }

    void printMenuOne(){
        cout << "---------------------------------------------------------------------" << endl;
        cout << "--------------------------CLASSICAL CIPHERS--------------------------" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "------Select one of the ciphers to encrypt/decrypt your message------" << endl;

        cout << "A)Caesar cipher" << endl;
        cout << "B)Vigenere cipher(shifts by corresponding letter)" << endl;
        cout << "C)Vigenere cipher(shifts by the entire string)" << endl;
        cout << "D)Back to Main Menu" << endl;
        cout << "E)Quit" << endl;

        char choice;
        int keys;
        string msg;
        string strkey;

        cin >> choice;

        switch(toupper(choice)){
        case 'A':
           {


           cout << "Enter the message you want to encrypt" << endl;
           cin >> msg;
           cout << "Enter the key(it has to be an integer)" << endl;
           cin >> keys;

           if(cin.fail()){
            cerr << "Wrong value,please input an integer value" << endl;
            exit(ERR_INPUT);
           }

           string encrypted = caesarEncrypt(msg,keys);
           string decrypted = caesarDecrypt(encrypted,keys);
           cout << "Your encrypted message is: " << encrypted << endl;
           cout << "Your decrypted message is: " << decrypted << endl;
           cout << " " << endl;
           cout << "Your decrypted message by brute force" << endl;
           cout << "Your decrypted message is one of these options below: " << endl;
           caesarDecryptForce(msg,1);
           break;
           }

       case 'B':
          {

           cout << "Enter the message you want to encrypt" << endl;
           cin >> msg;
           cout << "Enter the key(string of letters)" << endl;
           cin >> strkey;
           string encrypted = vigeneraEncrypt(msg,strkey);
           string decrypted = vigeneraDecrypt(encrypted,strkey);
           cout << "Your encrypted message is: " << encrypted << endl;
           cout << "Your decrypted message is: " << decrypted << endl;
           break;
          }
       case 'C':
          {
            cout << "Enter the message you want to enrypt" << endl;
            cin >> msg;
            cout << "Enter the key(string of letters)" << endl;
            cin >> strkey;
            string encrypted = vigeneraTryEncrypt(msg,strkey);
            string decrypted = vigeneraTryDecrypt(encrypted,strkey);
            cout << "Your encrypted message is: " << encrypted << endl;
            cout << "Your decrypted message is: " << decrypted << endl;
            break;

          }

      case 'D':
          mainMenu();


      case 'E':
        exit(EXIT_CODE);
        break;

      default:
        cerr << "Invalid option" << endl;

    }


   }


    void printMenuTwo(){

     cout << "1)XOR encrypt a file" << endl;
     cout << "2)XOR decrypt a file" << endl;
     cout << "3)Store a password" << endl;
     cout << "4)Verify password" << endl;
     cout << "5)Back to main menu" << endl;

     string secretKey;
     string userName;
     string password;

     int intChoice;
     cin >> intChoice;

     switch(intChoice){

         case 1:
             {
              cout << "Enter the key to encrypt your file(string)" << endl;
              cin >> secretKey;
              fileEncryption(secretKey);
              break;

             }

         case 2:
            {
                cout << "Enter the key to decrypt your file(string)" << endl;
                cin >> secretKey;
                fileDecryption(secretKey);
                break;
            }

         case 3:
            {
                cout << "Enter your username" << endl;
                cin >> userName;
                cout << "Enter your password" << endl;
                cin >> password;
                registerUser(userName,password);
                break;
            }
         case 4:
            {
                cout << "Enter your username" << endl;
                cin >> userName;
                cout << "Enter your password" << endl;
                cin >> password;
                verifyUser(userName,password);
                break;
            }
         case 5:
             {
                 mainMenu();
             }
         default:
             cerr << "Wrong input" << endl;
             exit(ERR_INPUT);



     }
  }

    void rsaMenu() {

      cout << "1)RSA-Public Key encryption/Encryption" << endl;
      cout << "2)Back to Main Menu" << endl;
      cout << "3)Quit" << endl;

      int choice;
      cin >> choice;

      switch(choice){

      case 1:
          {
             long long p;
             long long q;

             cout << "Enter prime p: ";
             cin >> p;
             cout << "Enter prime q: ";
             cin >> q;

             RSAKeys keys = generateKeys(p, q);

            //stop if bad primes are given
            if (!keys.valid) return;

            string message;
            cout << "Enter message to encrypt: ";
            cin.ignore();
            getline(cin, message);

            string encrypted = rsaEncrypt(message, keys);
            cout << "Encrypted: " << encrypted << endl;

            string decrypted = rsaDecrypt(encrypted, keys);
            cout << "Decrypted: " << decrypted << endl;
            break;
           }

           case 2:
             mainMenu();
             break;

          case 3:
            exit(EXIT_CODE);

      default:
        cerr << "Invalid Input" << endl;
        exit(ERR_INPUT);

         }

       }

}
