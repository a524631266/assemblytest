#include<cstdio>

int main()
{
	char * c = "s0123456789"; //字符0 并不是\0
	int len;
	__asm
	{
		xor eax, eax; // 清空eax
		mov edi,c // edi保持字符串的字符
		mov ecx, -1; // 设置循环次数，其中repnz会影响ecx，rep都会使得ecx减1
		repnz scasb; // scasb 每次会比较cmp [edi]与al，不想等就会自动 inc edi(方向符号DF=0的时候会使得edi自增1)，同时
		 // repnz 为当 ecx!=0或者zf=0的时候都会自动执行repnz所指定的命令，也就是会不断重复执行scasb，当al与[edi]中的值相等
		// 的时候（该案例中al==0，字符串结尾为0）及zf=0，跳出同时也会使得edi加1 
		mov eax,-1
		sub eax,ecx //计算长度
		sub eax,1 // \0会加1，所以要使长度-1
		mov len,eax
	}

	printf("len %d \n", len);
	getchar();
	return 0;
}