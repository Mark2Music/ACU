#include <iostream>
#include <unistd.h>

using namespace std;

//设计一个类，只能生成该类的一个实例
//饿汉式单例模式：在类加载时就完成了初始化，所以类加载比较慢、获取对象的速度快、以空间换取时间
//优点：线程安全
//缺点：不管你用不用这个对象，他都会先创建出来，会造成浪费内存空间
class Singleon
{
private:
	Singleon()
	{
		cout << "Singleon()" << endl;
	}
	static Singleon* instance;

public:
	static Singleon* GetSingleon()
	{
		return instance;
	}
	static Singleon* Destroy()
	{
		delete instance;
		instance = NULL;
	}
};


Singleon* Singleon::instance = new Singleon();

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
