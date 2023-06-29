#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int space_char(char c)
{
  if(c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}


int non_space_char(char c)
{
  if(c != ' ' && c != '\t' && c != '\0'){
    return 1;
  }
  return 0;
}


char* token_start(char* str)
{
  for(int i = 0; *(str + 1) != '\0'; i++)
    {
      if(non_space_char(*(str + i))){
	return str + i;
      }
    }
  return 0;
}


char* token_terminator(char* str)
{
  int i;

  for(i=0; *(str + i) != '\0'; i++)
     {
      if(space_char(*(str + i))){
	return str + i;
	    }
    }
  return str + i;
}


int count_tokens(char *str)
{

  int count = 0;
  int i = 0;

  while(str){
    str = token_start(str);
    if(str)
      {
	count++;
	str = token_terminator(str);
      }
  }
  return count;
}


char* copy_str(char *inStr, short len)
{

  int i = 0;
  char* outStr = malloc((len+1) * sizeof(char));

  while(i <= len){
    outStr[i] = inStr[i];
    i++;
  }
  outStr[i] = '\0';
  return outStr;
}


char** tokenize(char* str)
{
  int token_count = count_tokens(str);
  char** tokens = (char**)malloc(sizeof(char*) * (token_count + 1));

  char* terminator = str;

  for(int i = 0; i < token_count; i++)
    {
      str = token_start(terminator);
      terminator = token_terminator(str);

      tokens[i] = copy_str(str, terminator-str);
    }

  tokens[token_count] = '\0';

  return tokens;
}


void print_tokens(char **tokens)
{
  
  int i;

  for(i = 0;tokens[i]; i++)
    {
      //printf("\nStart of while in print");
      
      printf("\n%s", tokens[i]);

      //printf("\n %d checking i\n", i);
    }
  //printf("\n %d", i);

  // printf("\n", *tokens);

  //printf("end of print");

}


void free_tokens(char **tokens)
{

  int i;

  for(i = 0;tokens[i]; i++)
    {
      
      free((tokens[i]));

    }
  free(tokens);
}
