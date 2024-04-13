/*
  - Drain Sweeper
  - Embedded code to unclog drains in cities and towns
  - Uses Step motor and water sensor
  - NJIT Hackathon 2024
*/

//Include the Arduino stepper library
#include <Stepper.h>

//sensor pin connected to analog pin A0
const int sensorPin= 0; 
int liquid_level;

//Set how many steps it takes to make a full revolution
//Divide the degrees per step by 360 to get the steps
const int stepsPerRevolution = 2048;

//Use pin 8-11 to IN1-IN4
Stepper stepper1 = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper stepper2 = Stepper(stepsPerRevolution, 0, 2, 1, 3);

void setup() {
  // put your setup code here, to run once:

  //Set the RPM of the stepper motor
  stepperName.setSpeed(15);

  Serial.begin(9600); //sets the baud rate for data transfer in bits/second
  pinMode(sensorPin, INPUT);

}

void sweepDrain() {
  //Calibrate to sweep the entire drain length
  stepper1.step(stepsPerRevolution);
  delay(1000);
  stepper1.step(stepsPerRevolution);
}

void loop() {
  // put your main code here, to run repeatedly:
  liquid_level= analogRead(sensorPin); //arduino reads the value from the liquid level sensor
  Serial.println(liquid_level);//prints out liquid level sensor reading
  int counter = 0;
  while(liquid_level > 600)
  {
    counter++;
    delay(500)
    liquid_level= analogRead(sensorPin);
    if (liquid_level > 600){ counter++; }
  }

}

