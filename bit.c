
#include<stdio.h>
#include<time.h>

int main()
{
	unsigned int v,k;
	unsigned int c;


    //intialise clock to calculate   total time required


	clock_t begin = clock();


	v=1232423634;

	k=3489362036;

	v=v^k;

	static const int S[] = {1, 2, 4, 8, 16};

	//B is an array of Magic binary numbers


static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};

c = v - ((v >> 1) & B[0]);c = ((c >> S[1]) & B[1]) + (c & B[1]);

c = ((c >> S[2]) + c) & B[2];

c = ((c >> S[3]) + c) & B[3];

c = ((c >> S[4]) + c) & B[4];


printf("\n%d\n",c);

	

	clock_t end = clock();


 double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

 //end the clock and find the time spent by taking the difference between begin and end clock values;


  //print the time taken


printf("\n%lf\n",time_spent);
}
