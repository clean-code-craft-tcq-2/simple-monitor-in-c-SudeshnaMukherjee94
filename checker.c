#include <stdio.h>
#include <assert.h>

int TemperatureIsNotOk (float temperature){
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 1;
    }
  else return 0;
}

int StateOfChargeOutOfRange (float soc){
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 1;
    }
  else return 0;
}

int ChargeRateOutOfRange (float chargeRate){
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 1;
    }
  else return 0;
}
  
int batteryIsOk(float temp, float state, float charge) {
  int BatteryCondition = 0;
  BatteryCondition = !(TemperatureIsNotOk(temp) || StateOfChargeOutOfRange(state) || ChargeRateOutOfRange(charge));
  return BatteryCondition;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == 1); //battery condition is fine
  assert(batteryIsOk(50, 85, 1) == 0);  //battery condition is not fine
}
