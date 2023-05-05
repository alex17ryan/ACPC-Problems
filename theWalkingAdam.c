#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countSteps(char code[]) {

    int s = 0;

    for (int i = 0; i < (int)strlen(code); i++) {
        if(code[i] == 'U') {
            s++;
        }
        else if (s != 0 && code[i] == 'D'){
            return s;
        }
    }

    return s;
}

int main() {

    int T, steps[100];
    char code[100];
    
    FILE *input_file = fopen("standard_input.txt", "r");
    FILE *output_file = fopen("standard_output.txt", "r");

    fscanf(input_file, "%d", &T);

    for(int i = 0; i < T; i++) {
        fscanf(input_file, "%s", code);
        steps[i] = countSteps(code);
        fprintf(output_file, "%i\n", steps[i]);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
