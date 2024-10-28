#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Define the Course class to store course information
class Course {
public:
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;

    Course() {}

    Course(string courseNumber, string courseTitle, vector<string> prerequisites) {
        this->courseNumber = courseNumber;
        this->courseTitle = courseTitle;
        this->prerequisites = prerequisites;
    }
};

// Function to split strings by a delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to load course data from the file into the hash table
void loadCourses(unordered_map<string, Course>& courses, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        vector<string> data = split(line, ',');
        string courseNumber = data[0];
        string courseTitle = data[1];
        vector<string> prerequisites;

        // Collect prerequisites if they exist
        for (size_t i = 2; i < data.size(); ++i) {
            if (!data[i].empty()) {
                prerequisites.push_back(data[i]);
            }
        }

        // Create a Course object and insert it into the hash table
        Course course(courseNumber, courseTitle, prerequisites);
        courses[courseNumber] = course;
    }

    cout << "Courses loaded successfully!" << endl;
    file.close();
}

// Function to print the entire course list in alphanumeric order
void printCourseList(const unordered_map<string, Course>& courses) {
    vector<string> courseNumbers;

    // Extract all the course numbers from the hash table
    for (const auto& pair : courses) {
        courseNumbers.push_back(pair.first);
    }

    // Sort the course numbers
    sort(courseNumbers.begin(), courseNumbers.end());

    // Print the sorted course list
    cout << "Here is a sample schedule:" << endl;
    for (const string& courseNumber : courseNumbers) {
        cout << courseNumber << ", " << courses.at(courseNumber).courseTitle << endl;
    }
}

// Function to print information of a specific course, including its prerequisites
void printCourse(const unordered_map<string, Course>& courses, const string& courseNumber) {
    // Check if the course exists in the hash table
    if (courses.find(courseNumber) != courses.end()) {
        const Course& course = courses.at(courseNumber);
        cout << course.courseNumber << ", " << course.courseTitle << endl;

        if (course.prerequisites.empty()) {
            cout << "Prerequisites: None" << endl;
        } else {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < course.prerequisites.size(); ++i) {
                if (i > 0) cout << ", ";
                cout << course.prerequisites[i];
            }
            cout << endl;
        }
    } else {
        cout << "Course not found." << endl;
    }
}

// Display the menu and handle user input
void displayMenu() {
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
}

int main() {
    unordered_map<string, Course> courses; // Hash table to store course data
    int choice = 0;
    string filename;
    string courseNumber;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        displayMenu();
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Load course data from file
                cout << "Enter the file name to load: ";
                cin >> filename;
                loadCourses(courses, filename);
                break;

            case 2:
                // Print the course list in alphanumeric order
                printCourseList(courses);
                break;

            case 3:
                // Print specific course information
                cout << "What course do you want to know about? ";
                cin >> courseNumber;
                // Convert course number to uppercase to match the stored format
                transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);
                printCourse(courses, courseNumber);
                break;

            case 9:
                // Exit the program
                cout << "Thank you for using the course planner!" << endl;
                break;

            default:
                // Handle invalid input
                cout << choice << " is not a valid option." << endl;
                break;
        }
    }

    return 0;
}