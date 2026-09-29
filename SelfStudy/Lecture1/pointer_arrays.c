#include <stdio.h>

int main(void) {
    const char* weekdays[7] = {
        "Monday", "Tuesday",
        "Wednesday", "Thursday",
        "Friday", "Saturday",
        "Sunday"
    };

    char name[] = "Yavuz";
    int birth_year = 1990;
    float weight = 75.2;

    void* person[] = { name, &birth_year, &weight };

    int born_at = *(int*)person[1]; //person[1] içinde 1990'ın adresi var. Öncelikle bu bir integer pointer'dır diyoruz (int*) sayesinde. Sonrasında da en baştaki * yardımı ile o adresteki 1990'ı bulmuş oluyoruz.

    printf("Haftanin ilk gunu: %s\n", weekdays[0]);
    printf("Isim: %s\n", (char*)person[0]);
    printf("Dogum yili: %d\n", born_at);
    printf("Kilo: %.1f\n", *(float*)person[2]);

    return 0;
}