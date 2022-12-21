/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  Kp = Kpi;
  Ki = Kii;
  Kd = Kdi;
  output_lim_max = output_lim_maxi;
  output_lim_min = output_lim_mini;
  prev_cte = 0;
  int_cte = 0;
  delta_time = 0;
  
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  // update init and prev cte
  int_cte += cte*delta_time;
  if (delta_time>0){
  d_error = (cte - prev_cte)/delta_time;
      }
  else {
  d_error = 0.0;
  }
  
  // PID parts errors
  p_error = cte;
  i_error = int_cte;
    // update previous Cte
  prev_cte = cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
  double control;
  	control = Kp*p_error + Ki*i_error + Kd*d_error;
  // handle min max limits
  if (control >output_lim_max ) {
    control = output_lim_max;
  }
  else if (control < output_lim_min){
  control = output_lim_min;
  }
  

    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  delta_time = new_delta_time;
  return delta_time;
}