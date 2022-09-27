# C Language in practice

This repository is intended to serve as a tool for learning C language. Through practical examples I am going to explore the power of the C language.

## 07.09.2022 

I started with a single main function that prints values of linear function. I also added for loop in order to simplify my code.

### .gitignore

In order to avoid commiting .swp and .out files I added .gitignore to my repository.

## 13.09.2022

I altered main.c file in such a way, that all operations and calculations are made in separate functions and function "main"only  calls these functions. The result of the program is the same as in the version from 07.09.2022 but the code is more open to modifications and becomes more versatile. Additionally I made sure that single function encorporates one operation. Instead of making one complex function I created 5 smaller ones. This is easier to modify and to manage in case of future alterations.

## 27.09.2022

I made some more changes to main.c file so that I use the concept of arrays and pointers. First I created two arrays and then I used for loops to initialize them. In the end I printed my results. In order to avoid magic numbers (values that say nothing to future user of the program), I introduced symbolic constants into my code.

### const int

In order to secure the code from unwanted modifications I added const int prefix to functions declarations. By doing it I explicitly show which values are open for modifications and which are not. 
