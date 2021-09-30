#include <iostream>

using namespace std;

class Shape
{
    public:
        virtual float comp_area()=0;
        virtual float comp_perimeter()=0;
};
class Polygon: public Shape
{
};
class Rectangle: public Polygon
{
    float len,brdh,area,perimeter;
    public:
        Rectangle(float l, float b)
        {
            len = l;
            brdh = b;
        }
        float comp_area()
        {
            area = len*brdh;
            return area;
        }
        float comp_perimeter()
        {
            perimeter = 2*(len+brdh);
            return perimeter;
        }
};
class Circle: public Shape
{
    float rad,area,perimeter;
    public:
        Circle(float r)
        {
            rad = r;
        }
        float comp_area()
        {
            area = 3.14*rad*rad;
            return area;
        }
        float comp_perimeter()
        {
            perimeter = 6.28*rad;
            return perimeter;
        }
};
int main()
{
    Shape* a[100];
    int i,count = 0;
    char ch;
    float l,b,r;
    cout<<"------Shape Area Menu------ ";
    cout<<"\n1)Rectangle ";
    cout<<"\n2)Circle ";
    do
    {
        cout<<"\nEnter your choice: ";
        cin>>i;
        switch(i)
        {
            case 1: cout<<"Enter length and breadth: ";
                    cin>>l>>b;
                    a[count] = new Rectangle(l,b);
                    cout<<"Area: "<<a[count]->comp_area();
                    cout<<"\tPerimeter: "<<a[count]->comp_perimeter();
                    count++;
                    break;
            case 2: cout<<"Enter radius: ";
                    cin>>r;
                    a[count] = new Circle(r);
                    cout<<"Area: "<<a[count]->comp_area();
                    cout<<"\tPerimeter: "<<a[count]->comp_perimeter();
                    count++;
                    break;
            default: cout<<"Enter either 1 or 2.";
                     break;
        }
        cout<<"\nWant to add more?(y/n): ";
        cin>>ch;
    }while(ch == 'Y'||ch == 'y');

    return 0;
}
