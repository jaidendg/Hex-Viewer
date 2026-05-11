# First C Program: Simple Hex Viewer in C

This is my first ever C program.

I made this project to start learning how C works, especially things like:

- `malloc` and manual memory management
- `structs`
- file handling
- loops and pointers
- working with raw bytes

The program opens a file, reads its contents into memory, and prints the data in both:

- hexadecimal format
- readable ASCII text

Kind of like a very bad version of `xxd`.

And yes, I know my approach and code is probably terrible but once again this is my first C program and this was a learning experience.

---

## Example Output

```text
2369 6e63 6c75 6465 203c 7374 6469 6f2e  #include <stdio.
683e 0d0a 2369 6e63 6c75 6465 203c 7374  h>..#include <st
646c 6962 2e68 3e0d 0a23 696e 636c 7564  dlib.h>..#includ
6520 3c73 7472 696e 672e 683e 0d0a 2369  e <string.h>..#i
6e63 6c75 6465 203c 7374 6462 6f6f 6c2e  nclude <stdbool.
683e 0d0a 0d0a 7479 7065 6465 6620 7374  h>....typedef st
7275 6374 207b 0d0a 2020 2020 756e 7369  ruct {..    unsi
676e 6564 2063 6861 7220 2a74 6578 743b  gned char *text;
0d0a 2020 2020 696e 7420 7374 6172 743b  ..    int start;
0d0a 2020 2020 696e 7420 7369 7a65 3b0d  ..    int size;.
0a20 2020 2062 6f6f 6c20 6973 4865 783b  .    bool isHex;
0d0a 2020 2020 696e 7420 7370 6163 6573  ..    int spaces
````

Non-printable characters are shown as `.`.

---

## Usage

```bash
./main <filename>
```

Example:

```bash
./main test.txt
```
