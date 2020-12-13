#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char str[20];
    struct lnode *prev;
    struct lnode *next;
};

struct lnode *add_end(struct lnode *head, char *str);

void printList(struct lnode *cur);

void deleteList(struct lnode *cur);

struct lnode *delete_element(struct lnode *head, char *str);

int main() {
    struct lnode *head = NULL;
    char str[20] = "", buf[20] = "";
    int flag = 0;

    head = (struct lnode *) malloc(sizeof(struct lnode));
    if (!head)
        exit(1);

    scanf("%19s", buf);
    if (buf[0] == '\0') {
        free(head);
        return 0;
    }
    scanf("%19s", str);
    if (str[0] == '\0') {
        printf("empty");
        free(head);
        return 0;
    }
    strcpy(head->str, str);
    if (!strcmp(str, buf))
        flag = 1;
    head->prev = NULL;
    head->next = NULL;

    while (scanf("%19s", str) != EOF) {
        struct lnode *ptr = NULL;
        if (!strcmp(str, buf))
            flag = 1;
        ptr = add_end(head, str);
        if (ptr != NULL)
            head = ptr;
    }

    if (!strcmp(head->str, buf) && flag == 1 && head->next == NULL && head->prev == NULL) {
        printf("empty");
        free(head);
        return 0;
    }
    if (head != NULL && flag == 1) {
        struct lnode *ptr = NULL;
        ptr = delete_element(head, buf);
        if (ptr != NULL)
            head = ptr;
        printList(head);
        deleteList(head);
    } else if (head == NULL) {
        printf("empty");
    } else if (head != NULL && flag == 0) {
        printList(head);
        deleteList(head);
    }
    printf("\n");
    return 0;
}

struct lnode *add_end(struct lnode *head, char *str) {

    if (!head)
        return NULL;
    struct lnode *new = NULL;
    while (head->next) {
        head = head->next;
    }
    new = (struct lnode *) malloc(sizeof(struct lnode));
    if (!new)
        return NULL;
    strcpy(new->str, str);
    new->prev = head;
    new->next = NULL;
    head->next = new;

    while (head)
        head = head->prev;
    return head;
}

struct lnode *delete_element(struct lnode *head, char *str) {
    if (!head)
        return NULL;
    struct lnode *del = NULL;

    while (head) {
        if (!strcmp(head->str, str)) {
            del = head;
            if (head->prev == NULL && head->next != NULL) {
                head = head->next;
                head->prev = NULL;
                free(del);
            } else if (head->prev != NULL && head->next == NULL) {
                head = head->prev;
                head->next = NULL;
                free(del);
            } else if (head->prev == NULL && head->next == NULL) {
                free(head);
                return NULL;
            } else {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                free(head);
            }
            break;
        }
        head = head->next;
    }
    return head;
}

void printList(struct lnode *cur) {
    if (cur == NULL)
        printf("empty");
    else {
        while (cur->prev)
            cur = cur->prev;
        while (cur) {
            if (cur->next != NULL)
                printf("%s ", cur->str);
            else
                printf("%s", cur->str);
            cur = cur->next;
        }
    }
}

void deleteList(struct lnode *cur) {
    while (cur->prev)
        cur = cur->prev;
    while (cur) {
        struct lnode *next = cur->next;
        free(cur);
        cur = next;
    }
    free(cur);
}