/**
 * mytoc.h
 *
 * This file contains the necessary functions in order to call them throughout other c files
 * such as test.c
 * @author Erik Corral
 * @version 1.0
 */


#ifndef mytoc
#define mytoc

int countTokens(char *str, char delim);
int * getTokenLength(char * str, char delim, int numTokens);
void setTokens(char ** tokenVec, char * str, char delim, int numTokens, int * tokenLength);
//char ** mytoc(char *str, char delim);
#endif
