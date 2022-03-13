@echo off

FOR /l %%n IN (1,1,100) DO (

CountingInversions ./test_cases/test_case%%n.txt

copy "%cd%\test_case_result.txt" "%cd%\test_case_result%%n.txt"
DEL /q test_case_result.txt
copy /Y "%cd%\test_case_result%%n.txt" "%cd%\test_cases\results\test_case_result%%n.txt"
DEL /q test_case_result%%n.txt
)