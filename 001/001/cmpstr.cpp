#include <cstdio>

/*
cmpsb��scasb�Ĺ�ϵ
scasb ��edi�� al��byte��/ax��word ==��scasw��/eax��dword   ===�� scasd����Ȼ��ʹ��edi����Ӧ���ٶȸ���DF������0�� ����-1�����������Ӧ�ƶ�
���repnz/repne һ��ʹ�ÿ�������ַ������ȣ���λ�Լ���������ҵĹ���
cmpsb �� edi �� esiͬ��ִ�бȽ������ȾͶ����1��zf=1 ���repz��zp=1����ecx��=0��ʱ�����ִ�� ecx�������ȣ�,ͬ��ÿһ��ecx�����1

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
		not ecx; // ����\0���ַ���
		mov len, ecx;

		mov edi, str;
		mov esi, str2;
		repz cmpsb; // �Ա������ַ���
		mov index,ecx;

		//xor al,al // ��Ӱ�� ZF XOR
		mov al,0
		sete al // ȡ zf= 1 ��ʾ���

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
	printf("len��%d, index�� %d", len, index);
	getchar();
	return 0;
}
