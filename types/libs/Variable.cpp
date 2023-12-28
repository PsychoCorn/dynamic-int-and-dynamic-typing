#include "../headers/Variable.hpp"
#include <string>

Variable::Variable()
{
    type = VarType::None;
}

Variable::Variable(const dynamic_int& intValue)
{
    data.intData = new dynamic_int(intValue);
    type = VarType::Int;
}

Variable::Variable(const int& intValue)
{
    data.intData = new dynamic_int(intValue);
    type = VarType::Int;
}

Variable::Variable(const long long& intValue)
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

std::ostream& operator<<(std::ostream& os, const var& obj)
{
    switch (obj.type)
    {
        case VarType::Int:
            os << *(obj.data.intData);
            break;
        
        case VarType::Float:
            os << *(obj.data.floatData);
            break;
        
        case VarType::String:
            os << *(obj.data.stringData);
            break;

        case VarType::Bool:
            os << *(obj.data.boolData);
            break;

        case VarType::None:
        os << "None";
        break;
        
        default:
            break;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Variable& obj)
{
    std::string val;
    is >> val;
    obj = Variable(val.c_str());
    return is;
}

Variable& Variable::toInt()
{
    switch (type)
    {
    case VarType::Float:
        *this = Variable(dynamic_int(*(data.floatData)));
        break;

    case VarType::String:
        *this = Variable(dynamic_int(data.stringData->c_str()));
        break;
    
    case VarType::Bool:
        *this = Variable(*(data.boolData) ? 1 : 0);
        break;

    case VarType::None:
        *this = Variable(0);
        break;

    default:
        break;
    }
    return *this;
}

Variable toInt(const Variable& obj)
{
    switch (obj.getType())
    {
    case VarType::Float:
        return Variable(dynamic_int(*(obj.getData().floatData)));
        break;

    case VarType::String:
        return Variable(dynamic_int(obj.getData().stringData->c_str()));
        break;
    
    case VarType::Bool:
        return Variable(*(obj.getData().boolData) ? 1 : 0);
        break;

    case VarType::None:
        return Variable(0);
        break;

    default:
        break;
    }
    return obj;
}

Variable& Variable::toFloat()
{
    switch (type)
    {
    case VarType::Int:
        *this = Variable(data.intData->doubleGetNumber());
        break;

    case VarType::String:
        *this = Variable(std::stod(data.stringData->c_str()));
        break;
    
    case VarType::Bool:
        *this = Variable(*(data.boolData) ? 1.0f : 0.0f);
        break;

    case VarType::None:
        *this = Variable(0.0f);
        break;

    default:
        break;
    }
    return *this;
}

Variable toFloat(const Variable& obj)
{
    switch (obj.getType())
    {
    case VarType::Int:
        return Variable(obj.getData().intData->doubleGetNumber());
        break;

    case VarType::String:
        return Variable(std::stod(obj.getData().stringData->c_str()));
        break;
    
    case VarType::Bool:
        return Variable(*(obj.getData().boolData) ? 1.0f : .0f);
        break;

    case VarType::None:
        return Variable(.0f);
        break;

    default:
        break;
    }
    return obj;
}

Variable& Variable::toString()
{
    switch (type)
    {
    case VarType::Int:
        *this = Variable(data.intData->strGetNumber());
        break;

    case VarType::Float:
        *this = Variable(std::to_string(*(data.floatData)).c_str());
        break;
    
    case VarType::Bool:
        *this = Variable(std::to_string(*(data.boolData)).c_str());
        break;

    case VarType::None:
        *this = Variable("");
        break;

    default:
        break;
    }
    return *this;
}

Variable toString(const Variable& obj)
{
    switch (obj.getType())
    {
    case VarType::Int:
        return Variable(obj.getData().intData->strGetNumber());
        break;

    case VarType::Float:
        return Variable(std::to_string(*(obj.getData().floatData)).c_str());
        break;
    
    case VarType::Bool:
        return Variable(std::to_string(*(obj.getData().boolData)).c_str());
        break;

    case VarType::None:
        return Variable("");
        break;

    default:
        break;
    }
    return obj;
}