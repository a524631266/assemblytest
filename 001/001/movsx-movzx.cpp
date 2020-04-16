#include<Windows.h>
#include<cstdio>
/*
movsx signal x 符号扩展穿送
movzx zero x 零扩展传送

xxx 操作A,操作B, 操作b的空间比操作A空间要不大
*/
int main() {
	printf("asaaaaa");
	char c = 0x33;
	int i = 0x87654321;
	// 带符号类型传送
	i = c; // 
	printf("23423");
	__asm 
	{
		mov i, 0x87654321  //013F17F4           C745 E8 2143658>mov dword ptr ss:[ebp-0x18],0x87654321

		mov c, 0x87654321  // 013F17FB           C645 F7 21      mov byte ptr ss : [ebp - 0x9], 0x21

	}
	return 0;
}