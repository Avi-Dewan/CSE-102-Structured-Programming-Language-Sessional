#include<stdio.h>
int main()
{
    int a1,b1,c1,a2,b2,c2;
    float X,Y,Z;

    printf("Enter the first co-ordinate:\n");
    scanf("%d%d%d",&a1,&b1,&c1);

    printf("Enter the second co-ordinate:\n");
    scanf("%d%d%d",&a2,&b2,&c2);

    Z=a1*b2-b1*a2;

    if(Z==0){
        printf("Does not intersect");
    }
    else{
        X=(b1*c2-b2*c1)/Z;
        Y=(a2*c1-a1*c2)/Z;
        printf("Intersection point: %.3f %.3f",X,Y);
    }
    return 0;

}
