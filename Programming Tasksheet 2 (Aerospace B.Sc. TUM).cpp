#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Task 4.8: Imput a certain array of integers, it will return you the same.
 
int main() {

	printf("Put your integers here: \n"); 

	int random[5]; //Define a random integer with 5 elements. No decimal portions possible since it is an integer
	
	for  (int i = 0; i < 5; ++i) { //Iterate a loop for the array 
		scanf("%d", &random[i]); //Evaluate the input 
	}

	printf("\nYour chosen array:\n"); 
	for (int i = 0; i < 4; i++) { 
		printf("%d ", random[i]); //Print the array until the next to last digit of the array
	}
	printf("%d\n", random[4]); //Print the last digit of the array
	
	return 0; 

}