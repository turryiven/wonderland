#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<stdexcept>
#include<iostream>
class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();

private:
    char* m_pData;
};

CMyString::CMyString(char *pData)
{
    if(pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    std::cout<<"copy construction started"<<std::endl;
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
    std::cout<<"c c end: "<<m_pData<<std::endl;
}

CMyString::~CMyString()
{
    delete[] m_pData;
}
/**********
    方案0：初始方案 delete new
**********/
/*
CMyString& CMyString::operator = (const CMyString& str)
{
    if(this == &str)
        return *this;

    delete []m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}
*/
/************
    方案1：先new再delete
*************/
/*
CMyString& CMyString::operator = (const CMyString & str){
    if(this == &str)
        return *this;
    char *temp = new char[strlen(str.m_pData)+1];
    if(temp){
        strcpy(temp,str.m_pData);
        delete []m_pData;
        m_pData = temp;
        temp = nullptr;
    }
    else std::cerr<<"error"<<std::endl;
    return * this;
}
*/
/********
方案2:高级进阶
********/

CMyString& CMyString::operator = ( const CMyString &str){
    if(this != &str){
        CMyString strtemp(str);

        char* ptemp = strtemp.m_pData;
        strtemp.m_pData = m_pData;
        m_pData = ptemp;
    }
    return *this;
}

// ====================���Դ���====================
void CMyString::Print()
{
    printf("%s", m_pData);
}

void Test1()
{
    printf("Test1 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// ��ֵ���Լ�
void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    system("pause");

    return 0;
}
