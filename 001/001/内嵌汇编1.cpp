#include <cstdio>
/*
__declspec(naked) ��ʾ����C�������Զ���Ӷ�ջƽ��ͼĴ�����������
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
		//push eax; // 1.����Ҫeax
		push edx;

		// �Ƚ������ַ���
		xor al, al;
		mov ecx, -1;
		//mov edi, s1; //��ӵ�ַ + 8  call����չeip��ͬʱ����push ebp
		mov edi, [ebp + 4 + 4];
		repnz scasb;
		not ecx;


		// mov edi, s1;
		mov edi, [ebp + 4 +4];
		//mov esi, s2;
		mov esi, [ebp + 4 + 4 + 4]; // ������ջ
		repz cmpsb; // �Ա������ַ���


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