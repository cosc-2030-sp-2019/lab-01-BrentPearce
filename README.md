# Lab01
For Lab 01:  Process Numbers and Compress Data

If the input file contains a four byte zero (which could happen in a bitmap file, r b, g, &
a all 00) then as a result the line in the output file would be :
00000000 for a single black completely transparent pixel(I believe), and for a repeated pixel:
00000000 00000000 xxx (where xxx is the number of times the pixel is repeated).

For a single 00000000 pixel then a
program reading the output file (for decompression for example) could think that the pixel
is flag and then may attempt to read the next flag and the again attempt(it may crash the program)
to read the first two numbers of the next pixel and use that number to repeat a black completely
transparent pixel.

In order to fix this perhaps a character string containing characters that are not hex digits. A possible 
flag could be the string is "ISO" greak for equal. As such the author implemented this in his solution.
