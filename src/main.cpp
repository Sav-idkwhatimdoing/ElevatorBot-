/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision1              vision        1               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "VisionSensor.h"

using namespace vex;

// A global instance of competition
competition Competition;

vex::motor   RightFrontMotor= vex::motor(vex::PORT20);
vex::motor   LeftFrontMotor= vex::motor(vex::PORT19, true);
vex::motor   RightBackMotor= vex::motor(vex::PORT9);
vex::motor   LeftBackMotor= vex::motor(vex::PORT10, true);

vex::motor   LeftSuction= vex::motor(vex::PORT18);
vex::motor   RightSuction= vex::motor(vex::PORT17);

vex::vision VisionSensor(PORT1);









// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  LeftFrontMotor.startRotateFor(vex::directionType::rev, 2400, vex::rotationUnits::deg);
  LeftBackMotor.startRotateFor(vex::directionType::fwd, 2400, vex::rotationUnits::deg);
  RightBackMotor.startRotateFor(vex::directionType::fwd, 2400, vex::rotationUnits::deg);
  RightFrontMotor.rotateFor(vex::directionType::rev, 2400, vex::rotationUnits::deg);

  RightSuction.startRotateFor(vex::directionType::fwd, 1000, vex::rotationUnits::deg);
  LeftSuction.rotateFor(vex::directionType::rev, 1000, vex::rotationUnits::deg);

  while (true){
    Brain.Screen.clearLine();
    Vision1.takeSnapshot(BLUEBALL);
    
    if (Vision1.largestObject.exists) {
    Brain.Screen.print("Vision Sensor");

    }
    
    else  {
    Brain.Screen.print("Vision Sensor: Color Signature Not Found!");
    }
    task::sleep(100);
    }





  //while (Vision1.value() != Vision1.takeSnapshot(REDBALL);


  


  




  // Run the pre-autonomous function.
  pre_auton();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}