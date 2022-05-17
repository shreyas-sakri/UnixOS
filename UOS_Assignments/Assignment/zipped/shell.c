#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

int main()

{




char str[100];

printf("Input command\n");

scanf("%[^\n]%*c", str);

printf("Thank you\n");

}

