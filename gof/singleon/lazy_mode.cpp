#include <iostream>
#include <unistd.h>

using namespace std;

class Singleon
{
private:
	Singleon()
	{
		cout << "Singleon()" << endl;
	}
	static Singleon*instance;
public:
	static Singleon* GetSingleon()
	{
		if (NULL == instance)
		{
			instance = new Singleon();
			cout << "instance is created successfully!" << endl;
		}
		else
		{
			cout << "instance was already created, don't create instance again!" << endl;
		}
		return instance;
	}
	static Singleon* Destroy()
	{
		delete instance;
		instance = NULL;
	}
};

Singleon* Singleon::instance =  NULL;
int main()
{
	Singleon* sl1 = Singleon::GetSingleon();
	Singleon* sl2 = Singleon::GetSingleon();
	Singleon* sl3 = Singleon::GetSingleon();
	cout << sl1 << endl;
	cout << sl2 << endl;
	cout << sl2 << endl;
	
	pause();

	return 0;
}
