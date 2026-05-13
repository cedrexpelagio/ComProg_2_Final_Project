#include <iostream>
#include <string>

using namespace std;
// UnitSync

const int MAX_CADETS = 1000;

// Basic Cadets struct
struct BasicCadets { 
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

// Function to register a user
void registerUser (BasicCadets *cadets, int *index, int *numberOfCadets) {
    cout << "User Number " << *index + 1 << ":" << endl;
    cout << "User Name: ";
    getline (cin, (cadets + *index)->userName);
    cout << "Student ID: ";
    getline (cin, (cadets + *index)->studentID);
    cout << "Program: ";
    getline (cin, (cadets + *index)->program);
    cout << "Company: ";
    getline (cin, (cadets + *index)->company);
    cout << "Platoon: ";
    getline (cin, (cadets + *index)->platoon);
    *index++;
    *numberOfCadets++;
}


int main (){
    int numberOfCadets = 0; // total number of cadets registered
    int lastCadetIndex = 0; // track the last index of user
    BasicCadets *cadets = new BasicCadets[MAX_CADETS]; // dynamic array to store cadets

    registerUser(cadets, &lastCadetIndex, &numberOfCadets); 

    delete[] cadets;
    return 0;
}