#include <stdio.h>
#include <stdlib.h>

int getRandomInteger(int minValue, int maxValue) {
  int range = 1 + maxValue - minValue; /* This will ensure we include minValue and maxValue as possible random ints */

  double normal = (rand() / (RAND_MAX + 1.0));  /* cannot divide by just RAND_MAX because we want a number strictly less than 1,
                                                   since rand() has the possibility of equaling RAND_MAX we would get 1 as a 
                                                   value for normal which would put the ending random int outside of the range */ 

  int randomInteger = range * normal + minValue;

  return randomInteger;
}

int main() {
  int minValue = 0;
  int maxValue = 0;

  printf("Enter a minimum value: ");
  scanf("%d", &minValue);
  printf("Enter a maximum value: ");
  scanf("%d", &maxValue);

  for (int i = 0; i <= 10; i++)
    printf("Random integer: %d\n", getRandomInteger(minValue, maxValue));

  return 0;
}
