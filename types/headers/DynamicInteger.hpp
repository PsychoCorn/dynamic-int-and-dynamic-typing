#ifndef DynamicInteger_HPP
#define DynamicInteger_HPP

#include <gmp.h>
#include <iostream>

class DynamicInteger
{
private:
    mpz_t value;
public:
    DynamicInteger();
    DynamicInteger(const int&);
    DynamicInteger(const long long&);
    DynamicInteger(const char*);
    DynamicInteger(const double&);
    DynamicInteger(const DynamicInteger&);
    ~DynamicInteger();
    char* strGetNumber() const;
    double doubleGetNumber() const;
    long long longLongGetNumber(bool = true) const;
    bool boolGetNumber() const;
    DynamicInteger& operator=(const DynamicInteger&);
    DynamicInteger operator+(const DynamicInteger&) const;
    DynamicInteger operator-(const DynamicInteger&) const;
    DynamicInteger operator*(const DynamicInteger&) const;
    DynamicInteger operator/(const DynamicInteger&) const;
    DynamicInteger operator%(const DynamicInteger&) const;
    DynamicInteger operator-() const;
    bool operator!() const;
    bool operator<(const DynamicInteger&) const;
    bool operator>(const DynamicInteger&) const;
    bool operator<=(const DynamicInteger&) const;
    bool operator>=(const DynamicInteger&) const;
    bool operator==(const DynamicInteger&) const;
    bool operator!=(const DynamicInteger&) const;
    DynamicInteger operator~() const;
    DynamicInteger operator&(const DynamicInteger&) const;
    DynamicInteger operator|(const DynamicInteger&) const;
    DynamicInteger operator^(const DynamicInteger&) const;
    DynamicInteger operator<<(const long long&) const;
    DynamicInteger operator>>(const long long&) const;
    friend std::ostream& operator<<(std::ostream&, const DynamicInteger&);
    friend std::istream& operator>>(std::istream&, DynamicInteger&);
};

typedef DynamicInteger dynamic_int;

#endif