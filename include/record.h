#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Record {
protected:
    std::string name;
    std::string type;
    std::string record;

public:
    Record();
    Record(std::string name, std::string type, std::string record);
    virtual ~Record() = default;

    void setName(const std::string &r_name);
    void setRecord(const std::string &r_record);
    void setType(const std::string &r_type);

    std::string getName() const;
    std::string getRecord() const;
    std::string getType() const;

    std::string printRecord() const;
};

#endif