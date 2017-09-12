/**
 * test.c
 * This file contains the main for the tokenizing program
 *
 * @author Erik Corral
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "mytoc.h"

  void  main()
{

  int status = 1;
  printf("%s", "hello");

   while(status != 0)
    {
      int buffer[4096];
      read(0, buffer, 4096);
      char ** vecTokens = mytoc(buffer, ' ');

      for(int i = 0 ; vecTokens[i] != '\0' ; i++)
	{
	  printf("%d, %s", i, vecTokens[i]); 
	}
    }
  
  
}


