/**
*@file Task1_z_18
*@brief Solution (C++ code) of Task1.18 GL 
* (Використовуючи тільки бітові операції, написати функцію, яка повертає значення 1, 
* якщо у двійковому коді параметра x немає двох підряд одиниць і 0 - в іншому випадку; x - беззнакове довге ціле число.)
*Copyright 2014 by Roman Bojko
*/
#include <iostream>
using namespace std;

// This function looks for a block of two bits equal to 1 in a binary code of number
unsigned short TwoBits ( unsigned long x )
{
	x &= x << 1;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return ~x & 1UL;
}
// This function provides the correct input data by user
template< typename T > 
T ProtectionInput ( T minValue, T maxValue )
{
	long long x;
	while (!scanf("%lld", &x) || (x < minValue || x > maxValue) )
	{
		fflush(stdin);
		printf("Error! Incorrectly input data!\n");
		printf("Please enter the number once again: ");
	}
	return (T)x;
}

int main()
{
	const unsigned short BUFFER_LENGTH = 33;	//	Size of buffer
	char *buffer = new char[BUFFER_LENGTH];
	unsigned long x;
	printf ("\nEnter the unsigned long number please: ");
				x = ProtectionInput<unsigned long>(0, ULONG_MAX);

				printf ("Input values:\n");
				printf ("\tdecimal: %d\n", x);
				itoa(x, buffer, 2);
				printf ("\tbinary:  %032s\n", buffer);

				x = TwoBits(x);



	system("pause");
    return 0;
}
