# Completion Times

## Overview

This folder contains a program that finds the minimum completion time for a number of jobs, each with its own weight _(priority)_ and length _(duration)_.

The algo uses two ways to sort the schedule:
1. Algorithm 1 - sort in decreasing order of ```(weight-length)``` with weight being the tie breaker
1. Algorithm 2 - sort in decreasing order of ```(weight/length)```.

### Execution steps

To run and test it out for yourself, run the batch file 
```
run_greedy.bat
