#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int choice;
    string username, password;
    string fileUser, filePass;
    bool found;

    while (true)
    {
        cout << "\n=====================================\n";
        cout << "   LOGIN & REGISTRATION SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            cout << "\nEnter Username: ";
            cin >> username;

            found = false;
            ifstream checkFile("users.txt");

            while(checkFile >> fileUser >> filePass)
            {
                if(username == fileUser)
                {
                    found = true;
                    break;
                }
            }
            checkFile.close();

            if(found)
            {
                cout << "\nUsername already exists!\n";
                break;
            }

            cout << "Enter Password: ";
            cin >> password;

            ofstream file("users.txt", ios::app);
            file << username << " " << password << endl;
            file.close();

            cout << "\nRegistration Successful!\n";
            break;
        }

        case 2:
        {
            cout << "\nEnter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            found = false;

            ifstream file("users.txt");

            while(file >> fileUser >> filePass)
            {
                if(username == fileUser && password == filePass)
                {
                    found = true;
                    break;
                }
            }

            file.close();

            if(found)
                cout << "\nLogin Successful!\n";
            else
                cout << "\nInvalid Username or Password!\n";

            break;
        }

        case 3:
            cout << "\nThank You for Using the Program!\n";
            return 0;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }
    }

    return 0;
}
