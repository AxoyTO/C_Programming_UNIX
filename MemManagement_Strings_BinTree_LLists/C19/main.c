#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    char c;
    int charCount = 0, wordCount = 0, stringCount = 0, wordFlag = 0, endFlag = 1;

    FILE *fi, *fo;
    if (argc < 3)
        return 1;
    
    fi = fopen(argv[1], "r");
    if (!fi)
        return 1;

    fo = fopen(argv[2], "w");
    if (!fo)
        return 1;

    while (1) {
        c = fgetc(fi);

        if (feof(fi) != 0) {
            break;
        }
        if(c!='\n')
            endFlag = 0;
        charCount++;
        if(charCount==1 && c!='\n' && c!=' ')
            wordFlag = 1;
        if (c == ' ' || c == '\n') {
            wordFlag = 1;
        } else {
            if (wordFlag == 1){
                wordCount++;
            }
            wordFlag = 0;
        }
        if (c == '\n') {
            stringCount++;
        }
    }

    fprintf(fo, "%d %d %d", stringCount, wordCount, charCount);

    fclose(fi);
    fclose(fo);
    return 0;
}
