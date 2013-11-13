/*  ElasticCollision Implementation File
    CSC350, Final Project
    Created by Joseph Canero
 
    This is the implementation file of the ElasticCollision header and contains definitions of several functions that will be used to ensure realistc motion is achieved for the pool simulator
 */

#include "ElasticCollision.h"

//function compute the movement of a particular ball
//the movement angle is computed as asin( (abs(y-component))/(magnitude of velocity) )
double calculateTheta(PoolBall Ball) {
    double x = Ball.getXComponent();
    double y = Ball.getYComponent();
    double z = Ball.getZComponent();
    double magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    if (magnitude == 0.0) return 0;
    else return asin((std::abs(y))/(magnitude));
    
}

//function to compute the collision angle between two balls
//the collision angle is computed as atan( (y2Loc - y1Loc)/(x2Loc - x1Loc) )
double calculatePhi(PoolBall Ball1, PoolBall Ball2) {
    double dy = (Ball2.getYLocation() - Ball1.getYLocation());
    double dx = (Ball2.getXLocation() - Ball2.getXLocation());
    if (dx == 0.0) return 1.570796326;
    else return atan( dy/dx );
}

/*  this next function accepts two parameters that are both PoolBall objects
 
    The pool ball program I am writing is effectively simulating a 2D environment for the balls as they are unable to leave the table and lie along the plane of the tabletop.
    
    BEWARE! Scary physics follows...
 
    Elastic Collisions are collisions in which the total kinetic energy of the bodies before the collision is equal to the total kinetic energy after.
    The velocities of the two balls after the collision will be determined via the four equations:
 
    Ball1 X-component: 
        ((b1x * cos(theta1 - phi) * (mass1 - mass2) + 2 * mass2 * b1y * cos(theta2 - phi))/(mass1 + mass2))*cos(phi)+b1x*sin(theta1 - phi)*cos(phi + pi/2)
 
    Ball1 Y-component:
        ((b1x * cos(theta1 - phi) * (mass1 - mass2) + 2 * mass2 * b1y * cos(theta2 - phi))/(mass1 + mass2))*sin(phi)+b1x*sin(theta1 - phi)*sin(phi + pi/2)
 
    Ball2 X-component:
        ((b2y * cos(theta2 - phi) * (mass2 - mass1) + 2 * mass1 * b2x * cos(theta2 - phi))/(mass1 + mass2))*cos(phi)+b2y*sin(theta2 - phi)*cos(phi + pi/2)
 
    Ball2 Y-component:
        ((b2y * cos(theta2 - phi) * (mass2 - mass1) + 2 * mass1 * b2x * cos(theta2 - phi))/(mass1 + mass2))*sin(phi)+b2y*sin(theta2 - phi)*sin(phi + pi/2)
 
    These equations use several variables that will need to be either A) calculated with via functions or B) retrieved from each ball
 */
void ComputeElasticCollision(PoolBall &Ball1, PoolBall &Ball2) {
    if (Ball1 != Ball2) { //only  do the calculation if the balls colliding are two different objects
//        if (sqrt((pow(Ball2.getXComponent(),2) + pow(Ball2.getYComponent(),2)))  - testFloat < 0.0 || sqrt((pow(Ball2.getXComponent(),2) + pow(Ball2.getYComponent(),2)))  - testFloat < 0.0) {
//            /*std::cout << "COMPUTING A CASE ONE BALL IS NOT MOVING" << std::endl;
//            std::cout << "*********************************************" << std::endl;
//            //Ball 2 is not moving or Ball 1 is not moving
//            //SET UP ALL NEEDED VARIABLES
//            //velocity variables
//            double b1x = Ball1.getXComponent();
//            double b1y = Ball1.getYComponent();
//            double b2x = Ball2.getXComponent();
//            double b2y = Ball2.getYComponent();
//            
//            //mass variables
//            float mass1 = Ball1.getMass();
//            float mass2 = Ball2.getMass();
//            //change in mass
//            float dm = mass2 - mass1;
//            
//            //slope
//            double dydx = (Ball2.getYComponent() - Ball1.getYComponent())/(Ball2.getXComponent() - Ball1.getXComponent());
//            
//            double dvx2 = (-2 * (b2x - b1x) + dydx * (b2y - b1y))/((1 + dydx * dydx)*(1 + dm));
//            b2x = b2x + dvx2;
//            b2y = b2y + dydx * dvx2;
//            b1x = b1x - dm*dvx2;
//            b1y = b1y - dydx*dm*dvx2;
//            
//            //BALL1
//            Ball1.setXComponent(b1x);
//            Ball1.setYComponent(b1y);
//            
//            //BALL2
//            Ball2.setXComponent(b2x);
//            Ball2.setYComponent(b2y);
//    
//            std::cout << "RESULTS: 1x: " << b1x << " 1y: " << b1y << " 2x: " << b2x << " 2y: " << b2y << std::endl;
//            std::cout << "RESULTS: 1x: " << Ball1.getXComponent() << " 1y: " << Ball1.getYComponent() << " 2x: " << Ball2.getXComponent() << " 2y: " << Ball2.getYComponent() << std::endl;*/
//            double nX = Ball1.getXComponent() - Ball2.getXComponent();
//            double nY = Ball1.getYComponent() - Ball2.getYComponent();
//            double nMag = sqrt( pow(nX, 2) + pow(nY, 2) );
//            std::cout << "NORMAL X: " << nX << " NORMAL Y: " << nY << std:: endl;
//            std :: cout << "MAGNITUDE: " << nMag << std::endl;
//            nX /= nMag; nY /= nMag;
//            
//            Ball2.setXComponent(Ball1.getXComponent() * -nX * -nX);
//            Ball2.setYComponent(Ball1.getYComponent() * -nY * -nY);
//            
//            double unitOrigVelMag = sqrt( pow(Ball1.getXComponent() ,2) + pow(Ball1.getYComponent(), 2) );
//            double unitOrigVelX = Ball1.getXComponent() / unitOrigVelMag;
//            double unitOrigVelY = Ball1.getYComponent() / unitOrigVelMag;
//            std::cout << "ORIG X: " << unitOrigVelX << " ORIG Y: " << unitOrigVelY << std::endl;
//            double theta = acos( nX * (-unitOrigVelX) + nY * (-unitOrigVelY) );
//            
//            double newVelX = (nX * cos(theta) - nY * sin(theta));
//            double newVelY = (nX * sin(theta) - nY * cos(theta));
//            std::cout << "NEW VEL X: " << newVelX << " NEW VEL Y: " << newVelY << std::endl;
//            Ball1.setXComponent(-Ball1.getXComponent() * nX * newVelX);
//            Ball1.setYComponent(-Ball1.getYComponent() * nY * newVelY);
//            
//        }
//        else { //Both balls are moving
//            std::cout << "in this shit" << std::endl;
//            //SET UP ALL NEEDED VARIABLES
//            //velocity variables
//            /*double b1x = Ball1.getXComponent();
//            double b1y = Ball1.getYComponent();
//            double b2x = Ball2.getXComponent();
//            double b2y = Ball2.getYComponent();
//            
//            //mass variables
//            float mass1 = Ball1.getMass();
//            float mass2 = Ball2.getMass();
//            
//            //theta
//            double theta1 = calculateTheta(Ball1);
//            double theta2 = calculateTheta(Ball2);
//            //phi
//            double phi = calculatePhi(Ball1, Ball2);
//            //CALCULATE THE NEW COMPONENTS FOR EACH BALL
//            double ball1X = ((b1x * cos(theta1 - phi) * (mass1 - mass2) + 2 * mass2 * b1y * cos(theta2 - phi))/(mass1 + mass2))*cos(phi)+b1x*sin(theta1 - phi)*cos(phi + PI/2);
//            
//            double ball1Y =  ((b1x * cos(theta1 - phi) * (mass1 - mass2) + 2 * mass2 * b1y * cos(theta2 - phi))/(mass1 + mass2))*sin(phi)+b1x*sin(theta1 - phi)*sin(phi + PI/2);
//            
//            double ball2X = ((b2y * cos(theta2 - phi) * (mass2 - mass1) + 2 * mass1 * b2x * cos(theta2 - phi))/(mass1 + mass2))*cos(phi)+b2y*sin(theta2 - phi)*cos(phi + PI/2);
//            
//            double ball2Y = ((b2y * cos(theta2 - phi) * (mass2 - mass1) + 2 * mass1 * b2x * cos(theta2 - phi))/(mass1 + mass2))*sin(phi)+b2y*sin(theta2 - phi)*sin(phi + PI/2);
//            
//            //UPDATE THE VELOCITY FOR EACH BALL
//            //BALL 1
//            Ball1.setXComponent(ball1X);
//            Ball1.setYComponent(ball1Y);
//            
//            //BALL2
//            Ball2.setXComponent(ball2X);
//            Ball2.setYComponent(ball2Y);*/
//            Ball1.setXComponent(Ball2.getXComponent());
//            Ball1.setYComponent(Ball2.getYComponent());
//            
//            //BALL2
//            Ball2.setXComponent(Ball1.getXComponent());
//            Ball2.setYComponent(Ball1.getYComponent());
//            
//            
//            
//            
//            
//            /*newVelX1 =  (2 * secondBall.speed.x)) / (firstBall.mass + secondBall.mass);
//            newVelY1 =  (2 * secondBall.speed.y)) / (firstBall.mass + secondBall.mass);
//            newVelX2 =  (2 * firstBall.speed.x)) / (firstBall.mass + secondBall.mass);
//            newVelY2 =  (2 * firstBall.speed.y)) / (firstBall.mass + secondBall.mass);*
//
        double tempX = .5 * Ball1.getXComponent();
        double tempY = .5 * Ball1.getYComponent();
        Ball1.setXComponent(.5 * tempX + Ball2.getXComponent());
        Ball1.setYComponent(.5 * tempY + Ball2.getYComponent());
        Ball2.setXComponent(tempX);
        Ball2.setYComponent(tempY);
        std::cout << "BALL 1 X: " << Ball1.getXComponent() << " BALL 1 Y: " << Ball1.getYComponent() << " BALl 2 X: " << Ball2.getXComponent() << " BALL 2 Y: " << Ball2.getYComponent() << std::endl;
        //}
    }
}