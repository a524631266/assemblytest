#include<cstdio>
int main() {

	printf("Jump Less or jump not greater and equal\n");

	int a = 0x26;
	int b = 0xCD;
	if (a >= b) { // SF ��־Ϊ1 ��ת JL ��ַ/ JNGE ��ַ SF Ϊcmp a,b  a- b < 0 �� SF Ϊ1 ���з��ŵ���˼������Ϊ�з���
		printf("a is >= b");
	}
	else {
		
		printf("a is < b");

	}

	// ������
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