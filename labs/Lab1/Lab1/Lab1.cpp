/*  
* Lab 1
* Rafael Hernandez               // Part 1
* COSC 1436
* Spring 2026
*/

#include <iostream>
#include <string>
#include <iomanip>

void main()
{  
    std::string fullName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, fullName);

    // Enter inputs for your grades
    double labOneGrade, labTwoGrade, labThreeGrade, labFourGrade;
    std::cout << "Enter your lab 1 grade: ";
    std::cin >> labOneGrade;
    std::cout << "Enter your lab 2 grade: ";
    std::cin >> labTwoGrade;
    std::cout << "Enter your lab 3 grade: ";
    std::cin >> labThreeGrade;
    std::cout << "Enter your lab 4 grade: ";
    std::cin >> labFourGrade;

    double examGradeOne, examGradeTwo, examGradeThree;
    std::cout << "Enter your exam 1 grade: ";
    std::cin >> examGradeOne;
    std::cout << "Enter your exam 2 grade: ";
    std::cin >> examGradeTwo;
    std::cout << "Enter your exam 3 grade: ";
    std::cin >> examGradeThree;

    double participation, finalExam;
    std::cout << "Enter your participation grade: ";
        std::cin >> participation;
    std::cout << "Enter your final exam grade: ";
    std::cin >> finalExam;

    // Story 3 and 4 averages
    double averageLab;
    averageLab = (double)(labOneGrade + labTwoGrade + labThreeGrade + labFourGrade) / 4; 

    double averageExam;
    averageExam = (double)(examGradeOne + examGradeTwo + examGradeThree) / 3;
    std::cout << "\n" << std::endl;

    // Labs grade and average
    std::cout << fullName << "," << " your lab grades are:" << std::endl;
    std::cout << "Lab 1 grade = " << labOneGrade << std::endl;
    std::cout << "Lab 2 grade = " << labTwoGrade << std::endl;
    std::cout << "Lab 3 grade = " << labThreeGrade << std::endl;
    std::cout << "Lab 4 grade = " << labFourGrade << std::endl;
    std::cout << "The average lab grade = "
        << averageLab << std::endl;
    std::cout << "\n" << std::endl;
    
    // Exam Grade
    std::cout << fullName << "," << " your exam grades are:" << std::endl;
    std::cout << "Exam 1 grade = " << examGradeOne << std::endl;
    std::cout << "Exam 2 grade = " << examGradeTwo << std::endl;
    std::cout << "Exam 3 grade = " << examGradeThree << std::endl;
    std::cout << "The average exam grade = "
        << averageExam << std::endl;
    std::cout << "\n" << std::endl;

    // Final exam and other grades
    std::cout << fullName << "," << " your other grades are: " << std::endl;
    std::cout << "Participation = " << participation << std::endl;
    std::cout << "Final exam = " << finalExam << std::endl;
    std::cout << "\n" << std::endl;

    // Your class average
    double classAverage = (averageLab * 0.65) + (averageExam * 0.20) + (participation * 0.05) + (finalExam * 0.10);
    
    std::cout << fullName << "," << " your class grade is: " << std::endl;
    std::cout << "Average lab grade (65%) is: "
    << std::fixed << std::setprecision(2)       
        << averageLab << "%" << std::endl;
    std::cout << "Average exam grade (20%) is: "
        << averageExam << "%" << std::endl;
    std::cout << "Participation grade (5%) is: "
        << participation << "%" << std::endl;
    std::cout << "Final exam grade (10%) is: "
        << finalExam << "%" << std::endl;
    
    std::cout << "\n" << std::endl;
    std::cout << "Your class average is: " << std::endl;
    std::cout << "Class average = "
        << classAverage << "%" << std::endl;
}

