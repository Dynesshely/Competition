@echo off
if "%1"=="" goto loop
copy farm%1.in farm.in >nul
echo Problem Test
echo Data %1
time<enter
farm
time<enter
fc farm.out farm%1.out
del farm.in
del farm.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
