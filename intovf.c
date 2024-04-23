#include <stdio.h>
#include <stdlib.h>

#define PIN_INCREMENT 90000
/*  Check a PIN.  Negative value indicates
    Already validated */
void check (int pin)
{
    if (pin < 0 || pin == 91234)
        printf ("PIN correct!\n");
    else
        printf ("Bad PIN\n");
}

int main (int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Please provide a PIN"); 
        return 1; 
    }
    
    char *endptr; 
    long pin = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0'){
        fprintf(stderr, "Enter a valid number\n");
        return 1; 
    }

    if (pin < 0)
        fprintf (stderr, "Positive numbers only!\n");
    else
        check (pin+PIN_INCREMENT);

    return 0;
}


