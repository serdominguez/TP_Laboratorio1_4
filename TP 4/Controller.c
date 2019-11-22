#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* f = fopen(path, "r");

    if (f != NULL)
    {
        if (parser_EmployeeFromText(f, pArrayListEmployee))
        {

            todoOk = 1;
        }

    }

    fclose(f);

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* f = fopen(path, "rb");

    if (f != NULL)
    {
        if (parser_EmployeeFromBinary(f, pArrayListEmployee))
        {

            todoOk = 1;
        }

    }

    fclose(f);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    altaEmpleado(pArrayListEmployee);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    modificaEmpleado(pArrayListEmployee);
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    bajaEmpleado(pArrayListEmployee);
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    listarEmpleados(pArrayListEmployee);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    switchOrdenaEmpleado(pArrayListEmployee);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* f = fopen(path, "w");
    Employee* temp = (Employee*) employee_new();

    if (path != NULL && pArrayListEmployee != NULL && f != NULL )
    {
        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");


        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            temp = ll_get(pArrayListEmployee, i);

            fprintf(f, "%d,%s,%d,%d\n", temp->id, temp->nombre, temp->horasTrabajadas, temp->sueldo );


        }
        printf("ARCHIVO GUARDADO CON EXITO\n");
        todoOk = 1;
    } else {
        printf("OCURRIO UN ERROR GUARDANDO EL ARCHIVO\n");
    }


    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    Employee* temp = (Employee*) employee_new();
    FILE* f = fopen(path, "wb");

    if (path != NULL && pArrayListEmployee != NULL && f != NULL && temp != NULL )
    {


        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            temp = ll_get(pArrayListEmployee, i);
            cant = fwrite(temp, sizeof(Employee), 1, f );


            if (cant<1)
            {
                printf("OCURRIO UN ERROR GUARDANDO EL ARCHIVO\n");
                return todoOk;
            }
        }

        todoOk = 1;
        printf("ARCHIVO GUARDADO\n");
    }



    return todoOk;
}

