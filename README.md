# Udacity_controllerProject
This repo contains the project done with Udacity's self driving car nano degree program. 

#Project Instructions
In the directory /pid_controller you will find the files pid_controller.cpp and pid_controller.h. This is where you will code your pid controller. The function pid is called in main.cpp.

# Step 1: Build the PID controller object
Under files pid_controller.h and pid_controller.cpp the constants and PID class is defined. 
![step1_control](https://user-images.githubusercontent.com/32779283/209024157-6037e7fa-b26e-4ca7-a9a7-14e5eef4080b.jpg)

# Step 2 : PID controller for throttle:
    1) In main.cpp compute the error for the throttle pid. The error is the speed difference between the actual speed and the desired speed.

    Useful variables:

    The last point of v_points vector contains the velocity computed by the path planner.
    velocity contains the actual velocity.
    The output of the controller should be inside [-1, 1].
    The controller parameters for throttle control are
    Kp = 0.21
    Ki = 0.0009
    Kd = 0.1
    
    The method used to come up with initial set of PID values is Zeigler Nicholson method:https://en.wikipedia.org/wiki/Ziegler%E2%80%93Nichols_method

![image](https://user-images.githubusercontent.com/32779283/209024347-b1de1293-965a-422f-bd89-b87edf828009.png)

#Step 3: PID controller for steer:
In main.cpp, complete the TODO (step 3) to compute the error for the steer pid. The error is the angle difference between the actual steer and the desired steer to reach the planned position.

Useful variables:

The variable y_points and x_point gives the desired trajectory planned by the path_planner.
yaw gives the actual rotational angle of the car.
The output of the controller should be inside [-1.2, 1.2].
PID values
Kp = 0.29 Ki = 0.0011 Kd = 0.3
![image](https://user-images.githubusercontent.com/32779283/209024765-9f8153a2-340a-4ace-8023-75ca8bdadd97.png)

Step 4 : Carla simulation
![754uns](https://user-images.githubusercontent.com/32779283/209026453-ad9bf0ea-38ec-4efc-82b3-43d9805b1964.gif)

#Add the plots to your report and explain them (describe what you see)
What is the effect of the PID according to the plots, how each part of the PID affects the control command?
- by applying Zeigler Nicholson technique we start with only a P controller. we notice that the throttle controller is pretty stable but has some oscillations with P controller.
![image](https://user-images.githubusercontent.com/32779283/209026635-7ae6f1f2-4e72-4dca-ab2e-a6c36bfc3af6.png)
further to reduce oscillations we try to apply a Derivative part and make the controller predominently PD controller. to get the following result
![image](https://user-images.githubusercontent.com/32779283/209026761-be85cf30-a609-49c6-b257-6c4bc1ea05ef.png)

I also tried with  a higher I controller to make it PID but with the integral part the overshoot increases, however the controler does become faster and reaches steady state quicker.

How would you design a way to automatically tune the PID parameters?
According to the course "Twiddle " algorithm is a good non-manual way to tune PID. however I was unsure how to implement it with the carla simulator. Perhaps one way to do it would be using python and implement the same vehicle dynamics model from carla and provide a reference inout trajectory from one of the spirals developed during planning project.
PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?

(Optional) What would you do to improve the PID controller?
typically a feed forward element helps with PI and PID controllers. feed forward controllers when added can help with disturbances added due to the environment or feedforward controllers can also help with noisy sensors and account for noise into the control calculation. feed forward controllers can also assist with system delays.
