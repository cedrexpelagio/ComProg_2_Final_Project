#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
// UnitSync

const int MAX_USER = 100;
const int NUM_TRAINING_DAY = 15;

// Struct for User's data
struct User
{
    string userName = "";
    string lastName = "";
    string sureName = "";
    string middleName = "";
    string studentID = "";
    string program = "";
    string company = "";
    string platoon = "";
    string status[NUM_TRAINING_DAY] = {""};
    string role = "";
    string rank = "";     // For advance cadets, staff officers and brigade staff
    string staff = "";    // For staff officers and brigade staff
    string password = ""; // User Password
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
    else if (typeMenu == "Cadets Menu")
    {
        cout << "Menu\n";
        cout << "1. View My Profile\n";
        cout << "2. Announcements\n";
        cout << "3. View My Attendance\n";
        cout << "4. Exit\n";
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
        {"1st Platoon", "2nd Platoon", "3rd Platoon", "4th Platoon"}
    }; // row 1

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
    cout << "Last Name(ex. DELA CRUZ)   : ";
    getline(cin, (user + index)->lastName);
    cout << "Sure Name(ex. JUAN)   : ";
    getline(cin, (user + index)->sureName);
    cout << "Middle Name(ex. REYES)   : ";
    getline(cin, (user + index)->middleName);
    cout << "Student ID(ex. LQ-00093-2025): ";
    getline(cin, (user + index)->studentID);
    cout << "Program(ex. BSCE-1-1)        : ";
    getline(cin, (user + index)->program);
}

// Function to register advance cadets, staff officer and brigade staff ranks
void registerRank(User *user, int index)
{
    cout << "Rank(ex. C/1LT): ";
    cin.ignore();
    getline(cin, (user + index)->rank);
}

// Function to register the staff of advance cadets, staff officer and brigade staff
void registerStaff(User *user, int index)
{
    cout << "Staff(ex. S3)  : ";
    getline(cin, (user + index)->staff);
}

// Function that removes the space in text
string spaceRemover(string text)
{
    string result = "";
    for (char c : text)
    {
        if (c != ' ')
            result += c;
    }
    return result;
}

// Function that auto generate the user's name in a format
string generateUserName(User *user, int index)
{
    string noSpaceLastName = "",
           noSpaceSureName = "",
           userName = "";

    noSpaceLastName = spaceRemover((user + index)->lastName);
    noSpaceSureName = spaceRemover((user + index)->sureName);

    userName = noSpaceLastName + "." + noSpaceSureName;

    return userName;
}

// Function that auto generate the user's password
string generatePassword(User *user, int index)
{
    string password = ""; // Store the user password
    string userIndex = to_string(index);

    // Extract last name (first word of userName)
    string fullName = (user + index)->userName;
    string lastName = spaceRemover((user + index)->lastName);

    string studentID = (user + index)->studentID;

    // Find positions of the dashes
    int firstDash = studentID.find("-");
    int secondDash = studentID.find("-", firstDash + 1);

    // Extract between first and second dash
    string idNumber = studentID.substr(firstDash + 1, secondDash - firstDash - 1);
    password = lastName + "-" + idNumber + "-" + userIndex;

    return password;
}

// Function to register a user
void registerUser(User *user, int *index, int *numberOfUser)
{
    // Store the role
    string role = (user + *index)->role;

    registerUser(user, *index); // register student information

    // Registration of Basic Cadets
    if (role == "Basic Cadet")
    {
        // Function for selecting the unit
        selectUnit(user, *index, "Company"); // For Company
        selectUnit(user, *index, "Platoon"); // For Platoon
    }
    // Registration of Advance Cadets
    else if (role == "Advance Cadet")
    {
        registerRank(user, *index);
    }
    // Registration of Staff Officers and Brigade Staff
    else if (role == "Staff Officer" || role == "Brigade Officer")
    {
        registerRank(user, *index);
        registerStaff(user, *index);
    }

    (user + *index)->password = generatePassword(user, *index);
    (user + *index)->userName = generateUserName(user, *index);

    cout << "\nUser Name: " << (user + *index)->userName << endl;
    cout << "Your Password: " << (user + *index)->password << endl;
    cout << "Please Save your password!\n";

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

// Function that verify the user name
bool verifyUserName(User *user, string userName, int numUser, int *index)
{
    // Linear Search to search if the user name exist
    for (int i = 0; i < numUser; i++)
    {
        if (userName == (user + i)->userName) // Condition to verify the user name
        {
            cout << "Name Exist\n";
            *index = i;  // Store the index of the user
            return true; // return if the user name exist
        }
    }

    cout << "No Name Found\n";
    return false; // return if the user name is not found
}

// Function that verify the user's password
bool verifyPassword(User *user, string password, int index)
{

    if (password == (user + index)->password) // Condition to verify the password
    {
        cout << "Password Correct\n";
        return true; // return if the password is correct
    }
    else
    {
        cout << "Password Incorrect\n";
        return false; // return if the password is incorrect
    }
}

// Function for user log in
void userLogIn(User *user, int numUser, int *index)
{
    string userName = "";
    string password = "";
    bool verification = false;

    cin.ignore();
    do
    {
        cout << "User Name: ";
        getline(cin, userName);
        // Verify the user name
        verification = verifyUserName(user, userName, numUser, index);
    } while (!verification); // Loop if the user do not exist

    do
    {
        cout << "Password : ";
        cin >> password;
        // Verify the password
        verification = verifyPassword(user, password, *index);
    } while (!verification); // Loop if the password is incorrect
}

// Function for debugging
void cadetProfile(User *user, int index)
{
    cout << "User Name  : " << (user + index)->userName << "\n";
    cout << "Last Name  : " << (user + index)->lastName << "\n";
    cout << "Sure Name  : " << (user + index)->sureName << "\n";
    cout << "Middle Name: " << (user + index)->middleName << "\n";
    cout << "Student ID : " << (user + index)->studentID << "\n";
    cout << "Program    : " << (user + index)->program << "\n";
    cout << "Company    : " << (user + index)->company << "\n";
    cout << "Platoon    : " << (user + index)->platoon << "\n";
    cout << "Role       : " << (user + index)->role << "\n";
    cout << "Rank       : " << (user + index)->rank << "\n";
}

void viewAttendance(User *user, int index)
{
    
    cout << setw(15) << left << "TRAINING DAY";
    for (int i = 0; i < NUM_TRAINING_DAY; i++) {
        if (i < 9) {
            cout << "0";
        }
        cout << to_string(i + 1) << " ";
    }
    cout << endl;

    cout << setw(14) << left << "STATUS";
    cout << "|";
    for (int i = 0; i < NUM_TRAINING_DAY; i++) {
        (user + index)->status[i] = "--";
        cout << (user + index)->status[i] << "|";
    }
    cout << endl;
}

void cadetsFeature(User *user, int index)
{
    int choice = 0;
    choice = userMenu("Cadets Menu");

    switch (choice)
    {
    case 1:
        cadetProfile(user, index);
        break;
    case 2:
        cout << "Coming Soon";
        break;
    case 3:
        viewAttendance(user, index);
        break;
    case 4:
        break;
    default:
        break;
    }
}

int main()
{
    int option = 0;    // Store the user's option
    int role = 0;      // Store the user's role
    int userIndex = 0; // Store the user's index in logging in

    // Basic Cadets Main Variables
    int numCadets = 0;                      // total number of basic cadets registered
    int lastCadet = 0;                      // track the last index of basic cadets
    User *basicCadets = new User[MAX_USER]; // dynamic array to store basic cadets

    // Advance Cadets Main Variables
    int numAdvanceCadets = 0;                 // total number of advance cadets registered
    int lastAdvanceCadet = 0;                 // track the last index of advance cadets
    User *advanceCadets = new User[MAX_USER]; // dynamic array to store advance cadets

    // Staff Officers Main Variables
    int numOfficers = 0;                      // total number of staff officer registered
    int lastOfficer = 0;                      // track the last index of staff officer
    User *staffOfficers = new User[MAX_USER]; // dynamic array to store staff officers

    // Brigade Staffs Main Variables
    int numBrigades = 0;                      // total number of brigade staff registered
    int lastBrigade = 0;                      // track the last index of brigade staff
    User *brigadeStaffs = new User[MAX_USER]; // dynamic array to store brigade staffs

    while (true) // Debugging condition
    {
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

            // Role Based Log In
            role = userMenu("Role"); // Role Menu

            switch (role)
            {
            case 1: // Basic Cadets
                userLogIn(basicCadets, numCadets, &userIndex);
                cadetsFeature(basicCadets, userIndex);
                break;
            case 2: // Advance Cadets
                userLogIn(advanceCadets, numAdvanceCadets, &userIndex);
                break;
            case 3: // Staff Officers
                userLogIn(staffOfficers, numOfficers, &userIndex);
                break;
            case 4: // Brigade Staff
                userLogIn(brigadeStaffs, numBrigades, &userIndex);
                break;
            }

            break;
        case 3: // Exit
            cout << "\nThank you for using UnitSync!\n";
            break;
        }
    }

    // Free Memory
    delete[] basicCadets;
    delete[] advanceCadets;
    delete[] staffOfficers;
    delete[] brigadeStaffs;
    return 0;
}