#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main() {

  char *input = NULL;
  size_t inputSize = 0;
  ssize_t bytesRead;

  printf("$");

  bytesRead = getline(&input, &inputSize, stdin);

  if (bytesRead != -1) {

    char *ptr = input;  // Pointer to traverse the input string

    while (*ptr != '\0') {

      printf("%c", *ptr);

      ptr++;
    }

  }
  
  free(input);  // Free dynamically allocated memory
      return 0;
}
