#include<Stdio.h>
#include<stdlib.h>
int main()
{

    char s[1000001];

    scanf("%s", s);


    int i=0;
    int sum = 0;
  //scanf("%d", &num)

    while (s[i] != '\0')

    {
        if(s[i]>='0'&& s[i]<='9')
        {
        sum += s[i] +'0';

    }
    i++;
    }
  printf("%d", sum);



}
---------------------------------------------------PROBLEM G------------------------------------
#include <stdio.h>

int main() {
    char s[100000];
    scanf("%s", s);

    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == ',') {
            s[i] = ' ';
        }
        i++;
    }

    i = 0;

    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        }
        i++;
    }

    printf("%s", s);

    return 0;
}
---------------------------------------------------problem I------------------------------




#include<stdio.h>
int main()
{
    char s[1000];
    scanf("%s", s);
    int i =0;
int  palindrome =1;
    while(s[i] != '\0')
    {
        if(s[i]!=s[strlen(s)-i-1])
        {
            palindrome =0;
            break;
        }
        i++;

    }

if (palindrome==1){
    printf("YES");
}
else
{
    printf("NO");
}
}
--------------------------------------------------problem O----------------------------------------
#include <stdio.h>

int main()
{
    int n;
    char s[10000001];
    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
         {
            if (s[j] > s[j + 1])
             {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("%s\n", s);

    return 0;
}
-------------------------------------------------problem R-------------------------------------------

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char s[n + 1];
    scanf("%s", s);

    double score = 0.0;
    int i = 0;

    while (i < strlen(s)) {
        if (s[i] == 'V') {
            score += 5;
            i++;
        } else if (s[i] == 'W') {
            score += 2;
            i++;
        } else if (s[i] == 'X') {
            int len = strlen(s);
            if (i + 1 < len) {
                for (int j = i + 1; j < len; j++) {
                    s[j] = s[j + 1];
                }
            }
            i++;
        } else if (s[i] == 'Y') {
            int len = strlen(s);
            if (i + 1 < len) {
                char next = s[i + 1];
                for (int j = i + 1; j < len; j++) {
                    s[j] = s[j + 1];
                }
                s[len - 1] = next;
                s[len] = '\0';
            }
            i++;
        } else if (s[i] == 'Z') {
            int len = strlen(s);
            if (i + 1 < len) {
                if (s[i + 1] == 'V') {
                    score /= 5;
                    for (int j = i + 1; j < len; j++) {
                        s[j] = s[j + 1];
                    }
                } else if (s[i + 1] == 'W') {
                    score /= 2;
                    for (int j = i + 1; j < len; j++) {
                        s[j] = s[j + 1];
                    }
                }
            }
            i++;
        } else {
            i++;
        }
    }

    printf("%.0lf", score);
    return 0;
}