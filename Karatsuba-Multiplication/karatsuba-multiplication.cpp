 #include <iostream>
#include <math.h>
using namespace std;

// Karatsuba algorithm is an efficient integer multiplication algorithm
// Takes n-digit two integers and return their multiplication 

int karatsuba(int multiplicator, int multiplier){

	// Find digit count
	int digit_num = (multiplicator != 0) ? log10(multiplicator) + 1 : 1;

	// Base case
	if(digit_num == 1)
		return multiplicator * multiplier;

	// Split numbers into two parts
	int coeff = pow(10, (digit_num / 2));
	int mul1  = multiplicator / coeff;
	int mul2  = multiplicator % coeff;
	int mul3  = multiplier / coeff;
	int mul4  = multiplier % coeff;
 
	// Find sub-products recursively
	int sub1 = karatsuba(mul1, mul3);
	int sub2 = karatsuba(mul2, mul4);
	int sub3 = karatsuba((mul1 + mul2), (mul3 + mul4)) - (sub1 + sub2);

	int mul;

	// Multiplication is calculated differently for odd digit numbers and even digit numbers
	if(digit_num % 2 == 0)
		mul = (pow(10,digit_num) * sub1) + (pow(10, (digit_num / 2)) * sub3) + sub2;
	else
		mul = (pow(10,digit_num -1) * sub1) + (pow(10, (digit_num / 2)) * sub3) + sub2;

	return mul;
}

int main(){
 	int result = karatsuba(12345, 45678);
 	cout << "Result is:" << result << endl;
	return 0;
}