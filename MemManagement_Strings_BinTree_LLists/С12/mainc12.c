#include <stdio.h>
#include <string.h>
#define MAX 20

struct person{
    char name[20];
    int age;
};

int addPerson(struct person *person, char buf[20], int age, int *count){
    person->age = age;
    strcpy(person->name, buf);
    (*count)++;
    if(*count >= MAX)
        return 1;
    return 0;
}

void sortArray(struct person person[MAX], int count)
{
    int i,j, tmp;
    char buf[20];
    for(i=0; i<count; i++){
        for(j=i+1; j<count; j++){
            if(strcmp(person[i].name, person[j].name)>0){
                strcpy(buf, person[i].name);
                tmp = person[i].age;
                strcpy(person[i].name, person[j].name);
                person[i].age = person[j].age;
                strcpy(person[j].name, buf);
                person[j].age = tmp;
            }
            else if(!strcmp(person[i].name, person[j].name)){
                if(person[i].age>person[j].age){
                    strcpy(buf, person[i].name);
                    tmp = person[i].age;
                    strcpy(person[i].name, person[j].name);
                    person[i].age = person[j].age;
                    strcpy(person[j].name, buf);
                    person[j].age = tmp;
                }
            }
        }
    }
}
int main()
{
    struct person personData[MAX];
    char buf[20];
    int i, count = 0;
    int age;

    while(scanf("%19s%d", buf, &age) != EOF)
    {
        if(addPerson(personData+count, buf, age, &count))
            break;
    }

    sortArray(personData, count);

    for(i=0; i<count; i++) {
        printf("%s %d\n", personData[i].name, personData[i].age);
    }
    return 0;
}

