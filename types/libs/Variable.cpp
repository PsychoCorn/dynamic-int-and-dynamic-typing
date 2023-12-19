#include "../headers/Variable.hpp"


Variable::Variable()
{
    type = VarType::None;
}

Variable::Variable(const dynamic_int& intValue)
{
    data.intData = new dynamic_int(intValue);
    type = VarType::Int;
}

Variable::Variable(const long long& intValue)
{
    data.intData = new dynamic_int(intValue);
    type = VarType::Int;
}

Variable::Variable(const int& intValue)
{
    data.intData = new dynamic_int(intValue);
    type = VarType::Int;
}

Variable::Variable(const double& floatValue)
{
    data.floatData = new double(floatValue);
    type = VarType::Float;
}

Variable::Variable(const char* strValue)
{
    data.stringData = new std::string(strValue);
    type = VarType::String;
}

Variable::Variable(const bool& boolValue)
{
    data.boolData = new bool(boolValue);
    type = VarType::Bool;
}

Variable::Variable(const Variable& varValue)
{
    copyDataFromOther(varValue);
}

void Variable::copyDataFromOther(const Variable& other)
{
    type = other.getType();
    switch (type)
    {
        case VarType::Int:
            data.intData = new dynamic_int(*(other.getData().intData));
            break;
        
        case VarType::Float:
            data.floatData = new double(*(other.getData().floatData));
            break;
        
        case VarType::String:
            data.stringData = new std::string(*(other.getData().stringData));
            break;

        case VarType::Bool:
            data.boolData = new bool(*(other.getData().boolData));
            break;
        
        default:
            break;
    }
}

Variable::~Variable()
{
    clearData();
}

VarType Variable::getType() const
{
    return type;
}

VarData Variable::getData() const
{
    return data;
}

void Variable::clearData()
{
    switch (type)
    {
    case VarType::Int:
        delete data.intData;
        break;

    case VarType::Float:
        delete data.floatData;
        break;

    case VarType::String:
        delete data.stringData;
        break;

    case VarType::Bool:
        delete data.boolData;
        break;
        
    default:
        break;
    }
    type = VarType::None;
}

Variable& Variable::operator=(const Variable& other)
{
    if (type == other.getType())
    {
        switch (type)
        {
        case VarType::Int:
            *(data.intData) = *(other.getData().intData);
            break;
        
        case VarType::Float:
            *(data.floatData) = *(other.getData().floatData);
            break;
        
        case VarType::String:
            *(data.stringData) = *(other.getData().stringData);
            break;

        case VarType::Bool:
            *(data.boolData) = *(other.getData().boolData);
            break;

        default:
            break;
        }
    }
    else
    {
        clearData();
        copyDataFromOther(other);
    }
    return *this;
}