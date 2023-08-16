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
        s1 = p;  //找一次重新定位一次
        s2 = str2;//每次重置

        while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2)   //两个字符串任意一个结束就停止循环，相同便向下查找
        {
            s1++;
            s2++;
        }

        if(*s2 == '\0')  //成功找到子串，返回子串在长串中地址
        {
            return (char*)p;  //防止报错，p为const char*
        }

        p++;
    }

    return NULL;  //当*p为\0时，未找到，返回空指针
}
//情况1，abcdef中找bcd(一次匹配)
//情况2，abbbcdef中找bbc(多次匹配)

int main()
{
    char arr1[] = "abbbcghhghghgjhfgfgfgh";
    char arr2[] = "bbc";

    char* pp = my_strstr(arr1,arr2);
    printf("%s\n",pp);

    return 0;
}
//效率低，有待优化(KMP算法使用，较复杂，但高效，有待研究)