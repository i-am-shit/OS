#include<stdio.h>
void bsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
            }
        }
    }
    printf("Second smallest ele is :%d",arr[1]);
}
int main()
{
    int arr[]={1,5,4,3,2,8};
    bsort(arr,6);
    return 0;
}
