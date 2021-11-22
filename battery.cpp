#include "battery.h"

Battery::Battery()
{
    power=100;
    drain=0.5;
    /*sets up the default battery, Life being 100 and Speed being .5,
    These are just arbitray number which are subject to change. Point being:
    power represents the batteries charge and, while the battery is on, it will be
    decreasing
    */
}

Battery::~Battery()
{
  delete decay_mod;
}
QString Battery::decay()
{
  while (power<0)
  {
    power-=drain;
  }
  charged=false;
  return "Your battery is out of life ";
}
/* Basic decay function. Missing a lot of what we need (being able to run in
the background primarily) but a good starting point. There's two versions
of this function, the second takes in a modifier which is needed for when
the machine is running.

*/
QString Battery::decay(int mod)
{
  while (power<0)
  {
    power-=(drain+(drain*mod));
  }
  charged=false;
  return "Your battery is out of life ";
}
void Battery::charge(){power=100; charged=true;}
//Basic Funct to reset the battery.