#include <stdio.h>

//For all digits from 0 to 10, we're gonna calculate their double
//Defune a function that multiplies a certain integer a (Interval [0, 10]) by 2 to get the double: 
int timestwo(int a) {
	return 2 * a; 
}
//"size_t" is an unsigned integer. It can store negative values only. 
//This function uses an unsinged integer value and returns its double as output
size_t timestwo(size_t a) {
	return 2 * a; 
}
//Print every number in the interval and its respective multiple by 2. Note that integers will be considered only
int main(void) {
	printf("Integers and their double:\n\n"); 

	for (size_t i = 0; i < 11; i++) 
		printf("%d -> %d\n", i, timestwo(i));   

	return 0; 
}

