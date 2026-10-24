#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string fullName;
    int groupNumber;
    int absences;
};

int main() {
    const int numStudents = 10;
    Student students[numStudents];

    cout << "=== Введення даних про студентів ===" << endl;
    for (int i = 0; i < numStudents; i++) {
        Student* studentPtr = &students[i];

        cout << "\nСтудент №" << i + 1 << ":" << endl;
        cout << "ПІБ: ";
        getline(cin >> ws, studentPtr->fullName);

        cout << "Номер групи: ";
        cin >> studentPtr->groupNumber;

        cout << "Кількість пропусків: ";
        cin >> studentPtr->absences;
    }

    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            Student* ptr1 = &students[i];
            Student* ptr2 = &students[j];

            if (ptr1->groupNumber < ptr2->groupNumber) {
                swap(*ptr1, *ptr2);
            }
        }
    }

    cout << "\n=== Студенти з кількістю пропусків більше 20 ===" << endl;
    bool found = false;

    for (int i = 0; i < numStudents; i++) {
        Student* studentPtr = &students[i];

        if (studentPtr->absences > 20) {
            cout << "ПІБ: " << studentPtr->fullName 
                 << " | Група: " << studentPtr->groupNumber 
                 << " | Пропусків: " << studentPtr->absences << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Студентів з кількістю пропусків більше 20 не знайдено." << endl;
    }

    return 0;
}
