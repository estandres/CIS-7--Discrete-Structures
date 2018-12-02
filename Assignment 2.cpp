#include <iostream>
#include <string>

int main()
{
	bool repeat = true;
	do{
	std::string input;
	
	bool charRepeat = true;
	char cInput;
	bool alphaCheck = false;
	bool firstCheck = false;
	bool lastWasConnector = false;
	bool lastWasNot = false;
	bool lastWasSpace = false;
	bool lastWasAlpha = false;
	bool ifAndOnlyCheck = false;
	bool characterCheck = false;
	bool followingIsValid = true;
	int leftParCount = 0;
	int rightParCount = 0;

	int count = 0;
	
		std::cout << "Input your string.\n";
		std::cin >> input;
		std::cin.ignore();
		std::cout << "\nYou have input: " << input << std::endl;


		for (int i = 0; i < input.size(); i++) {
			count++;
			char c = input[i];
			char d = input[i + 1];

			if (isalpha(input[0]) || input[0] == '~' || input[0] == ' ' || input[0] == '(') {
				firstCheck = true;
			}
			if (firstCheck == false) {
				std::cout << "Invalid format, first character must be '~', or an alphabet letter, or a space.\n";
				repeat = false;
				break;
			}
			for (int j = 0; j < input.size(); j++) {
				if (isalpha(input[j])) {
					alphaCheck = true;
				}
				if (j == '(') {
					leftParCount++;
				}
				if (j == ')') {
					rightParCount++;
				}
			}

			if (rightParCount != leftParCount) {
				std::cout << "Invalid format, you left an open paranthesis bracket!\n";
				repeat = false;
				break;
			}
			if (alphaCheck == false) {
				std::cout << "Invalid format, no alphabet letter found\n";
				repeat = false;
				break;
			}

			if ((c == '^' || c == 'V' || c == '~' || (c == '-' && d == '>')) && lastWasConnector == true) {
				std::cout << "Invalid format, consecutive connectors ('^' or 'V' or '~' or '->') found.\n";
				repeat = false;
				break;
			}
			if (c == ' ' || c == '^' || c == 'V' || c == '~' || isupper(c) || (c == '-' && d == '>')) {
				characterCheck = true;
			}
			else {
				characterCheck = false;
			}
			if (((c == '^' || c == 'V' || (c == '-' && d == '>')) && (lastWasNot == false || lastWasAlpha == false || lastWasSpace == false)))  {
				lastWasConnector = true;
			}
			else {
				lastWasConnector == false;
			}
			if (c == '-' && d == '>') {
				ifAndOnlyCheck = true;
			}
			else if (c == '(') {

			}
			else {
				ifAndOnlyCheck = false;
			}
			if (isalpha(c)) {
				lastWasAlpha = true;
			}
			else {
				lastWasAlpha = false;
				lastWasConnector = false;
			}
			if (c == ' ') {
				lastWasSpace = true;
				lastWasConnector = false;
			}
			else {
				lastWasSpace = false;
			}
			if (c == '~') {
				lastWasNot = true;
				lastWasConnector = false;
				if (isalpha(d) || d == '~' || d == ' ' || d == '(') {
					followingIsValid = true;
				}
				else {
					followingIsValid = false;
				}
			
			}
			else {
				lastWasNot = false;
			}
			if (ifAndOnlyCheck == true) {
				char e = input[i + 2];
				if (isalpha(e) || e == '~' || e == '(') {
					followingIsValid = true;
				}
				else {
					followingIsValid = false;
				}
			}
			if (characterCheck == false && ifAndOnlyCheck == false && (c == '>' && input[i-1] != '-') ) {
				std::cout << "Invalid format, " << c << " is not a WFF\n";
				repeat = false;
				break;
			}
			if (isalpha(c) && isalpha(input[i + 1])) {
				std::cout << "Invalid format, 2 consecutive alphas found.\n";
				repeat = false;
				break;
			}
			if (c == d && lastWasNot == false && lastWasSpace == false) {
				std::cout << "Invalid format, invalid consecutive characters found.\n";
				repeat = false;
				break;	
			}
			if (followingIsValid == false) {
				std::cout << "Invalid format, your input is not a WFF.\n";
				repeat = false;
				break;
			}
			
			if (c == '(' && lastWasAlpha) {
				std::cout << "Invalid format, you cannot place a paranthesis right after a letter.\n";
				repeat = false;
				break;
			}
			if (c == ')' && (lastWasConnector == true || lastWasNot == true)) {
				std::cout << "Invalid format, you cannot close a paranthesis in that way.\n";
				repeat = false;
				break;
			}
		}
		if (repeat == true) {
			std::cout << "You entered a WFF!\n";
		}
		do {
			std::cout << "Would you like to try another input?: (Y/N)\n";
			std::cin >> cInput;
			cInput = toupper(cInput);
			if (cInput == 'Y' || 'N') {
				if (cInput == 'Y') {
					repeat = true;
				}
				if (cInput == 'N') {
					repeat = false;
				}
				charRepeat = false;
			}
			else {
				std::cout << "Invalid input.\n";
				charRepeat == true;
			}
		} while (charRepeat == true);

	} while (repeat == true);
	return 0;
}
