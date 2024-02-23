@echo off
if "%1"=="" goto loop
copy mat%1.in mat.in >nul
echo Problem Test
echo Data %1
time<enter
mat
time<enter
fc mat.out mat%1.out
del mat.in
del mat.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13) do call %0 %%i
:end
