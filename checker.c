#include <stdio.h>
#include <assert.h>

int IsOutOfRange (float Value, float LowerThreshold, float UpperThreshold){
  if(Value < LowerThreshold || Value > UpperThreshold) {
    printf("The value %.1f is out of range!\n", Value);
    return 1;
    }
  else return 0;
}
  
int batteryIsOk(float Temperature, float StateOfCharge, float RateOfCharge) {
  int BatteryCondition = 0;
  BatteryCondition = !(IsOutOfRange(Temperature,0,45) || IsOutOfRange(StateOfCharge,20,80) || IsOutOfRange(RateOfCharge,0,0.8));
  return BatteryCondition;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == 1); //battery condition is fine
  
  //Checking Boundary conditions
  assert(batteryIsOk(1, 79, 0.7) == 1); //battery condition is fine
  assert(batteryIsOk(45, 80, 0.8) == 1); //battery condition is fine
  assert(batteryIsOk(0, 70, 0.9) == 0); //battery condition is not fine
  
  assert(batteryIsOk(50, 85, 1) == 0);  //battery condition is not fine
  assert(batteryIsOk(25, 85, 1) == 0);  //battery condition is not fine
  assert(batteryIsOk(50, 70, 1) == 0);  //battery condition is not fine
  assert(batteryIsOk(50, 85, 0.7) == 0);  //battery condition is not fine
}
