#include <stdio.h> 

void hello(void) 
{
	fprintf(stderr, "hello!\n"); 
} 

void func(void) 
{ 
	void *buf[10]; 
	static int i; 
	
	for (i = 0; i < 100; i++) 
	{ //←越界！ 
		buf[i] = hello; 
	} 
}

/*
 *在早期的编译器中，这样做，会导致hello被调用多次，因为栈空间被覆盖甚至溢出
 *但是现在的编译器，不会出现调用hello多次，直接出现 stack smashed
 * */
int main(void)
{
	int buf[1000];
	
	func(); 
	
	return 0;
}
