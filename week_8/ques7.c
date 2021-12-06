#include <stdio.h>
void tower_of_hanoi_535(int, char, char, char);
int main()
{
    int noOfPegs_535;
    printf("Enter number of pegs: ");
    scanf("%d", &noOfPegs_535);
    char source_535 = 'S';
    char aux_535 = 'A';
    char dest_535 = 'D';
    tower_of_hanoi_535(noOfPegs_535, source_535, dest_535, aux_535);
    return 0;
}
void tower_of_hanoi_535(int noOfPegs_535, char source_535, char dest_535, char aux_535)
{
    if (noOfPegs_535 == 1)
    {
        printf("Peg %d: %c -> %c\n", noOfPegs_535, source_535, dest_535);
        return;
    }
    tower_of_hanoi_535(noOfPegs_535 - 1, source_535, aux_535, dest_535);
    printf("Peg %d: %c -> %c\n", noOfPegs_535, source_535, dest_535);
    tower_of_hanoi_535(noOfPegs_535 - 1, aux_535, dest_535, source_535);
}

