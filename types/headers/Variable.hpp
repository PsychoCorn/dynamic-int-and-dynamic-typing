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
};

enum class VarType
{
    None,
    Int,
    Float,
    String,
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
    Variable(const Variable&);
    ~Variable();
    VarType getType() const;
    VarData getData() const;
    Variable& operator=(const Variable&);
};

typedef Variable var;


#endif