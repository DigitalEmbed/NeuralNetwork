#ifndef SynapticFunctions_H
#define SynapticFunctions_H

#include <math.h>

//! Synaptic Function: Step
/*!
  This is a public synaptic function that will be used on a neurone type object.
  \param f_valueInput an float variable.
  \return A float variable (-1 or 1).
*/
float f_stepFunction(float f_valueInput);
//! Synaptic Function: Linear
/*!
  This is a public synaptic function that will be used on a neurone type object.
  \param f_valueInput an float variable.
  \return A float variable (the input).
*/
float f_linearFunction(float f_valueInput);
//! Synaptic Function: Exponential Propagation
/*!
  This is a public synaptic function that will be used on a neurone type object.
  \param f_valueInput an float variable.
  \return A float variable.
*/
float f_exponencialPropagationFunction (float f_valueInput);
//! Synaptic Function: Tangential Propagation
/*!
  This is a public synaptic function that will be used on a neurone type object.
  \param f_valueInput an float variable.
  \return A float variable.
*/
float f_tangentialPropagationFunction (float f_valueInput);

#endif
