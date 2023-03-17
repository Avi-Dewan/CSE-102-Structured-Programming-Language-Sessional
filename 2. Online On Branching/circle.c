#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,r,x,y,z;

    printf("Enter the co-ordinates of the center:\n");
    scanf("%d%d",&a,&b);

    printf("Enter radius:\n");
    scanf("%d",&r);

    printf("Enter the co-ordinates of the point:\n");
    scanf("%d%d",&x,&y);

    z=pow((x-a),2)+pow((y-b),2)-pow(r,2);

    if(z==0){
        printf("On the circle");
    }
    else if(z<0){
        printf("Inside the circle");
    }
    else{
        printf("Outside the circle");
    }



    return 0;
}
