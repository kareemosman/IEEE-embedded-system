/*------------hacker rank 1----------------*/
#include<stdio.h>
int main()
{
    int n,sum=0;
    scanf("%d",&n);
     int *arr = (int*)malloc(n * sizeof(int));
     if (arr== NULL)
     {
         printf("memory allocation failed");

     }
     for (int i =0 ; i <n ; i++)
     {
         scanf("%d",&arr[i]);
         sum+= arr[i];

     }
     printf("%d\n",sum);

}
/*------------hacker rank 2----------------*/


int main() {
    int arr[6][6];
    for (int i = 0; i < 6; i++){
    for (int j = 0; j < 6; j++){
    scanf("%d", &arr[i][j]);}
    }
    int max_sum = -63;

    for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
    int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2]+ arr[i+1][j+1]+ arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (sum > max_sum){
                max_sum = sum;
            }
        }
    }

    printf("%d\n", max_sum);
    return 0;
}
/*------------p1----------------*/

#include <stdio.h>

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Output: ");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }

    return 0;
}
/*------------p3----------------*/

#include <stdio.h>

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int array[size];
    int sum = 0;

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }

    printf("Sum of all elements = %d\n", sum);

    return 0;
}
/*------------p5----------------*/
#include <stdio.h>

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int largest = array[0], secondLargest = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > largest) {
            secondLargest = largest;
            largest = array[i];
        } else if (array[i] > secondLargest && array[i] != largest) {
            secondLargest = array[i];
        }
    }

    printf("Second largest = %d\n", secondLargest);

    return 0;
}
/*------------p8----------------*/
#include <stdio.h>

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int array1[size], array2[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array1[i]);
    }

    for (int i = 0; i < size; i++) {
        array2[i] = array1[i];
    }

    printf("Array1: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array1[i]);
    }

    printf("\nArray2: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array2[i]);
    }

    return 0;
}
/*------------p9----------------*/
#include <stdio.h>

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int array[size + 1];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int element, position;
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position to insert (1 to %d): ", size + 1);
    scanf("%d", &position);

    if (position < 1 || position > size + 1) {
        printf("Error: Invalid position!\n");
        return 1;
    }

    for (int i = size; i >= position; i--) {
        array[i] = array[i - 1];
    }
    array[position - 1] = element;
    size++;

    printf("Elements of array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

/*------------p13----------------*/
#include <stdio.h>

int main() {
    int n, i, j, count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }

    printf("Total number of duplicate elements = %d\n", count);

    return 0;
}

/*------------p15----------------*/
#include <stdio.h>

int main() {
    int size1, size2, i, j, k;

    printf("Enter number of elements in first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter %d elements: ", size1);
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    printf("Enter %d elements: ", size2);
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int mergeSize = size1 + size2;
    int mergeArray[mergeSize];
    i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergeArray[k++] = arr1[i++];
        } else {
            mergeArray[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        mergeArray[k++] = arr1[i++];
    }

    while (j < size2) {
        mergeArray[k++] = arr2[j++];
    }

    printf("Merged array in ascending order: ");
    for (i = 0; i < mergeSize; i++) {
        printf("%d ", mergeArray[i]);
    }
    printf("\n");

    return 0;
}

/*------------p16----------------*/
#include <stdio.h>

int main() {
    int size, i;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements after reverse: ");
    for (i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*------------p19----------------*/
#include <stdio.h>

int main() {
    int size, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array sorted in ascending order: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
 
/*------------p24----------------*/
#include <stdio.h>

int main() {
    int rows, cols, i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols], matrix2[rows][cols], difference[rows][cols];

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    printf("Difference of both matrices:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", difference[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*------------p27----------------*/
#include <stdio.h>

int main() {
    int rows, cols, i, j, isEqual = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols], matrix2[rows][cols];

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                isEqual = 0;
                break;
            }
        }
        if (!isEqual) {
            break;
        }
    }

    if (isEqual) {
        printf("Both matrices are equal\n");
    } else {
        printf("Both matrices are not equal\n");
    }

    return 0;
}

/*------------p30----------------*/
#include <stdio.h>

int main() {
    int rows, cols, i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    printf("Enter elements of matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        int rowSum = 0;
        for (j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, rowSum);
    }

    for (j = 0; j < cols; j++) {
        int colSum = 0;
        for (i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, colSum);
    }

    return 0;
}

/*------------p37----------------*/
#include <stdio.h>

int main() {
    int size, i, j;
    
    printf("Enter the size of the matrix (2 or 3): ");
    scanf("%d", &size);

    if (size != 2 && size != 3) {
        printf("Invalid matrix size! Please enter 2 or 3.\n");
        return 1;
    }

    int matrix[size][size];

    printf("Enter elements of the %dx%d matrix:\n", size, size);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int determinant;
    if (size == 2) {
        determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else {
        determinant = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]))
                    - matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]))
                    + matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));
    }

    printf("Determinant of the matrix = %d\n", determinant);

    return 0;
}

/*------------p40----------------*/
#include <stdio.h>

int main() {
    int size, i, j, isSymmetric = 1;

    printf("Enter the size of square matrix: ");
    scanf("%d", &size);

    int matrix[size][size];

    printf("Enter matrix elements:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    if (isSymmetric) {
        printf("Given matrix is symmetric.\n");
    } else {
        printf("Given matrix is not symmetric.\n");
    }

    return 0;
}
