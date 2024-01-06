#include<stdio.h>
#include "../DataStructures/LinkedList.h"

int main() {

    struct LinkedList list = linked_list_constructor();

    printf("linked list succesfully constructed\n");
    for(int i = 0; i < 10; i++){
        list.insert(i, IntToListData(i), &list);
        
        printf("list = %d , i = %d\n",*(int*)list.retreive(i , &list),i);
    }
   
    printf("list made successfully\n");
    list.remove(0 , &list);
    list.remove(3 , &list);
    list.remove(7 , &list);
    list.insert(1, IntToListData(99) , &list);
    printf("list edited successfully\n");

    for(int i = 0; i < list.length; i++) {
        printf("%d\n",*(int*)list.retreive(i , &list));
    }

    printf("list read successfully\n");
    //list.retreive(100 , &list);
} 
