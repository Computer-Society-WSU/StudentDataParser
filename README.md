# README: Student Data Parser

## Table of Contents
1. [Introduction](#introduction)
2. [How to Use the Software](#how-to-use-the-software)
3. [Updating File Paths](#updating-file-paths)
4. [Loading the Project in Visual Studio](#loading-the-project-in-visual-studio)
5. [Guide for Non-CS Professors](#guide-for-non-cs-professors)

---

## Introduction
This software, created by **Isaias Hernandez**, is designed to parse IEEE/IEEE:Computer Society hackathon data. It processes student attendance data and generates a filtered list of students eligible for extra credit based on their participation.

By following these instructions, you should be able to successfully run the software and process your attendance data.

Thank you for rewarding your students with extra credit for their participation in the hackathon!
We appreciate your support and dedication to enhancing their learning experience! - IEEE and IEEE:Computer Society WSU Chapter
---

## How to Use the Software
1. **Replace the Attendance CSV File**:
    - Replace the file path for `Class_List.csv` in the code with the path to your attendance CSV file from the WSU classroom portal.
    - The file should contain student data in a similar format to the provided `Class_List.csv`.

2. **Run the Software**:
    - The program will parse the attendance data and generate an output file named `IEEE_CS_Extra_Credit.csv` containing the filtered list of students.

3. **Output File**:
    - The output file will be saved in the location specified in the code (default: `/Users/isaachernandez/CLionProjects/StudentDataParser/IEEE_CS_Extra_Credit.csv`).

---

## Updating File Paths
To ensure the software works correctly, you must update the file paths in `main.cpp`:

1. **Locate the File Paths**:
    - Open `main.cpp` and navigate to the following lines:
        - **Line 93**: Replace the file path for `Class_List.csv`.
        - **Line 94**: Replace the file path for `Check_in_Data.csv`.
        - **Line 97**: Replace the file path for `IEEE_CS_Extra_Credit.csv`.

2. **Update the Paths**:
    - Replace the default file paths with the appropriate paths to your local files. For example:
      ```cpp
      parseClassList("path/to/your/Class_List.csv", students);
      parseCheckInData("path/to/your/Check_in_Data.csv", attendedIDs);
      writeExtraCreditFile("path/to/your/IEEE_CS_Extra_Credit.csv", students, attendedIDs);
      ```

---

## Loading the Project in Visual Studio
To load the project in **Visual Studio (the purple one)**:

1. **Install Visual Studio**:
    - Download and install Visual Studio from [Microsoft's website](https://visualstudio.microsoft.com/).

2. **Install C++ Development Tools**:
    - During installation, ensure you select the **Desktop development with C++** workload.

3. **Open the Project**:
    - Open Visual Studio.
    - Go to `File > Open > CMake...`.
    - Navigate to the folder containing the `CMakeLists.txt` file and select it.

4. **Build the Project**:
    - Click on `Build > Build All` to compile the project.

5. **Run the Program**:
    - After building, click on `Debug > Start Without Debugging` to run the program.

---

## Guide for Non-CS Professors
If you are not familiar with programming, follow these steps to clone the repository and run the software:

1. **Install Git**:
    - Download and install Git from [git-scm.com](https://git-scm.com/).

2. **Clone the Repository**:
    - Open a terminal or command prompt.
    - Run the following command to clone the repository:
      ```bash
      git clone https://github.com/Computer-Society-WSU/StudentDataParser.git
      ```
3. **Install CLion or Visual Studio**:
    - Download and install either **CLion** or **Visual Studio** (see instructions above for Visual Studio).

4. **Open the Project**:
    - Open the folder containing the cloned repository in your chosen IDE.

5. **Update File Paths**:
    - Follow the instructions in the [Updating File Paths](#updating-file-paths) section to replace the file paths with your local file paths.

6. **Run the Program**:
    - Build and run the program using the IDE's interface.

7. **View the Output**:
    - The output file `IEEE_CS_Extra_Credit.csv` will be generated in the specified location.

---
