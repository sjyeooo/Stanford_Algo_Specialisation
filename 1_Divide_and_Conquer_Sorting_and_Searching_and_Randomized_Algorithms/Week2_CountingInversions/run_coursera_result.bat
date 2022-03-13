@echo off


CountingInversions IntegerArray.txt

copy "%cd%\test_case_result.txt" IntegerArrayAnswer.txt
DEL /q test_case_result.txt