#include <stdio.h>
#include <string.h>


struct PersonInfo{
    char Name[30];
    int age;
    float gpa;
};

int main(){
    struct PersonInfo person1 = {"Onur", 19, 3.72};
    struct PersonInfo person2;
    strcpy(person2.Name, "Abdülkerim");
    person2.age = 33;
    person2.gpa = 1.26;

    printf("%s - Yaş: %d - GPA: %.2f\n", person1.Name, person1.age, person1.gpa);
    printf("%s - Yaş: %d - GPA: %.2f\n", person2.Name, person2.age, person2.gpa); 

    return 0;
}