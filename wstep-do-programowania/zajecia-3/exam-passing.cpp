#include <iostream>
#include <cmath>


int main() {
    // input
    int absent1, absent2, pts1, pts2;
    std::cout << "Please input number of: absences before 1st colloq, after 1st colloq, points from 1st colloq and points from 2nd colloq.\n";
    std::cin >> absent1 >> absent2 >> pts1 >> pts2;

    // calculations
    int score1 = __max(0, pts1 - __max(absent1 - 2, 0) * 5);
    int absences_to_include_after_1st_colloq = abs(__min(pts1 - __max(absent1 - 2, 0) * 5, 0) / 5);
    int free_absences = __max(2 - absent1, 0);

    absent2 = absent2 + absences_to_include_after_1st_colloq;

    int score2 = __max(0, pts2 - __max(absent2 - free_absences, 0) * 5);
    int absences_to_include_after_2nd_colloq = abs(__min(pts2 - __max(absent2 - free_absences, 0) * 5, 0) / 5);

    float grade;
    int total_score = score1 + score2;

    if (total_score < 50) {
        grade = 2;
    } else if (total_score < 60) {
        grade = 3;
    } else if (total_score < 70) {
        grade = 3.5;
    } else if (total_score < 80) {
        grade = 4;
    } else if (total_score < 90) {
        grade = 4.5; 
    } else {
        grade = 5;
    }

    // output
    if (score1 + score2 > 50) {
        // student zaliczyl
        std::cout << "Student passed. ";
        std::cout << "Total score: " << score1 << " + " << score2 << " = " << score1 + score2 << ". ";
        std::cout << "Grade: " << grade << "\n";
    } else {
        std::cout << "Student has not passed. ";
        std::cout << "Total score: " << score1 << " + " << score2 << " = " << score1 + score2 << ". ";
        std::cout << "Number of points to subtract from the next result: " << absences_to_include_after_2nd_colloq * 5 << "\n";
    }
    return 0;
}