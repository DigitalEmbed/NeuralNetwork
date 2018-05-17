#include "Neurone.h"

Neurone::Neurone(uint8_t ui8_amountOfDendrites, SynapticFunction f_synapticFunction) {
  this->ui8_amountOfDendrites = ui8_amountOfDendrites;
  this->f_bias = 0;
  this->f_axonium = 0;
  this->f_synapticWeights = new float [ui8_amountOfDendrites];
  this->f_synapticInputs = new float [ui8_amountOfDendrites];
  this->f_synapticFunction = f_synapticFunction;
  uint8_t ui8_counter = 0;
  while(ui8_counter < ui8_amountOfDendrites){
    this->f_synapticWeights[ui8_counter] = 0;
    this->f_synapticInputs[ui8_counter] = 0;
    ui8_counter++;
  }
}

Neurone::~Neurone(void) {
  delete this->f_synapticWeights;
  delete this->f_synapticInputs;
}

uint8_t Neurone::ui8_getAmountOfDendrites(void){
  return this->ui8_amountOfDendrites;
}

float Neurone::f_getSynapticWeights (uint8_t ui8_dendrite){
  if (ui8_dendrite < 0 || ui8_dendrite > ui8_amountOfDendrites){
    return 0;
  }
  else{
    return f_synapticWeights[ui8_dendrite];
  }
}

float Neurone::f_getAxonium(void) {
  return this->f_axonium;
}

float Neurone::f_getBias(void){
  return this->f_bias;
}

float Neurone::f_getSynapticInputs(uint8_t ui8_dendrite){
  if (ui8_dendrite < this->ui8_amountOfDendrites){
    return this->f_synapticInputs[ui8_dendrite];
  }
  else{
    return 0;
  }
}

float Neurone::f_useSynapticFunction(float f_input){
  return this->f_synapticFunction(f_input);
}

float Neurone::f_process(float *f_condition) {
  float f_output = 0;
  uint8_t ui8_counter = 0;
  while (ui8_counter < ui8_amountOfDendrites) {
    setSynapticInputs(ui8_counter, f_condition[ui8_counter]);
    f_output = f_output + this->f_synapticWeights[ui8_counter] * f_condition[ui8_counter];
    ui8_counter++;
  }
  f_output = this->f_synapticFunction(f_output + this->f_bias);
  this->f_axonium = f_output;
  return f_output;
}

float Neurone::f_process(float **f_condition, uint8_t ui8_column) {
  float f_output = 0;
  uint8_t ui8_counter = 0;
  while (ui8_counter < ui8_amountOfDendrites) {
    setSynapticInputs(ui8_counter, f_condition[ui8_column][ui8_counter]);
    f_output = f_output + this->f_synapticWeights[ui8_counter] * f_condition[ui8_column][ui8_counter];
    ui8_counter++;
  }
  f_output = this->f_synapticFunction(f_output + this->f_bias);
  this->f_axonium = f_output;
  return f_output;
}

float Neurone::f_process(void) {
  float f_output = 0;
  uint8_t ui8_counter = 0;
  while (ui8_counter < ui8_amountOfDendrites) {
    f_output = f_output + this->f_synapticWeights[ui8_counter] * this->f_synapticInputs[ui8_counter];
    ui8_counter++;
  }
  f_output = this->f_synapticFunction(f_output + this->f_bias);
  this->f_axonium = f_output;
  return f_output;
}

void Neurone::setBias(float f_bias) {
  this->f_bias = f_bias;
}

void Neurone::setConstants(float *f_userConstants) {
  uint8_t ui8_counter = 0;
  while (ui8_counter < ui8_amountOfDendrites) {
    this->f_synapticWeights[ui8_counter] = f_userConstants[ui8_counter];
    ui8_counter++;
  }
  this->f_bias = f_userConstants[this->ui8_amountOfDendrites];
}

void Neurone::setSynapticWeights(uint8_t ui8_dendrite, float f_synapticWeights) {
  this->f_synapticWeights[ui8_dendrite] = f_synapticWeights;
}

void Neurone::setSynapticInputs(uint8_t ui8_dendrite, float f_value){
  if (ui8_dendrite < this->ui8_amountOfDendrites){
    this->f_synapticInputs[ui8_dendrite] = f_value;
  }
}

void Neurone::setSynapticFunction(SynapticFunction f_synapticFunction){
  this->f_synapticFunction = f_synapticFunction;
}
