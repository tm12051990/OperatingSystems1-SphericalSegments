#include <stdio.h>
#include <math.h>

const double pi = 3.14159265359;

int i;
int n;

double R;
double h_a;
double h_b;

double a;
double b;
double h;

double topSA;
double bottomSA;
double lateralSA;
double totalSA;
double volume;

double avgSA;
double avgVol;
double volumeSum;
double tsaSum;


int main(void) {

    /* n must be between 2 and 10 inclusive, continue to ask until valid */    
    do {

        printf("Please provide the number of spherical segments you wish to evaluate between 2 and 10: ");
        scanf("%d", &n);

        if (n < 2 || n > 10) {
            printf("Invalid input. Please enter a number between 2 and 10.\n");
        }
    } while (n < 2 || n > 10);

/* Process valid input segments */

    for (i = 1; i <= n; i++) {
        do
        {
            printf("Obtaining data for spherical segment: %d", i);
            printf("\nPlease enter sphere radius: ");
            scanf("%lf", &R);

            printf("\nPlease enter the top height of the sphere segment: ");
            scanf("%lf", &h_a);

            printf("\nPlease enter the bottom height of the sphere segment: ");
            scanf("%lf", &h_b);

            if (R <= 0 || h_a <= 0 || h_b <= 0 || h_a > R || h_b > R || h_a < h_b) {
                printf("\nInput invalid. \n");
                printf("Radius, top height, and bottom height must be positive. \n");
                printf("Top height and bottom height must be less than or equal to the radius. \n");
                printf("Top height must be greater than or equal to the bottom height. \n");
            }
        } while (R <= 0 || h_a <= 0 || h_b <= 0 || h_a > R || h_b > R || h_a < h_b);

        /* Computations */

        a = sqrt((R * R) - (h_a * h_a));
        b = sqrt((R * R) - (h_b * h_b));
        h = h_a - h_b;
        topSA = pi * (a * a);
        bottomSA = pi * (b * b);
        lateralSA = 2 * pi * R * h;
        totalSA = topSA + bottomSA + lateralSA;
        volume = (1.0 / 6.0) * pi * h * (3 * a * a + 3 * b * b + h * h); 
        
        /* Print results for the current segment */

        printf("Computed values for the segment %d: \n", i);
        printf("Top radius (a)       = %.2f\n", a);
        printf("Bottom radius (b)    = %.2f\n", b);
        printf("Segment height (h)   = %.2f\n", h);
        printf("Top Surface Area     = %.2f\n", topSA);
        printf("Bottom Surface Area  = %.2f\n", bottomSA);
        printf("Lateral surface area = %.2f\n", lateralSA);
        printf("Total surface area   = %.2f\n", totalSA);
        printf("Volume               = %.2f\n", volume);

        tsaSum += totalSA;
        volumeSum += volume;
    }
    tsaSum = totalSA / n;
    volumeSum = volume / n;

    printf("\nAverages across %d segments: \n", n);
    printf("Average Surface Area: %.2f\n", avgSA);
    printf("Average Volume: %.2f\n", avgVol);

    return 0;
}

