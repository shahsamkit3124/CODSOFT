/*Create a program that manages student grades. Allow the user
to input student names and their corresponding grades.
Calculate the average grade and display it along with the highest
and lowest grades*/

#include <iostream>
#include <string>

using namespace std;

struct Student {
  string name;
  int grade;
};

int main() {
  // Declare variables.
  int n;
  Student students[100];
  int highest_grade = 0;
  int lowest_grade = 100;
  int sum_of_grades = 0;

  // Get the number of students from the user.
  cout << "Enter the number of students: ";
  cin >> n;

  // Get the names and grades of the students from the user.
  for (int i = 0; i < n; i++) {
    cout << "Enter the name of student " << i + 1 << ": ";
    cin >> students[i].name;

    cout << "Enter the grade of student " << i + 1 << ": ";
    cin >> students[i].grade;

    // Update the highest and lowest grades.
    if (students[i].grade > highest_grade) {
      highest_grade = students[i].grade;
    }

    if (students[i].grade < lowest_grade) {
      lowest_grade = students[i].grade;
    }

    sum_of_grades += students[i].grade;
  }

  // Calculate the average grade.
  float average_grade = (float)sum_of_grades / n;

  // Display the results.
  cout << "The average grade is " << average_grade << endl;
  cout << "The highest grade is " << highest_grade << endl;
  cout << "The lowest grade is " << lowest_grade << endl;

  return 0;
}
