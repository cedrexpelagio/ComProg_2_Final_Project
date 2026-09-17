### 🎖️ UnitSync: ROTC Cadet & Attendance Management System

UnitSync is a terminal-based cadet administration and attendance tracking system developed in C++ as the final project for Computer Programming 2 (second semester, first year). Built to digitize and streamline ROTC corps management, UnitSync offers role-based access control for Basic Cadets, Advance Cadets, Staff Officers, and Brigade Staff. It features automated credential generation, real-time 15-day attendance tracking with color-coded status badges, multi-criteria smart search, an announcement bulletin board, alphabetical sorting, and file persistence.

## 💻 Preview

```text
========================================
                UnitSync
========================================
----------------------------------------
 MAIN MENU
----------------------------------------
 1. Register
 2. Log In
 3. Exit
========================================

============================================================
                      USER ATTENDANCE
============================================================
Legend:
== Present  == Late  == Excuse  == Absent  -- Not Yet Taken
------------------------------------------------------------
TRAINING DAY   01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 
STATUS        |==|==|==|==|==|==|==|==|==|==|==|--|--|--|--|
------------------------------------------------------------
                     ATTENDANCE SUMMARY
------------------------------------------------------------
Present    : 11                  Late       : 0
Excuse     : 0                   Absent     : 0
============================================================
```

[UnitSync: ROTC Management System](https://github.com/cedrexpelagio/ComProg_2_Final_Project) ← Click the link to visit the repository

## 🚀 Features

- **Role-Based Access Control (RBAC)**: Distinct permissions and personalized dashboards for **Basic Cadets**, **Advance Cadets**, **Staff Officers (S1/S3)**, and **Brigade Staff**.
- **Automated Credential Generation**: Automatically formats standardized usernames (`LASTNAME.SURENAME`) and secure default passwords (`LASTNAME-<ID_NUMBER>-<INDEX>`) from student records.
- **Cadet & Officer Registration**: Captures complete student information (Last Name, Sure Name, Middle Name, Student ID, Program) alongside role-specific assignments like Company, Platoon, Military Rank, and Staff designation.
- **15-Day Attendance Cycle Tracking**: Comprehensive multi-day tracking supporting four official statuses: Present, Late, Excuse, and Absent.
- **Color-Coded Status Display**: Terminal status indicators rendered using ANSI escape sequences: **Present** (Green), **Late** (Blue), **Excuse** (Yellow), and **Absent** (Red).
- **Officer Attendance Logging**: Staff Officers (S1 for Basic Cadets, S3 for Advance Cadets) can take batch attendance designated by Company and Platoon with built-in input validation.
- **Attendance Smart Search**: Brigade Staff can search and filter cadet attendance by Company, Platoon, Academic Program, Last Name, or Sure Name.
- **Corps Announcement System**: Brigade Staff can post official drill orders (What, Who, Where, When, Uniform Attire, Checklist of items to bring, and Notes) accessible to all units.
- **Alphabetical Auto-Sorting**: Automatically sorts cadet and officer registries from A to Z by last name using an optimized bubble sort algorithm powered by a C++ template swap function.
- **Master User Roster & Analytics**: Displays full battalion rosters broken down by tier with total headcount statistics.
- **Persistent File Storage**: Saves and loads all user data, attendance matrix records, and announcements to persistent comma-separated text files.
- **Input Validation & Security**: Sanitizes numeric and string inputs against unexpected entries and enforces a 3-attempt login lockout to prevent unauthorized access.

## 🛠 Technologies

- **C++ (C++11 or higher)**
- **ANSI Escape Sequences** (for screen clearing and colored terminal text)
- **C++ Standard Library**:
  - `<iostream>` & `<iomanip>` (formatted tabular output with `std::setw`, `std::left`)
  - `<fstream>` & `<sstream>` (file persistence and comma-delimited parsing)
  - `<string>` & `<limits>` (robust string manipulation and input buffer clearing)

## 🛠 Tools

- Visual Studio Code
- MinGW / GCC (`g++`)
- Git & GitHub
- Windows PowerShell / Command Prompt

## 🤳 How to Use

**Registering a User**
1. Select `1. Register` from the Main Menu.
2. Select your role (`1. Basic Cadet`, `2. Advance Cadet`, `3. Staff Officer`, or `4. Brigade Staff`).
3. Enter your student information:
   - Last Name (e.g., `DELA CRUZ`)
   - Sure Name (e.g., `JUAN`)
   - Middle Name (e.g., `REYES`)
   - Student ID (e.g., `LQ-00093-2025`)
   - Academic Program (e.g., `BSIT-1-1`)
4. Fill in role-specific details:
   - **Basic Cadet**: Choose your assigned Company (Alpha, Bravo, Charlie, Delta) and Platoon (1st to 4th).
   - **Advance Cadet**: Enter your military rank (e.g., `C/1LT`) and select your Platoon.
   - **Staff Officer / Brigade Staff**: Enter your military rank and select your staff office (`S1` or `S3`).
5. The system will display your auto-generated **User Name** and **Password**. Keep a copy for logging in!

**Logging In**
1. Select `2. Log In` from the Main Menu and choose your corresponding role.
2. Enter your auto-generated username (e.g., `DELACRUZ.JUAN`).
3. Enter your password (e.g., `DELACRUZ-00093-0`).
4. Upon successful validation, your role-specific dashboard will appear.

**Viewing Attendance (Cadets)**
1. From the Cadet Menu, select `3. View My Attendance`.
2. Inspect your personal 15-day training status matrix and color-coded attendance breakdown summary.

**Taking Attendance (Staff Officers)**
1. From the Staff Officer Menu, select `2. Take Attendance`.
2. Enter the training day number (1–15).
3. Select the target Company and Platoon.
4. For each cadet displayed in the roster, enter the status code:
   - `1` for Present
   - `2` for Late
   - `3` for Excuse
   - `4` for Absent
5. The roster file updates automatically upon completion.

**Creating Announcements (Brigade Staff)**
1. From the Brigade Staff Menu, select `2. Create an Announcement`.
2. Enter the What, Who, Where, When, and Uniform Attire details.
3. Enter list items for the "To Bring" checklist (type `done` when finished).
4. Enter any special instructions or reminders for "Note" (type `done` when finished).
5. The announcement is immediately published to `announcement.txt`.

**Using Attendance Smart Search (Brigade Staff)**
1. From the Brigade Staff Menu, select `4. Attendance Smart Search`.
2. Select whether to query Basic Cadets or Advance Cadets.
3. Choose your filter criteria:
   - Search by Company
   - Search by Platoon
   - Search by Program
   - Search by Name (Last Name or Sure Name)
4. View the matching cadets alongside their full 15-day attendance charts.

## 👨‍💻 Run Locally

1. Clone the repository:
```bash
   git clone https://github.com/cedrexpelagio/ComProg_2_Final_Project.git
```
2. Navigate to the project directory:
```bash
   cd ComProg_2_Final_Project
```
3. Compile the program using `g++`:
```bash
   g++ -std=c++11 main.cpp -o main
```
4. Run the executable:
   - On Windows:
     ```bash
     .\main.exe
     ```
   - On Linux / macOS:
     ```bash
     ./main
     ```

> **Note**: For Windows Command Prompt or PowerShell, ANSI escape sequences are supported in modern Windows 10/11 terminals for displaying colors and screen clearing.

## 🔮 Future Improvements

**User Experience & Interface**
- GUI Migration: Transition the CLI console interface to a graphical user interface (using Qt, ImGui, or web frontend) for enhanced usability.
- Password Management: Allow cadets and officers to change default passwords and update personal contact details.

**Data & Analytics**
- Export to Excel / PDF: Enable exporting formatted attendance sheets and battalion rosters into `.xlsx` or `.pdf` for submission to ROTC commandants.
- Attendance Correction Tool: Allow authorized officers to review and retroactively adjust attendance records for past training days.
- Database Integration: Upgrade flat CSV-style `.txt` storage to an embedded database like SQLite for enhanced relational queries and data integrity.

## ⚙ Process

I started by identifying key pain points in our university's ROTC corps operations: paper attendance rosters were easily damaged or lost, manual roll-calls were slow, and cross-checking cadet records across companies and platoons was tedious. 

To solve this, I mapped out the corps hierarchy into four roles (Basic Cadets, Advance Cadets, Staff Officers, and Brigade Staff) and designed custom C++ `struct` definitions (`User` and `Announcement`) to handle cadet profiles, credentials, and 15-day attendance arrays. 

During development, I utilized dynamic memory allocation (`new User[MAX_USER]`) and modularized the codebase into functional areas:
1. **Authentication & Validation**: Designed automated username/password generation based on string parsing and added input-clearing mechanisms with `cin.clear()` and `numeric_limits` to prevent infinite loops from invalid keystrokes.
2. **Data Conversion**: Initially used multiple verbose `switch` cases for converting menu choices to strings, then refactored them into a 2D lookup array (`CONVERT_TABLE[5][4]`) to keep the code clean and maintainable.
3. **Sorting & File Handling**: Created a generic template swap function (`swapUser<T>`) to power an alphabetical bubble sort on registered users by last name, ensuring all persistent files remain organized in alphabetical order.
4. **Attendance Matrix & Visual UI**: Leveraged ANSI escape codes to render colored status markers and formatted tabular rosters with `<iomanip>` (`setw`, `left`) for a clean terminal dashboard experience.
5. **Search Algorithms**: Developed overloaded `attendanceSmartSearch` functions to enable multi-criteria queries across companies, platoons, programs, and cadet names.

I used Git for version control, documenting each milestone through clear commit messages and hosting the project on GitHub.

## 📝 Learning

Developing UnitSync significantly deepened my mastery of core C++ and object-oriented programming concepts taught throughout Computer Programming 2:
- **Pointers and Dynamic Memory**: Gained hands-on experience allocating and deallocating memory on the heap using `new[]` and `delete[]`, managing pointer arithmetic, and passing pointers to functions.
- **File Handling & Stream Parsing**: Mastered persistent data storage using `<fstream>` (`ios::in`, `ios::out`, `ios::app`) and parsed comma-separated string records using `std::stringstream` and `std::getline`.
- **Function Overloading & Templates**: Applied function overloading for `takeAttendance`, `attendanceSmartSearch`, and `verifyInput`, and wrote a reusable generic template function (`swapUser<T>`) for data manipulation.
- **Defensive Programming & Input Sanitization**: Learned how to handle unexpected user inputs by clearing the `cin` fail state and flushing the input buffer, preventing stream corruptions and crashes.
- **2D Arrays as Lookup Tables**: Replaced nested switch-case blocks with multi-dimensional constant arrays, improving code clarity and runtime efficiency.
- **Terminal UI/UX Design**: Explored ANSI escape sequences for text coloring and screen manipulation, transforming a standard CLI into an interactive, intuitive management tool.

Overall, this project was a rewarding milestone that bridged foundational programming theory with a practical, real-world application for campus organizations.
