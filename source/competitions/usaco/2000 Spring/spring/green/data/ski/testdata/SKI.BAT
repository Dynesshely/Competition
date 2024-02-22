@echo off
if "%1"=="" goto loop
copy ski%1.in ski.in >nul
echo Problem Test
echo Data %1
time<enter
ski
time<enter
fc ski.out ski%1.out
del ski.in
del ski.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12) do call %0 %%i
:end
