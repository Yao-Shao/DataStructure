#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point{
    private:
      int x;
      int y;   
    public:
      void setX(int xx){
          x = xx;
      }
      void setY(int yy){
          y = yy;
      }
      int getX(void) const{
          return this->x;
      }
      int getY(void) const{
          return this->y;
      }
      Point(int x, int y){
          setX(x);
          setY(y);
      }
      Point(void){
          setX(0);
          setY(0);
      }
};

int main()
{
    Point p1, p2;
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    p1.setX(x1);
    p1.setY(y1);
    p2.setX(x2);
    p2.setY(y2);
    double x = p1.getX() - p2.getX();
    double y = p1.getY() - p2.getY();
    double len = sqrt(x * x + y * y);
    cout << fixed << setprecision(2) << len << endl;
	
	  const Point p3(5,5);
	  const Point p4(20,30);
	  x = p3.getX() - p3.getX();
	  y = p3.getY() - p4.getY();
    len = sqrt(x * x + y * y);
    cout << fixed << setprecision(2) << len << endl;
	
    return 0;
}