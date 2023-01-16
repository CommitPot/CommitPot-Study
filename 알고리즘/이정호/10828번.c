#include<stdio.h>
#include<string.h>

int stack[10000];
int top = -1;

void size() {
   printf("%d", top + 1);
}

int empty1() {
   if (top <= -1) {
       return 1;
   } else {
       return 0;
   }
}

void top1() {
   if (empty1())
       printf("%d", -1);
   else {
       printf("%d", stack[top]);
   }
}

void push1(int n) {
   stack[++top] = n;
}

int pop1() {
   if (empty1()) {
       return -1;
   } else {
       return stack[top--];
   }
}

int main() {

   int N = 0;
   char stack[10];

   scanf("%d", &N);

   for (int i = 0; i < N; i++) {
       scanf("%s", &stack);

       if (strcmp(stack, "push") == 0) {
           int num;
           scanf("%d", &num);
           push1(num);
       } else if (strcmp(stack, "pop") == 0) {
           printf("%d\n", pop1());
       } else if (strcmp(stack, "top") == 0) {
           top1();
           printf("\n");
       } else if (strcmp(stack, "size") == 0) {
           size();
           printf("\n");
       } else if (strcmp(stack, "empty") == 0) {
           printf("%d\n", empty1());
       }
   }
}

# 백준 스택 10828
