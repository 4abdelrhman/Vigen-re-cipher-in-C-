#include <iostream>
#include <string>
using namespace std;

string massage;
string key;

void encryptMessage() {
    cout << "Vigenere Cipher Encryption " << endl;
    // Input message
    cout << "Enter your message: ";
    getline(cin, massage);
    // Input key
    cout << "Enter key: ";
    getline(cin, key);
    // Convert message and key to uppercase
    for (int i = 0; i < massage.length(); i++) {
        massage[i] = toupper(massage[i]);
    }
    for (int i = 0; i < key.length(); i++) {
        key[i] = toupper(key[i]);
    }
    // Adjust the key length
    while (key.length() < massage.length()) {
        key += key;
    }
    key = key.substr(0, massage.length());
    // Encrypt the message
    string ciphermsg = "";
    for (int i = 0; i < massage.length(); i++) {
        char msgchar = massage[i];
        if (isalpha(msgchar)) {
            char keychar = key[i % key.length()];
            int msgnum = msgchar - 'A';
            int keynum = keychar - 'A';
            char encChar = 'A' + (msgnum + keynum) % 26;
            ciphermsg += encChar;
        } else {
            ciphermsg += msgchar;
        }
    }
    // Output the encrypted message
    cout << "Repeated key: " << key << '\n';
    cout << "Ciphered message: " << ciphermsg << endl;
}

void decryptMessage() {
    cout << "Vigenere Cipher Decryption " << endl;
    string cipheredMessage;
    string key;
    // Enter the ciphered message
    cout << "Enter the ciphered message: ";
    getline(cin, cipheredMessage);
    // Enter the key
    cout << "Enter key: ";
    getline(cin, key);
    // Convert ciphered message and key to uppercase
    for (int i = 0; i < cipheredMessage.length(); i++) {
        cipheredMessage[i] = toupper(cipheredMessage[i]);
    }
    for (int i = 0; i < key.length(); i++) {
        key[i] = toupper(key[i]);
    }
    // Repeat the key until it becomes the same length as the message
    while (key.length() < cipheredMessage.length()) {
        key += key;
    }
    key = key.substr(0, cipheredMessage.length());
    // Decrypt the message
    string decryptedMessage = "";
    for (int i = 0; i < cipheredMessage.length(); i++) {
        char msgChar = cipheredMessage[i];
        if (isalpha(msgChar)) {
            char keyChar = key[i % key.length()];
            int msgNum = msgChar - 'A';
            int keyNum = keyChar - 'A';
            char decChar = 'A' + (msgNum - keyNum + 26) % 26;
            decryptedMessage += decChar;
        } else {
            decryptedMessage += msgChar;
        }
    }
    // Output the decrypted message
    cout <<"Repeated key: " << key << '\n';
    cout << "Deciphered message: " << decryptedMessage << endl;
}

void displayMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Encrypt Message" << endl;
    cout << "2. Decrypt Message" << endl;
    cout << "3. Exit" << endl;
    cout << "================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // to consume the newline character left in the input buffer

        switch (choice) {
            case 1:
                encryptMessage();
                break;
            case 2:
                decryptMessage();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
