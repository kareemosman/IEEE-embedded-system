/*-------------P5-----------------*/

#include <stdio.h>
int main ()
{
    int size= 10;
    int arr1[] ={ 10 , -1,  100 , 90 , 87 , 0,  15,  10 ,  20,  30};
    int arr2[size];

    int * ptr1= arr1; // pointer to array one
    int * ptr2 = arr2; // pointer to array two

    for ( int  i = 0 ; i < size ; i++ )
    {
     *( ptr2 + i) = *( ptr1 +i);
    }

printf (" the array after copied is : ");
 for ( int i = 0 ; i< size ; i++ )
 {
      printf(" %d " , arr2[i]);
 }
 return 0;
}

//------------------- p6--------------------//

#include <stdio.h>

// Function to swap corresponding elements of two arrays
void swapTwoArrays(int *arr1, int *arr2, int size1, int size2) {
    int limit = (size1 < size2) ? size1 : size2;

    for (int i = 0; i < limit; i++) {
        int temp = *(arr1 + i);  // Temporary variable for swap
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;
    }
}

int main() {
    int arr1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arr2[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);


    printf("First array before swapping: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\nSecond array before swapping: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }


    swapTwoArrays(arr1, arr2, size1, size2);


    printf("\n\nFirst array after swapping: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\nSecond array after swapping: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }

    return 0;
}

//-------------------------p7-------------------------//
#include <stdio.h>

void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {

        int temp = *(arr + i);                 // Access the element at index i
        *(arr + i) = *(arr + size - i - 1);    // Access the element at the mirrored position
        *(arr + size - i - 1) = temp;          // Perform the swap
    }
}

int main() {
    int size;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse the array
    reverseArray(arr, size);

    // Print the reversed array
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
//-------------------------p8-------------------------//
#include <stdio.h>

void searchElement(int *arr, int size, int target) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (*(arr + i) == target) {
            found = 1;
            printf("%d exists in the array at position %d.\n", target, i + 1);
            break;
        }
    }

    if (!found) {
        printf("%d does not exist in the array.\n", target);
    }
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    searchElement(arr, size, target);

    return 0;
}

//-------------------------p11-------------------------//
#include <stdio.h>

void multiplyMatrices(int *mat1, int *mat2, int *result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(result + i * c2 + j) = 0;
            for (int k = 0; k < c1; k++) {
                *(result + i * c2 + j) += *(mat1 + i * c1 + k) * *(mat2 + k * c2 + j);
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input the dimensions of the matrices
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication is not possible. Number of columns of first matrix must equal number of rows of second matrix.\n");
        return 0;
    }

    int mat1[r1][c1], mat2[r2][c2], result[r1][c2];

    // Input elements of the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input elements of the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Multiply the matrices
    multiplyMatrices(&mat1[0][0], &mat2[0][0], &result[0][0], r1, c1, c2);

    // Print the resulting matrix
    printf("Product of matrices is:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//-------------------------p12-------------------------//
#include <stdio.h>

#include <stdio.h>
#include <string.h>

int findLength(char *str) {
    int length = 0;
    while (*(str + length) != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int length1 = findLength(str);
    int length2 = strlen(str) - 1;
    printf("Length of string (without strlen): %d\n", length1 - 1);
    printf("Length of string (using strlen): %d\n", length2);
    return 0;
}
//-------------------------p14-------------------------//
#include <stdio.h>
#include <string.h>

void concatenateStrings(char *str1, char *str2, char *result) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    concatenateStrings(str1, str2, result);
    printf("Concatenated string (without strcat): %s\n", result);
    strcpy(result, str1);
    strcat(result, str2);
    printf("Concatenated string (using strcat): %s\n", result);
    return 0;
}

//-------------------------p16-------------------------//
#include <stdio.h>

void reverse(char *str)
 {
    char * end = str;
    char temp;


    while (*end)
        end++;
    end--;


    while (str < end) {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    reverse(str);

    printf("Reversed String: %s\n", str);
    return 0;
}
