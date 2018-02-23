
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<stdexcept>
#include<iostream>
class CMyString{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();
private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if(pData == nullptr){
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else{
        int len = strlen(pData);
        m_pData = new char[len+1];
        strcpy(m_pData,pData);
    }
}

CMyString::CMyString(const CMyString & str){
    int len = strlen(str.m_pData);
    m_pData = new char[len+1];
    strcpy(m_pData,str.m_pData);
}

CMyString::~CMyString(void){
    delete[] m_pData;
}

CMyString& CMyString::operator = (const CMyString & str){
    if(this == &str)
        return *this;
    char *temp = new char[strlen(str.m_pData)+1];
    if(temp){
        delete []m_pData;
        m_pData = temp;
    }
    else std::cerr<<"error"<<std::endl;
    return * this;
}

