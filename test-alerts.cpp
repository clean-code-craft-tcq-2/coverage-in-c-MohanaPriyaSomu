#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") 
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(35, 15, 30) == TOO_HIGH);
  REQUIRE(inferBreach(38, 10, 40) == NORMAL);
}

TEST_CASE("Passive Cooling Type")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -5) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 13) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
}

TEST_CASE("High Active Cooling Type")
{
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -7) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 22) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 63) == TOO_HIGH);
}

TEST_CASE("Medium Active Cooling Type")
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -2) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 39) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 51) == TOO_HIGH);
}

TEST_CASE("Alert to Controller for Passive Cooling Type")
{
	BatteryCharacter battchar1 = {PASSIVE_COOLING, "Brand1"};
	REQUIRE(checkAndAlert(TO_CONTROLLER, battchar1, -7) == TO_CONTROLLER);
	BatteryCharacter battchar2 = {PASSIVE_COOLING, "Brand2"};
	REQUIRE(checkAndAlert(TO_CONTROLLER, battchar2, 15) == TO_CONTROLLER);
	BatteryCharacter battchar3 = {PASSIVE_COOLING, "Brand3"};
	REQUIRE(checkAndAlert(TO_CONTROLLER, battchar3, 45) == TO_CONTROLLER);
}

TEST_CASE("Mail for Passive Cooling Type")
{
	BatteryCharacter battchar1 = {PASSIVE_COOLING, "Brand1"};
	REQUIRE(checkAndAlert(TO_EMAIL, battchar1, -7) == TO_EMAIL);
	BatteryCharacter battchar2 = {PASSIVE_COOLING, "Brand2"};
	REQUIRE(checkAndAlert(TO_EMAIL, battchar2, 15) == TO_EMAIL);
	BatteryCharacter battchar3 = {PASSIVE_COOLING, "Brand3"};
	REQUIRE(checkAndAlert(TO_EMAIL, battchar3, 45) == TO_EMAIL);
}

TEST_CASE("Alert to Controller for High Active Cooling Type")
{
	BatteryCharacter battchar1 = {HI_ACTIVE_COOLING, "Brand1"};
	REQUIRE(checkAndAlert(TO_CONTROLLER, battchar1, -2) == TO_CONTROLLER);
	BatteryCharacter battchar2 = {HI_ACTIVE_COOLING, "Brand2"};
	REQUIRE(checkAndAlert(TO_CONTROLLER, battchar2, 20) == TO_CONTROLLER);
	BatteryCharacter battchar3 = {HI_ACTIVE_COOLING, "Brand3"};
	REQUIRE(checkAndAlert(TO_CONTROLLER, battchar3, 57) == TO_CONTROLLER);
}

TEST_CASE("Mail for High Active Cooling Type")
{
	BatteryCharacter battchar1 = {HI_ACTIVE_COOLING, "Brand1"};
	REQUIRE(checkAndAlert(TO_EMAIL, battchar1, -2) == TO_EMAIL);
	BatteryCharacter battchar2 = {HI_ACTIVE_COOLING, "Brand2"};
	REQUIRE(checkAndAlert(TO_EMAIL, battchar2, 20) == TO_EMAIL);
	BatteryCharacter battchar3 = {HI_ACTIVE_COOLING, "Brand3"};
	REQUIRE(checkAndAlert(TO_EMAIL, battchar3, 57) == TO_EMAIL);
}
TEST_CASE("Alert to Controller for Medium Active Cooling Type")
{
	BatteryCharacter battchar1 = {PASSIVE_COOLING, "Brand1"};
	REQUIRE(checkAndAlert(TO_CONTROLLER, battchar1, -13) == TO_CONTROLLER);
	BatteryCharacter battchar2 = {PASSIVE_COOLING, "Brand2"};
	REQUIRE(checkAndAlert(TO_CONTROLLER, battchar2, 11) == TO_CONTROLLER);
	BatteryCharacter battchar3 = {PASSIVE_COOLING, "Brand3"};
	REQUIRE(checkAndAlert(TO_CONTROLLER, battchar3, 52) == TO_CONTROLLER);
}

TEST_CASE("Mail for Medium Active Cooling Type")
{
	BatteryCharacter battchar1 = {PASSIVE_COOLING, "Brand1"};
	REQUIRE(checkAndAlert(TO_EMAIL, battchar1, -13) == TO_EMAIL);
	BatteryCharacter battchar2 = {PASSIVE_COOLING, "Brand2"};
	REQUIRE(checkAndAlert(TO_EMAIL, battchar2, 11) == TO_EMAIL);
	BatteryCharacter battchar3 = {PASSIVE_COOLING, "Brand3"};
	REQUIRE(checkAndAlert(TO_EMAIL, battchar3, 52) == TO_EMAIL);
}
