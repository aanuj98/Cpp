#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;

// Define the Class
class Student {

// Declare the variables
private : std:: string name;
                double gpa;
                double grade;

                

// Create public methods to access private variables
// Get used to get variables and protects the data
// 'this' keyword used to set the name
// -> is the pointer operator, used to access the object's fields
public: 
    //Static value that stays the same
     //   static string classLevel;
        
        std::string GetName(){return name;}  
        void SetName(std::string name){this->name = name;}
        double GetGpa(){return gpa;}
        void SetGpa(double gpa){this->gpa = gpa;}
        double GetGrade(){return grade;}
        void SetGrade(double grade){this->grade = grade;}

        //this function allows the user to set the values
        void SetAll(std:: string, double, double);

        //Constructor
        Student(std::string, double, double);

        // Overload constructor for when no data is passed
        Student();

        //Created to make print easy
        void ToString();

};


//Define method for setAll
void Student::SetAll(std::string name,
                        double gpa, double grade){
                            this->name = name;
                            this->gpa = gpa;
                            this-> grade = grade;
                        }
                    

// Created the constructor
Student::Student(std::string name,
                        double gpa, double grade){
                            this->name = name;
                            this->gpa = gpa;
                            this->grade = grade;
                         //   Student::classLevel ="Junior";
}

//Constructor that will handle default values
Student::Student(){
                    this->name = "";
                    this->gpa = 0;
                    this->grade = 0;
                 //   Student::classLevel = "Junior";
}

//Override Method to print the data
void Student::ToString(){
    std::cout << this->name << "'s gpa is " << this->gpa << ".\n";
}

//New Class that inherits from Student class
class Math: public Student{
    public:
            // Set the static course value as Math
            std::string course = "Math";
            void SetAll(std:: string, double, double, std::string);

            // Passing in a new variable in the constructor from Student class
            Math(std::string, double, double, std::string);
            Math(): Student(){};

            //Overide the ToString() method
            void ToString(){
            std::cout << this->GetName() << " received a grade of "<< this->GetGrade() << " in " << this->course << ". " 
            << this->GetName() << "'s GPA is: " << this->GetGpa() << ".\n";
            }

            //Overloading Method used to filter students by string name
            void studentPrint(int numStudents, Math mathClass[], string nameFind){
                
                for (int i = 0; i <= numStudents; i++) { 
                        if (mathClass[i].GetName() == nameFind){
                            mathClass[i].ToString();
                        }
                        }
            }
};
//Constructor 
Math::Math(std:: string name, double gpa, 
                double grade, std::string course): Student(name, gpa, grade){
                    this -> course = course;
                }

//New Class that inherits from Student class
class English: public Student{
    public:
            std::string course = "English";
            void SetAll(std:: string, double, double, std::string);

            
            English(std::string, double, double, std::string);
            English(): Student(){};

            //Override the ToString() method
            void ToString(){
            std::cout << this->GetName() << " received a grade of "<< this->GetGrade() << " in " << this->course << ". " 
            << this->GetName() << "'s GPA is: " << this->GetGpa() << ".\n";
            }

            //Overloading Method used to filter students by grade instead of name
            void studentPrint(int numStudents, English englishClass[], double gradeFind){
                
                for (int i = 0; i <= numStudents; i++) { 
                        if (englishClass[i].GetGrade() == gradeFind){
                            englishClass[i].ToString();
                        }

                        }
            }

};
//Constructor 
English::English(std:: string name, double grade, 
                double gpa, std::string course): Student(name, grade, gpa){
                    this -> course = course;
                }


//Main Method 
int main() {


// For adding new students
string names, courses;
double gpaNew, gradesNew;
Math addingMath;
English addingEng;
int numStudents = 1;
string toQuit = "";
string input;
string newInput;
string filter;
int filterGrade;
string filterName;
int aryTracker = 2;

// Create Math objects data and give them data
Math Sky("Sky", 3.8, 98, "Math");
Math Dillon("Dillion", 3.6, 89, "Math");

// Create English objects data and give them data
English Susan("Susan", 3.1, 79, "English");
English Sam("Sam", 3.7, 90, "English");

//Create object arrays for easy handling of data
Student studentAry[20] = {Sky, Dillon, Susan, Sam};
Math mathClass[10] = {Sky, Dillon};
English englishClass[10] = {Susan, Sam};


// Ask user if they want to print exisiting class records
cout << "Enter 'All' if you would like to see a list of all students:\nIf you would like to see Math or English class records enter 'Math' or 'English':\nIf you would like to enter new student information enter 'New':";
cin >> input;

// Checks if input is math then prints the math class
if (input == "Math"){
    for (int i = 0; i < 2; i++) { 
        mathClass[i].ToString();
    }
}

// If input if enligh then prints english class
else if (input == "English"){
    for (int i = 0; i < 2; i++) { 
        englishClass[i].ToString();
    }
}

// If input is All then print all the students
 else if (input == "All"){
     for (int i = 0; i < 4; i++) { 
        studentAry[i].ToString();
    }
 }

// If input is new then helps you add students to new class
else if (input =="New"){
    cout << "Please enter 'Math' or 'English' depending on which class you would like to add to.";
    cin >> newInput;
    
    // Functions to add students to math class
    if (newInput == "Math"){
        cout << "You can add 5 more students or enter 'Quit' to exit.\n";

        // Add students to Math class
        while (numStudents < 9){
            // Create a math object to add students
            Math newStudent;

            //Get data from user, get name, gpa, and grade
            cout << "Enter student's name: " << endl;
            cin >> names;
            newStudent.SetName(names);
            cout <<"Enter student's gpa: " << endl;
            cin >> gpaNew;
            newStudent.SetGpa(gpaNew);
            cout << "Enter student's grades: " << endl;
            cin >> gradesNew;
            newStudent.SetGrade(gradesNew);
          
            //Add the new student from user inputs to math array 
            mathClass[aryTracker] = newStudent;
            aryTracker++;
            numStudents++;
            //Ask the user if they want to print or keep adding
            cout << "Enter 'Print' to print the Math class or enter 'Add' to continue.\n";
            if (numStudents == 8){
                cout << "The class is full and you can't add more students.\n";
                cout << "Enter 'Quit to exit or 'Continue' to print the students in class.";
            }
            cin >> toQuit;

            //If the user enters Quit then print the class data
            if (toQuit == "Continue" || toQuit == "Print"){
                 for (int i = 0; i <= numStudents; i++) { 
                    mathClass[i].ToString(); 
                }

                //Ask the user if they want to print the students by filtering by name
                cout << "Enter 'Filter' to filter students by name or enter 'Done' to exit: ";
                cin >> filter;
                if (filter == "Filter"){
                    cout << "Enter the name you want to use to filter variables: ";
                    cin >> filterName;
                    newStudent.studentPrint(numStudents, mathClass, filterName);
                }
                break;
            }
            else if (toQuit == "Quit"){
                break;
            }
           
        } 
    }


    if (newInput == "English"){
        cout << "You can add 5 more students or enter 'Quit' to exit.\n";
        while (numStudents < 9){
            English newStudent;
            cout << "Enter student's name: " << endl;
            cin >> names;
            newStudent.SetName(names);
            cout <<"Enter student's gpa: " << endl;
            cin >> gpaNew;
            newStudent.SetGpa(gpaNew);
            cout << "Enter student's grades: " << endl;
            cin >> gradesNew;
            newStudent.SetGrade(gradesNew);
            englishClass[aryTracker] = newStudent;
            aryTracker++;
            numStudents ++;
            //Ask the user if they want to print or keep adding
            cout << "Enter 'Print' to print the English class or enter 'Add' to continue:\n";
            if (numStudents == 8){
                cout << "The class is full and you can't add more students!!\n";
                cout << "Enter 'Quit to exit or 'Continue' to print the students in class: ";
            }
            cin >> toQuit;

            //If the user enters Quit then print the class data
            if (toQuit == "Continue" || toQuit == "Print"){
                 for (int i = 0; i <= numStudents; i++) { 
                    englishClass[i].ToString(); 
                }

                //Ask the user if they want to print the students by filtering by name
                cout << "Enter 'Filter' to filter students by grade or enter 'Done' to exit: ";
                cin >> filter;
                if (filter == "Filter"){
                    cout << "Enter the grade you want to use to filter variables: ";
                    cin >> filterGrade;
                    newStudent.studentPrint(numStudents, englishClass, filterGrade);
                }
                break;
            }
            else if (toQuit == "Quit"){
                break;
            }
        }
    }
}
 

  return 0;
  
}