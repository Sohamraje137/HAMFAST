<h><strong>HAMFAST</strong></h>
<p> The topic orients towards implementation of a faster coding scheme for calculating hamming distance between two binary strings.</p>

<p><br><strong>Hamming distance:</strong></p>
<p>The Hamming distance between two strings of equal length is the number of positions at which the corresponding symbols are different.</p>
<p>So,for two binary strings Hamming distance is the number of corresponding bits where the bit value differs.</p>
<p>We can calculate it by simply doing an XOR operations between the two strings.</p>
<p>The number of set bits(bit value=1) in the output of XOR will be the Hamming Disatnce between two strings.</p>
<p>So, the problem reduces to calculating the number of set bits in a string.</p>

<p><br><br>Traditionally,<strong>Look-up table </strong>approach was used to find the set bits in a string.</p>

<h><strong> LOOK_UP TABLE</strong></h>
<p>We store the number of set bits of all numbers in a table and then the output of XOR operation will be searched in the table</p>
<p>The corresponding entry will be returned,which is our required answer</p>
<pre>Time Complexity: O(N) </pre>
<p>As the algorithm to build look-up table will use a for loop from 0 to 2^N </p>
<p>In this apprach 12 CPU clock cycles are used. But, the main memory used is very large as look-up Table may range till 512 MB or Even 2 Gb</p>

<p>To avoid the memory usage and to achieve lesser time complexity .</p>
<p>We follow bit Counting method</p>

<h> <strong>Bit Counting </strong></h>

<p>In bit counting, the counts of bits set in the bytes is done in parallel, and the sum total of the bits set in
</p><p>the bytes is computed by multiplying and shifting right bits,using binary magic numbers.</p>
<p>Magic numbers in mathematics and computer science are numbers that show special properties when used in certain computations. In particular, they are successfully used in algo-
rithms involving bit handling. They offer faster versions of algorithms over those that can be developed </p>

<p>In our implementation we use five number <strong> 0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF</strong></p>
<p> The bit counting algoritm is given below</p>
<pre>v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count
</pre>

<p>The counts of bits set in the bytes is done in parallel, and the sum total of the bits set in the bytes</p><p> is computed by multiplying by 0x1010101 and shifting right 24 bits.</p>

<pre>Time Complexity: O( log(n) )</pre>

<p>bit counting method takes only 12 operations, which is the same as the lookup-table method,</p>
<p> but avoids the memory and potential cache misses of a table. It is a hybrid between the purely parallel method above </p>
<p>and the earlier methods using multiplies though it doesn't use 64-bit instructions</p>

<h><strong>SPLIT LOOK_UP Table</strong></h>
<p></p>
<p>Split look up table is same as that of a look-up table but uses relatively lesser space </p>
<p>Split look-up table divides the total length into sizes of 8bits or 16 bits depending on the code</p><p> and compute the corresponding bits in every 8 bits of a 32 bit integer valve</p>
 
<pre>
unsigned int v; // count the number of bits set in 32-bit value v
unsigned int c; // c is the total bits set in v
c = BitsSetTable256[v & 0xff] + 
    BitsSetTable256[(v >> 8) & 0xff] + 
    BitsSetTable256[(v >> 16) & 0xff] + 
    BitsSetTable256[v >> 24]; 
    </pre>
</pre>
  </pre>
    <pre>Time Complexity: O(N) </pre>
<p></p>
</p>
</pre>
    <p>This method has the same complexity as Look-up table  but space complexity reduces drastically </p>
    
</pre> 
    <p> We shift the integer value by 8 bits always </p>

<p> And then And with Oxff (1111 1111) And get the corrresopnding value in the look-up table</p>
