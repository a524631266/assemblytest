#include<cstdio>

int main()
{
	char * c = "s0123456789"; //�ַ�0 ������\0
	int len;
	__asm
	{
		xor eax, eax; // ���eax
		mov edi,c // edi�����ַ������ַ�
		mov ecx, -1; // ����ѭ������������repnz��Ӱ��ecx��rep����ʹ��ecx��1
		repnz scasb; // scasb ÿ�λ�Ƚ�cmp [edi]��al������Ⱦͻ��Զ� inc edi(�������DF=0��ʱ���ʹ��edi����1)��ͬʱ
		 // repnz Ϊ�� ecx!=0����zf=0��ʱ�򶼻��Զ�ִ��repnz��ָ�������Ҳ���ǻ᲻���ظ�ִ��scasb����al��[edi]�е�ֵ���
		// ��ʱ�򣨸ð�����al==0���ַ�����βΪ0����zf=0������ͬʱҲ��ʹ��edi��1 
		mov eax,-1
		sub eax,ecx //���㳤��
		sub eax,1 // \0���1������Ҫʹ����-1
		mov len,eax
	}

	printf("len %d \n", len);
	getchar();
	return 0;
}