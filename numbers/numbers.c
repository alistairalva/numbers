/*
Program Name: numbers.c
Coder Name: Alistair Alva, 2019
Purpose: To take in an integer from the user and perform operations on it
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void print(int accumulator);
void RPrint(int accumulator);
int divsum(int n);

void isNatural(int n);
void oddOrEven(int n);
int isPrime(int num);
void isTriangular(int accumulator);
void isSquare(int accumulator);
void isAPowerOf2(int accumulator);
void isFactorial(int accumulator);
void isPerfect(int accumulator);
bool isDeficient(int n);

int main() {

	puts("Numbers (v1.0.0), \xa9 2019 Alistair Alva");
	puts("\nPlease enter a number");

	//accumulator variable, this variable will store the number
	int accumulator = 0;
	int ch;
	int sign = 1;

	//use getchar to get the first character from stream
	ch = getchar();

	//if it is negative reaplace initialize a variable to -1 and replace the character by calling getchar again 
	if (ch == '-') {
		sign = -1;
		ch = getchar();
	}

	//quit if the following character is not a digit
	if (!isdigit(ch)) {
		puts("\nError: Not valid number.\nPlease try again.");
		exit(1);
	}
	
	//convert the character digit to its corresponding integer number and store it in the accumulator 
	accumulator = ch - '0';

	//loop to get the remaining digits, it will run until there is a newline or it meets the end-of-file character
	while ((ch = getchar()) != '\n' && ch != EOF) {
		
			if (!isdigit(ch)) {
				puts("\nError: Not valid number.\nPlease try again.");
				exit(1);
			}

			//multiply the accumulator by 10 and simply add the now converted digit(which is an int) to the accumulator
			accumulator *= 10;
			accumulator += (ch - '0');
	}

		accumulator *= sign;

	////used to test if accumulator was filled
	//printf("%d", accumulator);

	puts("\nYou entered...");
	print(accumulator);

	isNatural(accumulator);
	oddOrEven(accumulator);
	isPrime(accumulator);
	isTriangular(accumulator);
	isSquare(accumulator);

	isFactorial(accumulator);
	isPerfect(accumulator);

	if (isDeficient(accumulator)== true) {
		puts("The number is deficient.");
	}

	isAPowerOf2(accumulator);

	puts("\nEND OF PROGRAM");
}

//function to recursively print number
void RPrint(int accumulator) {

	if (accumulator == 0) {
		puts("\nError, Number entered is 0. Cannot calculate answers.");
		exit(1);
	}

	int remainder = 0;
	remainder = accumulator % 10;

	RPrint(accumulator/10);
	putchar(remainder + '0');

}

// function that will use  RPrint to print the number 
//void print(int accumulator) {
//	
//	if (accumulator == 0) {
//		putchar('0');
//		exit(EXIT_FAILURE);
//	}
//
//	if (accumulator < 0) {
//		putchar('-');
//		accumulator *= -1;
//	}
//		RPrint(accumulator);
//}

void print(int n)
{
	if (n == 0) {
		puts("\nError, Number entered is 0. Cannot calculate answers.");
		exit(1);
	}
	// If number is smaller than 0, put a - sign 
	// and change number to positive 
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	// Remove the last digit and recur 
	if (n / 10)
		print(n / 10);

	// Print the last digit 
	putchar(n % 10 + '0');
}

//function to check if number is natural
void isNatural(int n) {
	if (n == 0) {
		puts("\nThe number is 0.");
	}
	if (n < 0) {
		puts("\nThe number is an integer.");
	}

	if (n >= 0) {
		puts("\nThe number is a natural number.");
	}

}

//function to check if number is odd or even
void oddOrEven(int n) {
	if (n % 2 == 0) {
		puts("The number is even.");
	}

	else
		puts("The number is odd.");
}

int isPrime(int num) {

	//checkflag variable
	int flag = 0;
	int j;
	int sign = 1;
	
	if (num == 1 || num == 0) {
		puts("The number is neither prime nor composite.");
		return 1;
	}
	if (num < 0)
		sign = -1;

	num *= sign;
	flag = 0;
	for (j = 2; j <= num / 2; j++)
	{
		if ((num % j) == 0)
		{
			flag = 1;
			break;
		}
	}

	if (sign == -1 && flag == 1) {
		puts("The number is a negative composite number.");
		return 1;
	}
	if (flag == 0)
		puts("The number is prime.");
	else
		puts("The number is composite.");

	return 0;
}

void isTriangular(int accumulator) {

		int currentTriNum = 0;
		int n = 0;

		//loop will run until sum of natural numbers is less than the accumulator
		while (currentTriNum < accumulator)
		{
			currentTriNum += n;
			n++;
		}

		if (currentTriNum != accumulator)
			puts("The number is not triangular.");
		else
			puts("The number is triangular.");
}

void isSquare(int accumulator) {
	float tempVar;
	int iVar;
	tempVar = sqrt((double)accumulator);
	iVar = tempVar;

	if (iVar == tempVar)
		puts("The number is square.");

	else
		puts("The number is not square.");

}

void isAPowerOf2(int accumulator) {
	if (ceil(log2(accumulator)) == floor(log2(accumulator)))
		puts("The number is a power of two.");

	else
		puts("The number is not a power of two.");

}

void isFactorial(int accumulator) {
	int x = 1;
	int factorial = 1;
	while (factorial < accumulator) {
		x = x + 1;
		factorial = factorial * x;
	}
	if (factorial == accumulator)
		puts("The number is a factorial.");
	else
		puts("The number is not a factorial.");

}

void isPerfect(int accumulator) {
	int i = 1;
	int sum = 0;

	while (i < accumulator) {
		if (accumulator % i == 0)
			sum = sum + i;
		i++;
	}
	
	if (sum == accumulator)
		puts("The number is perfect.");

	if (sum > accumulator)
		puts("The number is abundant.");
} 

//function that will return an integer to be later checked if the number is deficient or not
int divsum(int n)
{
	
	int sum = 0;
	for (int i = 1; i <= (sqrt(n)); i++) {
		if (n % i == 0) {
			if (n / i == i) {
				sum = sum + i;
			}
			else
			{
				sum = sum + i;
				sum = sum + (n / i);
			}
		}
	}
	return sum;
}
 
//boolean function to check if the number is deficient or not using the divsum() function
bool isDeficient(int n)
{ 
	int deficient;
	deficient = (divsum(n) < (2 * n));
	if (deficient == 0)
		return false;
	else
		return true;
}
