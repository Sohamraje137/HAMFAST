 #include <stdio.h>
 #include<time.h>

// Generate a lookup table for 32 bit integers

#define B2(n) n, n + 1, n + 1, n + 2

#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)

#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
 
// Lookup table that store the reverse of each table 

//Look up table for 2^22 entries

unsigned int lookuptable[4194304] = { B6(0), B6(1), B6(1), B6(2) };
 
// function countset Bits Using lookup table

// ans return set bits count

unsigned int countSetBits(int N)
{
            // seach for number in lookuptable. It takes O(n) time.
   
            int   count=lookuptable[N];
   

    return count;
}
int main()
{

        //intialise clock to calculate   total time required

        clock_t begin = clock();
    
        int i;
   
    // generate lookup table with 4194304 entries
   

   

    for (i = 0; i < 4194304; i++)
        lookuptable[i] = (i & 1) + lookuptable[i / 2];
 
   
    unsigned int N = 1000;
   
    //  get an user input for the number whose number of 1 bits are to be counted;
   

 
    printf("\n%d\n",countSetBits(N));
 
 

    clock_t end = clock();

 //end the clock and find the time spent by taking the difference between begin and end clock values;

 double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  //print the time taken

printf("\n%lf\n",time_spent);
   

    return 0;
}
