#include<stdio.h>
#include "../DataStructures/Queue.h"

int main() {

    struct Queue queue = queue_constructor();

    printf("queue succesfully constructed\n");
    for(int i = 0; i < 10; i++){
        char x[3] = {'a' + i , 'a' + 1 + i , 'a' + 2 + i } ;
        queue.push(&queue,&x,Char,3);
    }

    int end_of_loop = queue.list.length;
    for(int i = 0 ; i < end_of_loop; i++) {
        printf("%d. = %s\n",i,(char *)queue.peek(&queue));
        queue.pop(&queue);
    }
    printf("queue read successfully\n");
} 
