#include<cstdio>

int main() 
{
	printf("Go to test \n");
	int a = 10;
	__asm
	{
		jmp end
	}
	printf("�����˳�");
	return 0;
end: 
	printf("got �˳�");
	getchar();
	return 0;

}