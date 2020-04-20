#include <cstdio>

/*
cmpsb与scasb的关系
scasb 是edi与 al（byte）/ax（word ==》scasw）/eax（dword   ===》 scasd），然后使得edi以相应的速度根据DF的正（0） 负（-1）方向进行相应移动
配合repnz/repne 一起使用可以完成字符串长度，定位以及机器码查找的功能
cmpsb 是 edi 与 esi同步执行比较如果相等就都会加1，zf=1 配合repz（zp=1或者ecx！=0的时候继续执行 ecx保留长度）,同理每一步ecx都会减1

*/
int main()
{
	printf("asm __ cmp\n");

	char * str  = "1234567890123456789";
	char * str2 = "1234567890123456789";
	int len;
	int index;

	__asm {
		xor al, al; // 
		mov ecx, -1 //
		mov edi, str;
		repnz scasb;
		not ecx; // 包含\0的字符串
		mov len, ecx;

		mov edi, str;
		mov esi, str2;
		repz cmpsb; // 对比两个字符串
		mov index,ecx;

		//xor al,al // 会影响 ZF XOR
		mov al,0
		sete al // 取 zf= 1 表示相等

		cmp al,1
		jnz notequal
		cmp ecx,0
		je equal
		jmp end
	}
	printf("8888888888");
notequal:
	printf("notnn equal\n");
	goto end;
equal:
	printf("equal\n");
end: 
	printf("len：%d, index： %d", len, index);
	getchar();
	return 0;
}
