#include <stdio.h>
#include <stdlib.h>
typedef struct employee_535
{
    char name_535[50];
    char gender_535;
    char desig_535[50];
    char dep_535[50];
    float basic_pay_535;
    float gross_pay_535;
} employee_535;
void output_535(employee_535);
void input_535(employee_535 *);
int main()
{
    int size_535;
    printf("Enter the number of employees: ");
    scanf("%d", &size_535);
    employee_535 *E1_535 = (employee_535 *)malloc(size_535 * sizeof(employee_535));
    for (int i = 0; i < size_535; i++)
    {
        printf("\nEmployee number (%d):\n", i + 1);
        input_535(&E1_535[i]);
    }
    printf("\n");
    for (int i = 0; i < size_535; i++)
    {
        printf("Sl.No.:%d ", i + 1);
        output_535(E1_535[i]);
    }
    free(E1_535);
    return 0;
}
void output_535(employee_535 e1_535)
{
    printf("%s\t", e1_535.name_535);
    printf("%c\t", e1_535.gender_535);
    printf("%s\t", e1_535.desig_535);
    printf("%s\t", e1_535.dep_535);
    printf("%0.2f\t", e1_535.basic_pay_535);
    printf("%0.2f\n", e1_535.gross_pay_535);
}
void input_535(employee_535 *e1_535)
{
    printf("Enter Name: ");
    scanf(" %[^\n]s", (*e1_535).name_535);
    printf("Enter Gender: ");
    scanf(" %c", &(*e1_535).gender_535);
    printf("Enter designation: ");
    scanf(" %[^\n]s", (*e1_535).desig_535);
    printf("Enter department: ");
    scanf(" %[^\n]s", (*e1_535).dep_535);
    printf("Enter basic pay: ");
    scanf(" %f", &(*e1_535).basic_pay_535);
    float DA = 75 * e1_535->basic_pay_535;
    float HRA = 25 * e1_535->basic_pay_535;
    e1_535->gross_pay_535 = e1_535->basic_pay_535 + DA + HRA;
}
