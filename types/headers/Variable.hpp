#ifndef Variable_HPP
#define Variable_HPP

#include "DynamicInteger.hpp"
#include <iostream>
#include <vector>

union VarData
{
    dynamic_int* intData;
    double* floatData;
    std::string* stringData;
    bool* boolData;
};

enum class VarType
{
    None,
    Int,
    Float,
    String,
    Bool
};


class Variable
{
private:
    VarData data;
    VarType type;

    void clearData();
    void copyDataFromOther(const Variable&);
public:
    Variable();
    Variable(const dynamic_int&);
    Variable(const long long&);
    Variable(const int&);
    Variable(const double&);
    Variable(const char*);
    Variable(const bool&);
    Variable(const Variable&);
    ~Variable();
    VarType getType() const;
    VarData getData() const;
    Variable& operator=(const Variable&);
    Variable& toInt();
    Variable& toFloat();
    Variable& toString();
    Variable& toBool();
    friend Variable toInt(const Variable&);
    friend Variable toInt(const dynamic_int&);
    friend Variable toInt(const long long&);
    friend Variable toInt(const int& = 0);
    friend Variable toInt(const double&);
    friend Variable toInt(const char*);
    friend Variable toInt(const bool&);
    friend Variable toFloat(const Variable&);
    friend Variable toString(const Variable&);
    friend Variable toBool(const Variable&);
    friend std::ostream& operator<<(std::ostream&, const Variable&);
    friend std::istream& operator>>(std::istream&, Variable&);
};

typedef Variable var;

#endif