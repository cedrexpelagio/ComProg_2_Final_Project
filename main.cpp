#include <iostream>
#include <string>

using namespace std;
// UnitSync

const int MAX_USER = 100;

// Struct for User's data
struct User
{
    string userName = "";
    string studentID = "";
    string program = "";
    string company = "";
    string platoon = "";
    string status = "";
    string role = "";
    string rank = "";        // For advance cadets, staff officers and brigade staff
    string designation = ""; // For staff officers and brigade staff
    int numPresent = 0;
    int numAbsent = 0;
    int numExcuse = 0;
};

// Function that display the user menu
void displayUserMenu(string typeMenu)
{
    if (typeMenu == "Main")
    {
        cout << "Welcome to UnitSync!\n\n";
        cout << "Menu:\n";
        cout << "1. Register\n";
        cout << "2. Log In\n";
        cout << "3. Exit\n";
    }
    else if (typeMenu == "Role")
    {
        cout << "Select Role:\n";
        cout << "1. Basic Cadet\n";
        cout << "2. Advance Cadet\n";
        cout << "3. Staff Officer\n";
        cout << "4. Brigade Staff\n";
    }
}

// Function that returns the user choice in the main menu
int userMenu(string typeMenu)
{
    int choice = 0;
    displayUserMenu(typeMenu); // display the menu
    cout << "Enter Choice: ";
    cin >> choice;

    return choice; // return the choice
}

// Function to select company or platoon
void selectUnit(User *basicCadets, int index, string type)
{
    int choice = 0; // Store the users choice
    int row = 0;    // Store the row based on the type

    // Stores the company and platoon type
    string unit[2][4] = {
        {"Alpha", "Bravo", "Charlie", "Delta"},                        // row 0
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
        (basicCadets + index)->company = unit[row][choice - 1];
    }
    else if (type == "Platoon")
    {
        (basicCadets + index)->platoon = unit[row][choice - 1];
    }
}

// Function to register user student information
// This is a required for every type of user
void registerUser(User *user, int index)
{
    cin.ignore();
    cout << "Student Information:\n\n";
    cout << "Full Name\n(ex. CRUZ JOSE A): ";
    getline(cin, (user + index)->userName);
    cout << "Student ID\n(ex. LQ-00093-2025): ";
    getline(cin, (user + index)->studentID);
    cout << "Program\n(ex. BSCE-1-1): ";
    getline(cin, (user + index)->program);
}

// Function to register a user
void registerUser(User *user, int *index, int *numberOfUser)
{

    string role = (user + *index)->role;

    registerUser(user, *index); // register student information

    // Registration of Basic Cadets
    if (role == "Basic Cadet")
    {
        cout << "Role: " << role << endl;
        // Function for selecting the unit
        selectUnit(user, *index, "Company"); // For Company
        selectUnit(user, *index, "Platoon"); // For Platoon
    }
    // Registration of Advance Cadets
    else if (role == "Advance Cadet")
    {
        cout << "Role: " << role << endl;
    }
    // Registration of Staff Officers
    else if (role == "Staff Officer")
    {
        cout << "Role: " << role << endl;
    }
    // Registration of Brigade Officers
    else if (role == "Brigade Officer")
    {
        cout << "Role: " << role << endl;
    }

    cout << "\nRegistration Complete!\n";

    (*index)++;
    (*numberOfUser)++;
}

// Function that converter user role based on role option
void roleConverter(User *user, int role, int index)
{
    switch (role)
    {
    case 1:
        (user + index)->role = "Basic Cadet";
        break;
    case 2:
        (user + index)->role = "Advance Cadet";
        break;
    case 3:
        (user + index)->role = "Staff Officer";
        break;
    case 4:
        (user + index)->role = "Brigade Officer";
        break;
    }
}

int main()
{
    int option = 0; // Store the user's option
    int role = 0;   // Store the user's role

    // Basic Cadets Main Variables
    int numCadets = 0;                      // total number of basic cadets registered
    int lastCadet = 0;                      // track the last index of basic cadet
    User *basicCadets = new User[MAX_USER]; // dynamic array to store cadets

    int numAdvanceCadets = 0;
    int lastAdvanceCadet = 0;
    User *advanceCadets = new User[MAX_USER];

    int numOfficers = 0;
    int lastOfficer = 0;
    User *staffOfficers = new User[MAX_USER];

    int numBrigades = 0;
    int lastBrigade = 0;
    User *brigadeStaffs = new User[MAX_USER];

    option = userMenu("Main"); // Main Menu

    switch (option)
    {
    case 1: // Registration Section
        // Role Based Registration
        role = userMenu("Role"); // Role Menu

        switch (role)
        {
        case 1: // Basic Cadets
            roleConverter(basicCadets, role, lastCadet);
            registerUser(basicCadets, &lastCadet, &numCadets);
            break;
        case 2: // Advance Cadets
            roleConverter(advanceCadets, role, lastAdvanceCadet);
            registerUser(advanceCadets, &lastAdvanceCadet, &numAdvanceCadets);
            break;
        case 3: // Staff Officers
            roleConverter(staffOfficers, role, lastOfficer);
            registerUser(staffOfficers, &lastOfficer, &numOfficers);
            break;
        case 4: // Brigade Staff
            roleConverter(brigadeStaffs, role, lastBrigade);
            registerUser(brigadeStaffs, &lastBrigade, &numBrigades);
            break;
        }

        break;
    case 2: // Log In
        cout << "\nComing Soon..\n";
        break;
    case 3: // Exit
        cout << "\nThank you for using UnitSync!\n";
        break;
    }

    // Free Memory
    delete[] basicCadets;
    delete[] advanceCadets;
    delete[] staffOfficers;
    delete[] brigadeStaffs;
    return 0;
}