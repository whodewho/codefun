// Problems.cpp : Defines the entry point for the console application.
/*
big number mully
*/

#include "stdafx.h"
#include "iostream"
#include "vector"
#include "string"
#include "map"
using namespace std;

string mul(string s1, string s2)
{
	//handle sign bit
	int sign=1;
	if(s1.empty()||s2.empty())return "";
	if(s1[0]=='+'||s1[0]=='-')
	{
		if(s1[0]=='-')sign=sign*(-1);
		s1.erase(s1.begin());
	}
	if(s2[0]=='+'||s2[0]=='-')
	{
		if(s2[0]=='-')sign=sign*(-1);
		s2.erase(s2.begin());
	}

	//handle float number with '.'
	int point=0;
	std::size_t s1p=s1.find(".");
	if(s1p!=std::string::npos)
	{
		point+=s1.size()-1-s1p;
		s1.erase(s1.begin()+s1p);
	}
	std::size_t s2p=s2.find(".");
	if(s2p!=std::string::npos)
	{
		point+=s2.size()-1-s2p;
		s2.erase(s2.begin()+s2p);
	}

	//multiply two big int number, 
	//number might starts or ends with '0', that's ok
	int m=s1.size();
	int n=s2.size();
	vector<int> result(m+n, 0);
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int carry=0;
	for(int i=0;i<m;i++)
	{
		carry=0;
		for(int j=0;j<n;j++)
		{
			int tmpM=(s1[i]-'0')*(s2[j]-'0');
			int tmpR=(tmpM+carry+result[i+j])%10;
			carry=(tmpM+carry+result[i+j])/10;
			result[i+j]=tmpR;	
		}
		if(carry)result[i+n]=carry;
	}
	if(carry)result[m+n-1]=carry;
	reverse(result.begin(), result.end());
	string tmp;
	for(int i=0;i<result.size();i++)
	{
		tmp.push_back(result[i]+'0');
	}

	//handle '.'
	if(point)
	{
		//insert the '.' into the string
		tmp.insert(tmp.end()-point, '.');
		//trim the '0' before '0.'
		while(tmp[0]=='0')tmp.erase(tmp.begin());
		if(tmp[0]=='.')tmp.insert(tmp.begin(), '0');
	}
	else
	{
		while(tmp[0]=='0')tmp.erase(tmp.begin());
	}
	//insert sign bit
	if(sign<0)tmp.insert(tmp.begin(), '-');
	return tmp;
}

int strcompare(string s1, string s2)
{
    //s1 < s2 return -1
    //s2 > s2 return 1
    //s1 == s2 return 0
    string s1I="", s1F="";
    std::size_t s1p=s1.find(".");
    if(s1p==string::npos)
    {
        s1I=s1;
        s1F="";
    }
    else
    {
        s1I=s1.substr(0, s1p);
        s1F=s1.substr(s1p+1, s1.size()-(s1p+1));
    }
    string s2I="", s2F="";
    std::size_t s2p=s2.find(".");
    if(s2p==string::npos)
    {
        s2I=s2;
        s2F="";
    }
    else
    {
        s2I=s2.substr(0, s2p);
        s2F=s2.substr(s2p+1, s2.size()-(s2p+1));
    }
    
    if(s1I.length()>s2I.length())return 1;
    else if(s1I.length()==s2I.length())
    {
        int cmp=s1I.compare(s2I);
        if(cmp!=0)return cmp;
        else return s1F.compare(s2F);
    }
    else return -1;
}

string absadd(string s1, string s2)
{
    int p1=0, p2=0, p=0;
    std::size_t s1p=s1.find(".");
    if(s1p!=string::npos)
    {
        p1=s1.size()-s1p-1;
        s1.erase(s1.begin()+s1p);
    }

    std::size_t s2p=s2.find(".");
    if(s2p!=string::npos)
    {
        p2=s2.size()-s2p-1;
        s2.erase(s2.begin()+s2p);
    }
    
    string tail(abs(p1-p2), '0');
    if(p1<p2)s1+=tail;
    else if(p1>p2)s2+=tail;
    
    p=max(p1, p2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string result="";
    int carry=0, i=0;
    while(i<s1.size()&&i<s2.size())
    {
        int tmp=s1[i]-'0'+s2[i]-'0'+carry;
        result.push_back(tmp%10+'0');
        carry=tmp/10;
        i++;
    }
    while(i<s1.size())
    {
        int tmp=s1[i]-'0'+carry;
        result.push_back(tmp%10+'0');
        carry=tmp/10;
        i++;
    }
    while(i<s2.size())
    {
        int tmp=s2[i]-'0'+carry;
        result.push_back(tmp%10+'0');
        carry=tmp/10;
        i++;
    }
    if(carry)result.push_back('1');
    if(p)result.insert(result.begin()+p, '.');
    reverse(result.begin(), result.end());
    return result;
}

string abssub(string s1, string s2)
{
   int p1=0, p2=0, p=0;
    std::size_t s1p=s1.find(".");
    if(s1p!=string::npos)
    {
        p1=s1.size()-s1p-1;
        s1.erase(s1.begin()+s1p);
    }

    std::size_t s2p=s2.find(".");
    if(s2p!=string::npos)
    {
        p2=s2.size()-s2p-1;
        s2.erase(s2.begin()+s2p);
    }
    
    string tail(abs(p1-p2), '0');
    if(p1<p2)s1+=tail;
    else if(p1>p2)s2+=tail;
    
    p=max(p1, p2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string result="";
    int carry=0, i=0;
    while(i<s2.size())
    {
        int tmp=s1[i]-s2[i]+carry;
        if(tmp>=0)
        {
            carry=0;
            result.push_back(tmp+'0');
        }
        else
        {
            carry=-1;
            result.push_back(tmp+10+'0');
        }
        i++;
    }
    while(i<s1.size())
    {
        int tmp=s1[i]-'0'+carry;
        if(tmp>=0)
        {
            carry=0;
            result.push_back(tmp+'0');
        }
        else
        {
            carry=-1;
            result.push_back(tmp+10+'0');
        }
        i++;
    }
    
    if(p)result.insert(result.begin()+p, '.');
    reverse(result.begin(), result.end());
	while(!result.empty()&&result[0]=='0')result.erase(result.begin());
	if(!result.empty()&&result[0]=='.')result.insert(result.begin(), '0');
    return result;
}

string add(string s1, string s2)
{
    int sign1=1;
    if(s1[0]=='-')sign1=-1;
    int sign2=1;
    if(s2[0]=='-')sign2=-1;
    
    int sign=1;
    string result="";
    if(sign1==-1&&sign2==-1)
    {
        s1.erase(s1.begin());
        s2.erase(s2.begin());
        sign=-1;
        result=absadd(s1, s2);
    }
    else if(sign1==1&&sign2==1)
    {
        if(s1[0]=='+')s1.erase(s1.begin());
        if(s2[0]=='+')s2.erase(s2.begin());
        return absadd(s1, s2);
    }
    else if(sign1==-1&&sign2==1)
    {
        s1.erase(s1.begin());
        if(s2[0]=='+')s2.erase(s2.begin());
        sign=strcompare(s2, s1);
        if(sign>0)result=abssub(s2, s1);
        else result=abssub(s1, s2);
    }
    else if(sign1==1&&sign2==-1)
    {
        if(s1[0]=='+')s1.erase(s1.begin());
        s2.erase(s2.begin());
        sign=strcompare(s1, s2);
        if(sign<0)result=abssub(s2, s1);
        else result=abssub(s1, s2);
    }
    
    if(sign<0&&result!="0")result.insert(result.begin(), '-');
    return result;
}

string sub(string s1, string s2)
{
    int sign1=1;
    if(s1[0]=='-')sign1=-1;
    int sign2=1;
    if(s2[0]=='-')sign2=-1;
    
    int sign=1;
    string result="";
    if(sign1==-1&&sign2==-1)
    {
        s1.erase(s1.begin());
        s2.erase(s2.begin());
        sign=strcompare(s2, s1);
        if(sign>0)result=abssub(s2, s1);
        else result=abssub(s1, s2);
    }
    else if(sign1==1&&sign2==1)
    {
        if(s1[0]=='+')s1.erase(s1.begin());
        if(s2[0]=='+')s2.erase(s2.begin());
        sign=strcompare(s1, s2);
        if(sign>0)result=abssub(s1, s2);
        else result=abssub(s2, s1);
    }
    else if(sign1==-1&&sign2==1)
    {
        s1.erase(s1.begin());
        if(s2[0]=='+')s2.erase(s2.begin());
        sign=-1;
        result=absadd(s1, s2);
    }
    else if(sign1==1&&sign2==-1)
    {
        if(s1[0]=='+')s1.erase(s1.begin());
        s2.erase(s2.begin());
        result=absadd(s1, s2);
    }
    
    if(sign<0&&result!="0")result.insert(result.begin(), '-');
    return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	cout<<mul("123456789", "99999999")<<endl;
	cout<<mul("12345.6789", "99999999")<<endl;
	cout<<mul("12345.6789", "99999.999")<<endl;
	cout<<"------"<<endl;
	cout<<mul("-12345.6789", "99999999")<<endl;
	cout<<mul("-12345.6789", "-9.9999999")<<endl;
	cout<<mul("-12345.6789", "-9.99999990000")<<endl;
	cout<<"------"<<endl;
	cout<<mul("-12345.6789", "0.99999999")<<endl;
	cout<<mul("-12.3456789", "+0.000000099999999")<<endl;
	cout<<mul("99999999999999", "+0.000000099999999")<<endl;
	*/

	const int n=11;
	string a[n]={"1", "12", "1234", "1.0", "1.2", "1.234", "12.34", "12345678.99", "999999.99999", "123456789987654321123456789.123456789", "9988776655443322144332211.123456789987654321"};
	string b[n]={"2", "13", "1235", "2.0", "2.2", "2.23", "13.1", "12345678,123", "999999.999", "9999999999999999999999999999.999999", "99999999999999999"};

	for(int i=0;i<n;i++)
	{
		cout<<i<<"-----------------"<<endl;
		cout<<"+"<<endl;
		cout<<add(a[i], b[i])<<endl;
		cout<<add("+"+a[i], "+"+b[i])<<endl;
		cout<<add("-"+a[i], "-"+b[i])<<endl;
		cout<<sub(a[i], "-"+b[i])<<endl;
		cout<<sub("-"+a[i], b[i])<<endl;
		cout<<"-"<<endl;
		cout<<add("-"+a[i], b[i])<<endl;
		cout<<add(a[i],"-"+b[i])<<endl;
		cout<<sub(a[i], b[i])<<endl;
		cout<<sub("-"+a[i], "-"+b[i])<<endl;
		cout<<"*"<<endl;
		cout<<mul(a[i], b[i])<<endl;
		cout<<mul("-"+a[i], b[i])<<endl;
		cout<<mul(a[i], "-"+b[i])<<endl;
		cout<<mul("-"+a[i], "-"+b[i])<<endl;
	}
	return 0;
}

	

