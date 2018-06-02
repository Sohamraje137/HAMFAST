/*
We can adjust the method for larger integer sizes by continuing with the patterns for the Binary Magic Numbers, B and S.
If there are k bits, then we need the arrays S and B to be ceil(lg(k)) elements long,
and we must compute the same number of expressions for c as S or B are long. For a 32-bit v,
16 operations are used.The best method for counting bits in a 32-bit integer v is the following:

v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count

The best bit counting method takes only 12 operations, which is the same as the lookup-table method,
but avoids the memory and potential cache misses of a table. It is a hybrid between the purely parallel method above and 
the earlier methods using multiplies (in the section on counting bits with 64-bit instructions),
though it doesn't use 64-bit instructions. The counts of bits set in the bytes is done in parallel, 
and the sum total of the bits set in the bytes is computed by multiplying by 0x1010101 and shifting right 24 bits.

The following algorithm will work till 128 bits.
v = v - ((v >> 1) & (T)~(T)0/3);                           // temp
v = (v & (T)~(T)0/15*3) + ((v >> 2) & (T)~(T)0/15*3);      // temp
v = (v + (v >> 4)) & (T)~(T)0/255*15;                      // temp
c = (T)(v * ((T)~(T)0/255)) >> (sizeof(T) - 1) * CHAR_BIT; // count




 Counting bits set, in parallel

unsigned int v; // count bits set in this (32-bit value)
unsigned int c; // store the total here
static const int S[] = {1, 2, 4, 8, 16}; 
// Magic Binary Numbersstatic const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};
c = v - ((v >> 1) & B[0]);c = ((c >> S[1]) & B[1]) + (c & B[1]);
c = ((c >> S[2]) + c) & B[2];
c = ((c >> S[3]) + c) & B[3];
c = ((c >> S[4]) + c) & B[4];
TheB array, expressed as binary, is:
B[0] = 0x55555555 = 01010101010101010101010101010101B[1] = 0x33333333 = 00110011001100110011001100110011B[2] = 0x0F0F0F0F = 00001111000011110000111100001111B[3] = 0x00FF00FF = 00000000111111110000000011111111B[4] = 0x0000FFFF = 00000000000000001111111111111111






*/

#include<stdio.h>
int main()
{
	unsigned int v;
	unsigned int c;

printf("\nEnter a integer\n");
scanf("%d",&v);
	v=v-((v>>1) & 0x55555555);
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // 

printf("\nno. of 1's =%d\n",c);
}	