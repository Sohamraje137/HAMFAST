# Data Comunication(CO250) Mini Project


## HAMFAST: Fast Hamming Distance Computation


#### Team members

Soham P. Patil (16CO249)<br />
Bidyadhar Mohanty(16CO212)<br />



#### Abstract 

The computational data is stored in forms of binary string almost everywhere. The size of the binary string depends on the complexity of the structure to represent, so the string can be quite
long. The Hamming distance is the most used metric with binary strings.  The computational effort required to compute the Hamming distance linearly depends on the size of the string. However
even a linear effort case may be computational heavy if many computations are required.  One of the fastest computational approach to evaluate Hamming distances relies on look-up tables.
The computational performance, however, rapidly deteriorates with the size of binary string length, due to cache misses. so here we implement a computational strategy and implementation 
which can handle huge number of Hamming distance evaluation between binary strings of arbitrary length keeping computational performance competitivity.

### Objectives

* Implementing the Strategy of computing hamming distance using bit-counting algorithms on magic number.
* Show how the new method reduces cache misses.

##### References:

HAMFAST: Fast Hamming Distance Computation
Francesco Pappalardo,Cristiano Calonaci,Marzio Pennisi,Emilio Mastriani,Santo Motta,"HAMFAST: Fast Hamming Distance Computation",: Computer Science and Information Engineering, WRI World Congress 2009 
[Click Here](http://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=5171235&tag=1)


<h2>File Structure:</h2>
1. Introduction.md - Explain theoretical aspects of the mini project.
2. Design.md - Explain design aspects of the mini project.
3. bit.c- Contains the Code for calculating the time and cache misses of Bit Counting Algorithm.
4. lookuptable.c- Contains the Code for calculating the time and cache misses of Look-Up Table Algorithm.
5. splitlookup.c- Contains the Code for calculating the time and cache misses of Split-Look-Up Table Algorithm.
6. bitxor.c- Contains the Code for getting the XOR of two binary Strings and calculating time and cache misses of Bit Counting Algorithm.
7. lookuptable.c -Contains the Code for getting the XOR of two binary Strings and calculating time and cache misses of Look-Up Table Algorithm.
8. splitlookup.c--Contains the Code for getting the XOR of two binary Strings and calculating time and cache misses of Split-Look-Up Table Algorithm.
9. Image- This directory contains the images used for showing the results.
10. Jupiter- This directory contains the codes used for getting graphs in Jupiter Notebooks.It also contains the Sheet containing the test cases for algorithms.
11. Result.md- Contains the results of the paper implementation.


<h2>Results and Analysis</h2>

<p>All the codes were complied in ANSI-C</p>
<p>Laptops with 8GB RAM and 4 mb caches were used to obtain the results</p>
<p>To obtained the cache misses Cachegrind tool was used </p>
<p>To uses cachegrind ,after compliation use the following code</p>
<pre>valagrind --tool=cachegrind ./a.out</pre>
<p>To obtain time v/s bit length graph the cache was flushed regularly.Following command was used:</p>
<pre>  echo /proc/sys/vm/drop_caches </pre>

<br/>

Following are the expected graphs from the implementation:<br/>
![Image 1](images/img1.png?raw=true "Time vs Bit-length")
![Image 2](images/img2.png?raw=true "Cache-miss vs Bit-length")
* **Note:**
* Red lines represent the look-up table method; 
* Green lines represent the split look-up table method 
* blue lines represent the bit-count method

<p>We can see that bit counting algorithm takes a constant time of O(log(n)) where n is number of bits in the number</p>
<p>Look-up table approach takes longer time as the bit length increases</p>
<p>Look-up table cache misses very greatly as the bit length</p>
<p>Split-lookup table has lesser time consumption then look-up table</p>
<p>As the laptops used have high RAM's and cache memory ,the result are not point-to-point same</p>


<p>For calculating  Hamming Distace we can use bit-counting algorithm and reduce the consumption</p>
<p>For calculating the Block Codes for calculating Minimum Hamming Distance. Bit Counting is an efficient algorithm to calculate the Hamming Distance </p>
