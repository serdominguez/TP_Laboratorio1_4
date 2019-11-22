#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Employee.h"
#include "LinkedList.h"
#include "valida.h"


/** \brief Reserva espacion en memoria para un Employee
 *
 * \return Employee* puntero al nuevo empleado
 *
 */
Employee* employee_new() {

    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

    if (newEmployee != NULL) {

        newEmployee->id = 0;
        strcpy(newEmployee->nombre," ");
        newEmployee->sueldo = 0;
        newEmployee->horasTrabajadas = 0;

    }

    return newEmployee;

}

/** \brief recibe datos como string, los convierte al tipo correcto y los carga en un nuevo Employee
 *
 * \param idStr char* id epleado
 * \param nombreStr char* nomnre emplead
 * \param horasTrabajadasStr char* horas trabajadas
 * \param sueldoStr char* sueldo empleado
 * \return Employee* puntero al nuevo empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr) {

    Employee* nuevo = employee_new();

    if (nuevo != NULL) {

        employee_setId(nuevo, atoi(idStr));
        employee_setNombre(nuevo, nombreStr);
        employee_setHorasTrabajadas(nuevo, atoi(horasTrabajadasStr));
        employee_setSueldo(nuevo, atoi(sueldoStr));

    }

    return nuevo;
}


/** \brief carga Id del Employee
 *
 * \param this Employee* puntero al Employee
 * \param id int id del empleado
 * \return int
 *
 */
int employee_setId(Employee* this,int id) {

    int todoOk = 0;

    if (this != NULL) {

        this->id = id;
        todoOk = 1;

    }

    return todoOk;

}

/** \brief carga el nombre del Employee
 *
 * \param this Employee* puntero al employee
 * \param nombre char* nombre del empleado
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre) {

    int todoOk = 0;

    if (this != NULL) {

        strcpy(this->nombre, nombre);
        todoOk = 1;

    }

    return todoOk;

}

/** \brief carga las horas trabajadas del employee
 *
 * \param this Employee*  puntero al employee
 * \param horasTrabajadas int cantidad de horas
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas) {

    int todoOk = 0;

    if (this != NULL) {

        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;

    }

    return todoOk;



}

/** \brief carga el sueldo del Employee
 *
 * \param this Employee* puntero al employee
 * \param sueldo int sueldo del empleado
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo) {

    int todoOk = 0;

    if (this != NULL) {

        this->sueldo = sueldo;
        todoOk = 1;

    }

    return todoOk;


}

/** \brief Carga el Id de un employee en una variable
 *
 * \param this Employee* puntero al employee
 * \param id int* puntero a la variable
 * \return int
 *
 */
int employee_getId(Employee* this,int* id) {

    int todoOk = 0;

    if (this != NULL && id !=NULL) {

        *id = this->id;
        todoOk = 1;


    }

    return todoOk;

}

/** \brief Carga el sueldo de un employee en una variable
 *
 * \param this Employee* puntero al employee
 * \param sueldo int* puntero a la variable
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo) {

    int todoOk = 0;

    if (this != NULL && sueldo !=NULL) {

        *sueldo = this->sueldo;
        todoOk = 1;


    }

    return todoOk;

}

/** \brief Carga las horas trabajadas de un employee en una variable
 *
 * \param this Employee* puntero al employee
 * \param horas int* puntero a la variable
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horas) {

    int todoOk = 0;

    if (this != NULL && horas !=NULL) {

        *horas = this->horasTrabajadas;
        todoOk = 1;


    }

    return todoOk;

}

/** \brief Carga las horas trabajadas de un employee en una variable
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre) {

    int todoOk = 0;

    if (this != NULL && nombre !=NULL) {

        strcpy(nombre,this->nombre );
        todoOk = 1;


    }

    return todoOk;

}


void employee_delete(Employee* this) {

    free(this);

}


/** \brief Da de alta un nuevo empleado a la lista
 *
 * \param lista LinkedList* lista donde se cargara el nuevo empleado
 * \return  int
 *
 */
int altaEmpleado (LinkedList* lista)
{
    int todoOk =0;
    int id;

    Employee* temporal = (Employee*) employee_new();

    system("cls");
    printf("***** ALTA EMPLEADO *****\n");



    validaInt("Ingrese ID: ", "ERROR, EL ID DEBE SER NUMERICO\nIngrese ID: ",0 , &id);

    if (verificaId(lista, id))
    {

        temporal->id = id;

        //printf("Ingrese nombre: ");
        //fflush(stdin);
        //gets(temporal->nombre);
        validaString("Ingrese nombre: ", "ERROR, el nombre no acepta numeros ni puede superar los 128 caracteres\nIngrese nombre: ", 128, temporal->nombre);
        poneMayuscula(temporal->nombre);

       // printf("ingrese horas trabajadas: ");
       // scanf("%d",&temporal->horasTrabajadas);
        validaInt("Ingrese horas trabajadas: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese horas trabajadas: ",0, &temporal->horasTrabajadas);


      //  printf("ingrese sueldo: ");
       // scanf("%d",&temporal->sueldo);
        validaInt("ingrese sueldo: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\ningrese sueldo: ",0, &temporal->sueldo);

        if (ll_add(lista, temporal) == 0)
        {
            todoOk = 1;
            printf("ALTA EXITOSA\n");
        }

    }
    else
    {
        printf("ID DUPLICADA\n");

    }


    if (!todoOk) {
        employee_delete(temporal);
    }



    return todoOk;
}


/** \brief Verfica si un ID esta en la lista
 *
 * \param lista LinkedList* Lista a recorrer
 * \param id int id a buscar
 * \return int
 *
 */
int verificaId (LinkedList* lista, int id)
{

    int todoOk = 1;

    Employee* temporal = (Employee*) employee_new();

    if (temporal != NULL)
    {

        for (int i=0; i<ll_len(lista); i++)
        {
            temporal = ll_get(lista, i);

            if (temporal->id == id)
            {
                todoOk = 0;
                break;
            }

        }

    }

    return todoOk;
}

/** \brief Pide id del empleado y muestra menu para modificar sus datos
 *
 * \param lista LinkedList* lista donde se buscara el empleado
 * \return int
 *
 */
int modificaEmpleado (LinkedList* lista)
{
    int todoOk = 0;
    int id;
    int index;
    int flag = 0;
    char respuesta;
    Employee* temporal = (Employee*) employee_new();

    if (lista != NULL && temporal !=NULL)
    {
        system("cls");
        printf("**** MODIFICACION DE EMPLEADO ****\n");

        do
        {
            validaInt("Seleccione Id para dar de baja o ingrese 0 para ver lista completa: ",
                      "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nSeleccione Id para dar de baja o ingrese 0 para ver lista completa: ", 0, &id );

            if (id == 0)
            {
                listarEmpleados(lista);
            }
            else
            {
                for (int i=0; i<ll_len(lista); i++)
                {
                    temporal = ll_get(lista, i);
                    if (temporal->id == id)
                    {
                        index = i;
                        flag = 1;
                        break;
                    }

                }
                if (flag)
                {
                    system("cls");
                    printf("Se va a modificar a: \n");
                    printf("  ID        NOMBRE  HORAS TRABAJADAS  SUELDO\n");
                    listarEmpleado(lista, index);
                    printf("\n\nEs correcto (s/n)? ");
                    fflush(stdin);
                    respuesta = getchar();
                    respuesta = tolower(respuesta);

                    if (respuesta == 's')
                    {
                        if (switchModificaEmpleado(lista, index))
                        {
                            todoOk = 1;
                        }
                    }
                    else if (respuesta != 's')
                    {
                        printf("Modificacion cancelada\n");
                    }

                    break;
                }
                else
                {

                    printf("El ID no corresponde a ningun empleado activo \n");
                    break;

                }

            }


        }
        while (flag == 0);

    }

    return todoOk;

}


/** \brief Llama la funcion que modifica el parametro seleccionado para un empleado de la lista
 *
 * \param lista LinkedList* lista donde se encuentra el empleado
 * \param index int indice de la lista en que se encuentra
 * \return int
 *
 */
int switchModificaEmpleado (LinkedList* lista, int index)
{

    int opcion;


    do
    {
        opcion = menuModificaEmpleado();
        switch(opcion)
        {
        case 1:
            modificaId(lista, index);
            system("pause");
            break;

        case 2:
            modificaNombre(lista, index);
            system("pause");
            break;

        case 3:
            modificaHoras(lista, index);
            system("pause");
            break;

        case 4:
            modificaSueldo(lista, index);
            system("pause");
            break;
        }
    }
    while(opcion != 5);

    return opcion;
}

/** \brief Muestra menu de opciones
 *
 * \return int el numero de opcion seleccionado
 *
 */
int menuModificaEmpleado()
{

    int opcion;

    system("cls");
    printf("**** MODIFICACION DE EMPLEADO ****\n\n");
    printf("1. Modificar ID.\n");
    printf("2. Modificar Nombre.\n");
    printf("3. Modificar Horas trabajadas.\n");
    printf("4. Modificar Sueldo.\n");
    printf("5. Salir\n");

    validaInt("Elija opcion: ", "DATO INVALIDO.\nElija opcion: ", 0, &opcion);


    return opcion;
}

/** \brief Modifica el ID de un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */
int modificaId(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int id;


    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {

        validaInt("Ingrese nuevo ID: ", "ERROR, EL ID DEBE SER NUMERICO\nIngrese nuevo ID: ",0, &id);


        if (verificaId(lista, id))
        {

            printf("Se modifico el ID %d por %d\n", temporal->id, id);
            temporal->id = id;
            todoOk = 1;

        }
        else
        {

            printf("ID DUPLICADA\n");

        }

    }
    else
    {

        printf("No se pudo modificar el ID");

    }


    return todoOk;
}



/** \brief Modifica el nombre de un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */
int modificaNombre(LinkedList* lista,int  index)
{

    int todoOk = 0;
    char nombre[128];

    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
        //  printf("Ingrese nuevo nombre: ");
        //  fflush(stdin);
        //  gets(nombre);

        validaString("Ingrese nuevo nombre: ", "ERROR, el nombre no acepta numeros ni puede superar los 128 caracteres\nIngrese nuevo nombre: ", 128, nombre);

        poneMayuscula(nombre);

        printf("Se modifico el nombre %s por %s\n", temporal->nombre, nombre);
        strcpy(temporal->nombre, nombre);
        todoOk = 1;

    }
    else
    {

        printf("No se pudo modificar el nombre");

    }


    return todoOk;
}

/** \brief Modifica las horas trabajadas por un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */
int modificaHoras(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int horas;

    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
        // printf("Ingrese nueva cantidad de horas trabajdas: ");
        // scanf("%d", &horas);

        validaInt("Ingrese nueva cantidad de horas trabajdas: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese nueva cantidad de horas trabajdas: ",
                  0, &horas);

        printf("Se modificaron las %d horas trabajadas por %d\n", temporal->horasTrabajadas, horas);
        temporal->horasTrabajadas = horas;
        todoOk = 1;

    }
    else
    {

        printf("No se pudo modificar las horas trabajadas");

    }


    return todoOk;
}

/** \brief Modifica el sueldo de un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */
int modificaSueldo(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int sueldo;

    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
        //   printf("Ingrese nuevo sueldo: ");
        //    scanf("%d", &sueldo);
        validaInt("Ingrese nuevo sueldo: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese nuevo sueldo: ",0, &sueldo);

        printf("Se modifico el sueldo %d por %d\n", temporal->sueldo, sueldo);
        temporal->sueldo = sueldo;
        todoOk = 1;

    }
    else
    {

        printf("No se pudo modificar el sueldo");

    }


    return todoOk;
}


/** \brief Borra un elemento de la lista por ID
 *
 * \param lista LinkedList* lista que se editara
 * \return int
 *
 */
int bajaEmpleado(LinkedList* lista)
{
    int todoOk = 0;
    int id;
    int index;
    int flag = 0;
    char respuesta;
    Employee* temporal = (Employee*) employee_new();

    if (lista != NULL)
    {
        system("cls");
        printf("**** BAJA DE EMPLEADO ****\n");

        do
        {
            //  printf("seleccion Id para dar de baja o ingrese 0 para ver lista completa: ");
            //  scanf("%d", &id );
            validaInt("Seleccione Id para dar de baja o ingrese 0 para ver lista completa: ",
                      "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nSeleccione Id para dar de baja o ingrese 0 para ver lista completa: ", 0, &id );

            if (id == 0)
            {
                listarEmpleados(lista);
            }
            else
            {
                for (int i=0; i<ll_len(lista); i++)
                {
                    temporal = ll_get(lista, i);
                    if (temporal->id == id)
                    {
                        index = i;
                        flag = 1;
                        break;
                    }



                }

                if (flag)
                {
                    system("cls");
                    printf("Se va a dar de baja a: \n");
                    printf("  ID        NOMBRE  HORAS TRABAJADAS  SUELDO\n");
                    listarEmpleado(lista, index);
                    printf("\n\nEs correcto (s/n)? ");
                    fflush(stdin);
                    respuesta = getchar();
                    respuesta = tolower(respuesta);

                    if (respuesta == 's' && ll_remove(lista, index)==0)
                    {
                        printf("BAJA EXITOSA\n");
                        todoOk = 1;
                    }
                    else if (respuesta != 's')
                    {
                        printf("Baja cancelada\n");
                    }
                    else
                    {
                        printf("error realizando la baja\n");
                    }


                }
                else
                {
                    printf("El ID no corresponde a un empleado activo\n");
                    flag = 1;
                }

            }


        }
        while (flag == 0);



    }


    return todoOk;

}


/** \brief Muestra en pantalla la lista completa
 *
 * \param lista LinkedList* lista que se va a mostrar
 * \return void
 *
 */
void listarEmpleados(LinkedList* lista)
{



    printf("  ID        NOMBRE  HORAS TRABAJADAS  SUELDO\n");

    for (int i=0; i<ll_len(lista); i++)
    {

        listarEmpleado(lista, i);


    }

}

/** \brief Muestra por pantalla un elemento de la lista
 *
 * \param lista LinkedList* lista a mostrar
 * \param index int indice del elemento
 * \return void
 *
 */
void listarEmpleado(LinkedList* lista, int index)
{

    Employee* temp = (Employee*) employee_new();

    temp = ll_get(lista, index);
    printf("%4d  %12s  %8d          %d \n", temp->id, temp->nombre, temp->horasTrabajadas, temp->sueldo);



}


/** \brief Llama a la funcion que ordena la lista segun el criterio seleccionado
 *
 * \param lista LinkedList* lista a ordenar
 * \return int
 *
 */
int switchOrdenaEmpleado(LinkedList* lista)
{

    int opcion;
    int criterio = -1;


    do
    {
        opcion = menuOrdenaEmpleado();
        if (opcion < 5)
        {
            while (criterio != 0 && criterio !=1)
            {
                validaInt("Seleccione 1 para orden ascendente, 0 para orden descendente: ",
                          "ERROR, debe ingresar 1 o 0\nSeleccione 1 para orden ascendente, 0 para orden descendente: ",0, &criterio);
            }
        }

        switch(opcion)
        {
        case 1:
            ll_sort(lista, ordenaPorId, criterio);
           // listarEmpleados(lista);
           // system("pause");
            break;

        case 2:
            ll_sort(lista, ordenaPorNombre, criterio);
          //  listarEmpleados(lista);
          //  system("pause");
            break;

        case 3:
            //horas
            ll_sort(lista, ordenaPorHoras, criterio);
          //  listarEmpleados(lista);
          //  system("pause");
            break;

        case 4:
            //sueldo
            ll_sort(lista, ordenaPorSueldo,criterio);
           // listarEmpleados(lista);
           // system("pause");
            break;
        }
    }
    while(opcion != 5);

    return opcion;
}


/** \brief Muestra menu de opciones
 *
 * \return int numero de opcion seleccionada
 *
 */
int menuOrdenaEmpleado()
{

    int opcion;

    system("cls");
    printf("**** ORDEN DE EMPLEADO ****\n\n");
    printf("1. Ordenar por ID.\n");
    printf("2. Ordenar por Nombre.\n");
    printf("3. Ordenar por Horas trabajadas.\n");
    printf("4. Ordenar por Sueldo.\n");
    printf("5. Salir\n");
    //  printf("Elija ocion: ");
    //  fflush(stdin);
    //  scanf("%d", &opcion);
    validaInt("Elija opcion: ", "DATO INVALIDO.\nElija opcion: ", 0, &opcion);


    return opcion;
}


/** \brief Ordena dos empleados por ID
 *
 * \param e1 void* primer empleado a ordenar
 * \param e2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */
int ordenaPorId(void* e1, void* e2)
{

    int respuesta;
    int id1;
    int id2;

    employee_getId(e1, &id1);
    employee_getId(e2, &id2);


    if (id1 > id2)
    {

        respuesta = 1;

    }
    else if (id1 < id2)
    {

        respuesta = -1;

    }
    else
    {
        respuesta = 0;
    }

    return respuesta;
}

/** \brief Ordena dos empleados por sueldo
 *
 * \param e1 void* primer empleado a ordenar
 * \param e2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */
int ordenaPorSueldo(void* e1, void* e2)
{
    int respuesta;
    int sueldo1;
    int sueldo2;

    employee_getSueldo(e1, &sueldo1);
    employee_getSueldo(e2, &sueldo2);

    if (sueldo1 > sueldo2)
    {

        respuesta = 1;

    }
    else if (sueldo1 < sueldo2)
    {

        respuesta = -1;
    }
    else
    {
        respuesta =0;
    }

    return respuesta;
}

/** \brief Ordena dos empleados por Horas trabajadas
 *
 * \param e1 void* primer empleado a ordenar
 * \param e2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */
int ordenaPorHoras(void* e1, void* e2)
{
    int respuesta;
    int horas1;
    int horas2;

    employee_getHorasTrabajadas(e1,&horas1);
    employee_getHorasTrabajadas(e2,&horas2);

    if (horas1 > horas2)
    {

        respuesta = 1;

    }
    else if (horas1 < horas2)
    {

        respuesta = -1;
    }
    else
    {
        respuesta =0;
    }

    return respuesta;
}

/** \brief Ordena dos empleados por Nombre
 *
 * \param e1 void* primer empleado a ordenar
 * \param e2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */
int ordenaPorNombre(void* e1, void* e2)
{

    int respuesta;
    char nombre1[128];
    char nombre2[128];

    employee_getNombre(e1, nombre1);
    employee_getNombre(e2, nombre2);


    if (strcmp(nombre1, nombre2) > 0)
    {

        respuesta = 1;

    }
    else if (strcmp(nombre1, nombre2) < 0)
    {

        respuesta = -1;

    }
    else
    {

        respuesta =0;
    }

    return respuesta;
}


/** \brief Muestra menu de opciones
 *
 * \return int el numero de opcion seleccionado
 *
 */
int menu()
{

    int opcion;

    system("cls");
    printf("--------------------------------------\n");
    printf("---TRABAJO PRACTICO NRO 4-------------\n");
    printf("--------------------------------------\n");
    printf("--------------------------------------\n");
    printf("-Sergio Dominguez-------LEG: 109290---\n");
    printf("--------------------------------------\n");
    printf("MENU DE OPCIONES:\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Vaciar lista\n");
    printf("11. Backupear lista\n");
    printf("12. Ver lista backup\n");
    printf("13. Comparar lista con backup\n");
    printf("14. Salir\n");

    validaInt("Elija opcion: ", "DATO INVALIDO.\nElija opcion: ", 0, &opcion);

    return opcion;
}
