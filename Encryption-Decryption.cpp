#include <iostream>  
#include <string>  
#include <ctime>  
#include <cstdlib>  
#include <cctype>  
using namespace std;
void encrypt(string& message, int key) {
    for (char& c : message) {
        c += key;
    }
}
void decrypt(string& message, int key) {
    for (char& c : message) {
        c -= key;
    }
}
void copyrightmessage() {
    cout << "\n\n\t\t ------------------------------------------------\n ";
    cout << "\t\t|      ENCRYPTION/DECRYPTION BY AHMAD KHALED     |\n ";
    cout << "\t\t ------------------------------------------------\n\n\n";
}
int main() {
    char choice;
    copyrightmessage();    do {
        do { 
            cout << "-------------------------------------------" << endl;
            cout << "A) Encrypt a message." << endl;
            cout << "B) Decrypt a message." << endl;
            cout << "C) Bruteforce." << endl;
            cout << "D) Exit." << endl;
            cout << "-------------------------------------------" << endl;
            cin >> choice;
            choice = tolower(choice);
        } while (!cin >> choice);
        switch (choice)
        {
        case 'a': {//Encryption:  
            string encryptmessage;
            int key;
            string makingsure;
            system("cls");
            copyrightmessage();
            cout << "\nAre you sure that you want to ecnrypt a message? Y/N" << endl;
            cin >> makingsure;
            if (makingsure == "N" || makingsure == "n" || makingsure == "No" || makingsure == "no" || makingsure == "NO" || makingsure == "nO")
                break;
            else
                if (makingsure == "Y" || makingsure == "y" || makingsure == "Yes" || makingsure == "yes" || makingsure == "YES" || makingsure == "yEs"
                    || makingsure == "yES" || makingsure == "YeS" || makingsure == "YEs") {
                    cout << "Enter a message: ";                    cin.ignore();
                    getline(cin, encryptmessage);
                    cout << "Enter the encryption key: "; 
                    cin >> key;
                    while (!cin >> key || key == 0)
                    {
                        cout << "Please enter an integer (different than 0):\n";
                        cin.clear();
                        cin.ignore(256, '\n');
                        cin >> key;
                    }
                    cin.ignore();
                    encrypt(encryptmessage, key);
                    cout << "Encrypted message: " << encryptmessage << endl;
                }
                else
                    cout << "Invalid input. Exiting... " << endl;
            break;
        }
        case 'b': { //Decryption:  
            int key;
            string decryptmessage;
            string makingsure;
            system("cls");
            copyrightmessage();
            cout << "Are you sure that you want to decrypt a message? Y/N" << endl;
            cin >> makingsure;
            if (makingsure == "N" || makingsure == "n" || makingsure == "No" || makingsure == "no" || makingsure == "NO" || makingsure == "nO")
                break;            else
                if (makingsure == "Y" || makingsure == "y" || makingsure == "Yes" || makingsure == "yes" || makingsure == "YES" || makingsure == "yEs" 
                    || makingsure == "yES" || makingsure == "YeS" || makingsure == "YEs") {
                    cout << "Enter message for decryption: ";
                    cin >> decryptmessage;
                    cout << "Enter key for decryption: ";
                    cin >> key;
                    while (!cin >> key || key == 0)
                    {
                        cout << "Please enter an integer (different than 0):\n";
                        cin.clear();
                        cin.ignore(256, '\n');
                        cin >> key;
                    }
                    decrypt(decryptmessage, key);
                    cout << "Decrypted message: " << decryptmessage << endl;
                    copyrightmessage();
                }
                else
                    cout << "Invalid input. Exiting... " << endl;
            break;
        }


        case 'c': { //Bruteforce:  
            srand(time(0));
            string originalmessage;
            string brutemessage;
            int originalkey = rand() % 50 + 1;
            int brutekey = 0;
            system("cls"); 
            copyrightmessage();
            cout << "Enter a message to encrypt: ";
            cin.ignore();
            getline(cin, originalmessage);
            do {
                cout << "Enter the maximum key to reach (between 1 and 50): ";
                cin >> brutekey;
                while (!cin >> brutekey || brutekey == 0)
                {
                    cout << "Please enter an integer (different than 0):\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> brutekey;
                }
                cin.ignore();
                int originalkey = rand() % brutekey + 1;
                encrypt(originalmessage, originalkey);
                brutemessage = originalmessage;
                if (brutekey > 50 || brutekey < 1) {
                    cout << "Invalid key, must be between 1 and 50" << endl;
                }
            } while (brutekey > 50 || brutekey < 1);
            for (int i = 0; i <= brutekey; i++) {
                decrypt(brutemessage, i);
                cout << "For key " << i << " the message is: " << brutemessage << endl;
                brutemessage = originalmessage;            }
            break; }
        case 'd': {
            string makingsure;
            cout << "Are you sure that you want to exit? Y / N" << endl; 
            cin >> makingsure;
            if (makingsure == "N" || makingsure == "n" || makingsure == "No" || makingsure == "no" || makingsure == "NO" || makingsure == "nO") {
                system("cls");
                break;
            }
            else
                if (makingsure == "Y" || makingsure == "y" || makingsure == "Yes" || makingsure == "yes" || makingsure == "YES" || makingsure == "yEs"
                    || makingsure == "yES" || makingsure == "YeS" || makingsure == "YEs") {
                    cout << "Exiting..." << endl;  
                    system("pause");
                    exit(0);
                }
            break;
        }
        case '*':
            cout << "Program terminating. Shutting down." << endl;
            break;
        default: {
            cout << "Invalid input, try again" << endl;
            break;
        }
        }    } while (choice != '*');
    system("pause");
    return 0;
}
