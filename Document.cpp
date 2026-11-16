#include "Document.h"
#include "Input.h"
#include <iostream>
using namespace std;

Document::Document(const string& number, const string& owner)
    : number(number), owner(owner) {}

string Document::getNumber() const { return number; }
string Document::getOwner() const { return owner; }
void Document::setNumber(const string& value) { number = value; }
void Document::setOwner(const string& value) { owner = value; }

void Document::show() const {
    cout << "Номер: " << number << " | Владелец: " << owner << endl;
}

void Document::edit() {
    setNumber(readText("Новый номер документа: "));
    setOwner(readText("Новый владелец: "));
}
