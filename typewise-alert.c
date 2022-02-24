#include "typewise-alert.h"
#include <stdio.h>

const char* mailMessage[] = {"Hi, the temperature is too normal", "Hi, the temperature is too low", "Hi, the temperature is too high"};
double range_lower_upper[3][2] = {{0,35}, {0,45}, {0,40}};

BreachType inferLowerBreach(double value, double lowerLimit)
{
	return((value < lowerLimit) ? (TOO_LOW) : (NORMAL));
}

BreachType inferUpperBreach(double value, double upperLimit)
{
	return((value > upperLimit) ? (TOO_HIGH) : (NORMAL));
}

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  BreachType breach1 = inferLowerBreach(value, lowerLimit);
  BreachType breach2 = inferUpperBreach(value, upperLimit);
  BreachType breach = BreachType(int(breach1) + int(breach2));
  return breach;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  double lowerLimit = range[int(coolingType)][0];
  double upperLimit = range[int(coolingType)][1];
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  (alertTarget == TO_CONTROLLER) ? sendToController(breachType) : sendToEmail(breachType);
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);
  printf(mailMessage[breachType]);
}
