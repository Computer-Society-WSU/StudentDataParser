#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

struct Student {
    std::string id;
    std::string name;
    std::string email;
    std::string units;
    std::string program;
    std::string level;
};

void parseClassList(const std::string& filename, std::unordered_map<std::string, Student>& students) {
    std::ifstream file(filename);
    std::string line, token;
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Skip the header line
    std::getline(file, line);

    // Read each line and store student data
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Student student;
        std::getline(ss, token, ','); // Skip index
        std::getline(ss, student.id, ',');
        std::getline(ss, student.name, ',');
        std::getline(ss, student.email, ',');
        std::getline(ss, student.units, ',');
        std::getline(ss, student.program, ',');
        std::getline(ss, student.level, ',');

        students[student.id] = student;
    }
    file.close();
}

void parseCheckInData(const std::string& filename, std::unordered_map<std::string, bool>& attendedIDs) {
    std::ifstream file(filename);
    std::string line, token;
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Skip the header line
    std::getline(file, line);

    // Read each line and extract IDs
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id;
        for (int i = 0; i < 4; ++i) std::getline(ss, token, ','); // Skip to the ID column
        id = token;
        if (!id.empty() && id != "0") {
            attendedIDs[id] = true;
        }
    }
    file.close();
}

void writeExtraCreditFile(const std::string& filename, const std::unordered_map<std::string, Student>& students, const std::unordered_map<std::string, bool>& attendedIDs) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Write header
    file << "ID,Name,Email,Units,Program,Level\n";

    // Write matching students
    for (const auto& [id, student] : students) {
        if (attendedIDs.find(id) != attendedIDs.end()) {
            file << student.id << "," << student.name << "," << student.email << "," << student.units << "," << student.program << "," << student.level << "\n";
        }
    }
    file.close();
}

int main() {
    std::unordered_map<std::string, Student> students;
    std::unordered_map<std::string, bool> attendedIDs;

    // Parse input files
    parseClassList("/Users/isaachernandez/CLionProjects/StudentDataParser/Class_List.csv", students);
    parseCheckInData("/Users/isaachernandez/CLionProjects/StudentDataParser/Check_in_Data.csv", attendedIDs);

    // Write output file
    writeExtraCreditFile("/Users/isaachernandez/CLionProjects/StudentDataParser/IEEE_CS_Extra_Credit.csv", students, attendedIDs);

    std::cout << "Data parsing and filtering complete. Output written to IEEE_CS_Extra_Credit.csv" << std::endl;
    return 0;
}