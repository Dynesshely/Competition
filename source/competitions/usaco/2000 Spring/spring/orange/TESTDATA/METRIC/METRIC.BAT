@echo off
if "%1"=="" goto loop
copy metric%1.in metric.in >nul
echo Problem Test
echo Data %1
time<enter
metric
time<enter
fc metric.out metric%1.out
del metric.in
del metric.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
