#include<cstdio>
int main() {

	printf("Jump Less or jump not greater and equal\n");

	int a = 0x26;
	int b = 0xCD;
	if (a >= b) { // SF 标志为1 跳转 JL 地址/ JNGE 地址 SF 为cmp a,b  a- b < 0 则 SF 为1 是有符号的意思，负数为有符号
		printf("a is >= b");
	}
	else {
		
		printf("a is < b");

	}

	// 汇编代码
	__asm
	{
		mov eax, b
		cmp a,eax
		JNGE end
	}
end:
	printf("a is < b");

	getchar();
	return 0;
}