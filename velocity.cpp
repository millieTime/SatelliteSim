/***********************************************************************
 * Header File:
 *    Velocity : Represents the velocity of an object in the artillery
 *    simulation.
 * Author:
 *    Emilio Regino
 * Summary:
 *    Keeps track of a velocity, and provides an easy interface to convert to
 *    and from angle, magnitude, and components.
 ************************************************************************/

#include "velocity.h"     // for the angle class definition

/*****************************************************************
 * VELOCITY : APPLY ACCELERATION
 * Updates the velocity by applying the effect of the given
 * acceleration vector for the specified amount of time
 * velocity += acceleration * time
 ****************************************************************/
void Velocity::applyAcceleration(const Vector2D &accel, double time)
{
   Vector2D delta = Vector2D(accel.getHorComponent() * time, accel.getVertComponent() * time);
   addVector(delta);
}