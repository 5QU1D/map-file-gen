# Map File Generator

This is a companion program to my [Map Maker project](https://github.com/5QU1D/map-maker).

This C++ program is written with a g++ compiler in mind. To run, download the Makefile, generator.cpp, and prettyheader.h, run the `make` command, then run the output file `out` using `./out`. The generator will then describe its functionality, identify the prompts it will ask in sequence, then finally prompt the user for input, all the way through to file generation. This program will generate a .txt file in the same location that the executable resides at.

The produced .txt file will be in the following format:
> POSITIVE_INT_WIDTH POSITIVE_INT_HEIGHT\
> (L,N) (L,N) (L,N)

Where `POSITIVE_INT_WIDTH` and `POSITIVE_INT_HEIGHT` are positive whole numbers indicative of the number of tiles in width and height of the map, with POSITIVE_INT_HEIGHT number of lines to the file with POSITIVE_INT_WIDTH number of (L,N) tuples, in which `L` is V, F, M, S, R and `N` is between 1-5 *__OR__* L and N are __both__ 0.

&nbsp; 

**NOTE:** You are strongly advised to ensure that your resulting text file contains **only** alphabetic characters, as the Map Maker project can be finicky with numeric or special characters in the file name.
