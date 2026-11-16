#include "EgeCertificate.h"
#include "Input.h"
#include <iostream>
#include <stdexcept>
using namespace std;

EgeCertificate::EgeCertificate(const string& number, const string& owner,
                             const string& school, int russian, int maths, int it)
    : Document(number, owner), school(school), scores{0, 0, 0} {
    if (!setScore(0, russian) || !setScore(1, maths) || !setScore(2, it))
        throw invalid_argument("Баллы ЕГЭ должны быть от 0 до 100.");
}

bool EgeCertificate::setScore(int subject, int value) {
    if (subject < 0 || subject >= 3 || value < 0 || value > 100) return false;
    scores[subject] = value;
    return true;
}

double EgeCertificate::averageScore() const {
    return (scores[0] + scores[1] + scores[2]) / 3.0;
}

void EgeCertificate::show() const {
    cout << "Свидетельство ЕГЭ" << endl;
    Document::show();
    cout << "Школа: " << school << endl;
    cout << "Русский язык: " << scores[0] << " | Математика: " << scores[1]
         << " | Информатика: " << scores[2] << endl;
    cout << "Средний балл (0-100): " << averageScore() << endl;
}

void EgeCertificate::edit() {
    Document::edit();
    school = readText("Новая школа: ");
    const string subjects[3] = {"Русский язык", "Математика", "Информатика"};
    for (int i = 0; i < 3; i++)
        setScore(i, readInt(subjects[i] + " (0-100): ", 0, 100));
}
