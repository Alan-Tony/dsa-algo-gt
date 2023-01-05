#include "../common_headers.hpp"

// Incomplete

class Ball{

    double rx, ry, vx, vy, radius;
    
    public:

    Ball(double rx, double ry, double vx, double vy, double radius):
    rx(rx), ry(ry), vx(vx), vy(vy), radius(radius) {}

    void move(double dt){

        double rx_new = rx + vx*dt, ry_new = ry + vy*dt;
        if(rx_new < radius || rx_new > 1 - radius){

            vx = -vx;
        }

        if(ry_new < radius || ry_new > 1 - radius){

            vy = -vy;
        }
    }

};