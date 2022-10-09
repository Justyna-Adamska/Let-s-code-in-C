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

## 08.10.2022

Next changes to main.c introduced the concept of dynamic memory allocation. New header file stdlib.h with functions malloc, calloc and realloc was used to reserve heap memory. Together with them the proper use of the function free() was necessary in order to avoid memory leaks. Valgrind was the tool that checked program against such leaks. What is more, one has to take into consideration the scenario when void pointer that returns address in malloc, calloc and realloc functions is of NULL type. This happens when there is no available memory in heap. In such case the program is terminated and returns error code ENOMEM. 

### scanf

This time program starts from requesting input data from user. In order to do this the scanf () function was introduced. In this version of the program user is asked to input integer numbers. If function scanf() is unable to retrieve integer values from input, the program terminates and prints error message on the console.

### pointer to pointer

In this modification of the program, the concept of pointers is further widened and 'pointer to pointer' pointers were introduced. This was necessary because I wanted to assign address given by malloc function to my original pointer from main function instead of creating a copy of this pointer.

###error codes

I used new header file errno.h is order to use different error codes, f.e. one that indicates 'not enough memory' in heap.

### if0 endif

In order to indicate, which lines of the code should be ignored by the preprocessor, I used #if 0 and #endif comments.

