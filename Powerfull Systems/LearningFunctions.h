#ifndef LearningFunctions_H
#define LearningFunctions_H

#include <inttypes.h>
#include <stdio.h>
#include "Neurone.h"
#include "ProgressBar.h"

//! Recalculate Synaptics Weights
/*!
  This is a private function that will be used on a learning of a neurone.
  \param ArtificialNeurone a neurone object pointer variable.
  \param f_learningRate a float variable.
  \param f_trainingMatrix a pointer of pointer (like a matrix) float variable.
  \param ui8_columnPosition a 8-bit integer variable.
*/

//! Recalculate Bias
/*!
  This is a private function that will be used on a learning of a neurone.
  \param ArtificialNeurone a neurone object pointer variable.
  \param f_learningRate a float variable.
  \param f_trainingMatrix a pointer of pointer (like a matrix) float variable.
  \param ui8_columnPosition a 8-bit integer variable.
*/

//! Learn
/*!
  This is a public function that will be used on a learning of a neurone.
  \param ArtificialNeurone a neurone object pointer variable.
  \param f_learningRate a float variable.
  \param f_trainingMatrix a pointer of pointer (like a matrix) float variable.
  \param ui8_amountOfLines a 8-bit integer variable.
  \param b_progressBar a boolean variable.
*/
void learn(Neurone *ArtificialNeurone, float f_learningRate, float **f_trainingMatrix, uint8_t ui8_amountOfLines, bool b_progressBar);

#endif
