#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "gonzalo.h"
#include "maca.h"
#include "laura.h"
#include "josefina.h"
#include "pablo.h"
#include "juanjo.h"


int main(int argc, char *argv[]) {
    // definimos los parametros del archivo exe como argumentos
    char *filename = argv[1];
    // printeamos el nombre del archivo
    printf("Filename: %s\n", filename);

    // declaramos las variables
    int input;
    char *buffer;
    char *book_name;
    char *author;
    char *anio;
    char *estante_numero;
    char *estante_seccion;
    char *piso;
    char *edificio;
    char *sede;
    char *book;

    // llamamos a la funcion del menu y almacenamos su variable de retorno
    input = menu();
    getchar();

    switch (input) {
        case 1:
            // inicializamos las variables
            book_name = (char *)malloc(100);
            author = (char *)malloc(100);
            anio = (char *)malloc(100);
            estante_numero = (char *)malloc(100);
            estante_seccion = (char *)malloc(100);
            piso = (char *)malloc(100);
            edificio = (char *)malloc(100);
            sede = (char *)malloc(100);

            int a=0;
            while (a==0){
                // le pedimos un input al usuario que cuente los espacios para evitar dar dos respuestas a la vez
                printf("Please enter the book name: ");
                scanf("%[^\n]s", book_name);
                getchar();
                int repetido=search_book_repetido(filename, book_name);
                if (repetido==1){
                    printf("The book is already in the database\n");
                }
                else{
                    a=1;
                }
            }

            printf("Please enter the author: ");
            scanf("%[^\n]s", author);
            getchar();

            printf("Please enter the year: ");
            scanf("%[^\n]s", anio);
            getchar();

            printf("Please enter the estante number: ");
            scanf("%[^\n]s", estante_numero);
            getchar();

            printf("Please enter the estante section: ");
            scanf("%[^\n]s", estante_seccion);
            getchar();

            printf("Please enter the piso: ");
            scanf("%[^\n]s", piso);
            getchar();

            printf("Please enter the edificio: ");
            scanf("%[^\n]s", edificio);
            getchar();

            printf("Please enter the sede: ");
            scanf("%[^\n]s", sede);
            getchar();

            // llamamos a la funcion para agregar libros al archivo csv
            add_new_book_to_csv(filename, book_name, author, anio, estante_numero, estante_seccion, piso, edificio, sede);
            return main(argc, argv);
        case 2:
            input = sub_menu();
            getchar();

            switch (input) {
                case 1:
                    get_last_element_of_each_line(filename);
                    return main(argc, argv);
                case 2:
                    return main(argc, argv);
            }
        case 3:
            printf("Please enter the book name: ");
            book_name = (char *)malloc(100);
            scanf("%[^\n]s", book_name);
            getchar();
            delete_line(filename, book_name);
            printf("Deleting book...\n");
            // esperamos 800 milisegundos
            Sleep(800);
            printf("Book deleted.\n");
            printf("\nRedirecting to main menu...\n");
            Sleep(2000);

            return main(argc, argv);
        case 4:
            // inicializamos la variable libro
            book = (char *)malloc(100);

            printf("Please enter the book name: ");
            scanf("%[^\n]s", book);
            getchar();

            search_book(filename, book);
            return main(argc, argv);
        case 5:
            buffer = read_file(filename);
            printf("%s\n", buffer);
            return main(argc, argv);
        case 6:
            // le pedimos al usuario el input de la variable libro
            printf("Please enter the book name: ");
            // alocamos el input en la memoria
            book_name = (char *)malloc(100);
            scanf("%[^\n]s", book_name);
            getchar();
            // llamamos a la funcion de editar la linea
            edit_line(filename, book_name);
            return main(argc, argv);
        case 7:
            printf("All the process has been saved\n");
            Sleep(2000);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid input\n");
            return main(argc, argv);
    }
}
