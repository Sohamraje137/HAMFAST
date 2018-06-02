# Design

The paper requires three main functionalities to be used<br />
1. Binary bit calculation <br />
2. Look-up Table set bit calculation <br />
3. Cachegrid tool for calculating cache misses. <br />

For comparison we have to implement: 
1. Look-up Table. <br />
2. Split-Look up. <br />
3. Bit-Counting Algorithm. <br />


## Initial
We will take input of two binary numbers .<br/>
XOR Operation will be performed on them and result will be taken<br/>
The result will be fed to one of the algorithm at a time<br/>
The cache misses will be calculated using cache grid tool by intel<br/>



### look-up Table method
Look-up table is a tabular representation of corresponding values associated to a character i.e. we can lookup the corresponding number of bits in binary number. <br />
It takes  O(1) time for counting number bits in a binary number.The Look up table stores all the values of number of set bits in an integer from 0 to k. <br />
So, when whenever we are implementing k bits of length we have a table with k rows.Whenever an input is given the number of bits is calculated and using this we calculate the hamming distance. <br />

#### Split- Look-up Table:
We split the look up table into divisions and use the look up table.

#### Bit counting: 
In,Bit counting you calculate the number of bits using Magic binary numbers. <br/>
We will have to implement the 12 cycle XOR operation algorithm for getting the desired results.

We have to use cachegrid tool by intel to get the results of cache misses . <br />
The reulting graph will be verified only for intel processors due to lack of other processor Computers. <br />

Finally, We will be proving that bit counting algorithm is one of the best methods for calculating hamming distance.

#### Expected results
The following result is expected from the implementation of the paper:<br/>
* Cache misses in bit-count will have to be less.
* Lookup-table should have a lot of potential cache misses and that should grow exponentially.
* Look-up table should run in O(n).
* bit count should run in O(Log n) time complexity.
* Split look up table method should have time complexity of O(256) which is constant and the potential cache misses should be greater than bit counting Algorithm and less than Lookup table.

##### Expected graphs

Following are the expected graphs from the implementation:<br/>
![Image 1](images/img1.png?raw=true "Time vs Bit-length")
![Image 2](images/img2.png?raw=true "Cache-miss vs Bit-length")
* **Note:**
* Red lines represent the look-up table method; 
* Green lines represent the split look-up table method 
* blue lines represent the bit-count method