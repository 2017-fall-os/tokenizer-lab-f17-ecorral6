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


void getTokenLength(int * tokenLengths, char * str, char delim, int numTokens)
{
  int i, j = 0, k = 0;

  
    for (i = 0; i < numTokens; i++)
    {
      
      while(str[j] != delim && str[j] != '\0')
	{
	 
	  tokenLengths[i] = k;  
	  k++;
	  j++;
	 
	}
     
      j++;
      
      k = 0;

    }
   

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
  int i, j= 0, k = 0;
  
  for (i = 0 ; i < numTokens ; i++)
    {
      tokenVec[i] = (char *)malloc(tokenLength[i]+1);
      
       while(str[j] != delim &&  str[j] != '\0')
      	{
	  
	  tokenVec[i][k] = str[j];
	 
	  
	          k++;
	  	  j++;
	  	 
	 	}
       tokenVec[i][j] = '\0';
       j++;
       k = 0;
   
     
       

       
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
  int tokenLengths[numTokens];
  getTokenLength(tokenLengths,str, delim, numTokens);
 char **tokenVec = (char **)calloc(numTokens, sizeof(char *));
 setTokens(tokenVec, str, delim, numTokens, tokenLengths);

  return tokenVec;
}

/**
 * Summary of checkExit
 * Checks to see if the first token in the vector equasl to exit
 * @param char ** tokenVec
 * @return int
 * */

  int checkExit(char ** tokenVec)
    {
      char * exit = "exit";
      int counter;
      int i;
      for(i = 0; i < 4 ; i++)
	{
	
	  if(tokenVec[0][i] == exit[i])
	    {
	      counter++;
	      if(counter == 3)
		{
		  return 1;
		}
	    }
	
	}
        return 0;
    }

/**
 * Summary of freeMem
 * Frees memory allocated by the token vector
 * @param char ** tokenVec
 * */

void freeMem(char ** tokenVec)
{
  for (int i = 0 ; tokenVec[i] != '\0' ; i++)
    {
      free(tokenVec[i]);
    }
}




  
