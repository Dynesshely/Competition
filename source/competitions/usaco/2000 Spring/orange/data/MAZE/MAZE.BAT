@echo off
if "%1"=="" goto loop
copy maze%1.in maze.in >nul
echo Problem Test
echo Data %1
time<enter
maze
time<enter
fc maze.out maze%1.out
del maze.in
del maze.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
