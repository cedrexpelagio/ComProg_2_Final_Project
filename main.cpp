#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;
// UnitSync

const int MAX_USER = 100;
const int NUM_TRAINING_DAY = 15;

// Add at top with your other constants
const string FILE_BASIC = "basicCadet.txt";
const string FILE_ADVANCE = "advanceCadet.txt";
const string FILE_OFFICER = "staffOfficer.txt";
const string FILE_BRIGADE = "brigadeStaff.txt";

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
        cout << "4. Log Out\n";
    }
    else if (typeMenu == "Staff Officer Menu")
    {
        cout << "Menu\n";
        cout << "1. View My Profile\n";
        cout << "2. Take Attendance\n";
        cout << "3. Announcements\n";
        cout << "4. Log Out\n";
    }
    else if (typeMenu == "Brigade Staff Menu")
    {
        cout << "Menu\n";
        cout << "1. View My Profile\n";
        cout << "2. Create an Announcement\n";
        cout << "3. List of User\n";
        cout << "4. Smart Search\n";
        cout << "5. Log Out\n";
    }
    else if (typeMenu == "Company Menu")
    {
        cout << "Company\n";
        cout << "1. Alpha\n";
        cout << "2. Bravo\n";
        cout << "3. Charlie\n";
        cout << "4. Delta\n";
    }
    else if (typeMenu == "Platoon Menu")
    {
        cout << "Platoon\n";
        cout << "1. 1st Platoon\n";
        cout << "2. 2nd Platoon\n";
        cout << "3. 3rd Platoon\n";
        cout << "4. 4th Platoon\n";
    }
    else if (typeMenu == "Status Menu"){
        cout << "Status\n";
        cout << "1. Present\n";
        cout << "2. Late\n";
        cout << "3. Excuse\n";
        cout << "4. Absent\n";
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

// Function for saving the user in a file based on their role
void saveUser(User *user, int index, string fileName)
{
    fstream file;

    file.open(fileName, ios::app);

    // Save structure members
    if (file.is_open())
    {
        file << (user + index)->userName << ",";
        file << (user + index)->lastName << ",";
        file << (user + index)->sureName << ",";
        file << (user + index)->middleName << ",";
        file << (user + index)->studentID << ",";
        file << (user + index)->program << ",";
        file << (user + index)->company << ",";
        file << (user + index)->platoon << ",";
        file << (user + index)->role << ",";
        file << (user + index)->rank << ",";
        file << (user + index)->staff << ",";
        file << (user + index)->password << ",";
        file << (user + index)->numPresent << ",";
        file << (user + index)->numAbsent << ",";
        file << (user + index)->numExcuse << ",";

        // Save status array
        for (int i = 0; i < NUM_TRAINING_DAY; i++)
        {
            if ((user + index)->status[i].empty())
                file << "--";
            else
                file << (user + index)->status[i];

            if (i < NUM_TRAINING_DAY - 1)
            {
                file << ",";
            }
        }

        file << "\n";
        file.close();
    }
}

// Function that load users from file
int loadUser(User *user, string fileName)
{
    fstream file;

    file.open(fileName, ios::in);

    if (!file.is_open())
    {
        cout << "File could not be opened.\n";
        return 0;
    }

    string line;
    int index = 0;

    while (getline(file, line))
    {
        stringstream ss(line);
        string temp;

        getline(ss, (user + index)->userName, ',');
        getline(ss, (user + index)->lastName, ',');
        getline(ss, (user + index)->sureName, ',');
        getline(ss, (user + index)->middleName, ',');
        getline(ss, (user + index)->studentID, ',');
        getline(ss, (user + index)->program, ',');
        getline(ss, (user + index)->company, ',');
        getline(ss, (user + index)->platoon, ',');
        getline(ss, (user + index)->role, ',');
        getline(ss, (user + index)->rank, ',');
        getline(ss, (user + index)->staff, ',');
        getline(ss, (user + index)->password, ',');

        // Convert string to int
        getline(ss, temp, ',');
        (user + index)->numPresent = stoi(temp);

        getline(ss, temp, ',');
        (user + index)->numAbsent = stoi(temp);

        getline(ss, temp, ',');
        (user + index)->numExcuse = stoi(temp);

        // Load status array
        for (int i = 0; i < NUM_TRAINING_DAY; i++)
        {
            getline(ss, (user + index)->status[i], ',');

            // Convert "--" back to empty string
            if ((user + index)->status[i] == "--")
            {
                (user + index)->status[i] = "";
            }
        }

        index++;
    }

    file.close();

    return index; // returns number of users loaded
}

// Function to register a user
void registerUser(User *user, int *index, int *numberOfUser, string fileName)
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
    else if (role == "Staff Officer" || role == "Brigade Staff")
    {
        registerRank(user, *index);
        registerStaff(user, *index);
    }

    (user + *index)->userName = generateUserName(user, *index);
    (user + *index)->password = generatePassword(user, *index);

    cout << "\nUser Name: " << (user + *index)->userName << endl;
    cout << "Your Password: " << (user + *index)->password << endl;
    cout << "Please Save your password!\n";

    saveUser(user, *index, fileName);
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
        (user + index)->role = "Brigade Staff";
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

// Function to display the user's personal information
// Still WIP, the UI will be improved in later phase
void viewProfile(User *user, int index)
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

// Function the display the user's attendance and status
// Still WIP, the UI will be improved in later phase
void viewAttendance(User *user, int index)
{
    cout << endl;
    // Display the number of training days
    cout << setw(15) << left << "TRAINING DAY";
    for (int i = 0; i < NUM_TRAINING_DAY; i++)
    {
        if (i < 9)
        {
            cout << "0";
        }
        cout << to_string(i + 1) << " ";
    }
    cout << endl;

    // Display the user's status in -- form
    // WIP: the -- will be converted into colored text to represent the user's status
    cout << setw(14) << left << "STATUS";
    cout << "|";
    for (int i = 0; i < NUM_TRAINING_DAY; i++)
    {
        cout << (user + index)->status[i] << "|";
    }

    cout << endl;
}

// Function that convert company option to string
string companyConverter(int company)
{
    switch (company)
    {
    case 1:
        return "Alpha";
    case 2:
        return "Bravo";
    case 3:
        return "Charlie";
    case 4:
        return "Delta";
    }
}

// Function that convert platoon option to string
string platoonConverter(int platoon)
{
    switch (platoon)
    {
    case 1:
        return "1st Platoon";
    case 2:
        return "2nd Platoon";
    case 3:
        return "3rd Platoon";
    case 4:
        return "4th Platoon";
    }
}

string statusConverter(int status){
    switch (status)
    {
    case 1:
        return "Present";
    case 2:
        return "Late";
    case 3:
        return "Excuse";
    case 4:
        return "Absent";
    }
}

void takeAttendance(User *user, int numUser, string company, string platoon)
{
    int trainingDay = 0;
    int status = 0;
    string fileName = "";
    string role = (user + 0)->role;

    cout << "Enter Training Day: ";
    cin >> trainingDay;

    if (role == "Basic Cadet"){
        fileName = FILE_BASIC;
    } else {
        fileName = FILE_ADVANCE;
    }

    for (int i = 0; i < numUser; i++){

        if((user + i)->company == company && (user + i)->platoon == platoon){
         cout << (user + i)->userName << endl;
         status = userMenu("Status Menu");
         (user + i)->status[trainingDay - 1] = statusConverter(status);
        }
    }
}

// Function for staff officers to take attendance
void takeAttendance(User *user, int numUser)
{
    int choice = 0;

    string company = "",
           platoon = "";

    choice = userMenu("Company Menu");
    company = companyConverter(choice);

    choice = userMenu("Platoon Menu");
    platoon = platoonConverter(choice);

    takeAttendance(user, numUser, company, platoon);
}

// Function for all user feature
void usersFeature(User *user, int index)
{
    string role = (user + index)->role;   // Store the user's role
    string staff = (user + index)->staff; // Store the staff designation of the user
    bool running = true;

    int choice = 0;

    // Load all users
    User *basicCadets = new User[MAX_USER];
    User *advanceCadets = new User[MAX_USER];
    User *staffOfficers = new User[MAX_USER];

    // Store the number of user based on type
    int numCadets = loadUser(basicCadets, FILE_BASIC);
    int numAdvanceCadets = loadUser(advanceCadets, FILE_ADVANCE);
    int numOfficers = loadUser(staffOfficers, FILE_OFFICER);

    // Feature for basic and advance cadets
    if (role == "Basic Cadet" || role == "Advance Cadet")
    {

        while (running)
        {
            choice = userMenu("Cadets Menu"); // Display the menu

            switch (choice)
            {
            case 1: // Display the user's personal information
                viewProfile(user, index);
                break;
            case 2: // View Announcements
                cout << "Coming Soon";
                break;
            case 3: // Display the user's attendance and status
                viewAttendance(user, index);
                break;
            case 4: // Log out
                running = false;
                break;
            default:
                break;
            }
        }
    }
    else if (role == "Staff Officer")
    {
        while (running)
        {
            choice = userMenu("Staff Officer Menu"); // Display the menu

            switch (choice)
            {
            case 1: // Display the user's personal information
                viewProfile(user, index);
                break;
            case 2: // Take Attendance: Basic Cadets or Advance Cadets
                if (staff == "S1")
                {
                    takeAttendance(basicCadets, numCadets);
                }
                else if (staff == "S3")
                {
                    // Advance Cadets
                }
                break;
            case 3: // View Announcements
                break;
            case 4: // Log out
                running = false;
                break;
            default:
                break;
            }
        }
    }
    else if (role == "Brigade Staff")
    {
        while (running)
        {
            choice = userMenu("Brigade Staff Menu"); // Display the menu

            switch (choice)
            {
            case 1: // Display the user's personal information
                viewProfile(user, index);
                break;
            case 2: // Create an Announcement
                break;
            case 3: // List of User
                break;
            case 4: // Smart Search
                break;
            case 5: // Log out
                running = false;
                break;
            default:
                break;
            }
        }
    }

    delete[] basicCadets;
    delete[] advanceCadets;
    delete[] staffOfficers;
}

int main()
{
    int option = 0;      // Store the user's option
    int role = 0;        // Store the user's role
    int userIndex = 0;   // Store the user's index in logging in
    bool running = true; // Condition to keep the system running

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

    // Load all users from files
    lastCadet = loadUser(basicCadets, FILE_BASIC);
    lastAdvanceCadet = loadUser(advanceCadets, FILE_ADVANCE);
    lastOfficer = loadUser(staffOfficers, FILE_OFFICER);
    lastBrigade = loadUser(brigadeStaffs, FILE_BRIGADE);

    // Store the number of user in different role
    numCadets = lastCadet;
    numAdvanceCadets = lastAdvanceCadet;
    numOfficers = lastOfficer;
    numBrigades = lastBrigade;

    while (running)
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
                registerUser(basicCadets, &lastCadet, &numCadets, FILE_BASIC);
                break;
            case 2: // Advance Cadets
                roleConverter(advanceCadets, role, lastAdvanceCadet);
                registerUser(advanceCadets, &lastAdvanceCadet, &numAdvanceCadets, FILE_ADVANCE);
                break;
            case 3: // Staff Officers
                roleConverter(staffOfficers, role, lastOfficer);
                registerUser(staffOfficers, &lastOfficer, &numOfficers, FILE_OFFICER);
                break;
            case 4: // Brigade Staff
                roleConverter(brigadeStaffs, role, lastBrigade);
                registerUser(brigadeStaffs, &lastBrigade, &numBrigades, FILE_BRIGADE);
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
                usersFeature(basicCadets, userIndex);
                break;
            case 2: // Advance Cadets
                userLogIn(advanceCadets, numAdvanceCadets, &userIndex);
                usersFeature(advanceCadets, userIndex);
                break;
            case 3: // Staff Officers
                userLogIn(staffOfficers, numOfficers, &userIndex);
                usersFeature(staffOfficers, userIndex);
                break;
            case 4: // Brigade Staff
                userLogIn(brigadeStaffs, numBrigades, &userIndex);
                usersFeature(brigadeStaffs, userIndex);
                break;
            }

            break;
        case 3:              // Exit
            running = false; // Stop the system from looping
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