#include <stdio.h>
#include <assert.h>


char* my_strstr(const char* str1,const char* str2)
{
    assert(str1 && str2);
    const char* s1 = str1;
    const char* s2 = str2;
    const char* p = str1;


    while(*p)
    {
        s1 = p;  //��һ�����¶�λһ��
        s2 = str2;//ÿ������

        while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2)   //�����ַ�������һ��������ֹͣѭ������ͬ�����²���
        {
            s1++;
            s2++;
        }

        if(*s2 == '\0')  //�ɹ��ҵ��Ӵ��������Ӵ��ڳ����е�ַ
        {
            return (char*)p;  //��ֹ����pΪconst char*
        }

        p++;
    }

    return NULL;  //��*pΪ\0ʱ��δ�ҵ������ؿ�ָ��
}
//���1��abcdef����bcd(һ��ƥ��)
//���2��abbbcdef����bbc(���ƥ��)

int main()
{
    char arr1[] = "abbbcghhghghgjhfgfgfgh";
    char arr2[] = "bbc";

    char* pp = my_strstr(arr1,arr2);
    printf("%s\n",pp);

    return 0;
}
//Ч�ʵͣ��д��Ż�(KMP�㷨ʹ�ã��ϸ��ӣ�����Ч���д��о�)