#include <stdio.h>
#include <assert.h>

int TemperatureIsOk (float temperature)
{
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
    }
  else return 1;
}

int StateOutOfRange (float soc)
{
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
    }
  else return 1;
}

int ChargeRateOutOfRange (float chargeRate)
{
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
    }
  else return 1;
}
  
int batteryIsOk(float temperature, float soc, float chargeRate) {

  int Result = 0;
  Result = TemperatureIsOk(temperature) || StateOutOfRange(soc) || ChargeRateOutOfRange(chargeRate);
  return Result;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));

}
