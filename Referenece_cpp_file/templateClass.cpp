#include<iostream>
using namespace std;

#define V(pratik) cout << "pratik Solanki :" #pratik << endl;

class Base
{
	private : 
			int a;

	public: 
			Base(){}
			Base(int b) : a(b){}
			void display(){
				cout << a << endl;
			} 
};

template <typename T>
class Derived : public T
{
public:
	Derived(string str, int a) : name(str), T(a){}
	void display(){
		cout << "NAME :" <<  name << endl;
		T :: display();
	}
private:
	string name;	

};


int main(int argc, char const *argv[])
{
	
	Base b;
	Derived<Base> derived("pratik", 20);

	derived.display();
	//b.display();

	V(false);

	return 0;
}