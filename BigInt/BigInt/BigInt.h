#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
using std::string;
using std::ostream;
using std::istream;
using std::vector;


const int base = 2;

struct BigInt{
	bool isnegative;			// змінна, котра відповідає за знак числа;
	vector <bool> bignumber;	// масив елементів BigInt розміром 1 біт;
};

// construct - allocate memory etc.
const BigInt create(const long);
const BigInt create(const unsigned long);
const BigInt create(const string &);

// destroy - free memory etc.
void destroy(BigInt &);

/**************************
** arithmetic operations **
**************************/
BigInt operator+(const BigInt &); //+
BigInt operator-(const BigInt &); //+

BigInt & operator++(BigInt &);
BigInt & operator++(BigInt &, int);

BigInt & operator--(BigInt &);
BigInt & operator--(BigInt &, int);

BigInt operator+(const BigInt &, const long int);
BigInt operator+(const BigInt &, const unsigned long int);
BigInt operator+(const long int, const BigInt &);
BigInt operator+(const unsigned long int, const BigInt &);
BigInt operator+(const BigInt &, const BigInt &);

BigInt operator-(const BigInt &, const long int);
BigInt operator-(const BigInt &, const unsigned long int);
BigInt operator-(const long int, const BigInt &);
BigInt operator-(const unsigned long int, const BigInt &);
BigInt operator-(const BigInt &, const BigInt &);

BigInt operator*(const BigInt &, const long int);
BigInt operator*(const BigInt &, const unsigned long int);
BigInt operator*(const long int, const BigInt &);
BigInt operator*(const unsigned long int, const BigInt &);
BigInt operator*(const BigInt &, const BigInt &);

BigInt operator/(const BigInt &, const long int);
BigInt operator/(const BigInt &, const unsigned long int);
BigInt operator/(const long int, const BigInt &);
BigInt operator/(const unsigned long int, const BigInt &);
BigInt operator/(const BigInt &, const BigInt &);

BigInt operator%(const BigInt &, const long int);
BigInt operator%(const BigInt &, const unsigned long int);
BigInt operator%(const long int, const BigInt &);
BigInt operator%(const unsigned long int, const BigInt &);
BigInt operator%(const BigInt &, const BigInt &);

BigInt & operator+=(BigInt &, const long int);
BigInt & operator+=(BigInt &, const unsigned long int);
BigInt & operator+=(BigInt &, const BigInt &);

BigInt & operator-=(BigInt &, const long int);
BigInt & operator-=(BigInt &, const unsigned long int);
BigInt & operator-=(BigInt &, const BigInt &);

BigInt & operator*=(BigInt &, const long int);
BigInt & operator*=(BigInt &, const unsigned long int);
BigInt & operator*=(BigInt &, const BigInt &);

BigInt & operator/=(BigInt &, const long int);
BigInt & operator/=(BigInt &, const unsigned long int);
BigInt & operator/=(BigInt &, const BigInt &);

BigInt & operator%=(BigInt &, const long int);
BigInt & operator%=(BigInt &, const unsigned long int);
BigInt & operator%=(BigInt &, const BigInt &);

/*************************
**  logical operations  **
*************************/
bool operator==(const BigInt &, const BigInt &);
bool operator==(const BigInt &, const long int);
bool operator==(const BigInt &, const unsigned long int);
bool operator==(const long int &, const BigInt &);
bool operator==(const unsigned long int &, const BigInt &);

bool operator!=(const BigInt &, const BigInt &);
bool operator!=(const BigInt &, const long int);
bool operator!=(const BigInt &, const unsigned long int);
bool operator!=(const long int &, const BigInt &);
bool operator!=(const unsigned long int &, const BigInt &);

bool operator>(const BigInt &, const BigInt &);
bool operator>(const BigInt &, const long int);
bool operator>(const BigInt &, const unsigned long int);
bool operator>(const long int &, const BigInt &);
bool operator>(const unsigned long int &, const BigInt &);

bool operator<(const BigInt &, const BigInt &);
bool operator<(const BigInt &, const long int);
bool operator<(const BigInt &, const unsigned long int);
bool operator<(const long int &, const BigInt &);
bool operator<(const unsigned long int &, const BigInt &);

bool operator>=(BigInt &, const BigInt &);
bool operator>=(BigInt &, const long int);
bool operator>=(BigInt &, const unsigned long int);
bool operator>=(long int &, const BigInt &);
bool operator>=(unsigned long int &, const BigInt &);

bool operator<=(BigInt &, const BigInt &);
bool operator<=(BigInt &, const long int);
bool operator<=(BigInt &, const unsigned long int);
bool operator<=(long int &, const BigInt &);
bool operator<=(unsigned long int &, const BigInt &);

/*************************
**  bitwise operations  **
*************************/
BigInt operator~(const BigInt &); //+

BigInt operator&(const BigInt & big, const BigInt & big1);
BigInt operator&(const BigInt &, const long int);
BigInt operator&(const BigInt &, const unsigned long int);
BigInt operator&(const long int &, const BigInt &);
BigInt operator&(const unsigned long int &, const BigInt &);

BigInt operator|(const BigInt &, const BigInt &);
BigInt operator|(const BigInt &, const long int);
BigInt operator|(const BigInt &, const unsigned long int);
BigInt operator|(const long int &, const BigInt &);
BigInt operator|(const unsigned long int &, const BigInt &);

BigInt operator^(const BigInt &, const BigInt &);
BigInt operator^(const BigInt &, const long int);
BigInt operator^(const BigInt &, const unsigned long int);
BigInt operator^(const long int &, const BigInt &);
BigInt operator^(const unsigned long int &, const BigInt &);

BigInt operator<<(const BigInt &, const unsigned long int); //+
BigInt operator>>(const BigInt &, const unsigned long int); //+

BigInt & operator&=(BigInt &, const BigInt &);
BigInt & operator&=(BigInt &, const long int);
BigInt & operator&=(BigInt &, const unsigned long int);

BigInt & operator|=(BigInt &, const BigInt &);
BigInt & operator|=(BigInt &, const long int);
BigInt & operator|=(BigInt &, const unsigned long int);

BigInt & operator^=(BigInt &, const BigInt &);
BigInt & operator^=(BigInt &, const long int);
BigInt & operator^=(BigInt &, const unsigned long int);

BigInt & operator<<=(BigInt &, const unsigned long int); //+
BigInt & operator>>=(BigInt &, const unsigned long int); //+

/*************************
**     IO operators     **
*************************/
ostream & operator<<(ostream &, const BigInt &);
istream & operator>>(istream &, BigInt &);