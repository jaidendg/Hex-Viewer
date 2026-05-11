#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned char *text;
    int start;
    int size;
    bool isHex;
    int spaces;
} Loop;

void loop_and_print(Loop *loop) {
    for (int i = loop->start; i < loop->size; i++) {
        if (loop->isHex && loop->spaces == 2) {
            printf(" ");
            loop->spaces = 0;
        }

        unsigned char str = loop->text[i];
        if (loop->isHex) {
            printf("%02x", str);
            loop->spaces++;
        } else {
            if (str >= 32 && str <= 126) {
                printf("%c", str);
            } else {
                printf(".");
            }
        }
    }
    loop->spaces = 0;
}

long get_file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    return size;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Incorrect format\nformat: ./main <file_name>\n");
        return EXIT_FAILURE;
    }
    
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("File failed to open.");
        return EXIT_FAILURE;
    }
    long fsize = get_file_size(file);
    unsigned char *cptr = malloc(fsize * sizeof(unsigned char));
    
    int ch;
    int index = 0;
    while ((ch = fgetc(file)) != EOF) {
        cptr[index] = (char)ch;
        index++;
    }

    int nlsize = 16;

    int length = fsize / nlsize;
    int remain = fsize % nlsize;
    int current = 1;

    Loop loop;
    loop.text = cptr;
    loop.spaces = 0;

    for (int i = 0; i < length; i++) {
        loop.start = (current - 1) * nlsize;
        loop.size = (current * nlsize);
        loop.isHex = true;

        loop_and_print(&loop);
        printf("  ");

        loop.isHex = false;

        loop_and_print(&loop);
        printf("\n");
        current++;
    }

    loop.start = (fsize - remain);
    loop.size = fsize;
    loop.isHex = true;
    loop_and_print(&loop);

    for (int i = 0; i < ((nlsize - remain)*3)-3; i++) {
        printf(" ");
    }

    loop.isHex = false;
    loop_and_print(&loop);
    printf("\n");

    fclose(file);
    free(cptr);
    return EXIT_SUCCESS;
}
