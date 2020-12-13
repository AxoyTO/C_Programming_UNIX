#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int len_str=20,len_arr=20;
    char *str=NULL, **arr_str=NULL, *buf=NULL;
    int i=0, j, k;
    
    
    str=(char*)malloc(len_str*sizeof(char));
    if (str==NULL) exit(1);
    
    while(scanf("%c", str+i)!=EOF)
    {
        i++;
        if (i == len_str)
        {
            len_str*=2;
            buf=(char*)realloc(str, len_str*sizeof(char));
            if (buf==NULL)
            {
                free(str);
                exit(1);
            }
            else str = buf;
        }
    }
    buf =(char*)realloc(str, i*sizeof(char));
    if (buf==NULL){free (str); exit(1);}
    else str=buf;
    
    str[i-1]='\0';
    
    
    // array of words from sentence 
    
    i=0; 
    arr_str = (char**)malloc(len_arr*sizeof(char*));
    if (arr_str==NULL){free(str); exit(1);}
    
    buf=strtok(str, " ");// вернет адрес первого слова 
    while (buf!=NULL)
    {
        arr_str[i]=(char*)malloc((strlen(buf)+1)*sizeof(char));
        if (arr_str[i]==NULL) {free(str); free (arr_str); exit(1);}
        strcpy (arr_str[i], buf);
        buf = strtok(NULL, " ");// продолжает разбивать - адрес очередного слова 
        i++;
        if (i==len_arr)
        {
            char** arr_buf=NULL;
            len_arr*=2;
            arr_buf=(char**)realloc(arr_str, len_arr*sizeof(char*));
            if (arr_buf==NULL){ free(arr_str); free (str); exit(1);}
            else arr_str=arr_buf;
        }
    }
    
    free (str);
    str=NULL;
    
    //сортировка массива слов 
    // i - число слов, 
    for (j=i-1; j>0; j--)
        for (k=0; k<j; k++)
            if(strcmp(arr_str[k], arr_str[k+1])>0)
            {
                char *tmp = arr_str[k]; // перестановка адресов 
                arr_str[k]=arr_str[k+1];
                arr_str[k+1]=tmp;
            }
        
    for (j=0; j<i; j++)
        printf ("%s\n", arr_str[j]);
    for (j=0;j<i;j++)
        free(arr_str[j]);
    free (arr_str);
    arr_str=NULL;
    return 0;
}
