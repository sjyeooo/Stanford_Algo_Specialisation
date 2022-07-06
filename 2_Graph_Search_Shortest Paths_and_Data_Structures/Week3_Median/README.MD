# Median Maintenance

## Overview

The goal of this problem is to implement the "Median Maintenance" algorithm (covered in the Week 3 lecture on heap applications).  The text file contains a list of the integers from 1 to 10000 in unsorted order; you should treat this as a stream of numbers, arriving one by one.  

Letting $x_i$​ denote the $i$ th number of the file, the $k$th median $m_k$​ is defined as the median of the numbers $x_1,...,x_k$.  

If $k$ is odd, then $m_k$ is ((k+1)/2) smallest number among $x_1,...,x_k$.

If $k$ is odd, then $m_k$ is $k/2$ smallest number among $x_1,...,x_k$.


### Execution steps

To run and test it out for yourself, run the batch file 
```
run_median.bat
```

### Assumptions
There are no assumptions made within the code wrt the size of input file.