#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;
// UnitSync

const int MAX_USER = 100;
const int NUM_TRAINING_DAY = 15;

// User files
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
    int numLate = 0;
    int numAbsent = 0;
    int numExcuse = 0;
};

struct Announcement
{
    string what = "";
    string who = "";
    string where = "";
    string when = "";
    string attire = "";
    string toBring = "";
    string note = "";
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
    else if (typeMenu == "Staff Menu")
    {
        cout << "Staff\n";
        cout << "1. S1\n";
        cout << "2. S3\n";
    }
    else if (typeMenu == "Status Menu")
    {
        cout << "Status\n";
        cout << "[1] Present    ";
        cout << "[2] Late     ";
        cout << "[3] Excuse     ";
        cout << "[4] Absent     \n";
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

string staffConverter(int staff)
{

    switch (staff)
    {
    case 1:
        return "S1";
    case 2:
        return "S3";
    }
}

string statusConverter(int status)
{
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

// Function to select company or platoon
void selectUnit(User *basicCadets, int index)
{
    int choice = 0; // Store the users choice

    choice = userMenu("Company Menu");
    (basicCadets + index)->company = companyConverter(choice);

    choice = userMenu("Platoon Menu");
    (basicCadets + index)->platoon = platoonConverter(choice);
}

// Function to register user student information
// This is a required for every type of user
void registerUser(User *user, int index)
{
    cin.ignore();
    cout << "Last Name(ex. DELA CRUZ)     : ";
    getline(cin, (user + index)->lastName);
    cout << "Sure Name(ex. JUAN)          : ";
    getline(cin, (user + index)->sureName);
    cout << "Middle Name(ex. REYES)       : ";
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
    int staff = 0;
    staff = userMenu("Staff Menu");
    (user + index)->staff = staffConverter(staff);
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

// Function to write data in files, serve as the helper function for save user and update file function
void writeFile(fstream &file, User *user, int index)
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
}

// Function for saving the user in a file based on their role
void saveUser(User *user, int index, string fileName)
{

    fstream file;

    file.open(fileName, ios::app);

    // Save structure members
    if (file.is_open())
    {
        writeFile(file, user, index);
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

// For attendance update — rewrites entire file
void updateFile(User *user, int numUser, string fileName)
{
    fstream file;
    file.open(fileName, ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < numUser; i++)
        {
            writeFile(file, user, i);
        }
        file.close();
    }
}

// Function to register a user
void registerUser(User *user, int *index, int *numberOfUser, string fileName)
{
    // Store the role
    string role = (user + *index)->role;
    int platoon = 0;

    registerUser(user, *index); // register student information

    // Registration of Basic Cadets
    if (role == "Basic Cadet")
    {
        // Function for selecting the unit
        // Select Company and Platoon
        selectUnit(user, *index);
    }
    // Registration of Advance Cadets
    else if (role == "Advance Cadet")
    {
        // Select Platoon
        platoon = userMenu("Platoon Menu");
        (user + *index)->platoon = platoonConverter(platoon);

        cin.ignore();
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

// Function for the user's to view their profile
void viewProfile(User *user, int index)
{
    string role = (user + index)->role;
    string line1 = string(70, '=');
    string line2 = string(70, '-');

    // Display the user's profile using setw
    cout << "\n";
    cout << line1 << "\n";
    cout << right << setw(41) << "USER PROFILE" << "\n";
    cout << line1 << "\n";
    cout << left << setw(15) << "User Name" << ": " << (user + index)->userName << "\n";
    cout << line2 << "\n";
    cout << left << setw(15) << "Last Name" << ": " << setw(25) << (user + index)->lastName
         << left << setw(10) << "Sure Name" << ": " << (user + index)->sureName << "\n";
    cout << left << setw(15) << "Middle Name" << ": " << setw(25) << (user + index)->middleName
         << left << setw(10) << "Student ID" << ": " << (user + index)->studentID << "\n";
    cout << left << setw(15) << "Program" << ": " << setw(25) << (user + index)->program
         << left << setw(10) << "Role" << ": " << (user + index)->role << "\n";

    // Additional information based on the user's role
    if (role == "Basic Cadet")
    {
        cout << left << setw(15) << "Company" << ": " << setw(25) << (user + index)->company
             << left << setw(10) << "Platoon" << ": " << (user + index)->platoon << "\n";
    }
    else if (role == "Advance Cadet")
    {
        cout << left << setw(15) << "Platoon" << ": " << setw(25) << (user + index)->platoon
             << left << setw(10) << "Rank" << ": " << (user + index)->rank << "\n";
    }
    else if (role == "Staff Officer" || role == "Brigade Staff")
    {
        cout << left << setw(15) << "Rank" << ": " << setw(25) << (user + index)->rank
             << left << setw(10) << "Staff" << ": " << (user + index)->staff << "\n";
    }

    cout << line1 << "\n";
}

void printColoredStatus(string status, string text)
{

    if (status == "Present")
    {
        cout << "\033[32m" << text << "\033[0m"; // Green
    }
    else if (status == "Late")
    {
        cout << "\033[34m" << text << "\033[0m"; // Blue
    }
    else if (status == "Excuse")
    {
        cout << "\033[33m" << text << "\033[0m"; // Yellow
    }
    else if (status == "Absent")
    {
        cout << "\033[31m" << text << "\033[0m"; // Red
    }
}

void statusCounter(User *user, int index, int statusIndex)
{
    string status = (user + index)->status[statusIndex];

    if (status == "Present")
    {
        ((user + index)->numPresent)++;
    }
    else if (status == "Late")
    {
        ((user + index)->numLate)++;
    }
    else if (status == "Excuse")
    {
        ((user + index)->numExcuse)++;
    }
    else if (status == "Absent")
    {
        ((user + index)->numAbsent)++;
    }
}

// Function the display the user's attendance and status
void viewAttendance(User *user, int index)
{
    string line = string(60, '-');
    string boldLine = string(60, '=');

    // Reset counts before recalculating
    (user + index)->numPresent = 0;
    (user + index)->numLate = 0;
    (user + index)->numExcuse = 0;
    (user + index)->numAbsent = 0;

    // Display feature title
    cout << boldLine << "\n";
    cout << string(22, ' ') << "USER ATTENDANCE" << "\n";
    cout << boldLine << "\n";

    // Color representation legend
    cout << "Legend:\n";
    printColoredStatus("Present", "== Present  ");
    printColoredStatus("Late", "== Late  ");
    printColoredStatus("Excuse", "== Excuse  ");
    printColoredStatus("Absent", "== Absent  ");
    cout << "\033[0m-- Not Yet Taken\n";
    cout << line << "\n";

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

    // Display the user's status
    cout << setw(14) << left << "STATUS";
    cout << "|";
    for (int i = 0; i < NUM_TRAINING_DAY; i++)
    {
        // Display for empty status
        if ((user + index)->status[i].empty())
        {
            cout << "--";
        }
        // Display colored text based on the user status
        else
        {
            printColoredStatus((user + index)->status[i], "=="); // Display
            statusCounter(user, index, i);                       // Count the status
        }
        cout << "|";
    }
    cout << "\n";
    cout << line << "\n";
    cout << endl;

    // Display attendance summary with colors
    cout << string(21, ' ') << "ATTENDANCE SUMMARY" << "\n";
    cout << line << "\n";

    // Row 1
    printColoredStatus("Present", "Present");
    cout << left << setw(10) << "" << ": " << setw(20) << (user + index)->numPresent;
    printColoredStatus("Late", "Late");
    cout << left << setw(13) << "" << ": " << (user + index)->numLate << "\n";

    // Row 2
    printColoredStatus("Excuse", "Excuse");
    cout << left << setw(11) << "" << ": " << setw(20) << (user + index)->numExcuse;
    printColoredStatus("Absent", "Absent");
    cout << left << setw(11) << "" << ": " << (user + index)->numAbsent << "\n";

    cout << line << "\n";
}

// Function for the staff officer to take cadets attendanc
void takeAttendance(User *user, int numUser, string company, string platoon)
{
    int trainingDay = 0;
    int status = 0;
    int counter = 0;
    string fileName = "";
    string role = (user + 0)->role;

    cout << "Enter Training Day: ";
    cin >> trainingDay;

    if (role == "Basic Cadet")
    {
        fileName = FILE_BASIC; // Basic Cadet File
    }
    else
    {
        fileName = FILE_ADVANCE; // Advance Cadet File
    }

    displayUserMenu("Status Menu");
    cout << endl;

    // Cadets information header
    cout << setw(5) << left << "No." << setw(14) << left << "Last Name" << setw(15) << left << "First Name"
         << setw(16) << left << "Middle Name" << setw(12) << left << "Program" << setw(5) << left << "Status" << endl;

    for (int i = 0; i < numUser; i++)
    {

        if ((user + i)->company == company && (user + i)->platoon == platoon)
        {
            // Display the users basic information
            counter++;
            cout << setw(5) << left << to_string(counter) << setw(14) << left << (user + i)->lastName << setw(15) << left << (user + i)->sureName
                 << setw(16) << left << (user + i)->middleName << setw(12) << left << (user + i)->program << setw(5) << left;
            cin >> status;

            (user + i)->status[trainingDay - 1] = statusConverter(status);
        }
    }

    updateFile(user, numUser, fileName);
}

// Function overloading to select the company and platoon of cadets
void takeAttendance(User *user, int numUser, string staff)
{
    int choice = 0;

    string company = "",
           platoon = "";

    if (staff == "S1")
    {
        choice = userMenu("Company Menu");
        company = companyConverter(choice);
    }

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
                    takeAttendance(basicCadets, numCadets, staff);
                }
                else if (staff == "S3")
                {
                    takeAttendance(advanceCadets, numAdvanceCadets, staff);
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

    while (running)
    {
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