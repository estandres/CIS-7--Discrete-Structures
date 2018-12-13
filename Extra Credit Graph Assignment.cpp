////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include "Vertice.h"
int main() {
	int numOfUniqueEdges = 0;		//Keeps track non-parallel edges, shared between any two vertices.
	int i = 0;
	int j = 0;

	bool repeat = true;
	std::vector <Vertice> vectorOfVertices;
	do {
		Vertice *temp = new Vertice;
		int input = 0;
		std::cout << "What would you like to do?\n"
			<< "1) Create a vertice.\n"
			<< "2) Create an edge.\n"
			<< "3) Get graph info.\n"
			<< "Or enter any key to quit the program.\n";
		std::cin >> input;

		if (input == 1) {
			bool nameRepeated = false;
			do {
				std::string inputVerticeName;
				std::cout << "Please enter what you would like this vertice to be named. (Names must be unique)\n";
				std::cin.ignore();
				std::cin >> inputVerticeName;
				if (!vectorOfVertices.empty()) { // checks to see if the name already exists within the vector of vertice.
					for (int i = 0; i < vectorOfVertices.size(); i++) {
						if (inputVerticeName == vectorOfVertices[i].getName()) {
							nameRepeated = true;
							std::cout << "You already have a vertice with that name.\nTry again.\n";
							break;
						}
						else if (inputVerticeName != vectorOfVertices[i].getName()) {
							nameRepeated = false;
						}
					}
				}
				if (nameRepeated == false) {
					temp->setName(inputVerticeName);
					vectorOfVertices.push_back(*temp);
				}
			} while (nameRepeated == true);
		}
		else if (input == 2 && vectorOfVertices.empty()) {
			std::cout << "You have not created any vertices. Option 2 is unavailable.\n";
		}
		else if (input == 2 && !vectorOfVertices.empty()) {
			bool parallelEdge = false;
			bool repeat = false;
			std::string verticeToSearch1,
				verticeToSearch2;
			do {
				repeat = false;
				std::cout << "Please enter the two vertices you would like to connect with an edge.\n"
					<< "Vertice #1: ";
				std::cin.ignore();
				std::cin >> verticeToSearch1;
				std::cout << "Vertice #2: ";
				std::cin.ignore();
				std::cin >> verticeToSearch2;
				for (int i = 0; i < vectorOfVertices.size(); i++) {
					if (verticeToSearch1 == vectorOfVertices[i].getName()) {
						repeat = false;
						break;
					}
					else {
						repeat = true;
					}
				}
				for (int i = 0; i < vectorOfVertices.size(); i++) {
					if (verticeToSearch2 == vectorOfVertices[i].getName()) {
						repeat = false;
						break;
					}
					else {
						repeat = true;
					}
				}
				if (repeat == true) {
					std::cout << "You entered a vertice that does not exist. Please try again.\n";
				}
			//	system("CLS");
			} while (repeat == true);
			//search for the first input in the vector of vertices.
			for (int i = 0; i < vectorOfVertices.size(); i++) {
				if (verticeToSearch1 == vectorOfVertices[i].getName()) {
					//search for the second input in the vector of vertices
					for (int j = 0; j < vectorOfVertices.size(); j++) {
						if (verticeToSearch2 == vectorOfVertices[j].getName()) {
							//if vertices have same name, that vertices loop is incremented.
							if (verticeToSearch1 == verticeToSearch2) {
								vectorOfVertices[i].addNumOfLoops();
								std::cout << "A loop has been created on vertice '" << vectorOfVertices[i].getName() << "'.\n";
								break;
							}
							//checking to see if a parallel edge was created. If it was, each vertices numOfParallelEdges gets incremented.
							for (int k = 0; k < vectorOfVertices[i].getConnectedVertices().size(); k++) {
								if (vectorOfVertices[i].getConnectedVertices().at(k) == verticeToSearch2) {	//if a vertices already share an edge, numOfParallelEdges++ for each.
									vectorOfVertices[i].addNumOfParallelEdges();
									vectorOfVertices[j].addNumOfParallelEdges();
									parallelEdge = true;
									std::cout << "A parallel edge has been created between vertices '" << vectorOfVertices[i].getName() << "' and '" << vectorOfVertices[j].getName() << "'.\n";
									break;
								}
							}
							//if the vertices do not share an edge or a name, then both the vertices edge counters are incremented and their isolated flag is set to false
							if (parallelEdge == false) {
								std::cout << "A new edge has been created between vertices " << vectorOfVertices[i].getName() << " and " << vectorOfVertices[j].getName() << ".\n";
								vectorOfVertices[i].pushConnectedVertices(verticeToSearch2);
								vectorOfVertices[j].pushConnectedVertices(verticeToSearch1);
								vectorOfVertices[i].addNumOfEdges();
								vectorOfVertices[j].addNumOfEdges();
								numOfUniqueEdges++;
								vectorOfVertices[i].setIsIsolated(false);
								vectorOfVertices[j].setIsIsolated(false);
								
								break;
							}
							break;
						}
					}
				}
			}
		}
		else if (input == 3) {
			std::string highestDegreeVertice = "";
			int highestDegreeTracker = 0;
			int loopTracker = 0;
			int parallelEdgeTracker = 0;
			bool isolatedFlag = false;
			for (int i = 0; i < vectorOfVertices.size(); i++) {
				//loop tracking
				loopTracker += vectorOfVertices[i].getNumOfLoops();
				//parallel edges tracking
				parallelEdgeTracker += vectorOfVertices[i].getNumOfParallelEdges();
				//degree tracking
				if (highestDegreeTracker < vectorOfVertices[i].getNumOfEdges() + vectorOfVertices[i].getNumOfLoops() + vectorOfVertices[i].getNumOfParallelEdges()) {
					highestDegreeTracker = vectorOfVertices[i].getNumOfEdges() + vectorOfVertices[i].getNumOfLoops() + vectorOfVertices[i].getNumOfParallelEdges();
					highestDegreeVertice = vectorOfVertices[i].getName();
				}
			}
			std::cout << "The vertice with the highest degree is vertice '" << highestDegreeVertice << "' with a degree of " << highestDegreeTracker << ".\n";
			std::cout << "List of isolated vertices: \n";
			for (int i = 0; i < vectorOfVertices.size(); i++) {
				if (vectorOfVertices[i].getIsIsolated() == true) {
					isolatedFlag = true;
					std::cout << vectorOfVertices[i].getName() << std::endl;
				}
			}
			std::cout << "Number of loops found: " << loopTracker << ".\n";
			//Test to see if the graph is connected.
			if (numOfUniqueEdges >= vectorOfVertices.size()-1 && loopTracker == 0 && parallelEdgeTracker == 0 && isolatedFlag == false){
				std::cout << "The graph is connected\n";
			}
			else {
				std::cout << "The graph is disconnected\n";
			}
			//test to see if graph is complete
			if (numOfUniqueEdges == ((vectorOfVertices.size())*(vectorOfVertices.size() - 1)) / 2 && loopTracker == 0 && parallelEdgeTracker == 0 && isolatedFlag == false) {
				std::cout << "The graph is complete.\n";
			}
			else {
				std::cout << "The graph is incomplete.\n";
			}
		}
		else {
			repeat = false;
		}
	} while (repeat == true);


	return	0;
}


///////////////////////////////////////////////// Vertice.h ///////////////////////////////////////////////////////
#ifndef VERTICE_H
#define VERTICE_H
#include <string>
#include <vector>
class Vertice {

private:
	std::string _name;
	int _numOfParallelEdges;
	int _numOfLoops;
	int _numOfEdges;
	bool _isIsolated;
	std::vector <std::string> _connectedVertices;
public:
	Vertice();
	void setName(std::string name);
	void addNumOfParallelEdges();
	void addNumOfLoops();
	void addNumOfEdges();
	void setIsIsolated(bool isIsolated);
	void pushConnectedVertices(std::string connectedVertices);
	std::string getName();
	int getNumOfParallelEdges();
	int getNumOfLoops();
	int getNumOfEdges();
	bool getIsIsolated();
	std::vector <std::string> getConnectedVertices();
};
#endif // !VERTICE_H
////////////////////////////////////////////Vertice.cpp//////////////////////////////////////////////////////////////////////
Vertice::Vertice()
{
	_name = "";
	_numOfParallelEdges = 0;
	_numOfLoops = 0;
	_numOfEdges = 0;
	_isIsolated = true;
}

void Vertice::setName(std::string name)
{
	this->_name = name;
}

void Vertice::addNumOfParallelEdges()
{
	this->_numOfParallelEdges++;
}

void Vertice::addNumOfLoops()
{
	this->_numOfLoops++;
}

void Vertice::addNumOfEdges()
{
	this->_numOfEdges++;
}

void Vertice::setIsIsolated(bool isIsolated)
{
	this->_isIsolated = isIsolated;
}

void Vertice::pushConnectedVertices(std::string connectedVertices)
{
	this->_connectedVertices.push_back(connectedVertices);
}

std::string Vertice::getName()
{
	return _name;
}

int Vertice::getNumOfParallelEdges()
{
	return _numOfParallelEdges;
}

int Vertice::getNumOfLoops()
{
	return _numOfLoops;
}

int Vertice::getNumOfEdges()
{
	return _numOfEdges;
}

bool Vertice::getIsIsolated()
{
	return _isIsolated;
}

std::vector<std::string> Vertice::getConnectedVertices()
{
	return _connectedVertices;
}
