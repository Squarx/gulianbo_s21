# CPP3_SmartCalc_v2.0-1 C++

## Introduction

The project has the abilities to calculate user's math expression with ( ) and exponential form of numbers. It's supported by:

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

To run the calculator you must be in the 'src' directory and follow the instructions below.

It also supports charting tools, credit calculator and deposit calculator.

## Graph mode:

Input f(x), x_min x_max output graph.

## Credit Calculator:

* Input: total credit amount, term, interest rate, type (annuity, differentiated)
* Output: monthly payment, overpayment on credit, total payment

## Deposit calculator

* Input: deposit amount, deposit term, interest rate, tax rate, periodicity of payments, capitalization of interest, replenishments list, partial withdrawals list
* Output: accrued interest, tax amount, deposit amount by the end of the term



## All

###(Directory: src)

```plaintext
make all
```

It includes: clean, install, test, gcov_report, dist.

## Install

###(Directory: src)

```plaintext
make install
```

Compile C/C++ code to build/Smart_calc.app

## Clean

###(Directory: src)

```plaintext
make clean
```

Remove .o files, build directory, files related with GCOV.

## Dvi

###(Directory: src)

```plaintext
make dvi
```

Open instruction in .md format

## Dist

###(Directory: src)

If you have a desire to arthivate the app folow code below.

```plaintext
make install
make dist
```

dist - creates an archive with .tgz extension and .zip extension

## Tests

###(Directory: src)

```plaintext
make test
```

Testing my C code.

## GCOV_Report

###(Directory: src)

```plaintext
make gcov_report
```

Create html page with coverage.

## Finishing

###(Directory: src)
If you'd like to finish the project and you're a responsible user that don't wanna left something folow code below.

Ps: you need to be in 'src' directory.

```plaintext
make uninstall
```
