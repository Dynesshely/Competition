@echo off
if "%1"=="" goto loop
copy route%1.in route.in >nul
echo Problem Test
echo Data %1
time<enter
route
time<enter
fc route.out route%1.out
del route.in
del route.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
