#include <stdio.h>
#include <stddef.h>

int main(){
    typedef struct PersonStruct {
        char name[32];
        int birth_year;
        float weight;
        struct PersonStruct* parent; //parent'ı da bir person
    } Person;

    Person yavuz = { "Yavuz", 1990, 75.2, NULL };

    typedef Person People[3];

    People group = {
        { "Aliye", 2026, 4.2, &group[2] },
        { "Vehbi", 1926, 46.2, NULL },
        { "Necmi", 1976, 96.2, &group[1] }
    };

        
    // Aliye'nin babasının adı:
    printf("%s\n", group[0].parent->name); // "Necmi" yazar

    // Aliye'nin dedesinin adı (zincirleme erişim):
    printf("%s\n", group[0].parent->parent->name); // "Vehbi" yazar
    return 0;
}