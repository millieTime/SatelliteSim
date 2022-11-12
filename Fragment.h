//
//  Fragment.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/12/22.
//

#ifndef Fragment_hpp
#define Fragment_hpp
#include "SpaceCollider.h"
#include <stdio.h>

class TestSpaceCollider;
class Fragment :public SpaceCollider
{
private:
   double seconds;
public:
   friend class TestSpaceCollider;
    Fragment()
    {
        
    }
    Fragment(Position p, Velocity v)
    {
        
    }
    void draw()
    {
        
    }
};

#endif /* Fragment_hpp */
