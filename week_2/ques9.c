// 11. Write a C program to create a structure of Employee having data members ID,
// Name, Age, Salary. Create array of structure of employee of size n by dynamic
// memory allocation. Assign pointer to the structure and find the highest salary of the
// employee and avgSalary().

#include <stdio.h>
#include <stdlib.h>

struct employee_535
{
    int id_535, age_535;
    char name_535[100];
    float salary_535;
};

float avgSalary_535(struct employee_535 *a_535, int n_535)
{
    float avgSalary_535 = 0;
    for (int i = 0; i < n_535; i++)
    {
        avgSalary_535 += a_535[i].salary_535;
    }
    avgSalary_535 /= (float)n_535;
    return avgSalary_535;
}

float highSalary_535(struct employee_535 *a_535, int n_535)
{
    float high_535 = -2147483648;
    for (int i = 0; i < n_535; i++)
    {
        if (high_535 < a_535[i].salary_535)
        {
            high_535 = a_535[i].salary_535;
        }
    }
    return high_535;
}

int main()
{
    int n_535;

    printf("Enter number of employees: ");
    scanf("%d", &n_535);
    struct employee_535 *a_535;

    a_535 = (struct employee_535 *)malloc(n_535 * sizeof(struct employee_535));

    for (int i = 0; i < n_535; i++)
    {
        printf("\nEnter employee id: ");
        scanf("%d", &a_535[i].id_535);

        printf("Enter employee name: ");
        getchar();
        fgets(a_535[i].name_535, 100, stdin);

        printf("Enter employee age: ");
        scanf(" %d", &a_535[i].age_535);

        printf("Enter employee salary: ");
        scanf("%f", &a_535[i].salary_535);
    }

    printf("Average Salary: %0.2f\n", avgSalary_535(a_535, n_535));
    printf("Highest Salary: %0.2f\n", highSalary_535(a_535, n_535));
    return 0;
}