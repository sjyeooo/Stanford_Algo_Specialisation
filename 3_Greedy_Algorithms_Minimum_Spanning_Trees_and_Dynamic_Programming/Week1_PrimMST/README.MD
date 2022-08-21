# Prim's Minimum Spanning Tree Algorithm

## Overview

This folder contains a program that implements Prim's algorithm for finding the Minimum Spanning Tree of an undirected weighted graph, with positive and negative edge lengths.

The algo uses two ways to sort the schedule:
1. Algorithm 1 - sort in decreasing order of ```(weight-length)``` with weight being the tie breaker
1. Algorithm 2 - sort in decreasing order of ```(weight/length)```.

### Execution steps

To run and test it out for yourself, run the batch file 
```
run_prim_mst.bat
