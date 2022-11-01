/*
The monty hall problem
Josue Sandoval - 12/04/2020
*/
#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h> 
using namespace std;

//declare simple struct 
struct Door {
	bool isWinnner = false;
};

int main() {
	//declare variables
	vector<Door> list;
	int nTimes = 0, nDoors = 0 ,nCount = 0, nSamples = 0;
	int dSwitchDoorWin = 0, dNSwitchDoorWin = 0;
	bool set = false;
	Door dUnit;

	//get user inputs for number of times and number of doors in simulation
	std::cout << "Enter the number of times to run the simulation: ";
	cin >> nTimes;
	std::cout << "Enter the number of doors in each simulation: ";
	cin >> nDoors;

	nSamples = nTimes;
	//set one member in array to the winner(true) and the rest as losers(false).
	while (nTimes > 0) {
		//set seed to generate a random number; I tried to do it by including a rand() within the srand() but it kept producting the same statistical result
		//by combining the time() + the number simulations it is more random 
		
		srand(time(0)+nTimes);
		while (!set && (nCount < nDoors)){
		
			//if rand number modules the total number of doors is equal to 1, then set that door to winner.
			//if i use 2 as modules, it is less probable that the winning door will be towards the end of the list.
			if (rand() % nDoors == 1) {
				dUnit.isWinnner = true;
				list.push_back(dUnit);
				set = true;
			}
			// in the case that all doors before this one is a losing door,we'll set the last door as the winner.
			else if (nCount == nDoors - 1) {
				dUnit.isWinnner = true;
				list.push_back(dUnit);
				set = true;
			}
			else if (!set) {
				dUnit.isWinnner = false;
				list.push_back(dUnit);
			}
			nCount++;
		}
		//to set other remaining doors to losing doors
		while (nCount < nDoors) {
			dUnit.isWinnner = false;
			list.push_back(dUnit);
			nCount++;
		}
		
		//list reduction
		//removes all losing doors that are not in index 0 and leaves only two doors
		//therfore the door it either in the first element or in the one left element
		while (list.size() > 2) {
			if (list.back().isWinnner == false) {
				list.pop_back();
			}
			else if (list[list.size() - 2].isWinnner == false) {
				list.erase(list.begin() + (list.size() -2));
			}
		}

		//count wins if player does not switch and if they do switch 
		if (list[0].isWinnner == true) {
			dNSwitchDoorWin++;
		}
		else if (list[1].isWinnner == true) {
			dSwitchDoorWin++;
		}


		//output list of doors; should be only one winner
		for (Door d : list) {
			std::cout << d.isWinnner << " ";
		}
		std::cout << endl;
		
		
		//clear vector for next simulation; reset variables
		list.clear();
		set = false;
		nCount = 0;
		nTimes--;
	}

	//output results of simulations
	std::cout << "Results:\nWins if player does not switch: " << dNSwitchDoorWin << " / " << nSamples << endl;
	std::cout << "Wins if player does switch doors: " << dSwitchDoorWin << " / " << nSamples<< endl;
	std::cout << "Theortical chance of win if door is switched should be: " << (double) (nDoors - 1)/nDoors << endl;
	std::cout << "Experimental probability of this simulation is : " << (double)dSwitchDoorWin / nSamples << endl;

	return 0;
}