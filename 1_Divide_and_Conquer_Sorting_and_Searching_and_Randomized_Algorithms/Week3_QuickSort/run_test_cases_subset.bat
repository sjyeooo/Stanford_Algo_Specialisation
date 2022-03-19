@echo off

mkdir "%cd%\test_cases\results"

FOR /l %%n IN (1,1,10) DO (

QuickSort ./test_cases/test_case%%n.txt

copy "%cd%\test_case_result.txt" "%cd%\test_case_result%%n.txt"
DEL /q test_case_result.txt
DEL /q test_case_number_compares.txt
copy /Y "%cd%\test_case_result%%n.txt" "%cd%\test_cases\results\test_case_result%%n.txt"
DEL /q test_case_result%%n.txt
)