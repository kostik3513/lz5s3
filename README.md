# Лабораторна робота №5

**Виконав:** студент групи 4СОМ Кланцатий Костянтин

**Варіант:** №3

**Тема: Використання вказівників.**

**Мета:** *Отримати навички роботи з структурами з використанням вказівників.*

---

## Завдання (Варіант 3)

Опишіть структуру з іменем Student, яка б містила наступні поля:
* ПІБ;
* Номер групи;
* Кількість пропусків.

Напишіть програму, яка б виконувала наступні дії:
- введення з клавіатури даних в масив, що складається з десяти структур типу Student;
- впорядкування записів у масиві за зменшенням номеру групи.
- виведення на дисплей ПІБ і номерів груп для всіх студентів, кількість пропусків яких більша за 20.

Якщо таких студентів немає – вивести відповідне повідомлення.

---

**Код:**

```
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
```

<img width="1897" height="887" alt="image" src="https://github.com/user-attachments/assets/b3890912-2286-4a40-b76e-97d34206eb8d" />

---

## Висновок
У ході виконання лабораторної роботи було створено програму мовою C++ для обробки масиву структур `Student` з використанням вказівників та оператора `->`. 

Програма забезпечує:
* Введення даних про 10 студентів у пам'ять за допомогою вказівників.
* Сортування масиву за зменшенням номеру групи.
* Пошук та виведення даних про студентів, які мають більше 20 пропусків, із виведенням відповідного повідомлення у разі їх відсутності.
