#include <stdio.h>
#include <stdlib.h>

// ֻҪ�ǵ�ַ��ռ4�ֽ�
int main(){
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));// 16 ���ֽ��� = ��Ԫ�ظ��� * ����Ԫ��ռ���ֽ���
	printf("%d\n", sizeof(a + 0));// 4 ��Ԫ�أ����Σ��ĵ�ַ��ռ4�ֽڣ�
	printf("%d\n", sizeof(*a));// 4 ��Ԫ�أ����Σ�ռ4�ֽ�
	printf("%d\n", sizeof(a + 1));// 4 �ڶ���Ԫ�صĵ�ַ =a[1],a[0]+1
	printf("%d\n", sizeof(a[1]));// 4 ��Ԫ��
	printf("%d\n", sizeof(&a));// 4 ��������ĵ�ַ��ռ4�ֽڣ�
	printf("%d\n", sizeof(*&a));// 16 ����������ĵ�ַ������Ϊ�������飬�൱��a
	printf("%d\n", sizeof(&a + 1));// 4 ��һ������ĵ�ַ
	printf("%d\n", sizeof(&a[0]));// 4 ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1));// 4 �ڶ���Ԫ�صĵ�ַ


// arr���� 6 ��Ԫ�أ���\0'û�б��Ž����鵱�У�����"��������"����f'�������ֵ����������Ϊ 6���󳤶ȿ���Խ��
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));// 6
	printf("%d\n", sizeof(arr + 0));// 4 ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*arr));// 1 ��Ԫ��
	printf("%d\n", sizeof(arr[1]));// 1 �ڶ���Ԫ��
	printf("%d\n", sizeof(&arr));// 4 ����ĵ�ַ
	printf("%d\n", sizeof(&arr + 1));// 4 ��һ������ĵ�ַ
	printf("%d\n", sizeof(&arr[0] + 1));// 4 �ڶ���Ԫ�صĵ�ַ
	
	// strlen ������ַ����ĳ��ȣ��ַ��ĸ�����Ϊ������һ����Ҫ�ԡ�\0'��β�ģ�����ʱ�ڵ��õ�ʱ��ȷ���ģ����ؼ����Ǳ����ʱ��ȷ����
	// sizeof Ϊ�ؼ��� ������
	int a = 10;
	printf("%d\n", sizeof(a));// 4 �����������
	printf("%d\n", sizeof a);// 4
	printf("%d\n", sizeof(int));// 4 
	//printf("%d\n", sizeof int);���


	// size_t strlen(const char* str) ��������Ϊ��ַ
	printf("%d\n", strlen(arr));// ��ȷ�� ��Ԫ�صĵ�ַ >=6
	printf("%d\n", strlen(arr + 0));// = &a ��Ԫ�ص�ַchar *���������ϣ���Ԫ�صĵ�ַҲ��>=6 �ģ�
	printf("%d\n", strlen(*arr));// ���� ��Ԫ�� warning ���Ͳ�ƥ�� char != char *
	printf("%d\n", strlen(arr[1]));// ���� �ڶ���Ԫ�أ����Ͳ�ƥ�䣬
	printf("%d\n", strlen(&arr));// ����ĵ�ַ�� ��ȷ�� ����ĵ�ַ������������ָ�룬char* != char*[],����warning������ĵ�ַ��������Ԫ�صĵ�ַ����ֵ����һ����
	printf("%d\n", strlen(&arr + 1));// ��һ������ĵ�ַ������Ϊchar*[]����ָ�� warning ֵǡ��Ϊ��һ��������׵�ֵַ��>=0;
	printf("%d\n", strlen(&arr[0] + 1));// �ڶ���Ԫ�صĵ�ַ��>= 5;


	system("pause");
	return 0;
}
