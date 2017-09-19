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



  int  main()
{
  char ** tokenVec;
  do{
  	char buffer[128];
	printf ("$ ");
	fflush(stdout);
	fgets(buffer, 128, stdin);	

	tokenVec = mytoc(buffer, ' ');
        
	for(int i = 0 ; tokenVec[i] != '\0' ; i++)
	  {
	    printf("%d: %s\n", i, tokenVec[i]);
	  }
	
  }

  while(checkExit(tokenVec) != 1);
  freeMem(tokenVec);
}	
 



       



