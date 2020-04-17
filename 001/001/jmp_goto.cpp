#include<cstdio>

int main() 
{
	printf("Go to test \n");
	int a = 10;
	__asm
	{
		jmp end
	}
	printf("正常退出");
	return 0;
end: 
	printf("got 退出");
	getchar();
	return 0;

}