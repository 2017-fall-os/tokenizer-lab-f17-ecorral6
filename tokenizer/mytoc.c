/**
 * mytoc.c
 *
 * This file contains the necessary functions for tokenizing strings
 *
 * @author Erik Corral
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * Summary of countTokens
 * counts the number of tokens given a string pointer
 * @param char * str 
 * @param char delim 
 * @return int 
 * */


int countTokens(char *str, char delim)
{
  
  
  int numTokens = 0, i;
  for( i = 0; str[i] != '\0' ; i++)
    {
      if(str[i] == delim)
	{
	  numTokens++;
	}
    }


  return numTokens+1;
}

/**
 * Summary of getTokenLength
 * counts the length of a token
 * @param char * str
 * @param char delim
 * @param int numTokens
 * @return int 
 * */


int * getTokenLength(char * str, char delim, int numTokens)
{
  int i, j = 0;

  /**
   *There is a warning when using @var numTokens, variable was declared static with fixed
   *int
   */
  
  static int tokenLengths[5];
  
  for (i = 0; i < numTokens; i++)
    {
     
      tokenLengths[i] = 0;
      while(str[j] != delim && str[j] != '\0')
	{
	  tokenLengths[i] = j;
	  j++;
	}
    }
  return tokenLengths;

}

/**
 * Summary of setTokens
 * sets the tokens in a vector
 * @param char ** tokenVec
 * @param char * str
 * @param char delim
 * @param int numTokens
 * @param tokenLength
 * */

void setTokens(char ** tokenVec, char * str, char delim, int numTokens, int * tokenLength)
{
  int i, j, k;

  for (i = 0 ; i < numTokens ; i++)
    {
      tokenVec[i] = (char *)malloc(tokenLength[i]);
    
      while( str[j] != delim && str[j] != '\0')
	{
	  tokenVec[i][k] = str[j];
	  j++;
	  k++;
	}

      tokenVec[i][k] = '\0';
	
    }
  
}

/**
 * Summary of mytoc
 * Returns a vector of tokens
 * @param char * str
 * @param char * delim
 * @return char **
 * */

char ** mytoc(char *str, char delim)
{
  int numTokens = countTokens(str, delim);
  int * tokenLengths = getTokenLength( str, delim, numTokens);
  char **tokenVec = (char **)calloc(numTokens, sizeof(char *));
  setTokens(tokenVec, str, delim, numTokens, tokenLengths);

  return tokenVec;
}



  
