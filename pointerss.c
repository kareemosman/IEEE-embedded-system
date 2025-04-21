
/***hacker rank***/
#include<stdio.h>
void update ( int *a , int *b)
{
   int sum = *a +*b;
   int diff = abs(*a - *b);

   *a = sum;
   *b = diff;

}
  int main ()
  {
      int a,b;
      printf("enter the value of a and b\n");
      scanf("%d %d", &a,&b);

      update(&a,&b);
      printf("%d\n%d", a,b);
      return 0;
  }
----------------------------------------------------------p17------------------------------------------------------------
#include<stdio.h>

int sortAscending(int *num1, int *num2)
{
return *num1-*num2;
}
int sortDescending(int *num1 , int *num2)
{
return *num2-*num1;
}
void sort(int * arr, int size, int (* compare)(int *, int *))
{

for (int i=0; i<size-1 ; i++)
{
    for (int j=i+1; j<size ; j++){

        if(compare(&arr[i],&arr[j])>0){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
  }
}
int main()
{
    int size;
    int i;
    printf("enter the array size :");
    scanf("%d", &size);
    int arr[size];
    printf("enter elements of array ");
    for(i=0;i<size ;i++)
    {
         scanf("%d", &arr[i]);
    }
      sort(arr, size, sortAscending);
    printf("Array in ascending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort in descending order
    sort(arr, size, sortDescending);
    printf("Array in descending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}