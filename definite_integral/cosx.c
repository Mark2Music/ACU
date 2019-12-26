#include <stdio.h>
#include <math.h>

float sinx(float x)
{
	return sin(x);
}

float cosx(float x)
{
	return cos(x);
}

float ex(float x)
{
	return exp(x);//按理应该定义为double类型，但此处不影响，笔者懒，有需要的伙伴可以改为double类型
}
 
int main(void)
{
   int flag;
   float (*p)(float);//此处定义指针函数，可以选择计算不同的积分
   float h,i,a,b,n,sum,t;
   n=1000000;//n的值越大，分的区域越多，精度越高
   sum=0;
   printf("请输入积分上下限(空格隔开)\n");
   scanf("%f %f",&a,&b);
   if(a<b)
   {
       printf("输入错误，但已自动改正\n");
       t=a;
       a=b;
       b=t;
   }
   h=(a-b)/n;
   printf("请选择你要计算的积分 0:sinx 1:cosx 2:ex\n");
   scanf("%d",&flag);
      
   if(flag==0) p=sinx;
   else if (flag==1) p=cosx;//指针指向所对应的函数，可以选择计算不同的积分
   else p=ex;
   
   for(i=b;i<a;i+=h)//进行累加
   	sum+=p(i)*h;//这点乘以它的函数值
   
   printf("%f\n",sum);

   return 0;
}
