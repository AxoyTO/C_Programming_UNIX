#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char str[20];
    struct lnode *next;
    struct lnode *prev;
};

struct lnode *add_first(struct lnode *head, char *str);         //-af
struct lnode *add_end(struct lnode *head, char *str);           //-ae
struct lnode *insert(struct lnode *head, char *str, int n);     //-i
struct lnode *delete_element(struct lnode *head, char *str);    //-d

void printList(struct lnode *head);

void freeList(struct lnode *head);


int main(int argc, char **argv) {
    // -af "str"- add str to the beginning
    // -ae str - add str to end
    // -i str -n - insert str after nth word
    // -d str - delete the first word that is str

    struct lnode *head = NULL;

    char str[20], cmd[4];
    int n, count = 1, flag = 0;

    scanf("%19s", str);

    head = (struct lnode *) malloc(sizeof(struct lnode));
    if (!head) {
        exit(1);
    }
    if (str[0] == '\0')
        printf("OH NO!\n");
    else
        strcpy(head->str, str);

    head->next = NULL;
    head->prev = NULL;

    if (argc >= 2)
        if (!strcmp(argv[1], "-d"))
            if (!strcmp(argv[2], str))
                flag = 1;

    while (scanf("%19s", str) != EOF) {
        if (argc >= 2)
            if (!strcmp(argv[1], "-d"))
                if (!strcmp(argv[2], str))
                    flag = 1;
        struct lnode *ptr = NULL;
        count++;
        ptr = add_end(head, str);
        if (ptr != NULL)
            head = ptr;
    }

    if (argc >= 2) {
        struct lnode *ptr = NULL;
        strcpy(cmd, argv[1]);

        if (!strcmp(cmd, "-af"))                 // add first
        {
            if (argv[2] && argc == 3) {
                strcpy(str, argv[2]);
                ptr = add_first(head, str);
                if (ptr != NULL)
                    head = ptr;
            }
        } else if (!strcmp(cmd, "-ae"))            // add end
        {
            if (argv[2] && argc == 3) {
                strcpy(str, argv[2]);
                if (head->str[0] == '\0')
                    add_first(head, str);
                else {
                    ptr = add_end(head, str);
                    if (ptr != NULL)
                        head = ptr;
                }
            }
        } else if (!strcmp(cmd, "-i"))             // insert
        {
            if (argv[2] && argc == 4) {
                strcpy(str, argv[2]);
                n = atoi(argv[3]);
                if (n == count) {
                    ptr = add_end(head, str);
                    if (ptr != NULL)
                        head = ptr;
                } else if (n > count || n < 1) {}
                else {
                    ptr = insert(head, str, n);
                    if (ptr != NULL)
                        head = ptr;
                }
            }

        } else if (!strcmp(cmd, "-d"))             // delete
        {
            if (argv[2] && argc == 3) {
                if (!strcmp(head->str, str) && flag == 1 && head->next == NULL && head->prev == NULL) {
                    free(head);
                    flag = 0;
                    return 0;
                }
                if (head != NULL && flag == 1) {
                    strcpy(str, argv[2]);
                    ptr = delete_element(head, str);

                    if (ptr != NULL)
                        head = ptr;
                    //TODO ERROR WHEN FIRST STR TO DELETE - MORE THAN 1 FREE
                    flag = 0;
                }
            }
        }
    }
    if (head && flag == 0) {
        printList(head);
        freeList(head);
    }
    printf("\n");
    return 0;
}

struct lnode *add_end(struct lnode *head, char *str) {
    if (!head)
        return NULL;

    struct lnode *new = NULL;
    while (head->next)
        head = head->next;

    new = (struct lnode *) malloc(sizeof(struct lnode));
    if (!new)
        return NULL;

    strcpy(new->str, str);
    new->prev = head;
    new->next = NULL;
    head->next = new;

    while (head->prev)
        head = head->prev;

    return head;
}

void printList(struct lnode *head) {
    if (!head)
        return;

    while (head->prev)
        head = head->prev;

    while (head) {
        if (head->next)
            printf("%s ", head->str);
        else
            printf("%s", head->str);
        head = head->next;
    }
}

void freeList(struct lnode *head) {
    if (!head)
        return;

    while (head->prev)
        head = head->prev;

    while (head->next) {
        struct lnode *next = head;
        head = head->next;
        free(next);
    }
    free(head);
}

struct lnode *delete_element(struct lnode *head, char *str) {
    if (head == NULL) {
        return head;
    }
    struct lnode *cur = head, *del = NULL;
    while (cur != NULL) {
        if (strcmp(cur->str, str) == 0) {
            del = cur;
            if (cur->prev != NULL) {
                cur = cur->prev;
                if (del->next != NULL) {
                    cur->next = del->next;
                    del->next->prev = cur;
                    free(del);
                    return head;
                } else {
                    cur->next = NULL;
                    free(del);
                    return head;
                }
            } else if (cur->prev == NULL && cur->next != NULL) {
                del = cur;
                head = del->next;
                head->prev = NULL;
                free(del);
                return head;
            } else if (cur->prev == NULL && cur->next == NULL) {
                free(head);
                head = NULL;
                return head;
            }
        }
        cur = cur->next;
    }
    return head;
}

struct lnode *add_first(struct lnode *head, char *str) {
    if (!head)
        return NULL;

    struct lnode *new = NULL;
    new = (struct lnode *) malloc(sizeof(struct lnode));
    if (!new)
        return NULL;

    while (head->prev)
        head = head->prev;

    strcpy(new->str, str);
    new->prev = NULL;
    new->next = head;
    head->prev = new;

    return new;
}

struct lnode *insert(struct lnode *head, char *str, int n) {
    while (head->prev)
        head = head->prev;

    while (n - 1) {
        head = head->next;
        n--;
    }

    if (!head)
        return NULL;

    struct lnode *new = NULL;
    new = (struct lnode *) malloc(sizeof(struct lnode));
    if (!new)
        return NULL;

    strcpy(new->str, str);
    new->prev = head;
    new->next = head->next;
    head->next->prev = new;
    head->next = new;

    while (head->prev)
        head = head->prev;
    return head;
}
