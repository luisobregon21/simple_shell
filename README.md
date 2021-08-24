<p align="center">
   <img src="https://www.holbertonschool.com/holberton-logo.png"(https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcTLtL_ToHLEo_BWFxD-yf32Ux3zfsH_NPc8Qw&usqp=CAU)
     alt="Flow chart"
     style="float: left; margin-right: 10px;">
</p>

## SIMPLE SHELL 🐚🐚🐚
Holberton's final project is designing, and writing a UNIX operating system.
This project will place your C language knowleged into practice after
3 months of learning low-level-programming.

#### Follow the steps bellow to compile.
 - `cd simple_shell`
 - `gcc -Wall -Werror -Wextra -pedantic *.c`
 - `./a.out`


### Functions
Prototypes | Description
----------- | -------------
**strncmp** | Function that compares two strings.
**_putchar** | Prints a character.
**userinput** | Reads the user input.
**envprinter** | Function that prints the enviroment.
**split_string** | Function that tokenizes a string's delimiter.
**_strlen** | Function gets the length of a string.
**strcpy** | Function copies the string pointed to.
**path_to_arr** | Function gets the path of an array.
**input_validator** | Reads the user's command line input.
**concatinator** | Function that concatinates strings.
**executor** | Function executes arguments in the command prompt line.
**memclean** | Function to free all arguments.

### Files
This is the list of files used to build and run our shell.

* [memclean.c](https://github.com/luisobregon21/simple_shell/blob/master/memclean.c)
Function to free passed arguments or any leaks.
* [main.c](https://github.com/luisobregon21/simple_shell/blob/master/main.c)
First function in our program that is executed when it begins executing,
nevertheless, it's not the first function executed.
* [strmanipulation.c](https://github.com/luisobregon21/simple_shell/blob/master/strmanipulation.c)
Function that will make the shell run seamlessly under the hood.
* [utilities.c](https://github.com/luisobregon21/simple_shell/blob/master/utilities.c)
Function helps the shell's enviroment.
* [validate.c](https://github.com/luisobregon21/simple_shell/blob/master/utilities.c)
Functions to execute and validate input strings.
* [shell.h](https://github.com/luisobregon21/simple_shell/blob/master/shell.h)
Header file of functions where prototypes and libraries are all stored.

#### REQUIREMENTS (Rules)

* Allowed editors: *vi*, *vim*, *emacs*
* All your files will be compiled on Ubuntu 14.04 LTS.
* Your programs and functions will be compiled with *gcc 4.8.4* using the flags *-Wall -Werror -Wextra* and *-pedantic*
* All your files should end with a new line
* A *README.md* file, at the root of the folder of the project is mandatory
* Your code should use the *Betty* style. It will be checked using *betty-style.pl* and *betty-doc.pl*
* No more than 5 functions per file.
* Your shell should not have any memory leaks.
* All your header files should be include guarded.
* Use system calls only when you need to.


### EXAMPLES
#### Type of interractions:

##### Non-interactive
*Command*
```
echo "/bin/ls" | ./a.out
```
*Output*
```
AUTHORS    a.out    compile_valgring  memclean.c  shell.h     test  validate.c
README.md  compile  main.c  oldfiles  strmanipulation.c  utilities.c

```
<hr>

##### Interactive
*Command*
```
./a.out
```
Once the prompt `($)` is on display, you can type in the command line,
enter
**Example input** - `/bin/ls`

*Output*
```
AUTHORS    compile     memclean.c  strmanipulation.c  validate.c
README.md  compile_valgring  oldfiles test
a.out   main.c     shell.h utilities.c

```



<p align="center"> AUTHORS </p>

<h3 align="center">Made by Gillermo Lorca, Johanne Lopez, and Luis Obregon.</h3>
