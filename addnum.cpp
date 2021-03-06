// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
//	输入：
//	输入可能包含多个测试样例。
//	对于每个测试案例，输入为两个整数m和n(1<=m,n<=1000000)。
//	输出：
//	对应每个测试案例，输出m+n的值。
//	样例输入：
//	3 4 7 9
//	样例输出：
//	7 16
//	思路：
//	1、先将各bit位相加，不计进位，这一步可以用m^n实现
//
//	2、加上进位，进位如何来，用m&n可以得到m和n中都为1的bit位，而不全为1的位则全部变为了0，该位相加会发生进位，使得左边一位加1，
//	因此(m&n)<<1边可得到进位后要加的1的位置；
//
//	3、将前面两步的结果相加，相加的时候还有可能再产生进位，因此二者相加的过程可以再次重复循环步骤1和2，
//	直到(m&n)<<1变为了0，这时候不会再产生进位，退出循环即可。

int addNum (int a, int b)
{
	int sum = 0; // 保存m^n
	while (b != 0)
	{
		sum = a ^ b;
		printf ("sum = %d\n", sum);
		int add1 = (a & b) << 1;
		printf ("add1 = %d\n", add1);
		a = sum ;
		b = add1;
	}

	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf ("out");
	printf ("result = %d", addNum(3, 5));
	return 0;
}

