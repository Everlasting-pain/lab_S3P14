#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Document.h"
#include "EgeCertificate.h"
#include "RecordBook.h"
#include "Input.h"
using namespace std;

void showAll(Document* documents[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Документ №" << i + 1 << " ---" << endl;
        documents[i]->show();
    }
}

void calculate(Document* documents[], int n) {
    double egeSum = 0, bookSum = 0;
    int egeCount = 0, bookCount = 0;
    for (int i = 0; i < n; i++) {
        double average = documents[i]->averageScore();
        cout << "Документ №" << i + 1 << " (" << documents[i]->getOwner()
             << "): " << average << endl;
        if (dynamic_cast<EgeCertificate*>(documents[i])) {
            egeSum += average;
            egeCount++;
        } else if (dynamic_cast<RecordBook*>(documents[i])) {
            bookSum += average;
            bookCount++;
        }
    }
    if (egeCount > 0)
        cout << "Средний балл по свидетельствам ЕГЭ (0-100): " << egeSum / egeCount << endl;
    if (bookCount > 0)
        cout << "Средний балл по зачётным книжкам (2-5): " << bookSum / bookCount << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << fixed << setprecision(2);
    EgeCertificate ege1("EGE-101", "Иванов И.И.", "Школа №10", 80, 90, 100);
    EgeCertificate ege2("EGE-102", "Петров П.П.", "Школа №25", 60, 70, 80);
    RecordBook book1("ZK-201", "Сидоров С.С.", "СПбГУТ", 1, 5, 4, 3);
    RecordBook book2("ZK-202", "Смирнов А.А.", "СПбГУТ", 2, 5, 5, 5);
    const int N = 4;
    Document* documents[N] = {&ege1, &ege2, &book1, &book2};

    try {
        while (true) {
            cout << "\n===== Документы. Вариант 17 =====\n"
                 << "1. Показать все документы\n"
                 << "2. Изменить документ по номеру в массиве\n"
                 << "3. Вычислить средние баллы\n"
                 << "0. Выход" << endl;
            int command = readInt("Ваш выбор: ", 0, 3);
            switch (command) {
                case 1: showAll(documents, N); break;
                case 2: {
                    int index = readInt("Номер документа (1-4): ", 1, N) - 1;
                    documents[index]->edit();
                    cout << "Документ изменён." << endl;
                    documents[index]->show();
                    break;
                }
                case 3: calculate(documents, N); break;
                case 0: cout << "До свидания!" << endl; return 0;
            }
        }
    } catch (const runtime_error& error) {
        cout << '\n' << error.what() << endl;
    }
    return 0;
}
