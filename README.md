Cryptography Application
A C++ console application implementing encryption and decryption algorithms from scratch.Built as a self-directed project to move from guided school practicals to independent software development.

What it does
The application has three sections,each accessible through a menu system:

Classical Ciphers - encrypt and decrypt text using letter-shifting algorithms
File Encryption & Password Manager - encrypt real files and store passwords securely
RSA Encryption - public-key encryption where different keys encrypt and decrypt

Classical Ciphers
Caesar Cipher
Shifts every letter in a message by a fixed number.A key of 3 turns A into D, B into E, and so on. When the shift goes past Z it wraps back around to A,this is modular arithmetic using the % operator.
Caesar Brute-Force
Since Caesar only has 26 possible keys,this option tries all of them and prints every result.Useful for breaking an encrypted message without knowing the key - you scan the output and spot the readable one.
Vigenère Cipher
An improved version of Caesar where instead of one fixed shift,a keyword provides a different shift for each letter.The keyword repeats across the message so every letter gets its own shift value, making it much harder to break than Caesar.
Sequential Keyword Cipher(custom)
An original cipher designed during development.It applies each letter of the keyword as a full Caesar shift across the entire message,one after another. Decryption reverses by applying the shifts in reverse keyword order.It behaves differently from standard Vigenère and was built as an experiment in designing original encryption logic.

File Encryption & Password Manager
XOR File Encryption
Encrypts any file by combining each byte with a key using the XOR bitwise operation.The interesting property of XOR is that applying the same operation twice returns the original,so the encrypt and decrypt functions are identical.Running it on an encrypted file with the same key gives back the original.
Note that the results of this process will have to be read directly on the generated encrypted.txt and decrypted.txt files.

Password Manager
Register:takes a username and password,converts the password to a hash number using a polynomial hash function and saves username + hash to a file. The actual password is never stored anywhere.
Verify:when logging in,hashes the entered password and compares it to the stored hash.If they match,access is granted,without ever needing to store or read the real password.
Prevents duplicate usernames at registration.
Data persists to a file so registered users survive after the program closes.

Hash Function
Converts any string into a large number by processing each character with a multiplier formula.The same string always produces the same number,but you cannot reverse the number back to the original string - which is what makes it safe for storing passwords.

RSA Encryption
RSA is a public-key encryption system - you have two keys,one to encrypt and one to decrypt.What one key locks, only the other can unlock.

How it works in this project
User provides two prime numbers
The application generates a public key and a private key from those primes
A message is encrypted using the public key - each character becomes a number
The encrypted numbers are decrypted back to the original message using the private key

What was implemented from scratch

Prime checker - validates that inputs are prime numbers before key generation
Modular exponentiation - computes very large powers without numbers overflowing,used during encryption and decryption
Extended Euclidean Algorithm - finds the private key mathematically from the public key and the prime inputs

Example
Primes:p=61,q=53
Public key:(e=17,n=3233)
Private key:(d=2753,n=3233)

Message: Hello
Encrypted: 3000 1313 745 745 2185
Decrypted: Hello

Project Structure
cryptography_app/
├── main.cpp          ← entry point
├── menu.h/.cpp       ← all menus and user interaction
├── cipher.h/.cpp     ← Ciphers
├── hashing.h/.cpp    ← File encryption and password manager
└── public_key.h/.cpp ← RSA
main.cpp only calls mainMenu() - all logic lives in the appropriate file.

What I learned building this

How to structure a C++ project across multiple files using headers
How classical ciphers work and why some are easier to break than others
How XOR operations can encrypt and decrypt with the same function
Why passwords should never be stored in plain text - and how hashing solves that
How RSA generates two mathematically linked keys from prime numbers
How to apply STL tools (vector,map,stringstream,fstream)in a real project rather than isolated exercises


Limitations

RSA works correctly for demonstration but uses standard integer sizes,real-world RSA uses much larger numbers requiring special big-integer libraries
The hash function is suitable for learning but not production security,real password systems use dedicated algorithms like bcrypt
Console only - no GUI
