/*
compression and decompression program
*/
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/* command line arguments
* ./compress	–c	       girl.pgm  	output.dat	50
* argv[0]       argv[1]    argv[2]      argv[3]     argv[4]
* ./compress	–d	       output.dat	output.pgm
* argv[0]       argv[1]    argv[2]      argv[3]
*/
#define COMPRESSION_ARGS 5
#define DECOMPRESSION_ARGS 4

const static char* COMPRESSION = "-c";
const static char* DECOMPRESSION = "-d";

void usage(int argc, char** argv) {
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]:%s\n", i, argv[i]);
    }
    printf("\n-----Compression and decompression-----\n");
    printf("1. Compression: -c inputfile.pgm outfile.dat\n");
    printf("2. Decompression: -d inputfile.dat outfile.pgm\n");
}

int main(int argc, char** argv)
{
    char Inputfile[] = "sample.pgm";
    char* Outputfile = NULL;
    printf("Total Argument:%d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]:%s\n", i, argv[i]);
    }
    if (strcmp(argv[1], COMPRESSION) == 0) {
        if (argc != COMPRESSION_ARGS) {
            printf("Invalid Argument!\n");
            usage(argc, argv);
        }
        else {
            bool in = false, out = false, qlty = false;
            /*validate the input file extension, it should ends with.pgm*/
            char* ret1 = strstr(argv[2], ".pgm");
            if (ret1) {
                printf("found substring at address %p\n", ret1);
                in = true;
            }
            else {
                printf("Invalid input file extension\n");
                usage(argc, argv);
            }
            /*validate the output file extension, It should ends with.dat*/
            char* ret2 = strstr(argv[3], ".dat");
            if (ret2) {
                printf("found substring at address %p\n", ret2);
                out = true;
            }
            else {
                printf("Invalid output file extension\n");
                usage(argc, argv);
            }
            /*validate the quality Argument, It should be in between 0 - 100*/
            if (0 <= atoi(argv[4]) <= 100) {
                qlty = true;
            }
            if (in == true && out == true && qlty == true) {
                printf("compression\n");
            }
        }
    }
    else if (strcmp(argv[1], DECOMPRESSION) == 0) {
        if (argc != DECOMPRESSION_ARGS) {
            printf("Invalid Argument!\n");
            usage(argc, argv);
        }
        else {
            bool in = false, out = false;
            /*validate the input file extension, it should ends with.dat*/
            char* ret1 = strstr(argv[2], ".dat");
            if (ret1) {
                printf("found substring at address %p\n", ret1);
            }
            else {
                printf("Invalid input file extension\n");
                usage(argc, argv);
            }
            /*validate the output file extension, It should ends with.pgm*/
            char* ret2 = strstr(argv[3], ".pgm");
            if (ret2) {
                printf("found substring at address %p\n", ret2);
            }
            else {
                printf("Invalid output file extension\n");
                usage(argc, argv);
            }
            if (in == true && out == true) {
                printf("Decompression\n");
            }
        }
    }
    else {
        printf("Invalid option selected!\n");
        usage(argc, argv);
    }

    return 0;
}
