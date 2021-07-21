#include <stdio.h>
int main() {
    FILE *fp = fopen("file1.txt", "rw");
    FILE *fp2=fopen("file2.txt","rw");
    if (fp == NULL||fp2==NULL) {
        printf("error\n");
    } else {
        printf("print ok!\n");
        fclose(fp);
    }
    return 0;
}