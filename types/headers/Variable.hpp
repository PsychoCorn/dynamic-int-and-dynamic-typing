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
    friend Variable toFloat(const Variable&);
    friend Variable toString(const Variable&);
    friend Variable toBool(const Variable&);
    friend std::ostream& operator<<(std::ostream&, const Variable&);
    friend std::istream& operator>>(std::istream&, Variable&);
};

typedef Variable var;

Variable toInt(const dynamic_int& = 0);
Variable toInt(const char*);
Variable toFloat(const dynamic_int&);
Variable toFloat(const double&);
Variable toFloat(const char*);
Variable toFloat(const long long&);
Variable toFloat(const int&);


#endif