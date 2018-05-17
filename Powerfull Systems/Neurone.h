#ifndef Neurone_H
#define Neurone_H

#include <inttypes.h>

typedef float (*SynapticFunction)(float f_input);

//!  Neurone Class
/*!
  This class is the representation of a perceptron. This structure solves linearly separable problems.
*/
class Neurone {
private:
  //! Amount of Dendrites Variable
  /*!
    In this private float variable the amount of dendrites is stored.
  */
  uint8_t ui8_amountOfDendrites;
  //! Synaptic Weights
  /*!
    In this private 8-bit integer variable the amount of synaptic weights is stored. In many literatures, they are represented by Wi.
  */
  float *f_synapticWeights;
  //! Synaptic Inputs
  /*!
    In this private float variable the synaptic inputs is stored. In many literatures, they are represented by Xi.
  */
  float *f_synapticInputs;
  //! Bias
  /*!
    In this private float variable the bias is stored. In many literatures, they are represented by the Greek letter TETA.
  */
  float f_bias;
  //! Axonium (Output)
  /*!
    In this private float variable the axonium (output) is stored. In many literatures, they are represented by Y.
  */
  float f_axonium;
  //! Synaptic Function
  /*!
    In this private pointer function variable the synaptic function is stored. In many literatures, they are represented by f(t).
  */
  float (*f_synapticFunction)(float f_input);
public:
  //! Neuron Constructor
  /*!
    This constructor will build a neuron type object.
    \param ui8_amountOfDendrites an 8-bit integer (a.k.a. byte) argument.
    \param f_synapticFunction a function float pointer.
  */
  Neurone(uint8_t ui8_amountOfDendrites, SynapticFunction f_synapticFunction);
  //! Neuron Constructor
  /*!
    This destructor will delete this neuron object.
  */
  ~Neurone(void);
  //! GET: Amount of Dendrites
  /*!
    This method will return the amount of dendrites in this neuron.
    \return ui8_amountOfDendrites an 8-bit integer.
  */
  uint8_t ui8_getAmountOfDendrites(void);
  //! GET: Synaptic Weights
  /*!
    This method will return the synaptic weights in this neuron.
    \param ui8_dendrite an 8-bit integer.
    \return f_synapticWeights a float variable.
  */
  float f_getSynapticWeights(uint8_t ui8_dendrite);
  //! GET: Output (Axonium)
  /*!
    This method will return the output (axonium) in this neuron.
    \return f_axonium a float variable.
  */
  float f_getAxonium(void);
  //! GET: Bias
  /*!
    This method will return the Bias in this neuron.
    \return f_bias a float variable.
  */
  float f_getBias(void);
  //! GET: Synaptic Inputs
  /*!
    This method will return the synaptic inputs in this neuron.
    \param ui8_dendrite an 8-bit integer.
    \return f_synapticInputs a float variable.
  */
  float f_getSynapticInputs(uint8_t ui8_dendrite);
  //! Use Synaptic Function
  /*!
    This method will return the return of synaptic function stored in this neuron.
    \param f_input a float variable.
    \return A float variable.
  */
  float f_useSynapticFunction(float f_input);
  //! Process
  /*!
    This method will cause the neuron to process the inputs contained in the parameter of this function.
    \param f_condition a pointer float (like a vector) variable.
    \return f_axonium a float variable.
  */
  float f_process(float *f_condition);
  //! Process
  /*!
    This method will cause the neuron to process the inputs contained in the parameter of this function.
    \param f_condition a pointer of pointer float (like a matrix) variable.
    \param ui8_column an 8-bit integer.
    \return f_axonium a float variable.
  */
  float f_process(float **f_condition, uint8_t ui8_column);
  //! Process
  /*!
    This method will cause the neuron to process the private inputs contained in this object.
    \return f_axonium a float variable.
  */
  float f_process(void);
  //! SET: Bias
  /*!
    This method will set the Bias in this neuron.
    \param f_bias a float variable.
  */
  void setBias(float f_bias);
  //! SET: Constants
  /*!
    This method will set all constants in this neuron.
    \param f_userConstants a pointer float variable.
  */
  void setConstants(float *f_userConstants);
  //! SET: Synaptic Weights
  /*!
    This method will set a synaptic weight in this neuron.
    \param ui8_dendrite a 8-bit integer (a.k.a. byte) variable.
    \param f_synapticWeights a float variable.
  */
  void setSynapticWeights(uint8_t ui8_dendrite, float f_synapticWeights);
  //! SET: Synaptic Inputs
  /*!
    This method will set a synaptic input in this neuron.
    \param ui8_dendrite a 8-bit integer (a.k.a. byte) variable.
    \param f_value a float variable.
  */
  void setSynapticInputs(uint8_t ui8_dendrite, float f_value);
  //! SET: Synaptic Inputs
  /*!
    This method will set a synaptic input in this neuron.
    \param f_synapticFunction a function float pointer.
  */
  void setSynapticFunction(SynapticFunction f_synapticFunction);
};

#endif
