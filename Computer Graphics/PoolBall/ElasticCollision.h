/*  ElasticCollision Header
    CSC350, Final Project
    Created by Joseph Canero
 
    This is a header file that contains the declaration of a function that will handle elastic collisions between two pool balls
 */

#ifndef __PoolBall__ElasticCollision__
#define __PoolBall__ElasticCollision__

#define PI 3.141596

#include "PoolBall.h"
#include <iostream>
//function to update the velocities of two pool balls if they are colliding
void ComputeElasticCollision(PoolBall &Ball1, PoolBall &Ball2);

//function to compute the movement angle (theta) of a ball for use in the collision equations
double calculateTheta(PoolBall Ball);

//function to compute the collision angle (phi) of the balls for use in the collision equations
double calculatePhi(PoolBall Ball1, PoolBall Ball2);


#endif /* defined(__PoolBall__ElasticCollision__) */
