#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/





int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosBkp = ll_newLinkedList();

    do
    {
        option = menu();
        switch(option)
        {
        case 1:
            if (ll_isEmpty(listaEmpleados))
            {
                if (controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Archivo cargado con exito\n");

                }
                else
                {
                    printf("NO SE PUDO CARGAR EL ARCHIVO\n");
                }

            }
            else
            {
                printf("El archivo de datos ya fue cargado\n");

            }
            system("pause");
            break;

        case 2:

            if (ll_isEmpty(listaEmpleados))
            {
                if (controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("Archivo cargado con exito\n");

                }
                else
                {
                    printf("NO SE PUDO CARGAR EL ARCHIVO\n");
                }

            }
            else
            {
                printf("El archivo de datos ya fue cargado\n");

            }
            system("pause");
            break;

        case 3:
            if (!ll_isEmpty(listaEmpleados))
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 4:
            if (!ll_isEmpty(listaEmpleados))
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 5:
            if (!ll_isEmpty(listaEmpleados) )
            {

                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 6:
            if (!ll_isEmpty(listaEmpleados))
            {

                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 7:
            if (!ll_isEmpty(listaEmpleados))
            {

                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;

        case 8:
            if (!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsText("data.csv", listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;

        case 9:
            if (!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;

        case 10:
            if (!ll_isEmpty(listaEmpleados))
            {

                if (!ll_clear(listaEmpleados))
                {
                    printf("Se vacio la lista cargada\n");
                }

            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;

        case 11:
            if (!ll_isEmpty(listaEmpleados))
            {
                if ( (listaEmpleadosBkp = ll_clone(listaEmpleados)) )
                {
                    printf("se realizo la copia de la lista cargada\n");
                }

            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;

        case 12:
            if (!ll_isEmpty(listaEmpleados) || !ll_isEmpty(listaEmpleadosBkp))
            {
                controller_ListEmployee(listaEmpleadosBkp);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;

        case 13:
            if (!ll_isEmpty(listaEmpleados))
            {
                if (ll_containsAll(listaEmpleados, listaEmpleadosBkp) && ll_containsAll(listaEmpleadosBkp, listaEmpleados)  )
                {
                    printf("Su lista y el backup contienen los mismos elementos\n");
                }
                else
                {
                    printf("Hay diferencias entre la lista y su backup\n");

                }

            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        }
    }
    while(option != 14);
    return 0;
}
