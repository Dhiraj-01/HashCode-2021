:: run all file with inputs
@ECHO OFF
SET file=1.cpp
IF NOT '%1%'=='' (
SET file=%1
)

:: compile
ECHO compiling %file%
g++ -std=c++17 %file%

:: run with multiple input, output files
FOR /l %%x in (1, 1, 5) do (
ECHO "a.exe < i%%x.txt > o%%x.txt"
a.exe < i%%x.txt > o%%x.txt
)