#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <stdlib.h>

using namespace std;

double corr(double *v1, double *v2, int N)
{
    double S12 = 0, S11 = 0, S22 = 0;
    double m1 = 0, m2 = 0;

    for(int n=0; n<N; n++)
    {
        m1 += v1[n];
        m2 += v2[n];
    }
    m1 /= N;
    m2 /= N;

    for(int n=0; n<N; n++)
    {
        double d1 = v1[n]-m1;
        double d2 = v2[n]-m2;

        S12 += d1*d2;
        S11 += d1*d1;
        S22 += d2*d2;
    }

    return S12/sqrt(S11*S22);
}

double *readFile(const char *filename)
{
    FILE *file;
    int numer_of_elements, i;

    file = fopen(filename, "r");
    fscanf(file, "%d\*c", &numer_of_elements);

    double *values = reinterpret_cast<double *>(malloc(numer_of_elements*sizeof(double)));

    for(i=0; i<numer_of_elements; i++)
    {
        fscanf(file, "%lf\*c", values+i);
    }

    fclose(file);
    return values;
}

int main()
{
    double *BBAS3 = readFile("/home/sandri/Downloads/BVMF/BBAS3.txt");
    double *TELB4 = readFile("/home/sandri/Downloads/BVMF/TELB4.txt");
    double *VALE3 = readFile("/home/sandri/Downloads/BVMF/VALE3.txt");
    double *KROT3 = readFile("/home/sandri/Downloads/BVMF/KROT3.txt");
    double *PETR4 = readFile("/home/sandri/Downloads/BVMF/PETR4.txt");
    double *ABEV3 = readFile("/home/sandri/Downloads/BVMF/ABEV3.txt");

    double GOLL4[] ={32.64,
43.79,
31.91,
27.31,
22.56,
25.65,
26.42,
24.92,
25.45,
21.35,
19.25,
10.61,
10.86,
13.7,
10.12,
13.29,
18.3,
21.35,
19.1,
18.24,
15.19,
14.19,
13.86,
13.57,
11.38,
9.08,
7.42,
7.65,
10.69,
8.61,
9.23,
6.13,
4.51,
4.97,
7.43,
6.37,
6.31,
5.34,
3.4,
2.3,
2.56,
2.74,
2.25,
2.3,
2.41,
3.37,
3.66,
3.48,
3.82,
5.76,
7.1,
7.8,
7.97,
7.55,
9.58,
11.84,
14.99,
14.07,
12.66,
11.1,
14.4};

    double LAME4[] ={18.6,
18.86,
16,
15.72,
15.56,
17.01,
19.67,
20.57,
19.72,
19.77,
18.4,
15.5,
15.3,
18.17,
16.31,
18.16,
19.12,
18.68,
17.12,
16.96,
16.6,
15.11,
17.08,
19.12,
17.86,
15.9,
13.88,
14.33,
18.08,
16.25,
16.65,
16.75,
16.63,
15.58,
19.91,
20.6,
19.45,
19.35,
16.76,
15.2,
15.94,
16.79,
16.82,
15.33,
15.64,
14.54,
14.94,
13.85,
13.05,
13.93,
14.83,
13.65,
14.56,
13.93,
14.22,
13,
14.05,
13.63,
12.01,
11.28,
12.97};

    printf("TELB4 x VALE3 = %lf\n", corr(TELB4, TELB4, 10));
    printf("TELB4 x BBAS3  = %lf\n", corr(TELB4, BBAS3, 10));
    printf("TELB4 x KROT3   = %lf\n", corr(TELB4, KROT3, 10));
    printf("TELB4 x PETR4 = %lf\n", corr(TELB4, PETR4, 10));
    printf("TELB4 x ABEV3 = %lf\n", corr(TELB4, ABEV3, 10));
    printf("TELB4 x GOLL4 = %lf\n", corr(TELB4, GOLL4, 10));
    printf("TELB4 x LAME4 = %lf\n", corr(TELB4, LAME4, 10));

    printf("BBAS3  x VALE3  = %lf\n", corr(BBAS3, BBAS3, 10));
    printf("BBAS3  x TELB4   = %lf\n", corr(BBAS3, TELB4, 10));
    printf("BBAS3  x VALE3  = %lf\n", corr(BBAS3, BBAS3, 10));
    printf("BBAS3  x VALE3  = %lf\n", corr(BBAS3, BBAS3, 10));
    printf("BBAS3  x VALE3  = %lf\n", corr(BBAS3, BBAS3, 10));
    printf("BBAS3  x VALE3  = %lf\n", corr(BBAS3, BBAS3, 10));
    printf("BBAS3  x VALE3  = %lf\n", corr(BBAS3, BBAS3, 10));

    printf("VALE3  x TELB4  = %lf\n", corr(VALE3, TELB4, 10));
    printf("VALE3  x BBAS3  = %lf\n", corr(VALE3, BBAS3, 10));
    printf("VALE3  x KROT3  = %lf\n", corr(VALE3, KROT3, 10));
    printf("VALE3  x PETR4  = %lf\n", corr(VALE3, PETR4, 10));
    printf("VALE3  x ABEV3  = %lf\n", corr(VALE3, ABEV3, 10));
    printf("VALE3  x GOLL4  = %lf\n", corr(VALE3, GOLL4, 10));
    printf("VALE3  x LAME4  = %lf\n", corr(VALE3, LAME4, 10));

    printf("KROT3  x TELB4  = %lf\n", corr(KROT3, TELB4, 10));
    printf("KROT3  x BBAS3  = %lf\n", corr(KROT3, BBAS3, 10));
    printf("KROT3  x VALE3  = %lf\n", corr(KROT3, VALE3, 10));
    printf("KROT3  x PETR4  = %lf\n", corr(KROT3, PETR4, 10));
    printf("KROT3  x ABEV3  = %lf\n", corr(KROT3, ABEV3, 10));
    printf("KROT3 x GOLL4  = %lf\n", corr(KROT3, GOLL4, 10));
    printf("KROT3  x LAME4  = %lf\n", corr(KROT3, LAME4, 10));

    printf("PETR4  x TELB4  = %lf\n", corr(PETR4, TELB4, 10));
    printf("PETR4  x BBAS3  = %lf\n", corr(PETR4, BBAS3, 10));
    printf("PETR4  x VALE3  = %lf\n", corr(PETR4, VALE3, 10));
    printf("PETR4  x KROT3  = %lf\n", corr(PETR4, KROT3, 10));
    printf("PETR4  x ABEV3  = %lf\n", corr(PETR4, ABEV3, 10));
    printf("PETR4  x GOLL4  = %lf\n", corr(PETR4, GOLL4, 10));
    printf("PETR4  x LAME4  = %lf\n", corr(PETR4, LAME4, 10));

    printf("ABEV3  x TELB4  = %lf\n", corr(BBAS3, TELB4, 10));
    printf("ABEV3  x BBAS3  = %lf\n", corr(BBAS3, BBAS3, 10));
    printf("ABEV3  x VALE3  = %lf\n", corr(BBAS3, VALE3, 10));
    printf("ABEV3  x KROT3  = %lf\n", corr(BBAS3, KROT3, 10));
    printf("ABEV3  x PETR4  = %lf\n", corr(BBAS3, PETR4, 10));
    printf("ABEV3  x GOLL4  = %lf\n", corr(BBAS3, GOLL4, 10));
    printf("ABEV3  x LAME4  = %lf\n", corr(BBAS3, LAME4, 10));

    printf("GOLL4  x TELB4  = %lf\n", corr(BBAS3, TELB4, 10));
    printf("GOLL4  x BBAS3  = %lf\n", corr(BBAS3, BBAS3, 10));
    printf("GOLL4  x VALE3  = %lf\n", corr(BBAS3, VALE3, 10));
    printf("GOLL4  x KROT3  = %lf\n", corr(BBAS3, KROT3, 10));
    printf("GOLL4  x PETR4  = %lf\n", corr(BBAS3, PETR4, 10));
    printf("GOLL4  x LAME4  = %lf\n", corr(BBAS3, LAME4, 10));
    printf("GOLL4  x ABEV3  = %lf\n", corr(BBAS3, ABEV3, 10));

    printf("LAME4  x TELB4  = %lf\n", corr(BBAS3, TELB4, 10));
    printf("LAME4  x BBAS3  = %lf\n", corr(BBAS3, BBAS3, 10));
    printf("LAME4  x VALE3  = %lf\n", corr(BBAS3, VALE3, 10));
    printf("LAME4  x KROT3  = %lf\n", corr(BBAS3, KROT3, 10));
    printf("LAME4  x GOLL4  = %lf\n", corr(BBAS3, GOLL4, 10));
    printf("LAME4  x PETR4  = %lf\n", corr(BBAS3, PETR4, 10));
    printf("LAME4  x ABEV3  = %lf\n", corr(BBAS3, ABEV3, 10));

    free(BBAS3);
    free(TELB4);
    free(VALE3);
    free(KROT3);
    free(PETR4);
    free(ABEV3);
}
