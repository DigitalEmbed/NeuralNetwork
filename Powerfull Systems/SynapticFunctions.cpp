#include "SynapticFunctions.h"

float f_stepFunction(float f_valueInput) {
  if (f_valueInput >= 0) {
    return 1;
  }
  else {
    return -1;
  }
}

float f_linearFunction(float f_valueInput) {
  return f_valueInput;
}

float f_exponencialPropagationFunction (float f_valueInput){
  return (exp(f_valueInput)/pow(exp(f_valueInput) + 1, 2));
}

float f_tangentialPropagationFunction (float f_valueInput){
  return (1/(1 + tan(f_valueInput))) - ((f_valueInput * pow(1/cos(f_valueInput), 2))/pow(1 + tan(f_valueInput), 2));
}
