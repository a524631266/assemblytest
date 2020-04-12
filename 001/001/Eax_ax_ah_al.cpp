#include <Windows.h>
#include <cstdio>

int main() {
	DWORD ieax;
	WORD iax;
	BYTE iah;
	BYTE ial;
	printf("EAX_AX_AH_AL \n");
	__asm {
		mov eax, 0x12345678
		mov ieax, eax
		mov iax, ax
		mov ial, al
		mov iah, ah
	}
	/*
	002C17D5           8945 FC         mov dword ptr ss : [ebp - 0x4], eax; ucrtbase.6B5A3700
	002C17D8           68 306B2C00     push 001.002C6B30
	002C17DD           E8 43FBFFFF     call 001.002C1325
	002C17E2           83C4 04         add esp, 0x4
	002C17E5           B8 78563412     mov eax, 0x12345678
	002C17EA           8945 F4         mov dword ptr ss : [ebp - 0xC], eax; ucrtbase.6B5A3700
	002C17ED           66:8945 E8      mov word ptr ss : [ebp - 0x18], ax
	002C17F1           8865 DF         mov byte ptr ss : [ebp - 0x21], ah
	002C17F4           8845 D3         mov byte ptr ss : [ebp - 0x2D], al
	002C17F7           0FB645 D3       movzx eax, byte ptr ss : [ebp - 0x2D]
	*/


	printf("EAX=%x, AX=%x, AH=%x, AL=%x", ieax, iax, iah, ial);
	//EAX=12345678, AX=5678, AH=56, AL=78
	getchar();
	return 0;
}