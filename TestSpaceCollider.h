//
//  TestOrbitSimulator.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/8/22.
//

#ifndef TestOrbitSimulator_h
#define TestOrbitSimulator_h
#include "Sputnik.h"
#include "Fragment.h"
#include <stdio.h>
#include "position.h"
#include "acceleration.h"
#include <list>
#include <cassert>


class TestSpaceCollider
{
private:
    friend class SpaceCollider;
    friend class Sputnik;
    friend class Fragment;
public:
    void run()
    {
        testDefaultConstructor();
        testConstructorWithPosVel();
        testConstructorwithObj();
        testgetGenter();
        testgetRadius();
        testCollidesWith();
        testgetGravity();
        testonCollision();
        testAdvance();
        testIsTimedOut();
    }
    
    void testDefaultConstructor()
    {
        //setup
        //exercise
        Sputnik s;
        //verify
        
        //assert(s != NULL);
        
        //teardown
    }
    
    void testConstructorWithPosVel()
    {
        //setup
        Position p = Position();
        Velocity v = Velocity();
        Sputnik s = Sputnik(p,v);
        //exercise
        //verify
        //teardown
        
    }
    void testConstructorwithObj()
    {
        //setup
        Sputnik s = Sputnik(200,200);
        Fragment f = Fragment(200,200);
        
        //exercise
        s = Sputnik(&f);
        //verify
        //assert(s == );
        //teardown
    }
    void testgetGenter()
    {
        //setup
        Sputnik s = Sputnik(200,200);
        //exercise
        Position center = s.getCenter()
        //verify
        assert(center.getMetersX() == );
        assert(center.getMeterY() == );
        //teardown
    }
    void testgetRadius()
    {
        //setup
        Sputnik s = Sputnik(200,200);
        //exercise
        double radius = s.getRadius();
        //verify
        
        //assert(radius == );
        
        //teardown
    }
    void testCollidesWith()
    {
        //setup
        Sputnik s = Sputnik(200,200);
        Fragment f = Fragment(200,200);
        //exercise
        
        //verify
        //teardown
    }
    void testgetGravity()
    {
        //setup
        Sputnik s = Sputnik(200,200);
        //exercise
        Acceleration gravity = s.getGravity();
        //verify
        assert(s == );
        //teardown
    }
    void testonCollision()
    {
        //setup
        Sputnik s = Sputnik(200,200);
        Fragment f = Fragment(200,200);
        list<SpaceCollider*> collider;
        collider.insert(s, f);
        
        //exercise
        s.onCollision(&collider);
        //verify
        
        //teardown
    }
    void testAdvance()
    {
        //setup
        Sputnik s = Sputnik(200,200);
        double seconds = 5;
        //exercise
        s.advance(seconds);
        //verify
        assert();
        //teardown
    }
    void testIsTimedOut()
    {
        //setup
        Fragment f;
        f.second = 0;
        //exercise
        bool timedOut = f.isTimedOut();
        //verify
        assert(timedOut == true);
        //teardown
    }
};
#endif /* TestOrbitSimulator_h */
