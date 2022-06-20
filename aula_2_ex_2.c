// Program that takes three time arguments (hours, minutes and seconds) to transform them into a single seconds output

#include <stdio.h>

#define HOURS_MULTIPLIER 3600;
#define MINUTES_MULTIPLIER 60;

int main() {
    int hours;
    int minutes;
    int seconds;

    int converted_hours;
    int converted_minutes;

    int total_seconds;

    printf("Informe o total de horas:\n");
    scanf("%d", &hours);

    printf("Informe o total de minutos:\n");
    scanf("%d", &minutes);

    printf("Informe o total de segundos:\n");
    scanf("%d", &seconds);

    converted_hours = hours * HOURS_MULTIPLIER;
    converted_minutes = minutes * MINUTES_MULTIPLIER;

    total_seconds = converted_hours + converted_minutes + seconds;

    printf("Total de segundos informado: %d", total_seconds);

    return 0;
}
