#include "BigInt.h"
using namespace std;

const unsigned char toNumber(const char c)
{
        return c - '0';
}

const char toChar(const unsigned char c)
{
        return c + '0';
}

const BigInt create (const string & a)
{
	BigInt big;
	string tempstr = a;
	if (tempstr[0] == '-')
	{
		big.isnegative = true;
		tempstr[0] = '0';
	}
	else
	{
		big.isnegative = false;
	}
	const unsigned int bignumber_length = static_cast<unsigned int>(ceil((tempstr.length()-1) * (log(10.)/log(2.))));
	big.bignumber.reserve(bignumber_length);
	do
	{
		if (tempstr[0] == '0')
		{
			tempstr = tempstr.substr(1, tempstr.length()-1);
			continue;
		}
		unsigned char tempmod = 0; 
		for (unsigned long i = 0; i < tempstr.length(); i++)
		{
			unsigned char d = toNumber(tempstr[i]) + 10 * tempmod;
			tempmod = (d % base); // дістаємо остачу від ділення і-того елемента;
			d /= base; 
			tempstr[i] = toChar(d);
		}
		big.bignumber.push_back(tempmod ? true : false);
	} while (tempstr.length() != 0); // умова виконання циклу, поки довжина основного стрінга а не дорівнює '0';
	return big;
}

const BigInt create (const long number)
{
	BigInt big;
	big.isnegative = (number < 0); // визначаємо знак числа;
	long temp = number;
	do
	{
		big.bignumber.push_back((temp % base) ? true : false); //записуємо кожну остачу в кінець масиву;
		temp /= base;
	} while (temp != 0);
	return big;
}

const BigInt create (const unsigned long number)
{
	BigInt big;
	big.isnegative = (number < 0);
	unsigned long temp = number;
	do
	{
		big.bignumber.push_back((temp % base) ? true : false);
		temp /= base;
	} while (temp != 0);
	return big;
}

ostream & operator<<(ostream & os, const BigInt & a)
{
	os << "Is number has negative sign? - " << a.isnegative <<'\n';
	unsigned long i = a.bignumber.size();
	do
	{
		i--;
		os << a.bignumber.at(i) <<' ';
	}
	while (i != 0);
	os << '\n'  <<"Elemenths of vector - " << a.bignumber.size() << '\n';
	return os;
}

BigInt operator+(const BigInt & big)
{
	BigInt bigcopy = big;
	bigcopy.isnegative = bigcopy.isnegative;
	return big;
}
BigInt operator-(const BigInt & big)
{
	BigInt bigcopy = big;
	bigcopy.isnegative = !bigcopy.isnegative;
	return bigcopy;
}

BigInt & operator++(BigInt & big)
{
	vector <bool> one (1, true);
	
	return big;
}
BigInt & operator++(BigInt & big, int blind)
{
	vector <bool> one (1, true);

	return big;
}

BigInt & operator--(BigInt & big)
{
	vector <bool> one (1, true);

	return big;
}
BigInt & operator--(BigInt & big, int blind)
{
	vector <bool> one (1, true);

	return big;
}

BigInt operator~(const BigInt & big)
{
	BigInt bitnot = big;
	for (unsigned i = 0; i < bitnot.bignumber.size(); ++i)
	{
		bitnot.bignumber[i] = !bitnot.bignumber[i];
	}	
	while (bitnot.bignumber.back() == 0)
	{
		bitnot.bignumber.pop_back();
	}
	return bitnot;
}
BigInt operator&(const BigInt & big, const BigInt & big1)
{
	BigInt bigand;
	bigand.isnegative = (big.isnegative ^ big1.isnegative);
	bigand.bignumber = (big.bignumber.size() > big1.bignumber.size() ? big.bignumber : big1.bignumber);
	unsigned long limit = (big.bignumber.size() > big1.bignumber.size() ? big1.bignumber.size() : big.bignumber.size());
	for (unsigned i = 0; i < limit; ++i)
	{
		bigand.bignumber.at(i) = big.bignumber.at(i) & big1.bignumber.at(i);	
	}
	return bigand;
}
BigInt operator&(const BigInt & big, const unsigned long number)
{
	BigInt bignumb = create (number);
	BigInt bigand;
	bigand.bignumber = (big.bignumber.size() > bignumb.bignumber.size() ? big.bignumber : bignumb.bignumber);
	unsigned long limit = (big.bignumber.size() > bignumb.bignumber.size() ? bignumb.bignumber.size() : big.bignumber.size());
	for (unsigned long i = 0; i < limit; ++i)
	{
		bigand.bignumber.at(i) = big.bignumber.at(i) & bignumb.bignumber.at(i);	
	}
	return bigand;
}
BigInt operator&(const long int &, const BigInt &);
BigInt operator&(const unsigned long int &, const BigInt &);

BigInt operator|(const BigInt & big, const BigInt & big1)
{
	BigInt bigand;
	bigand.isnegative = (big.isnegative ^ big1.isnegative);
	bigand.bignumber = (big.bignumber.size() > big1.bignumber.size() ? big.bignumber : big1.bignumber);
	unsigned long limit = (big.bignumber.size() > big1.bignumber.size() ? big1.bignumber.size() : big.bignumber.size());
	for (unsigned i = 0; i < limit; ++i)
	{
		bigand.bignumber.at(i) = big.bignumber.at(i) | big1.bignumber.at(i);	
	}
	return bigand;
}
BigInt operator^(const BigInt & big, const BigInt & big1)
{
	BigInt bigand;
	bigand.isnegative = (big.isnegative ^ big1.isnegative);
	bigand.bignumber = (big.bignumber.size() > big1.bignumber.size() ? big.bignumber : big1.bignumber);
	unsigned long limit = (big.bignumber.size() > big1.bignumber.size() ? big1.bignumber.size() : big.bignumber.size());
	for (unsigned i = 0; i < limit; ++i)
	{
		bigand.bignumber.at(i) = big.bignumber.at(i) ^ big1.bignumber.at(i);	
	}
	return bigand;
}
BigInt operator<<(const BigInt & big, const unsigned long number)
{
	BigInt bitleftshift =  big;
	vector<bool> shift (number, false);
	for (unsigned i = 0; i < bitleftshift.bignumber.size(); ++i)
	{
		shift.push_back(bitleftshift.bignumber[i]);
	}
	bitleftshift.bignumber = shift;
	return bitleftshift;
}
BigInt operator>>(const BigInt & big, const unsigned long number)
{
	BigInt bitrightshift = big;
	for (unsigned i = 0; i < number; ++i)
	{
		bitrightshift.bignumber.erase(bitrightshift.bignumber.begin());
		bitrightshift.bignumber.push_back(false);
	}
	return bitrightshift;
}
BigInt & operator<<=(BigInt & big, const unsigned long number)
{
	vector<bool> shift (number, false);
	for (unsigned i = 0; i < big.bignumber.size(); ++i)
	{
		shift.push_back(big.bignumber[i]);
	}
	big.bignumber = shift;
	return big;
}
BigInt & operator>>=(BigInt & big, const unsigned long number)
{
	for (unsigned i = 0; i < number; ++i)
	{
		big.bignumber.erase(big.bignumber.begin());
		big.bignumber.push_back(false);
	}
	return big;
}