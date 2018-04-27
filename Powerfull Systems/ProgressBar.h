#ifndef ProgressBar_H
#define ProgressBar_H

#include <stdio.h>
#include <inttypes.h>

//!  Progress Bar Class
/*!
  This class is a simple progress bar.
*/
class ProgressBar{
  private:
    //! Bar Value
    /*!
      In this private 8-bit integer variable the bar value is stored.
    */
    uint8_t ui8_barValue;
    //! Max Bar Value
    /*!
      In this private 8-bit integer variable the max bar value is stored.
    */
    uint8_t ui8_maxBar;
    //! Character of Shadow Bar
    /*!
      In this private char variable the shadow char value is stored.
    */
    char c_shadowBar;
    //! Character of Shadow Bar
    /*!
      In this private char variable the progress bar char value is stored.
    */
    char c_progressBar;
    //! Character of Shadow Bar
    /*!
      In this private char variable the frame char value is stored.
    */
    char c_frame;
  public:
    //! Neuron Constructor
    /*!
      This constructor will build a progress bar type object.
      \param ui8_maxBar an 8-bit integer (a.k.a. byte) argument.
      \param b_printShadow a boolean variable.
    */
    ProgressBar(uint8_t ui8_maxBar, bool b_printShadow);
    //! Neuron Constructor
    /*!
      This destructor will delete this object.
    */
    ~ProgressBar(void);
    //! Neuron Constructor
    /*!
      This method will increase the progress bar.
      \param ui8_increase an 8-bit integer (a.k.a. byte) argument.
    */
    void showProgressBar(uint8_t ui8_increase);
};

#endif
