#include <stdio.h>
#include <string.h>
#include <math.h>



void trim(char a[]) {
    int j = 0, i = 0;
    while(a[i] != '\0') {
        if(a[i] != ' ') i++;
        j++;
        a[i] = a[j];
    }
}

int findN(char x[]) {
    int l = strlen(x);
    int a = 0;
    for(int i = 2; i < l; i++) {
        a += (x[i] - '0') * pow(10, l - 1 - i);
    }

    return a;
}

void inputMatrix( int r, int c, int a[][c]) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    getchar();  //
}

void outputMatrix( int r, int c,int a[][c]) {
     for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            printf("%d ", a[i][j]);

        printf("\n");
     }
}

void addMatrix(int rA, int cA, int rB, int cB, int a[][cA], int b[][cB]) {
    if(rA == 0 || cA == 0) {
        printf("no A matrix found\n");
        return;
    }
    if(rB == 0 || cB == 0) {
        printf("no B matrix found\n");
        return;
    }
    if(rA != rB || cA != cB) {
        printf("Addition not possible\n");
        return ;
    }
    for(int i = 0; i < rA; i++) {
        for(int j = 0; j < cA; j++)
            printf("%d ", a[i][j]+b[i][j]);
        printf("\n");
    }
    return;

}

void subMatrix(int rA, int cA, int rB, int cB, int a[][cA], int b[][cB]) {
    if(rA == 0 || cA == 0) {
        printf("no A matrix found\n");
        return;
    }
    if(rB == 0 || cB == 0) {
        printf("no B matrix found\n");
        return;
    }
    if(rA != rB || cA != cB) {
        printf("Subtraction not possible\n");
        return ;
    }
    for(int i = 0; i < rA; i++) {
        for(int j = 0; j < cA; j++)
            printf("%d ", a[i][j]-b[i][j]);
        printf("\n");
    }
    return;

}

void multiMatrix(int rA, int cA, int rB, int cB, int a[][cA], int b[][cB]) {
    if(rA == 0 || cA == 0) {
        printf("no A matrix found\n");
        return;
    }
    if(rB == 0 || cB == 0) {
        printf("no B matrix found\n");
        return;
    }
    if(cA != rB) {
        printf("Multiplication not possible\n");
        return ;
    }
    for(int i = 0; i < rA; i++) {
        for(int j = 0; j < cB; j++) {
            int multi = 0;
            for(int k = 0; k < rB; k++) {
                multi += a[i][k] * b[k][j];
            }

            printf("%d ", multi);
        }
        printf("\n");
    }

}

void devideMatrix(int rA, int cA, int n, int A[][cA]) {
    for(int i = 0; i < rA; i++) {
        for(int j = 0; j < cA; j++) {
            double x = (A[i][j]*1.0/n);
            int y = x;

            y == x? printf("%d ", y) : printf("%.1lf ", x);
        }
        printf("\n");
    }

}

void transMatrix(int rA, int cA, int A[][cA]) {
    if(rA != cA) {
        printf("Transformation not possible\n");
        return;
    }

    for(int i = 0; i < cA; i++) {
        for(int j = 0; j < rA; j++) {
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }

}

int determinant(int A[][5], int n) {
    if(n == 1) {
        return A[0][0];
    }
    int temp[5][5] = {0};

    int det = 0;

    int s = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 1, k = 0; j < n; j++, k++) {
                for(int x = 0, y = 0; x < n; x++) {
                    if(x != i) {
                        temp[k][y] = A[j][x];
                        y++;
                    }
                }


            }

        det += s*A[0][i]*determinant(temp, n-1);
        s = -s;
    }

    return det;
}



int  main()
{
    char input[30] = {0};
    int A[5][5] = {0}, B[5][5] = {0};

    int rA = 0, cA = 0, rB = 0, cB = 0;
    int i = 0;
    while(1) {

        gets(input);

        strlwr(input);
        trim(input);

        if(strcmp(input, "exit") == 0) break;

        else if(!strcmp(input, "ina")) {

                scanf("%d%d", &rA, &cA);
                inputMatrix(rA, cA, A);

        } else if(!strcmp(input, "inb")) {

                 scanf("%d%d", &rB, &cB);
                 inputMatrix(rB, cB, B);

        } else if(!strcmp(input, "outa")) {

                if(rA == 0 || cA == 0)
                    printf("No A matrix found\n");
                else
                    outputMatrix( rA, cA, A);

        } else if(!strcmp(input, "outb")) {

                if(rB == 0 || cB == 0)
                    printf("No B matrix found\n");
                else
                    outputMatrix( rB, cB, B);

        } else if(!strcmp(input,"a+b") || !strcmp(input, "b+a"))  {

            addMatrix(rA, cA, rB, cB, A, B);

        } else if(!strcmp(input,"a-b")) {

            subMatrix(rA, cA, rB, cB, A, B);

        } else if(!strcmp(input,"b-a")) {

            subMatrix(rB, cB, rA, cA, B, A);

        } else if(!strcmp(input,"a*b")) {

            multiMatrix(rA, cA, rB, cB, A, B);

        } else if(!strcmp(input,"b*a")) {

            multiMatrix(rB, cB, rA, cA, B, A);

        } else if(!strncmp(input, "a/", 2)) {

             int n = findN(input);
              if(rA == 0 || cA == 0)
                    printf("No A matrix found\n");
                else
                    devideMatrix(rA, cA, n, A);
        } else if(!strncmp(input, "b/", 2)) {

            int n = findN(input);

            if(rB == 0 || cB == 0)
                    printf("No B matrix found\n");
            else
                    devideMatrix(rB, cB, n, B);

        } else if(!strcmp(input,"deta")) {
            if(rA == 0 || cA == 0) {
                printf("No A matrix found\n");
            } else if( rA != cA) {
                printf("A is not a square matrix.\n");
            } else {
                 printf("%d\n", determinant(A, rA) );
            }


        } else if(!strcmp(input,"detb")) {
            if(rB == 0 || cB == 0) {
                printf("No B matrix found\n");
            } else if( rB != cB) {
                printf("B is not a square matrix.\n");
            } else {
                 printf("%d\n",determinant(B, rB));
            }
        }  else if(!strcmp(input,"transa")) {
            if(rA == 0 || cA == 0)
                    printf("No A matrix found\n");
                else
                    transMatrix(rA, cA, A);

        } else if(!strcmp(input,"transb")) {
            if(rB == 0 || cB == 0)
                    printf("No B matrix found\n");
                else
                    transMatrix(rB, cB, B);

        } else {
            printf("Incorrect input\n");
        }

    }

    return 0;
}
