#ifndef EGE_CERTIFICATE_H
#define EGE_CERTIFICATE_H

#include "Document.h"

class EgeCertificate : public Document {
private:
    std::string school;
    int scores[3];

public:
    EgeCertificate(const std::string& number, const std::string& owner,
                   const std::string& school, int russian, int maths, int it);
    bool setScore(int subject, int value);
    void show() const override;
    void edit() override;
    double averageScore() const override;
};

#endif
