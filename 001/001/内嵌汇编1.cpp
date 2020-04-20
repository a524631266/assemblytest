#include <cstdio>
/*
__declspec(naked) 表示不让C编译器自动添加堆栈平衡和寄存器保护功能
__declspec(naked)
*/
__declspec(naked) int cmp_str(char* s1, char * s2)
{
	__asm
	{
		push ebp;
		mov ebp, esp;

		push ecx;
		push edi;
		push esi;
		//push eax; // 1.不需要eax
		push edx;

		// 比较两个字符串
		xor al, al;
		mov ecx, -1;
		//mov edi, s1; //间接地址 + 8  call会入展eip，同时在上push ebp
		mov edi, [ebp + 4 + 4];
		repnz scasb;
		not ecx;


		// mov edi, s1;
		mov edi, [ebp + 4 +4];
		//mov esi, s2;
		mov esi, [ebp + 4 + 4 + 4]; // 倒序入栈
		repz cmpsb; // 对比两个字符串


					// 
		xor eax, eax;
		xor edx, edx;
		//
		mov al, [edi - 1];
		mov dl, [esi - 1];
		sub eax, edx;

		pop edx;
		//pop eax;
		pop esi;
		pop edi;
		pop ecx;
		pop ebp;
		ret;
	}
}

int main()
{
	printf("compare with two chars\n");

	printf("%d", cmp_str("aaaaa", "abbbbb"));
	getchar();
	return 0;
}