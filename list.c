#include "list.h"
#include <stdlib.h>
#include <string.h>

static void strlist_freeelem(StrListValue *elem) {
    if(elem != NULL) {
        free(elem->value);
        free(elem);
    }
}

StrList *strlist_create() {
    StrList *list = (StrList*)malloc(sizeof(StrList));
    list->first = list->last = NULL;
    return list;
}

void strlist_push_front(StrList *list, char *value, size_t size) {
    char* buf = (char*)malloc(size);
    memcpy(buf, value, size);

    StrListValue *oldFirst = list->first;

    list->first = (StrListValue*)malloc(sizeof(StrListValue));

    if(oldFirst != NULL) 
        oldFirst->prev = list->first;

    list->first->next = oldFirst;
    list->first->prev = NULL;

    list->first->value = buf;

    if(list->last == NULL)
        list->last = list->first;
}


void strlist_push_back(StrList *list, char *value, size_t size) {
    char* buf = (char*)malloc(size);
    memcpy(buf, value, size);

    StrListValue *newVal = (StrListValue*)malloc(sizeof(StrListValue));

    newVal->next = NULL;
    newVal->prev = list->last;
    newVal->value = buf;

    if(list->last != NULL) {
        list->last->next = newVal;
    }
    
    list->last = newVal;

    if(list->first == NULL) {
        list->first = list->last;
    }
}

int strlist_pop_front(StrList *list) {
    StrListValue *front = list->first;

    if(front == NULL)
        return 0;
    
    list->first = front->next;

    if(list->first != NULL)
        list->first->prev = NULL;

    if(list->last == front)
        list->last = list->first;

    strlist_freeelem(front);
}

int strlist_pop_back(StrList *list) {
    StrListValue *back = list->last;

    if(back == NULL)
        return 0;

    list->last = back->prev;

    if(back->prev != NULL)
        back->prev->next = NULL;

    if(list->first == back)
        list->first = list->last;

    strlist_freeelem(back);
}

int strlist_delete(StrList *list, int index) {
    int i = 0;

    StrListValue *current = list->first;

    if(current == NULL)
        return 0;
    
    while(current != NULL && i != index) {
        current = current->next;
        i++;
    }

    if(i == index) {
        if(current->prev != NULL) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            strlist_freeelem(current);
        } 
        else if(current->next != NULL && list->first == current) {
            list->first = current->next;
            strlist_freeelem(current);
        }
        else {
            list->first = NULL;
            list->last = NULL;
            strlist_freeelem(current);
        }

        return 1;
    }

    return 0;
}

int strlist_empty(StrList *list) {
    return list->first == NULL;
}

int strlist_size(StrList *list) {
    int i = 0;

    StrListValue *current = list->first;
    
    while(current != NULL) {
        current = current->next;
        i++;
    }

    return i;
}

void strlist_clear(StrList *list) {
    while(list->first != NULL) {
        StrListValue *next = list->first->next;
        strlist_freeelem(list->first);
        list->first = next;
    }

    list->first = list->last = NULL;
}

void strlist_free(StrList *list) {
    strlist_clear(list);
    free(list);
}
