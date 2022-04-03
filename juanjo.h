#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


int delete_line(char *filename, char *book_name) {

    FILE *fileptr1, *fileptr2;
    char filename1[100], filename2[100];
    char ch;
    int delete_line_, temp = 1;

    //open file in read mode
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
    while (ch != EOF) {
        //printf("%c", ch);
        ch = getc(fileptr1);
    }
    rewind(fileptr1);
    delete_line_ = search_book(filename, book_name);
    printf("\n");
    // printeamos el numero de la linea a borrar
    printf("Line number to be deleted: %d\n", delete_line_);
    // abrimos el archivo en modo lectura y escritura
    fileptr2 = fopen("replica.csv", "wb");
    ch = 'A';
    while (ch != EOF) {
        ch = getc(fileptr1);
        if (temp != delete_line_) {
            // copiamos el archivo original en el archivo de replica
            putc(ch, fileptr2);
        }
        if (ch == '\n') {
            temp++;
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    // renombramos el archivo de replica
    rename("replica.csv", filename);
    printf("\n The contents of file after being modified are as follows:\n");
    fileptr1 = fopen(filename, "rb");
    ch = getc(fileptr1);
    while (ch != EOF) {
        //printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;
}