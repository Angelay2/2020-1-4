#include <stdio.h>
#include <stdlib.h>

// 只要是地址就占4字节
int main(){
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));// 16 总字节数 = 总元素个数 * 单个元素占的字节数
	printf("%d\n", sizeof(a + 0));// 4 首元素（整形）的地址（占4字节）
	printf("%d\n", sizeof(*a));// 4 首元素（整形）占4字节
	printf("%d\n", sizeof(a + 1));// 4 第二个元素的地址 =a[1],a[0]+1
	printf("%d\n", sizeof(a[1]));// 4 首元素
	printf("%d\n", sizeof(&a));// 4 整个数组的地址（占4字节）
	printf("%d\n", sizeof(*&a));// 16 对整形数组的地址解引用为整个数组，相当于a
	printf("%d\n", sizeof(&a + 1));// 4 下一个数组的地址
	printf("%d\n", sizeof(&a[0]));// 4 首元素的地址
	printf("%d\n", sizeof(&a[0] + 1));// 4 第二个元素的地址


// arr里有 6 个元素，‘\0'没有被放进数组当中，不是"括起来的"，‘f'后面随机值，长度至少为 6，求长度可能越界
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));// 6
	printf("%d\n", sizeof(arr + 0));// 4 首元素的地址
	printf("%d\n", sizeof(*arr));// 1 首元素
	printf("%d\n", sizeof(arr[1]));// 1 第二个元素
	printf("%d\n", sizeof(&arr));// 4 数组的地址
	printf("%d\n", sizeof(&arr + 1));// 4 下一个数组的地址
	printf("%d\n", sizeof(&arr[0] + 1));// 4 第二个元素的地址
	
	// strlen 求得是字符串的长度（字符的个数）为函数，一定是要以’\0'结尾的，函数时在调用的时候确定的，而关键字是编译的时候确定的
	// sizeof 为关键字 操作符
	int a = 10;
	printf("%d\n", sizeof(a));// 4 建议带上括号
	printf("%d\n", sizeof a);// 4
	printf("%d\n", sizeof(int));// 4 
	//printf("%d\n", sizeof int);错的


	// size_t strlen(const char* str) 参数类型为地址
	printf("%d\n", strlen(arr));// 不确定 首元素的地址 >=6
	printf("%d\n", strlen(arr + 0));// = &a 首元素地址char *，参数符合，首元素的地址也是>=6 的，
	printf("%d\n", strlen(*arr));// 报错 首元素 warning 类型不匹配 char != char *
	printf("%d\n", strlen(arr[1]));// 报错， 第二个元素，类型不匹配，
	printf("%d\n", strlen(&arr));// 数组的地址， 不确定 数组的地址被保存在数组指针，char* != char*[],会有warning，数组的地址和数组首元素的地址在数值上是一样的
	printf("%d\n", strlen(&arr + 1));// 下一个数组的地址，类型为char*[]数组指针 warning 值恰好为下一个数组的首地址值，>=0;
	printf("%d\n", strlen(&arr[0] + 1));// 第二个元素的地址，>= 5;


	system("pause");
	return 0;
}
