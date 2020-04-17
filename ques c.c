/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<stdio.h>
#include<pthread.h> 
#include<semaphore.h>
void *fun1(); 
void *fun2();
void *fun3(); 
sem_t s1,s2,s3;
int x = 1;
int main() 
{
printf("Initial Value %d\n",x);
sem_init(&s1,3,1);
sem_init(&s2,3,1);
sem_init(&s3,3,1);
pthread_t t1,t2,t3; pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_create(&t3,NULL,fun3,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
printf("%d\n",x);
}
void *fun1()
{
int x1;
sem_wait(&s1);
sem_wait(&s2);
sem_wait(&s3);
x1 = x; x1++;
x = x1;
printf("%d\n",x);
sem_post(&s1);
sem_post(&s2);
sem_post(&s3);
}
void *fun2()
{
int x2;
sem_wait(&s2);
sem_wait(&s3);
sem_wait(&s1);
x2 = x;
x2--;
x = x2;
printf("%d\n",x);
sem_post(&s2);
sem_post(&s3);
sem_post(&s1);
}
void *fun3()
{
int x3;
sem_wait(&s2);
sem_wait(&s1);
sem_wait(&s3);
x3 = x;
x3++;
x = x3;
printf("%d\n",x);
sem_post(&s2);
sem_post(&s1);
sem_post(&s3);
}