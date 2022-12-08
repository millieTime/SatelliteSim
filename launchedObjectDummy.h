/***********************************************************************
 * Header File:
 *    Launched Object Dummy: A Dummy for the launched object class
 * Author:
 *    Preston Millward and Gergo Medveczky
 * Summary:
 *    The Launched Object class, but all public methods (besides default constructor)
 *    contain assert(false)
 ************************************************************************/

#pragma once
#include "LaunchedObject.h"
#include <cassert>

class LaunchedObjectDummy : public LaunchedObject
{
public:
    // Default constructor for Dummy
   LaunchedObjectDummy() : LaunchedObject() {}
    // Dummies
   virtual void launch(const Position& p, const Velocity& v) {assert(false);}
   virtual void draw() const {}
   virtual double getRadius() const { return 0.0; }
};
