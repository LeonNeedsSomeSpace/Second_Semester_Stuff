//Tasksheet 6
//NEW TASK! Task 11, Recursive Function: Eight Queens

#include <iostream> //Code is written in C++
using namespace std; //We use names for objects and variables from the standard library

const int N = 8; //Size of the chessboard has a dimension of 8

//We print a chessboard with the size of 8x8 on each row (that's what [N][N] stands for)
//Void functions do not return a value, which means they execute commands like value-returning functions but they do not output any result. 
//A void can, however, still perform tasks. Using commands to call the void function can visualize the executions of the void function by e.g. printing. 
void printChessboard(int chessboard[N][N]) { //Use the void function to print out the chessboard (only works when called)
	for (int i = 0; i < N; ++i) { //Loop iterates over this
		for (int j = 0; j < N; ++j) { //Loop iterates over this
			if (chessboard[i][j] == 1) {//If-condition. If the chessboard with inserted values of intigers i and j equals '1', command will execute
				cout << "Q "; //Should the if-condition be met, the value "Q " will be printed out

			}
			else {//Should the condition not be met, the value ". " will be printed out
				cout << ". ";
			}

		}
		cout << "\n"; //Switch to a new line when 8 values are printed out
	}
	cout << "\n"; //Print out a new chessboard ([N][N]) in the next row

}

//Our goal is to place each queen on a 8x8 chessboard such that no other queen will threaten the other Queen, not vertically, nor horizontally. 
//A boolean function will return a value that is either 'true' or 'false'
bool isSafe(int chessboard[N][N], int row, int col) { //Check if there is a safe place for our queen to be positioned where we use a boolean
	for (int i = 0; i < row; ++i) { //The loop iterates over this such that the column will be checked 
		if (chessboard[i][col] == 1) {//If-condition to check whether there is a queen in the same column
			return false; //If so, then the result will be false and no additional queen will be placed there
		}
	
		//Left diagonal expressed like this, where it subtracts current row 'row' and the loop variable 'i' from the current column 'col'
		//It represents the left diagonal position, because in a matrix, moving towards the left involves decreasing variable index
		if (col - (row - i) >= 0 && chessboard[i][col - (row - i)] == 1) { //Check if there is a queen threatening from the left diagonal 
			return false; //If so, then the result will be false and no additional queen will be placed in that diagonal
		}
		//Right diagonal expressed like this, where it adds the current row 'row' subtracted by the variable 'i' to the current column'col'
		//It represents the left diagonal position, because in a matrix, moving towards the right involves increasing variable index
		if (col + (row - i) < N && chessboard[i][col + (row - i)] == 1) { //Check if there is a queen threatening from the right column
			return false; //If so, then the result will be false and no additional queen will be placed in that diagonal 
		}
	}
	return true; //When the checking process has finished and that particular place turns out to be safe for positioning, a queen will be put on that spot
}

//Now, after checking, all the queens should now be positioned correctly
//Recursive function to solve the problem using backtracking
bool solveQueens(int chessboard[N][N], int row) { 
	if (row == N) { //If-condition, if all queens are positioned correctly, the following command will be executed
		//Remember that this is the function that calls the void function. Now the operation of the void can have an output
		printChessboard(chessboard); //If the condition is met, the chessboard with correctly positioned queens will be executed
		return true; //Boolean function returns the value true
	}

	bool result = false; //Should there be a false result, then search for another place that might be safe to place the queen
	for (int col = 0; col < N; ++col) { //Loop iterates over the columns
		if (isSafe(chessboard, row, col)) { //If-condition for searching a safe place to position a queen all over again, should result be 'false'
			chessboard[row][col] = 1; //If the condition is met, then a queen will be placed in that place


			result = solveQueens(chessboard, row + 1) || result; //Recursively trying to place queens in the next row, loop doesn't end
			chessboard[row][col] = 0; //Backtrack
		}
	}
	return result;
}


int main() { //Main function will dictate all the operations
	
	//Iterate the chessboard with zeroes
	int chessboard[N][N] = { 0 };
	
	//Start with the first row in checking and placing queens (row no. 0), then continue to the next rows
	solveQueens(chessboard, 0);

	return 0; //The codes will run
}