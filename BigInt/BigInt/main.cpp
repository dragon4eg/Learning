#include "BigInt.h"

using namespace std;

int main ()
{	
	long a = 4345612;
	BigInt bignumb1 = create (a);
	cout << "Constructor for const long number: " << a << '\n' << bignumb1 << '\n';
	/*************************************************************************************************************/
	unsigned long b = 1234;
	BigInt bignumb2 = create (b);
	cout << "Constructor for const unsigned long number: " << b << '\n' << bignumb2 << '\n';
/**************************************************************************************************************/
	const string c = "-0123456789";
	cout << "Length of string - " << c.length() << endl;
	clock_t start = clock() / (CLOCKS_PER_SEC / 1000);
	BigInt bignumb = create (c);
    clock_t end = clock() / (CLOCKS_PER_SEC / 1000);
    double diff = difftime(end,start);
    printf("Timed %.0f ms.\n", diff);
	cout << "Constructor for const string:\n" << c << '\n' << bignumb;
	system("pause");
	//cout << "\nOperator + for bignumber\n" << operator+(bignumb);
	//cout << "\nOperator - for bignumber\n" << operator-(bignumb);
	//cout << "\nOperator Bitwise Not\n" << operator~(bignumb);
	//cout << "\nOperator Bitwise Left Shift\n" << operator<<(bignumb, a);
	//cout << "\nOperator Bitwise Right Shift\n" << operator>>(bignumb, a);
	//cout << "\nOperator AND\n" << operator&(bignumb, bignumb2);
	cout << "\nOperator AND\n" << operator&(bignumb, bignumb1);
	cout << "\nOperator |\n" << operator|(bignumb, bignumb1);
	cout << "\nOperator ^\n" << operator^(bignumb, bignumb1);
	//cout << "\nOperator Bitwise Left Shift with assignment\n" << operator<<=(bignumb, a);
	//cout << "\nOperator Bitwise Right Shift with assignment\n" << operator>>=(bignumb, a);
	return 0;
}