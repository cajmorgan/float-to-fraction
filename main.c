#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int *floatToFractions(float numberToFrac, int *retLength);
char *returnStringOfHK(int *fractions, int *retLength);

int main() {
  int n, *fractions, *retLength;
  float numberToFrac;
  char *stringFracs[1];
  retLength = (int *)malloc(sizeof(int));

  numberToFrac = 5.4; //Need to contain decimals!
  fractions = floatToFractions(numberToFrac, retLength);
  *stringFracs = returnStringOfHK(fractions, retLength);

  printf("%s", *stringFracs);

  return 0;
}

char *returnStringOfHK(int *fractions, int *retLength) {
  int h[*retLength + 3], k[*retLength + 3];
  char static stringFracs[20], hStr[10], kStr[10];
  h[0] = 0;
  h[1] = 1;
  k[0] = 1;
  k[1] = 0;

  for(int i = 2; i < *retLength + 2; i++) {
    h[i] = (fractions[i - 2] * h[i - 1]) + h[i - 2];
    k[i] = (fractions[i - 2] * k[i - 1]) + k[i - 2];
    if(i == *retLength + 1) {
      printf("h: %d\n", h[i]);
      printf("k: %d\n", k[i]);
      sprintf(hStr, "%d", h[i]);
      sprintf(kStr, "%d", k[i]);
      break;
    }
  }

  strcpy(stringFracs, hStr);
  strcat(stringFracs, "/");
  strcat(stringFracs, kStr);

  return stringFracs;
}


int *floatToFractions(float numberToFrac, int *retLength) {
  int *fractions, length, i, flooredOneInt;
  float fractionLeft, flooredOne;
  length = 1;
  fractions = (int *)calloc(length, sizeof(int));
  i = 0;

  while(1) {
    length += 1;
    fractions = realloc(fractions, sizeof(int) * length);
    fractions[i] = floor(numberToFrac);
    fractionLeft = numberToFrac - floor(numberToFrac);
    if(fractionLeft == 0)
      break;
    else
      numberToFrac = pow(fractionLeft, - 1);
    i += 1;

    flooredOne = (floor(numberToFrac * 1000) / 1000) * 10;
    flooredOneInt = flooredOne;
    if(flooredOneInt == flooredOne || i == 10) {
      length += 1;
      fractions[i] = floor(numberToFrac);
      break;
    }
  }

  *retLength = length - 1;

  return fractions;
}