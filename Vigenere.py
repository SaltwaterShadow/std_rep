
import string

#Stantandard Vigenere, no enhancements, incredibly boring to write, but worthwhile base
# ord is convert letter into unicode
#chr converts unicode to letter
# using a defined main function called by one line of code
# encrypts/decrypts a file given to it by user
# lets user enter keyword



#Stantandard Vigenere, no enhancements, incredibly boring to write, but worthwhile base
# ord is convert letter into unicode
#chr converts unicode to letter
# using a defined main function called by one line of code
# encrypts/decrypts a file given to it by user
# lets user enter keyword



def encrypt(plain_text, key):
    print("encrypting...")
    cipher_text = ""

    for i in range(len(plain_text)):
        c = plain_text[i]
        k = key[i]

        if c.islower():
            cipher_text += chr((ord(c) - ord('a') + ord(k) - ord('a')) % 26 + ord('a'))
        elif c.isupper():
            cipher_text += chr((ord(c) - ord('A') + ord(k) - ord('A')) % 26 + ord('A'))
        else:
            cipher_text += c

    return cipher_text

def decrypt(cipher_text, key):
    print("decrypting...")
    plain_text = ""

    for i in range(len(cipher_text)):
        c = cipher_text[i]
        k = key[i]

        if c.islower():
            plain_text += chr((ord(c) - ord('a') - (ord(k) - ord('a'))) % 26 + ord('a'))
        elif c.isupper():
            plain_text += chr((ord(c) - ord('A') - (ord(k) - ord('A'))) % 26 + ord('A'))
        else:
            plain_text += c

    return plain_text

#generate key and confirm that it is fully alphabetic before expanding it out to the length of plaintext
def generate_key(txt):
    while True:
        keyphrase = input("Enter an alphabetic keyphrase: ")
        if keyphrase.isalpha():
            break
        print("Key must be alphabetic.")

    key = ""
    while len(key) < len(txt):
        key += keyphrase

    return key[:len(txt)]

print("Hello. Welcome to the Vigenere Cipher, version one. ")
print("This program will encrypt or decrypt the text typed into it using a user-entered keyword. It will do nothing else. ")

choice = int(input("Would you like this to 1. Encrypt or 2. Decrypt '1' or '2': "))
#if choice != 1 and choice != 2:

intact_txt = input("Enter the text you would like to encrypt/decrypt: ")


key = generate_key(intact_txt)

if choice == 1:
    ciphertext = encrypt(intact_txt, key)
    print("ciphertext: " + ciphertext)
else:
    plaintext = decrypt(intact_txt, key)
    print("plaintext: " + plaintext)
