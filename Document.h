#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document {
protected:
    std::string number;
    std::string owner;

public:
    Document(const std::string& number, const std::string& owner);
    virtual ~Document() = default;

    std::string getNumber() const;
    std::string getOwner() const;
    void setNumber(const std::string& value);
    void setOwner(const std::string& value);

    virtual void show() const;
    virtual void edit();
    virtual double averageScore() const = 0;
};

#endif
