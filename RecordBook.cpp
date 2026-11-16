#include "RecordBook.h"
#include "Input.h"
#include <iostream>
#include <stdexcept>
using namespace std;

RecordBook::RecordBook(const string& number, const string& owner,
                     const string& university, int semester,
                     int maths, int programming, int physics)
    : Document(number, owner), university(university), semester(1), grades{2, 2, 2} {
    if (!setSemester(semester) || !setGrade(0, maths)
        || !setGrade(1, programming) || !setGrade(2, physics))
        throw invalid_argument("Семестр: 1-12, оценки: 2-5.");
}

bool RecordBook::setGrade(int subject, int value) {
    if (subject < 0 || subject >= 3 || value < 2 || value > 5) return false;
    grades[subject] = value;
    return true;
}

bool RecordBook::setSemester(int value) {
    if (value < 1 || value > 12) return false;
    semester = value;
    return true;
}

double RecordBook::averageScore() const {
    return (grades[0] + grades[1] + grades[2]) / 3.0;
}

void RecordBook::show() const {
    cout << "Зачётная книжка" << endl;
    Document::show();
    cout << "Вуз: " << university << " | Семестр: " << semester << endl;
    cout << "Математика: " << grades[0] << " | Программирование: " << grades[1]
         << " | Физика: " << grades[2] << endl;
    cout << "Средний балл (2-5): " << averageScore() << endl;
}

void RecordBook::edit() {
    Document::edit();
    university = readText("Новый вуз: ");
    setSemester(readInt("Семестр (1-12): ", 1, 12));
    const string subjects[3] = {"Математика", "Программирование", "Физика"};
    for (int i = 0; i < 3; i++)
        setGrade(i, readInt(subjects[i] + " (2-5): ", 2, 5));
}
