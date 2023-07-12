# include<iostream>
using namespace std;
    
/*program for final keyword
	For final keyword that function can not override in child Class
*/
class parent
{
	virtual void show() final	
	{
		return ;
	}
};
class child : parent
{
	// void show() //* It give error because it can not replace in child
	// {}
};
