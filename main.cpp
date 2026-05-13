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

// Function to select company or platoon
void selectUnit(BasicCadets *cadets, int index, string type)
{
    int choice = 0; // Store the users choice
    int row = 0; // Store the row based on the type

    // Stores the company and platoon type
    string unit[2][4] = {
        {"Alpha", "Bravo", "Charlie", "Delta"}, // row 0
        {"1st Platoon", "2nd Platoon", "3rd Platoon", "4th Platoon"}}; // row 1

    // Identify the value of row based on the type
    if (type == "Company")
    {
        row = 0;
    }
    else if (type == "Platoon")
    {
        row = 1;
    }

    // Display the menu 
    cout << type << ":" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". " << unit[row][i] << endl;
    }
    cout << "Enter Choice: ";
    cin >> choice;

    // Assign the value to the comapany or platoon variable
    if (type == "Company")
    {
        (cadets + index)->company = unit[row][choice - 1];
    }
    else if (type == "Platoon")
    {
        (cadets + index)->platoon = unit[row][choice - 1];
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

    // Function for selecting the unit
    selectUnit(cadets, *index, "Company"); // For Company
    selectUnit(cadets, *index, "Platoon"); // For Platoon

    cout << (cadets + *index)->company << endl;
    cout << (cadets + *index)->platoon << endl;

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