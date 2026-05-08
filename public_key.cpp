#include "public_key.h"
#include <iostream>
#include <sstream>



namespace RSASpace{
//Checking if a number is prime or not
  bool isPrime(int number){
      if (number <= 1) return false;
      if (number == 2) return true;
      if (number % 2 == 0) return false;

      for (int i = 3; i * i <= number; i += 2) {
         if (number % i == 0)
            return false;
        }
      return true;

  }

  // Computes (base^exp) % mod efficiently without overflow
  long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;

    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp = exp / 2;
    }

      return result;
 }

  /* Finds x and y such that: a*x + b*y = gcd(a, b)
     We need this because when gcd(e, phi) = 1,
     it gives us e*x + phi*y = 1, meaning e*x ≡ 1 (mod phi)
     That x becomes our private key d
  */
  long long extendedGCD(long long a, long long b, long long &x, long long &y) {
      if (b == 0) {
          x = 1;
          y = 0;
          return a;
      }
      long long x1, y1;
      long long g = extendedGCD(b, a % b, x1, y1);
      x = y1;
      y = x1 - (a / b) * y1;
      return g;
  }

  /*Finds d such that: e * d ≡ 1 (mod phi)
    d is the private key — it reverses what e (the public key) did
  */
  long long modInverse(long long e, long long phi) {
      long long x, y;
      long long g = extendedGCD(e, phi, x, y);
      if (g != 1) {
          cout << "Inverse doesn't exist" << endl;
          return -1;
      }
      return (x % phi + phi) % phi;
  }

   // Generates a public and private key pair from two prime numbers
   RSAKeys generateKeys(long long p, long long q) {
        //Validating if the numbers are prime
        if (!isPrime(p) || !isPrime(q)) {
            cout << "Error: both numbers must be prime." << endl;
            return {0, 0, 0, false};
        }
        if (p == q) {
            cout << "Error: p and q must be different primes." << endl;
            return {0, 0, 0, false};
        }

        long long n   = p * q;
        long long phi = (p - 1) * (q - 1);
        long long e   = 17;
        long long d   = modInverse(e, phi);

        if (d == -1) {
            cout << "Error: could not generate private key." << endl;
            return {0, 0, 0, false};
        }

        //n must be > 127 to handle all ASCII characters
        if (n <= 127) {
            cout << "Error: primes too small. n must be > 127." << endl;
            return {0, 0, 0, false};
        }

        cout << "\nKeys generated successfully." << endl;
        cout << "Public key:  (e = " << e << ", n = " << n << ")" << endl;
        cout << "Private key: (d = " << d << ", n = " << n << ")" << endl;

        return {e, d, n, true};
    }

    /*Encrypts a string using the public key (e, n)
       Each character is converted to its ASCII number,
       then transformed using modPow — result is unreadable numbers
     */
    string rsaEncrypt(string text, RSAKeys keys) {
        if (!keys.valid) {
            return "Error: invalid keys.";
        }
        string result = "";
        for (char c : text) {
            long long encrypted = modPow((long long)c, keys.e, keys.n);
            result += to_string(encrypted) + " ";
        }
        return result;
    }

    /*Decrypts a string of numbers back to the original message
      Uses the private key (d, n) — reverses what rsaEncrypt did
    */
    string rsaDecrypt(string ciphertext, RSAKeys keys) {
        if (!keys.valid) {
            return "Error: invalid keys.";
        }
        string result = "";
        stringstream ss(ciphertext);
        long long num;
        while (ss >> num) {
            result += (char)modPow(num, keys.d, keys.n);
        }
        return result;
    }




}
