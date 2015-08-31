#include<iostream>
#include<cstdlib>
#include<math.h>
#include<cstdio>
#include<list>

using namespace std;

class Point {
	public:
	   double x;
	   double y;
	   
	Point(){
        this->x=0;
        this->y=0;
    }
	
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Point subtract(Point p) {
		Point aux;
		aux.x=this->x-p.x;
		aux.y=this->y-p.y;
		return aux;
        //return new Point(x - (p.x), y - (p.y));
	}
	double distance(Point p) {
		return hypot(x - p.x, y - p.y);;
	}
	// Signed area / determinant thing
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
	// Magnitude squared
	double norm() {
		return x * x + y * y;
	}
};

class Circle {
	public: 
	   double static const EPSILON = 1e-12;
	   Point c;   // Center
	   double r;  // Radius
	
	Circle(){
        this->c.x=-1;
        this->c.y=-1;
		this->r = -1;
    }
	
	Circle(Point c, double r) {
		this->c = c;
		this->r = r;
	}
	bool contains(Point p) {
		return (c.distance(p) <= r + EPSILON);
	}
	bool contains(list<Point> ps) {
		for (list<Point>::iterator it=ps.begin(); it != ps.end(); ++it) {
			if (!contains(*it))
				return false;
		}
		return true;
	}
};
	
Circle makeDiameter(Point a, Point b) {
    Circle aux;
    Point c;
    double r;
    c.x=(a.x + b.x)/ 2.0;
    c.y=(a.y + b.y) / 2.0;
    r=a.distance(b) / 2.0;
    aux.c=c;
    aux.r=r;
	return aux;
}

Circle makeCircumcircle(Point a, Point b, Point c) {
	double d = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2;
	Circle aux;
	if (d == 0)
		return aux;
	aux.c.x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y - b.y)) / d;
	aux.c.y = (a.norm() * (c.x - b.x) + b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x)) / d;
	aux.r=aux.c.distance(a);
	return aux;
}

Circle makeCircleTwoPoints(list<Point> points, Point p, Point q) {
	Circle temp = makeDiameter(p, q);
	if (temp.contains(points))
		return temp;
	
	Circle left;
	Circle right;
	for (list<Point>::iterator it=points.begin(); it != points.end(); ++it) {  // Form a circumcircle with each point
		Point pq = q.subtract(p);
		double cross = pq.cross((*it).subtract(p));
		Circle c = makeCircumcircle(p, q, (*it));
		if (c.r==-1)
			continue;
		else if (cross > 0 && (left.r==-1 || pq.cross(c.c.subtract(p)) > pq.cross(left.c.subtract(p))))
			left = c;
		else if (cross < 0 && (right.r==-1 || pq.cross(c.c.subtract(p)) < pq.cross(right.c.subtract(p))))
			right = c;
	}
	return right.r==-1 || left.r!=-1 && left.r <= right.r ? left : right;
}

Circle makeCircleOnePoint(list<Point> points, Point p) {
	Circle c; //new Circle(p, 0)
	c.c.x=p.x;
	c.c.y=p.y;
	c.r=0;
	for (list<Point>::iterator it=points.begin(); it != points.end(); ++it) {
		Point q = (*it);
		if (!c.contains(q)) {
			if (c.r == 0){
				c = makeDiameter(p, q);
            }
			else{
                list<Point> aux;
                for(list<Point>::iterator ite=points.begin(); ite!=it; ++ite){
                    aux.push_back(*ite);
                } 
				c = makeCircleTwoPoints(aux, p, q);
            }
		}
	}
	return c;
}

Circle makeCircle(list<Point> points) {
	// Clone list to preserve the caller's data, randomize order
	list<Point> shuffled = points;
	//Collections.shuffle(shuffled, new Random());
	
	// Progressively add points to circle or recompute circle
	Circle c;
	for (list<Point>::iterator it=shuffled.begin(); it != shuffled.end(); ++it){
		Point p = (*it);
    	if (c.r==0 || !c.contains(p)){
    		    list<Point> aux;  
    		    for(list<Point>::iterator ite=shuffled.begin(); ite!=it; ++ite){
                    aux.push_back(*ite);
                } 
    			c = makeCircleOnePoint(aux, p);
        }
	}
	return c;
}

int main(){
    
    return 0;
}
