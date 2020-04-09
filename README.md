# 42 Get Next Line tester

A tester for the get_next_line project from the 42 curriculum

### Quick start

To use the test, just clone it next to your get_next_line folder

```shell
$ git clone https://github.com/Tishj/GNL_Tester.git
```
Then open up the tester's Makefile and edit the following values:
```makefile
GNL_DIR = /path/to/your/get_next_line/
GNL_INCL = /incl/
```

`GNL_DIR` should point to the path of your get_next_line
`GNL_INCL` should point to the subdirectory of get_next_line that your header is in

### Usage

```shell
$ ./gnltest [FILE1] [FILE2] [FILE3] etc..
```

###### Features:
* Unlimited filedescriptors
* Random reading order

###### Flags:
    BUFFER_SIZE = N - sets BUFFER_SIZE to N (-D BUFFER_SIZE) to test gnl with, 128 by default
    
    BONUS = 1 - Indicates if the _bonus files should be used instead, off by default
    
    READEMPTYFD = 1 - Tells the tester to continue reading even if the given filedescriptor is empty (this does not work if there is only 1 fd), off by default

### Description:

The tester will pick at random one of the filedescriptors you have given it.
If that filedescriptor is already empty and READEMPTYFD is set to OFF, it will pick another filedescriptor at random, otherwise it will read from the filedescriptor regardless.
