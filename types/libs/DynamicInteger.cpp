#include "../headers/DynamicInteger.hpp"

DynamicInteger::DynamicInteger()
{
    mpz_init(value);
}

DynamicInteger::DynamicInteger(const long long& intValue)
{
    mpz_init_set_si(value, intValue);
}

DynamicInteger::DynamicInteger(const char* strValue)
{
    mpz_init_set_str(value, strValue, 10);
}

DynamicInteger::DynamicInteger(const DynamicInteger& dynIntValue)
{
    mpz_init_set_str(value, dynIntValue.strGetNumber(), 10);
}

DynamicInteger::~DynamicInteger()
{
    mpz_clear(value);
}

std::ostream& operator<<(std::ostream& os, const dynamic_int& obj)
{
    os << obj.strGetNumber();
    return os;
}

char* DynamicInteger::strGetNumber() const
{
    return mpz_get_str(nullptr, 10, value);
}

DynamicInteger DynamicInteger::operator+(const DynamicInteger& other) const
{
    DynamicInteger result;
    mpz_add(result.value, this->value, other.value);
    return result;
}

DynamicInteger& DynamicInteger::operator=(const DynamicInteger& other)
{
    mpz_set(this->value, other.value);
    return *this;
}

DynamicInteger DynamicInteger::operator-(const DynamicInteger& other) const
{
    DynamicInteger result;
    mpz_sub(result.value, this->value, other.value);
    return result;
}

DynamicInteger DynamicInteger::operator*(const DynamicInteger& other) const
{
    DynamicInteger result;
    mpz_mul(result.value, this->value, other.value);
    return result;
}

DynamicInteger DynamicInteger::operator/(const DynamicInteger& other) const
{
    DynamicInteger result;
    mpz_tdiv_q(result.value, this->value, other.value);
    return result;
}

bool DynamicInteger::operator<(const DynamicInteger& other) const
{
    return mpz_cmp(this->value, other.value) < 0;
}

bool DynamicInteger::operator>(const DynamicInteger& other) const
{
    return mpz_cmp(this->value, other.value) > 0;
}

bool DynamicInteger::operator==(const DynamicInteger& other) const
{
    return mpz_cmp(this->value, other.value) == 0;
}

bool DynamicInteger::operator!=(const DynamicInteger& other) const
{
    return !(mpz_cmp(this->value, other.value) == 0);
}

bool DynamicInteger::operator<=(const DynamicInteger& other) const
{
    return mpz_cmp(this->value, other.value) <= 0;
}

bool DynamicInteger::operator>=(const DynamicInteger& other) const
{
    return mpz_cmp(this->value, other.value) >= 0;
}

bool DynamicInteger::operator!() const
{
    return this != 0;
}

DynamicInteger DynamicInteger::operator%(const DynamicInteger& other) const
{
    DynamicInteger result;
    mpz_tdiv_r(result.value, this->value, other.value);
    return result;
}
DynamicInteger DynamicInteger::operator-() const
{
    DynamicInteger result;
    mpz_neg(result.value, this->value);
    return result;
}

DynamicInteger DynamicInteger::operator~() const
{
    DynamicInteger result;
    mpz_t one;
    mpz_init_set_str(one, "1", 10);
    mpz_xor(result.value, value, one);
    mpz_clear(one);
    return -result;
}

DynamicInteger DynamicInteger::operator&(const DynamicInteger& other) const {
    DynamicInteger result;
    mpz_and(result.value, this->value, other.value);
    return result;
}

DynamicInteger DynamicInteger::operator|(const DynamicInteger& other) const {
    DynamicInteger result;
    mpz_ior(result.value, this->value, other.value);
    return result;
}

DynamicInteger DynamicInteger::operator^(const DynamicInteger& other) const {
    DynamicInteger result;
    mpz_xor(result.value, this->value, other.value);
    return result;
}

DynamicInteger DynamicInteger::operator<<(const long long& shift) const {
    if (shift < 0) {
        throw std::runtime_error("Negative shift value");
    }
    DynamicInteger result;
    mpz_mul_2exp(result.value, this->value, shift);
    return result;
}

DynamicInteger DynamicInteger::operator>>(const long long& shift) const {
    if (shift < 0) {
        throw std::runtime_error("Negative shift value");
    }
    DynamicInteger result;
    mpz_tdiv_q_2exp(result.value, this->value, shift);
    return result;
}