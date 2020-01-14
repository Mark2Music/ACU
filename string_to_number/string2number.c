#include <stdio.h>
#include <stdlib.h>

int main()
{
   char str[30] = "2030300 This is test";
   char *ptr;
   long ret;

   ret = strtoul(str, &ptr, 10);
   printf("数字（无符号长整数）是 %lu\n", ret);
   printf("字符串部分是 |%s|\n", ptr);

   int a = 0xfffa;
   char string[30] = "0xff0x103";
   //这种写法可以让0x01显示出 01,而不是1，有几个字节就显示几个字节，使用 %.4x %.2x %.6x
   sprintf(string, "%.2x%.4x%.2x%.4x%.2x", 0xff, 0x0103, 0x01, 100, 0xfe);
   printf("string = %s\n", string);
   ret = strtoul(string, NULL, 16);
   printf("ret = %lx\n", ret);

   return(0);
}
