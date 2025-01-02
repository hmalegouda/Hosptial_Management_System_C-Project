#include "Utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definitions
void validateInput(char *input, int maxLength) {
    // Remove newline character from input
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Check if input exceeds maximum length
    if (strlen(input) > maxLength) {
        printf("Input exceeds maximum length of %d characters.\n", maxLength);
        exit(1);
    }
}

void handleFile(const char *filename, const char *mode, void (*operation)(FILE *file)) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    operation(file);

    fclose(file);
}

void exampleOperation(FILE *file) {
    // Example file operation
    fprintf(file, "This is an example file operation.\n");
}
