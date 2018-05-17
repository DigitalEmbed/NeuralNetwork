#include "LearningFunctions.h"

void f_recalculateSynapticWeights(Neurone *ArtificialNeurone, float f_learningRate, float **f_trainingMatrix, uint8_t ui8_columnPosition);
void f_recalculateBias(Neurone *ArtificialNeurone, float f_learningRate, float ** f_trainingMatrix, uint8_t ui8_columnPosition);

void f_recalculateSynapticWeights(Neurone *ArtificialNeurone, float f_learningRate, float **f_trainingMatrix, uint8_t ui8_columnPosition) {
  uint8_t ui8_counter = 0;
  float f_synapticWeights = 0;
  uint8_t ui8_amountOfDendrites = ArtificialNeurone->ui8_getAmountOfDendrites();
  while (ui8_counter < ui8_amountOfDendrites) {
    f_synapticWeights = (float)ArtificialNeurone->f_getSynapticWeights(ui8_counter) + (float)f_learningRate * f_trainingMatrix[ui8_columnPosition][ui8_amountOfDendrites] * f_trainingMatrix[ui8_columnPosition][ui8_counter];
    ArtificialNeurone->setSynapticWeights(ui8_counter, f_synapticWeights);
    ui8_counter++;
  }
}

void f_recalculateBias(Neurone *ArtificialNeurone, float f_learningRate, float **f_trainingMatrix, uint8_t ui8_columnPosition) {
  float f_bias = (float)ArtificialNeurone->f_getBias() + (float)f_learningRate * f_trainingMatrix[ui8_columnPosition][ArtificialNeurone->ui8_getAmountOfDendrites()];
  ArtificialNeurone->setBias(f_bias);
}

void learn(Neurone *ArtificialNeurone, float f_learningRate, float **f_trainingMatrix, uint32_t ui32_amountOfLines, bool b_flagProgressBar) {
  printf("Learning... Please wait...\n");
  ProgressBar BarLearning(10, ui32_amountOfLines, true);
  uint8_t ui8_counter = 0;
  uint8_t ui8_stateMachine = 0;
  uint8_t ui8_responseLine =  ArtificialNeurone->ui8_getAmountOfDendrites();
  bool b_flagRecalculateSynapticWeight = false;
  bool b_flagCountPreviousValues = false;
  bool b_flagLearningCompleted = false;
  while (b_flagLearningCompleted == false) {
    switch (ui8_stateMachine) {

      case 0:
        while (ui8_counter < ui32_amountOfLines) {
          float f_outputNeurone = ArtificialNeurone->f_process(f_trainingMatrix, ui8_counter);
          float f_correctOutput = f_trainingMatrix[ui8_counter][ui8_responseLine];
          if (f_outputNeurone != f_correctOutput) {
            b_flagRecalculateSynapticWeight = true;
            if (ui8_counter > 0) {
              b_flagCountPreviousValues = true;
            }
            ui8_stateMachine = 1;
            break;
          }
          else {
            if (b_flagCountPreviousValues == true) {
              b_flagCountPreviousValues = false;
              ui8_counter = 0;
            }
            else {
              ui8_counter++;
            }
          }
        }
        if (b_flagRecalculateSynapticWeight == false) {
          ui8_stateMachine = 2;
        }
        BarLearning.showProgressBar(ui8_counter);
        break;

      case 1:
        b_flagRecalculateSynapticWeight = false;
        f_recalculateBias(ArtificialNeurone, f_learningRate, f_trainingMatrix, ui8_counter);
        f_recalculateSynapticWeights(ArtificialNeurone, f_learningRate, f_trainingMatrix, ui8_counter);
        ui8_stateMachine = 0;
        break;

      case 2:
        printf("\n");
        printf("Learned!\n");
        b_flagLearningCompleted = true;
        break;
    }
  }
}

void learn(Neurone *ArtificialNeurone, float f_learningRate, float **f_trainingMatrix, uint32_t ui32_amountOfLines) {
  uint8_t ui8_counter = 0;
  uint8_t ui8_stateMachine = 0;
  uint8_t ui8_responseLine =  ArtificialNeurone->ui8_getAmountOfDendrites();
  bool b_flagRecalculateSynapticWeight = false;
  bool b_flagCountPreviousValues = false;
  bool b_flagLearningCompleted = false;
  while (b_flagLearningCompleted == false) {
    switch (ui8_stateMachine) {

      case 0:
        while (ui8_counter < ui32_amountOfLines) {
          float f_outputNeurone = ArtificialNeurone->f_process(f_trainingMatrix, ui8_counter);
          float f_correctOutput = f_trainingMatrix[ui8_counter][ui8_responseLine];
          if (f_outputNeurone != f_correctOutput) {
            b_flagRecalculateSynapticWeight = true;
            if (ui8_counter > 0) {
              b_flagCountPreviousValues = true;
            }
            ui8_stateMachine = 1;
            break;
          }
          else {
            if (b_flagCountPreviousValues == true) {
              b_flagCountPreviousValues = false;
              ui8_counter = 0;
            }
            else {
              ui8_counter++;
            }
          }
        }
        if (b_flagRecalculateSynapticWeight == false) {
          ui8_stateMachine = 2;
        }
        break;

      case 1:
        b_flagRecalculateSynapticWeight = false;
        f_recalculateBias(ArtificialNeurone, f_learningRate, f_trainingMatrix, ui8_counter);
        f_recalculateSynapticWeights(ArtificialNeurone, f_learningRate, f_trainingMatrix, ui8_counter);
        ui8_stateMachine = 0;
        break;
      case 2:
        b_flagLearningCompleted = true;
        break;
    }
  }
}

void learn(Neurone *ArtificialNeurone, float f_learningRate, File *TargetFile, bool b_flagProgressBar) {
  learn(ArtificialNeurone, f_learningRate, TargetFile->f_file, TargetFile->ui32_getAmountOfLines(), DEBUG);
}

void learn(Neurone *ArtificialNeurone, float f_learningRate, File *TargetFile) {
  learn(ArtificialNeurone, f_learningRate, TargetFile->f_file, TargetFile->ui32_getAmountOfLines());
}
