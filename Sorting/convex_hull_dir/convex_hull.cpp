#include "../../common_headers.hpp"
#include "../../utils.hpp"

struct Point{

    double x;
    double y;

    Point(double x=0, double y=0): x(x), y(y)
    {
    }

    Point operator-(const Point& a) const{

        return Point(x - a.x, y - a.y);
    }

    Point operator+(const Point& a) const{

        return Point(x + a.x, y + a.y);
    }
};


bool lessY(Point a, Point b){

    return a.y < b.y;
}

bool lessPolarAngle(Point a, Point b){  //Against point (0, 0)

    assert(a.y >= 0 && b.y >= 0);   //Since reference point is bottom-most point
    if(a.x * b.x <= 0){

        return a.x > b.x;
    }
    else{

        return a.y / a.x < b.y / b.x;
    }
}

bool counter_clock_wise(Point a, Point b, Point c){

    double area= (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if(area > 0){

        return true;
    }
    else{

        return false;
    }
}


vector<Point> convex_hull(vector<Point> points){

    sort(points.begin(), points.end(), lessY);
    vector<Point> points2(points);
    //Points with new origin as point with smallest y-coordinate
    for(int i=0; i<points.size(); i++){

        points2[i]= points2[i] - points[0];
    }

    //Sort by polar angle with referene to origin (points2[0])
    sort(points2.begin() + 1, points2.end(), lessPolarAngle);

    //Find convex hull
    stack<Point> hull;
    hull.push(points2[0]);  //Definitely on the hull
    hull.push(points2[1]);
    Point a, b, c;
    for(int i=2; i < points2.size(); i++){

        c = points2[i];
        b = hull.top();
        hull.pop();
        a = hull.top();
        while(hull.size() > 1 && !counter_clock_wise(a, b, c)){

            b = a;
            hull.pop();
            a = hull.top();
        }
        if(counter_clock_wise(a, b, c)){    //if while loop terminated due to hull.size() <= 1, there is a need to check for 
                                            //counter clock-wise before pushing back b, because counter_clock_wise() could be false
            
            hull.push(b);
        }
        hull.push(c);
    }

    //Hull with original origin
    vector<Point> hull_new_origin;    
    while(!hull.empty()){

        hull_new_origin.push_back(hull.top() + points[0]);
        hull.pop();
    }

    return hull_new_origin;
}

void printPoints(vector<Point>& points){

    cout<<"\n";
    for(auto p: points){

        cout<<"("<<p.x<<", "<<p.y<<")\t";
    }
    cout<<"\n";
}

int main(){

    //Generating random coordinates
    int num_points= 50;
    auto t= time(0);
    vector<double> x_cords= rand_vector_double(num_points, -1000, 1000, t);
    vector<double> y_cords= rand_vector_double(num_points, -1000, 1000, t+1);

    //Creating points
    vector<Point> points;
    for(int i=0; i<num_points; i++){

        points.push_back(Point(x_cords[i], y_cords[i]));
    }
    cout<<"\nInput points:";
    printPoints(points);

    vector<Point> hull = convex_hull(points);
    cout<<"\nPoints of Convex hull:";
    printPoints(hull);

    //Writing points and hull into files
    ofstream ofile;
    ofile.open("points.txt", ios::trunc);
    for(Point p: points){

        ofile<<p.x<<" "<<p.y<<"\n";
    }
    ofile.close();

    ofile.open("hull.txt", ios::trunc);
    for(Point p: hull){

        ofile<<p.x<<" "<<p.y<<"\n";
    }
    ofile.close();

    cout<<"\n";
    return 0;
}