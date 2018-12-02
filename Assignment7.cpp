#include <iostream>
#include <deque>
#include <stdlib.h>
int count = 0;
//to do: Fix the way the towers are loaded into the tempTowers
struct towerState {
	std::deque <int> P1, P2, P3;
};
void tOfH(int n, char fromPeg, char auxPeg, char toPeg, std::deque <int>* p1, std::deque <int>* p2, std::deque <int>* p3);
void printTowers(std::deque <int> p1, char peg);
int main() {

	int n;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	towerState towerStruct{};
	//std::deque <int> p1, p2, p3;
	std::cout << "This program will give you the most efficient steps to take in order to solve the famous Tower of Hanoi!\n"
		<< "Please enter the number of rings you wish the tower to have!\n";
	std::cin >> n;
	std::cout << "This program will now display the steps to take for the most efficient way to solve the puzzle with the given number of rings!\n\n";
	for (int i = 1; i <= n; i++) {
		towerStruct.P1.push_back(i);
		towerStruct.P2.push_back(0);
		towerStruct.P3.push_back(0);
	}
	tOfH(n, a, b, c, &towerStruct.P1, &towerStruct.P2, &towerStruct.P3);
	//towerStruct = tOfH(n, a, b, c, towerStruct->P1, towerStruct->P2, towerStruct->P3);
	return 0;
}

void tOfH(int n, char fromPeg, char auxPeg, char toPeg, std::deque <int>* p1, std::deque <int>* p2, std::deque <int>* p3) {
	towerState towerTemp;
	std::deque <int> toTemp;
	std::deque <int> fromTemp;

	if (n == 1) {
		count++;
		std::cout << "Move #" << count << ": Move disk 1 from tower " << fromPeg << " to tower " << toPeg << std::endl;

		//START COPY
		int i = 0;
		int j = 0;
		if (fromPeg == 'a') {
			static int num = p1->size();
			for (int i = 0; i < num; i++) {
				fromTemp.push_back(p1->front());
				p1->pop_front();
			}
		}
		else if (fromPeg == 'b') {
			static int num = p2->size() ;
			for (int i = 0; i < num; i++) {
				fromTemp.push_back(p2->front());
				p2->pop_front();
			}
		}
		else if (fromPeg == 'c') {
			static int num = p3->size() ;
			for (int i = 0; i < num; i++) {
				fromTemp.push_back(p3->front());
				p3->pop_front();
			}
		}
		if (toPeg == 'a') {
			static int num = p1->size();
			for (int i = 0; i < num; i++) {
				toTemp.push_back(p1->front());
				p1->pop_front();
			}

		}
		else if (toPeg == 'b') {
			static int num = p2->size();
			for (int i = 0; i < num; i++) {
				toTemp.push_back(p2->front());
				p2->pop_front();
			}
		}
		else if (toPeg == 'c') {
			static int num = p3->size();
			for (int i = 0; i < num; i++) {
				toTemp.push_back(p3->front());
				p3->pop_front();
			}
		}

		std::deque <int>::iterator it = toTemp.begin();
		if (fromTemp.back() != 0) {
			while (fromTemp[i] == 0) {
				i++;
			}
		}
		if (toTemp.back() == 0) {
			toTemp.push_back(fromTemp[i]);
			fromTemp.erase(fromTemp.begin() + i);
			fromTemp.push_front(0);
		}
		else {
			while (toTemp[j] == 0) {
				j++;
				it++;
			}
			if (j > 0) {
				toTemp.insert(it, fromTemp[i]);
				fromTemp.erase(fromTemp.begin() + i);
				fromTemp.push_front(0);
			}
		}

		if (toTemp.front() == 0) {
			toTemp.pop_front();
		}

		if (fromPeg == 'a') {
			static int num = fromTemp.size();
			for (int i = 0; i < num; i++) {
				p1->push_front(fromTemp.back());
				fromTemp.pop_back();
			}

		}
		else if (fromPeg == 'b') {
			static int num = fromTemp.size();
			for (int i = 0; i < num; i++) {
				p2->push_front(fromTemp.back());
				fromTemp.pop_back();
			}
		}
		else if (fromPeg == 'c') {
			static int num = fromTemp.size();
			for (int i = 0; i < num; i++) {
				p3->push_front(fromTemp.back());
				fromTemp.pop_back();
			}

		}
		if (toPeg == 'a') {
			static int num = toTemp.size();
			for (int i = 0; i < num; i++) {
				p1->push_front(toTemp.back());
				toTemp.pop_back();
			}
		}
		else if (toPeg == 'b') {
			static int num = toTemp.size();
			for (int i = 0; i < num; i++) {
				p2->push_front(toTemp.back());
				toTemp.pop_back();
			}
		}
		else if (toPeg == 'c') {
			static int num = toTemp.size();
			for (int i = 0; i < num; i++) {
				p3->push_front(toTemp.back());
				toTemp.pop_back();
			}
		}

		//STOP COPY

		if (fromPeg == 'a') {
			if (toPeg == 'b') {
				printTowers(*p1, fromPeg);
				printTowers(*p2, toPeg);
				printTowers(*p3, auxPeg);
			}
			else {
				printTowers(*p1, fromPeg);
				printTowers(*p2, auxPeg);
				printTowers(*p3, toPeg);
			}
			std::cout << "\nEnter any key to continue\n";
			std::cin.ignore();
			std::cin.get();
			system("CLS");
		}
		if (fromPeg == 'b') {
			if (toPeg == 'a') {
				printTowers(*p1, toPeg);
				printTowers(*p2, fromPeg);
				printTowers(*p3, auxPeg);
			}
			else {
				printTowers(*p1, auxPeg);
				printTowers(*p2, fromPeg);
				printTowers(*p3, toPeg);
			}
			std::cout << "\nEnter any key to continue\n";
			std::cin.ignore();
			std::cin.get();
			system("CLS");
		}

		if (fromPeg == 'c') {
			if (toPeg == 'a') {
				printTowers(*p1, toPeg);
				printTowers(*p2, auxPeg);
				printTowers(*p3, fromPeg);
			}
			else {
				printTowers(*p1, auxPeg);
				printTowers(*p2, toPeg);
				printTowers(*p3, fromPeg);
			}
			std::cout << "\nEnter any key to continue\n";
			std::cin.ignore();
			std::cin.get();
			system("CLS");
		}

		towerTemp.P1 = *p1;
		towerTemp.P2 = *p2;
		towerTemp.P3 = *p3;
		return;
	}
	tOfH(n - 1, fromPeg, toPeg, auxPeg, p1, p2, p3);

	count++;
	std::cout << "Move #" << count << ": Move disk " << n << " from tower " << fromPeg << " to tower " << toPeg << std::endl;

	//START COPY
	int i = 0;
	int j = 0;
	if (fromPeg == 'a') {
		static int num = p1->size();
		for (int i = 0; i < num; i++) {
			fromTemp.push_back(p1->front());
			p1->pop_front();
		}
	}
	else if (fromPeg == 'b') {
		static int num = p2->size();
		for (int i = 0; i < num; i++) {
			fromTemp.push_back(p2->front());
			p2->pop_front();
		}
	}
	else if (fromPeg == 'c') {
		static int num = p3->size();
		for (int i = 0; i < num; i++) {
			fromTemp.push_back(p3->front());
			p3->pop_front();
		}
	}
	if (toPeg == 'a') {
		static int num = p1->size();
		for (int i = 0; i < num; i++) {
			toTemp.push_back(p1->front());
			p1->pop_front();
		}

	}
	else if (toPeg == 'b') {
		static int num = p2->size();
		for (int i = 0; i < num; i++) {
			toTemp.push_back(p2->front());
			p2->pop_front();
		}
	}
	else if (toPeg == 'c') {
		static int num = p3->size();
		for (int i = 0; i < num; i++) {
			toTemp.push_back(p3->front());
			p3->pop_front();
		}
	}

	std::deque <int>::iterator it = toTemp.begin();
	if (fromTemp.back() != 0) {
		while (fromTemp[i] == 0) {
			i++;
		}
	}
	if (toTemp.back() == 0) {
		toTemp.push_back(fromTemp[i]);
		fromTemp.erase(fromTemp.begin() + i);
		fromTemp.push_front(0);
	}
	else {
		while (toTemp[j] == 0) {
			j++;
			it++;
		}
		if (j > 0) {
			toTemp.insert(it, fromTemp[i]);
			fromTemp.erase(fromTemp.begin() + i);
			fromTemp.push_front(0);
		}
	}

	if (toTemp.front() == 0) {
		toTemp.pop_front();
	}

	if (fromPeg == 'a') {
		static int num = fromTemp.size();
		for (int i = 0; i < num; i++) {
			p1->push_front(fromTemp.back());
			fromTemp.pop_back();
		}

	}
	else if (fromPeg == 'b') {
		static int num = fromTemp.size();
		for (int i = 0; i < num; i++) {
			p2->push_front(fromTemp.back());
			fromTemp.pop_back();
		}
	}
	else if (fromPeg == 'c') {
		static int num = fromTemp.size();
		for (int i = 0; i < num; i++) {
			p3->push_front(fromTemp.back());
			fromTemp.pop_back();
		}

	}
	if (toPeg == 'a') {
		static int num = toTemp.size();
		for (int i = 0; i < num; i++) {
			p1->push_front(toTemp.back());
			toTemp.pop_back();
		}
	}
	else if (toPeg == 'b') {
		static int num = toTemp.size();
		for (int i = 0; i < num; i++) {
			p2->push_front(toTemp.back());
			toTemp.pop_back();
		}
	}
	else if (toPeg == 'c') {
		static int num = toTemp.size();
		for (int i = 0; i < num; i++) {
			p3->push_front(toTemp.back());
			toTemp.pop_back();
		}
	}

	//STOP COPY



	if (fromPeg == 'a') {
		if (toPeg == 'b') {
			printTowers(*p1, fromPeg);
			printTowers(*p2, toPeg);
			printTowers(*p3, auxPeg);
		}
		else {
			printTowers(*p1, fromPeg);
			printTowers(*p2, auxPeg);
			printTowers(*p3, toPeg);
		}
		std::cout << "\nEnter any key to continue\n";
		std::cin.ignore();
		std::cin.get();
		system("CLS");
	}
	if (fromPeg == 'b') {
		if (toPeg == 'a') {
			printTowers(*p1, toPeg);
			printTowers(*p2, fromPeg);
			printTowers(*p3, auxPeg);
		}
		else {
			printTowers(*p1, auxPeg);
			printTowers(*p2, fromPeg);
			printTowers(*p3, toPeg);
		}
		std::cout << "\nEnter any key to continue\n";
		std::cin.ignore();
		std::cin.get();
		system("CLS");
	}
	if (fromPeg == 'c') {
		if (toPeg == 'a') {
			printTowers(*p1, toPeg);
			printTowers(*p2, auxPeg);
			printTowers(*p3, fromPeg);
		}
		else {
			printTowers(*p1, auxPeg);
			printTowers(*p2, toPeg);
			printTowers(*p3, fromPeg);
		}
		std::cout << "\nEnter any key to continue\n";
		std::cin.ignore();
		std::cin.get();
		system("CLS");
	}
	tOfH(n - 1, auxPeg, fromPeg, toPeg, p1, p2, p3);

}

void printTowers(std::deque <int> p, char peg) {
	std::deque <int>::iterator it = p.begin();
	std::cout << "Tower " << peg << ": ";
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 0) {
			std::cout << "-";
		}
		else {
			std::cout << p[i];
		}

		if (it != p.end() - 1) {
			std::cout << ", ";
			*it++;
		}
		
	}
	std::cout << std::endl;
	return;
}
