#include<stdlib.h>

typedef  struct elem {
    int value;
    struct elem *next;
    } ElemRec , *Elem;
typedef Elem  Liste;
    
void insert(int v, Liste *list) {
    Elem  newElem = malloc(sizeof(ElemRec));
        newElem ->value = v;
        newElem ->next = NULL;
        
        if(*list == NULL) {
            *list = newElem;
            }
        else{
            Elem  runner = *list;
            while(runner ->next != NULL) {
                    runner = runner ->next;}
                    runner ->next = newElem;
            }
    }
                    
Elem  removeFirst(Liste *list) {
    Liste *temp;
    temp = list;
    *list = (*list)->next; 
    (*temp)->next = NULL;
    return *temp;
    }
void insertCorrect(Elem e, Liste *list) {
    Elem runner = *list;
    while (e->value<runner->value&&runner->next!=NULL ){
        runner= runner->next;
    } 
    //erstes element ist größtes
    
   e->next= runner->next;
   runner->next=e; 
    }
        
void sort(Liste *list){
    Elem runner;
    Liste *temp;
    while(runner->next!=NULL){
        runner= *list;
    while(runner->next->value<runner->value&&runner->next!=NULL )
    {
        runner = runner->next; 

    }
    if (runner->next==NULL){
        return;
    }
    *temp=runner->next;
    insertCorrect(removeFirst(temp),list);
    }
    return;
    }
void main() {
Liste  list = NULL;
insert(5, &list);
insert(4, &list);
insert(7, &list);
insert(3, &list);
insert(2, &list);
/* list  -> 5 -> 4 -> 7 -> 3 -> 2 -> NULL */
sort(&list);
 }