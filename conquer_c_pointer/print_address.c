#include <stdio.h>
#include <stdlib.h>

int global_variable; 
static int file_static_variable;

void func1(void) 
{ 
	int func1_variable; 
	static int func1_static_variable; 
	printf("&func1_variable..%p\n", &func1_variable); 
	printf("&func1_static_variable..%p\n", &func1_static_variable);
}

void func2(void) 
{ 
	int func2_variable; 
	printf("&func2_variable..%p\n", &func2_variable);
}

int main(void)
{ 
	int *p;

	/*输出指向函数的指针*/
	printf("&func1..%p\n", func1);
	printf("&func2..%p\n", func2);
	
	/*输出字符串常量的地址*/ 
	printf("string literal..%p\n", "abc");
	
	/*输出全局变量*/ 
	printf("&global_variable..%p\n", &global_variable);
	
	/*输出文件内的static 变量的地址*/
	printf("&file_static_variable..%p\n", &file_static_variable); 
	
	/*输出局部变量*/ 
	func1();
	func2();
	
	/*通过malloc 申请的内存区域的地址*/
	p = malloc(sizeof(int)); 
	printf("malloc address..%p\n", p);
        free(p);

	//在书中，char *str = "abc",字符串可以被修改，本电脑的编译器不行了(ubuntu 18.04)
	char *string = "abcde";
	char *str = string;
	str[0] = 'n';	
	
	return 0;
}

/*
 *&func1..0x556ac1a216fa
 *&func2..0x556ac1a21758
 *string literal..0x556ac1a21942
 *&global_variable..0x556ac1c2201c
 *&file_static_variable..0x556ac1c22014
 *&func1_variable..0x7ffd2ef41954
 *&func1_static_variable..0x556ac1c22018
 *&func2_variable..0x7ffd2ef41954
 *malloc address..0x556ac3a02670
 *
 *   内存分布
 *
 * 各个函数自身和字符串常量在一个区域
 * 全局变量，各个函数内静态变量，文件内静态变量在一个区域
 * 利用malloc分配的变量 
 *
 * 中间距离很远
 *
 * 各个函数的局部变量在一个区域
 */
