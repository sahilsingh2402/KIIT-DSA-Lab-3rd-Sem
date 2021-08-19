#include <stdio.h>
typedef struct distance_535
{
    int km_535;
    int metre_535;
} distance_535;
distance_535 add_dist_535(distance_535, distance_535);
int main()
{
    distance_535 dist1_535, dist2_535;
    printf("Enter distance1: ");
    scanf("%d%d", &dist1_535.km_535, &dist1_535.metre_535);
    printf("Enter distance 2: ");
    scanf("%d%d", &dist2_535.km_535, &dist2_535.metre_535);
    dist1_535 = add_dist_535(dist1_535, dist2_535);
    printf("The resultant distance is: ");
    printf("%dKm %dM\n", dist1_535.km_535, dist1_535.metre_535);
    return 0;
}
distance_535 add_dist_535(distance_535 dist1_535, distance_535 dist2_535)
{
    dist1_535.km_535 = dist1_535.km_535 + dist2_535.km_535;
    dist1_535.km_535 += (dist1_535.metre_535 + dist2_535.metre_535) / 1000;
    dist1_535.metre_535 = (dist1_535.metre_535 + dist2_535.metre_535) % 1000;
    return dist1_535;
}

