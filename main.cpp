#include <iostream>
#include <string>

using namespace std;
// UnitSync

const int MAX_CADETS = 1000;

// Basic Cadets struct
struct BasicCadets
{
    string userName = "";
    string studentID = "";
    string program = "";
    string company = "";
    string platoon = "";
    string status = "";
    int numPresent = 0;
    int numAbsent = 0;
    int numExcuse = 0;
};

// Function to select a company
void selectCompany(BasicCadets *cadets, int *index)
{
    int companyChoice;
    cout << "Company:" << endl;
    cout << "1. Alpha" << endl;
    cout << "2. Bravo" << endl;
    cout << "3. Charlie" << endl;
    cout << "4. Delta" << endl;
    cout << "Choice: ";
    cin >> companyChoice;

    switch (companyChoice)
    {
    case 1:
        (cadets + *index)->company = "Alpha";
        break;
    case 2:
        (cadets + *index)->company = "Bravo";
        break;
    case 3:
        (cadets + *index)->company = "Charlie";
        break;
    case 4:
        (cadets + *index)->company = "Delta";
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
}

// Function to select a platoon
void selectPlatoon(BasicCadets *cadets, int *index)
{
    int platoonChoice;
    cout << "Platoon:" << endl;
    cout << "1. 1st Platoon" << endl;
    cout << "2. 2nd Platoon" << endl;
    cout << "3. 3rd Platoon" << endl;
    cout << "4. 4th Platoon" << endl;
    cout << "Choice: ";
    cin >> platoonChoice;

    switch (platoonChoice)
    {
    case 1:
        (cadets + *index)->platoon = "1st Platoon";
        break;
    case 2:
        (cadets + *index)->platoon = "2nd Platoon";
        break;
    case 3:
        (cadets + *index)->platoon = "3rd Platoon";
        break;
    case 4:
        (cadets + *index)->platoon = "4th Platoon";
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
}

// Function to register a user
void registerUser(BasicCadets *cadets, int *index, int *numberOfCadets)
{
    cout << "User Number " << *index + 1 << ":" << endl;
    cout << "Full Name\n(ex. CRUZ JOSE A): ";
    getline(cin, (cadets + *index)->userName);
    cout << "Student ID\n(ex. LQ-00093-2025): ";
    getline(cin, (cadets + *index)->studentID);
    cout << "Program\n(ex. BSCE-1-1): ";
    getline(cin, (cadets + *index)->program);
  
    selectCompany(cadets, index);
    selectPlatoon(cadets, index);

    (*index)++;
    (*numberOfCadets)++;
}

int main()
{
    int numberOfCadets = 0;                            // total number of cadets registered
    int lastCadetIndex = 0;                            // track the last index of user
    BasicCadets *cadets = new BasicCadets[MAX_CADETS]; // dynamic array to store cadets

    registerUser(cadets, &lastCadetIndex, &numberOfCadets);

    delete[] cadets;
    return 0;
}