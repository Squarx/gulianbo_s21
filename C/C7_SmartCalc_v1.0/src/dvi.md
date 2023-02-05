# C7_SmartCalc_v1.0-0 made by Gulian Boris aka Dimas

## Introduction

The project has the abilities to calculate user's math expression with ( ). It's supported by:

* Addition (+)
* Substraction (-)
* Multiplication (*)
* Division (/)
* Exponentiation(^)
* Remainder of the division (mod)
* Unary plus (-a)
* Unary minus (+a)

And also trigonometric:

* cos(x)
* sin(x)
* tan(x)
* acos(x)
* asin(x)
* atan(x)
* sqrt(x)
* log(x)
* ln(x)

The project has been developing and supporting by pain and struggling.


To run the calculator you must be in the 'src' directory and follow the instructions below.

## All
###(Directory: src)
```
make all
```
It includes: clean, install, test, gcov_report, dist.
## Install 
###(Directory: src)
```
make install
```
Compile C/C++ code to build/Smart_calc.app
## Clean
###(Directory: src)
```
make clean
```
Remove .o files, build directory, files related with GCOV.
## Dvi
###(Directory: src)
```
make dvi
```
Open instruction in .md format
## Dist | Dist_zip
###(Directory: src)

If you have a desire to arthivate the app folow code below.
```
make install
make dist
```
or
```
make install
make dist_zip
```
dist - creates an archive with .tgz extension \
dist_zip - creates an archive with .zip extension
## Test
###(Directory: src)
```
make test
```
Testing my C code.

## GCOV_Report
###(Directory: src)
```
make gcov_report
```
Create html page with coverage.
## Finishing
###(Directory: src)
If you'd like to finish the project and you're a responsible user that don't wanna left something folow code below.

Ps: you need to be in 'src' directory.

```
make uninstall
```
