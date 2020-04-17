/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
 
int main() {
 
   FILE *fp;
   char ch;
   int num;
   long length;
 
   printf("Enter the value of num : ");
   scanf("%d", &num);
 
   fp = fopen("test.txt", "r");
   if (fp == NULL) {
      puts("cannot open this file");
      exit(1);
   }
 
   fseek(fp, 0, SEEK_END);
   length = ftell(fp);
   fseek(fp, (length - num), SEEK_SET);
 
   do {
      ch = fgetc(fp);
      putchar(ch);
   } while (ch != EOF);
 
   fclose(fp);
   return(0);
}