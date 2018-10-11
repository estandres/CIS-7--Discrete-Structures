/*This program will be able to show you the greatest common denominator of any 2 numbers using the Euclidean Algorithm*/
#include <iostream>
#include <time.h>

int main() {

	int dividend = 0;
	int divisor = 0;
	int var1;
	int var2;
	int gcd = 0;
	int remainder;
	int quotient;
	char answer;
	bool repeat = true;
	bool inputRepeat = true;
	bool answerRepeat = true;
	bool programRepeat = true;
	clock_t begin;
	clock_t end;
	std::cout << "This program will be able to show you the greatest common denominator\n"
		<< "of any 2 numbers using the Euclidean Algorithm.\n";
	do {
		do {
			std::cout << "Enter your dividend: ";
			std::cin >> dividend;
			if (std::cin && dividend > 0) {
				inputRepeat = false;
			}
			else {
				std::cin.clear();
				std::cin.ignore();
				inputRepeat = true;
				std::cout << "You did not enter a valid alphanumeric character, please try again.\n"
					<< "Note: Your input must be a positive number.\n";
				inputRepeat = true;
			}
		} while (inputRepeat == true);
		do{
			std::cout << "Now enter you divisor: \n";
			std::cin >> divisor;

			if (std::cin && divisor > 0) {
				inputRepeat = false;
			}
			else {
				std::cin.clear();
				std::cin.ignore();
				inputRepeat = true;
				std::cout << "You did not enter a valid alphanumeric character, please try again.\n"
					<< "Note: Your input must be a positive number.\n";
				inputRepeat = true;
			}
		} while (inputRepeat == true);


		var1 = dividend;
		var2 = divisor;
		begin = clock();
		do {
			if (var1 == 0) {
				end = clock();
				int elapsedTime = end - begin;
				gcd = var2;
				printf ("This took %d milliseconds to calculate.\n", elapsedTime);
				repeat = false;
				break;
			}
			if (var2 == 0) {
				end = clock();
				int elapsedTime = end - begin;
				gcd = var1;
				std::cout << "The GCF of " << dividend << " & " << divisor << " is: " << var1 << std::endl;
				printf( "This took %d milliseconds to calculate.\n", elapsedTime);
				repeat = false;
				break;
			}
			else {
				repeat = true;
			}
			remainder = var1 % var2;
			quotient = var1 / var2;
			var1 = var2;
			var2 = remainder;

		} while (repeat == true);
		
		do{
		std::cout << "Would you like to enter a new pair of numbers?\n (Y/N)\n";
		std::cin >> answer;
		answer = toupper(answer);

			if (answer == 'Y') {
				answerRepeat = false;
				programRepeat = true;
			}
			else if (answer == 'N') {
				answerRepeat = false;
				programRepeat = false;
			}
			else if (!std::cin) {
				std::cout << "You input an invalid response./nPlease try again\n";
				answerRepeat = true;
			}
		} while (answerRepeat == true);
	} while (programRepeat == true);

	return 0;
}


