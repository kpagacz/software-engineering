#include <iostream>

bool isLeapYear (int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

bool isMonth (int month) {
    if ((month > 0) && (month < 13)) {
        return true;
    } else {
        return false;
    }
}

bool isDay (int year, int month, int day) {
    // february
    if (month == 2) {
        if (isLeapYear(year) && day > 0 && day < 30) {
            // is leap year and day is 1-29
            return true;
        } else if (isLeapYear(year) == false && day > 0 && day < 29) {
            // is leap year and day is 1-28
            return true;
        } else {
            // is anything else
            return false;
        }
    }

    // 31 day months
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        // months with 31 days here
        if (day > 0 && day < 32) {
            return true;
        } else {
            return false;
        }
    } else {
        // months with only 30 days here
        if (day > 0 && day < 31) {
            return true;
        } else {
            return false;
        }
    }
}

bool dateComparison(int date1[3], int date2[3]) {
    if (date1[2] != date2[2]) {
        return date1[2] < date2[2];
    } else if (date1[1] != date2[1]) {
        return date1[1] < date2[1];
    } else if (date1[0] < date2[0]) {
        return date1[0] < date2[0];
    } else {
        return false;
    }
}

int main () {
    // input 
    int date1[3], date2[3];
    std::cout << "Please provide two dates as 6 integeres of D M Y D M Y. ";

    // input first date
    for (int j = 0; j < 3; j++) {
        std::cin >> date1[j];
    }

    // input second date
    for (int j = 0; j < 3; j++) {
        std::cin >> date2[j];
    }

    // check whether valid dates
    //  && isDay(date1[0], date1[1], date1[2]) && isDay(date2[0], date2[1], date2[2])
    if (isMonth(date1[1]) && isMonth(date2[1]) && isDay(date1[2], date1[1], date1[0]) && isDay(date2[2], date2[1], date2[0])) {
        // legit dates
        std::cout << "Dates are legit, bro.\n";

        // check if the first one is earlier
        if (dateComparison(date1, date2)) {
            std::cout << "The first one is earlier than the second one.";
        } else {
            std::cout << "The first one is not earlier than the second one.";
        }
    } else {
        // not legit dates
        std::cout << "Dates are not valid. Input valid dates.";
    }
    return 0;
}