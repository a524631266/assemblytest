#include <cstdio>
#include <Windows.h>
int add(int a, int b) {
	return a + b;
}

int main() {
	printf("hello cpp");
	MessageBox(0, NULL, NULL, MB_OK);
	 // 没有做优化
	// 01061832    6A 22           push 0x22
    // 01061834    6A 11           push 0x11
	int c = add(0x11, 0x22);
	// 做了优化
	
	printf("%d", c);
	return 0;
}