@echo off


QuickSort QuickSort.txt

copy "%cd%\test_case_result.txt" QuickSortArraySorted.txt
copy "%cd%\test_case_number_compares.txt" QuickSortAnswer.txt
DEL /q test_case_result.txt
DEL /q test_case_number_compares.txt