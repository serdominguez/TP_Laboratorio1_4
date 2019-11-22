#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int altaEmpleado (LinkedList* lista);
int verificaId (LinkedList* lista, int id);
int modificaEmpleado (LinkedList* lista);
int switchModificaEmpleado (LinkedList* lista, int index);
int menuModificaEmpleado();
int bajaEmpleado (LinkedList* lista);
void listarEmpleados (LinkedList* lista);
void listarEmpleado (LinkedList* lista, int index);
int modificaId(LinkedList* lista,int  index);
int modificaHoras(LinkedList* lista,int  index);
int modificaNombre(LinkedList* lista,int  index);
int modificaSueldo(LinkedList* lista,int  index);
int ordenaPorId(void* id1, void* id2);
int ordenaPorSueldo (void* e1, void* e2);
int ordenaPorHoras (void* e1, void* e2);
int ordenaPorNombre (void* e1, void* e2);
int switchOrdenaEmpleado (LinkedList* lista);
int menuOrdenaEmpleado();

int menu ();

#endif // employee_H_INCLUDED
