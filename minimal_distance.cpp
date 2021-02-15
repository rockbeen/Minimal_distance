#include <iostream>
#include <cmath>
using namespace std;
class minimal  {
	
public:
	minimal()//constructor 
	{	
		while(1)
		{	
			cout<<"Enter the first pair of dots:\n"<<"1)\n";
			input_validation(xa);//performing input verification
			input_validation(ya);
			cout<<"2)\n";
			input_validation(xb);
			input_validation(yb);
			cout<<"Enter the second pair of dots:\n"<<"1)\n";
			input_validation(xc);
			input_validation(yc);
			cout<<"2)\n";
			input_validation(xd);
			input_validation(yd);
			if (!((xa==xb&&ya==yb)||(xc==xd&&yc==yd)))//check for the presence of points
				break;
			else 
				cout<<"You need to enter segments, not points";
			}
		}
	
	void distance(){//method for finding the minimum distance between segments

		if (intersection()) //checking the intersections of the segments
		{ 
			dl=minimum_height(xa,ya,xb,yb,xc,yc); 	//find the lowest height omitted from the end of one segment to the other
			answer=dl;								//updating the smallest
			dl=minimum_height(xa,ya,xb,yb,xd,yd); 	//similarly for the others
			if((dl<answer&&dl!=-1)||answer==-1)answer=dl;	//if we find less, we update it
			dl=minimum_height(xc,yc,xd,yd,xa,ya);
			if((dl<answer&&dl!=-1)||answer==-1)answer=dl;
			dl=minimum_height(xc,yc,xd,yd,xb,yb);
			if((dl<answer&&dl!=-1)||answer==-1)answer=dl;
			if(answer==-1)//if it is impossible to lower the height, then find the minimum distance between the ends of the segment
			{
				dl=sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
				answer=dl;
				dl=sqrt((xb-xd)*(xb-xd)+(yb-yd)*(yb-yd));
				if(dl<answer)answer=dl;
				dl=sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
				if(dl<answer)answer=dl;
				dl=sqrt((xa-xd)*(xa-xd)+(ya-yd)*(ya-yd));
				if(dl<answer)answer=dl;
				}
    }
    cout<<answer;}
    private:
     double xa, xb, xc, xd, ya, yb, yc, yd, dl, answer;
     bool intersection()//method to check the intersections
	{	
		double delta,delta1,delta2;
		delta=(xb-xa)*(-yd+yc)-(yb-ya)*(-xd+xc);//the method Of Kramer
		delta1=(xb-xa)*(yc-ya)-(yb-ya)*(xc-xa);
		delta2=(-yd+yc)*(xc-xa)-(-xd+xc)*(yc-ya);
		
		if(delta!=0&&delta1/delta>=0&&delta2/delta>=0&&delta1/delta<=1&&delta2/delta<=1)//if there is an intersection, the minimum distance is 0
		{	
		   answer=0;
		   return 0;
			}
		else
		   return 1;
		}
    
    double minimum_height(double x1, double y1, double x2, double y2, double x3, double y3)//method for finding the lowest height omitted from the end of one segment to the other
    {
		double k,d,x;
		if(x1==x2)//if the segment is vertical, make it horizontal
		{
			swap(x1, y1);
			swap(x2, y2);
			swap(x3, y3);
			}
		k=(y1-y2)/(x1-x2);//looking for the coefficients of the equation of a straight line
		d=y1-k*x1;
		x=(x3*x2-x3*x1+y2*y3-y1*y3+y1*d-y2*d)/(k*y2-k*y1+x2-x1);//finding the coordinates of the point from which the height was omitted
		if((x<=x2 && x>=x1)||(x<=x1 && x>=x2))//let's check whether the base of the height will lie on the segment.
			return sqrt((x3-x)*(x3-x)+(y3-x*k-d)*(y3-x*k-d));	//return its length if it lies
		else
			return -1;//if not, return -1
			
			}
		void input_validation(double &value)//input validation
		{
			double a;
			while(1)
			{
				cin>>a;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767,'\n');
					cout << "Oops, that input is invalid. Please try again.\n";
					}
				else
				{	
					cin.ignore(32767,'\n');
					value=a;
					break;
					}
		
				}
			}
};

int main() {
	minimal example; 
	example.distance();
	
    return 0;
}
