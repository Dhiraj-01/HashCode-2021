@ECHO OFF

:: compile
ECHO compiling : g++ -std=c++17 %*
g++ -std=c++17 %* || exit /b 0

:: run with multiple input, output files
FOR /l %%x in (1, 1, 5) do (
echo.
ECHO "a.exe < i%%x.txt > o%%x.txt"
a.exe < i%%x.txt > o%%x.txt
)