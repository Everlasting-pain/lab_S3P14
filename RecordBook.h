#ifndef RECORD_BOOK_H
#define RECORD_BOOK_H

#include "Document.h"

class RecordBook : public Document {
private:
    std::string university;
    int semester;
    int grades[3];

public:
    RecordBook(const std::string& number, const std::string& owner,
               const std::string& university, int semester,
               int maths, int programming, int physics);
    bool setGrade(int subject, int value);
    bool setSemester(int value);
    void show() const override;
    void edit() override;
    double averageScore() const override;
};

#endif
