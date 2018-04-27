#include "ProgressBar.h"

ProgressBar::ProgressBar(uint8_t ui8_maxBar, bool b_printShadow){
  this->c_shadowBar = 177;
  this->c_progressBar = 219;
  this->c_frame = 179;
  this->ui8_maxBar = ui8_maxBar;
  if(b_printShadow == true){
    printf("%c", this->c_frame);
    for(uint8_t ui8_counter = 0; ui8_counter < this->ui8_maxBar; ui8_counter++){
      printf("%c", this->c_shadowBar);
    }
    printf("%c", this->c_frame);
  }
  this->ui8_barValue = 0;
}

ProgressBar::~ProgressBar(){
}

void ProgressBar::showProgressBar(uint8_t ui8_increase){
  bool b_flagPrintPercentageProgress = false;
  if (ui8_increase > ui8_barValue){
    b_flagPrintPercentageProgress = true;
  }
  if(this->ui8_maxBar >= ui8_increase){
    printf ("\r");
    printf("%c", this->c_frame);
    for(uint8_t ui8_counter = 0; ui8_counter < ui8_increase; ui8_counter++){
      printf("%c", this->c_progressBar);
    }
    if (b_flagPrintPercentageProgress == true){
      this->ui8_barValue = ui8_increase;
    }
    while(ui8_increase < this->ui8_maxBar){
      printf("%c", this->c_shadowBar);
      ui8_increase++;
    }
    printf("%c", this->c_frame);
    printf(" - %.2f%c", (float)this->ui8_barValue/(float)this->ui8_maxBar*100, 37);
  }
}
