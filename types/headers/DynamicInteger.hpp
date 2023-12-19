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
    DynamicInteger(const long long&);
    DynamicInteger(const char*);
    DynamicInteger(const DynamicInteger&);
    ~DynamicInteger();
    char* strGetNumber() const;
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
};

typedef DynamicInteger dynamic_int;

std::ostream& operator<<(std::ostream&, const dynamic_int&);

#endif