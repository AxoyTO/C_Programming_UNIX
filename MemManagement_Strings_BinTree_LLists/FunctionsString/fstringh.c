#include <stdio.h>
#include <string.h>

int main() {

    char q1[10] = "qwe.c";
//	char q2[10] = "012345";
    char q3[20] = "ab fgbghdbjn";
    char sql[30] = "";
    char *p;
    const char php[] = ".php";
    int i = 0, val;
    //printf("%ld\n", strlen(q1));
    // strcat(q1, q2+2); // qwe012345
    // puts(q1);
//	printf("%ld", strlen(q1));
    while (q1[i] != '.') {
        if (q1[i] == '\0')
            break;
        i++;
    }

    if (q1[i] == '.')
        strcpy(q1 + i, php);

    puts(q1);
    strcpy(q1, "CHANGED");
    puts(q1);

    p = strchr(q3, ' ');
    val = p - q3;
    printf("index of first d = %d\n", val);
    printf("%c\n", q3[val]);
    strcpy(sql, q3 + val + 1);
    puts(sql);


    char str[] = "abcdef";
    char *t, *q, *r;
    int k;
    t = str;
    q = 0;
    t++;
    k = t - str;
    r = t + k;
    if (k && t || q)
        q = str + 6;
    t = q ? r : q;
    *(t - 1) = 'a';
    *r = 'x';
    printf("str: %s \n", str);


    return 0;
}
