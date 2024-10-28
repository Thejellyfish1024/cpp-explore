#include <stdio.h>
#include <string.h>

int main()
{
    struct Person
    {
        char name[20];
        int age;
    };

    struct Person person1, person2;
    struct Person *p;

    strcpy(person1.name, "rahim");
    person1.age = 24;
    strcpy(person2.name, "xyz");
    person2.age = 326;
    p = &person1;
    printf("%s\n", person1.name);
    printf("%d\n", person1.age);
    printf("%s\n", person2.name);
    printf("%d\n", person2.age);
}