TEST(ArrayAddTest, NULLArray)
{
	vector<int> a={1};
	EXPECT_THROW(arrayAdd(a, NULL), char *);
}

TEST(ArrayAddTest, OneEmptyArray)
{
	vector<int> a={1};
	vector<int> b;
	EXPECT_EQ(arrayAdd(a,b)[0], 1);
}

TEST(ArrayAddTest, TwoEmptyArray)
{
	vector<int> a;
	vector<int> b;
	vector<int> c=arrayAdd(a,b);
	EXPECT_TRUE(c.empty());
}

TEST(ArrayAddTest, LeftArrayLonger)
{
	vector<int> a={1,2};
	vector<int> b={1};
	vector<int> c=arrayAdd(a,b);
	EXPECT_TRUE(c[0]==1&&c[1]==3);
}

TEST(ArrayAddTest, RightArrayLonger)
{
	vector<int> a={1,2};
	vector<int> b={1};
	vector<int> c=arrayAdd(b,a);
	EXPECT_TRUE(c[0]==1&&c[1]==3);
}

TEST(ArrayAddTest, WithCarry)
{
	vector<int> a={9,2};
	vector<int> b={9};
	vector<int> c=arrayAdd(b,a);
	EXPECT_TRUE(c[0]==1&&c[1]==0&&c[2]==1);
}

vector<int> addArray(vector<int> a, vector<int> b)
{
	vector<int> result;
	int m=a.size();
	if(!m)return b;
	int n=b.size();
	if(!n)return result;

	int i=m-1,j=n-1;
	int carry=0;
	while(i>=0&&j>=0)
	{
	    int tmp=a[i]+b[j]+carry;
	    result.push_back(tmp%10);
	    carry=tmp/10;
	    i--;
	    j--;
	}
	while(i>=0)
	{
		int tmp=a[i]+carry;
		result.push_back(tmp%10);
		carry=tmp/10;
		i--;
	}
	while(j>=0)
	{
		int tmp=b[j]+carry;
		result.push_back(tmp%10);
		carry=tmp/10;
		j--;
	}
	if(carry)result.push_back(carry);
	reverse(result.begin(),result.end());
	return result;
}


vector<char> addArray(vector<char> a, vector<char> b)
{
	vector<char> result;
	if(a.empty())return b;
	if(b.empty())return result;

	int carry=0;
	vector<char>::reverse_iterator ita_from(a.end());
	vector<char>::reverse_iterator ita_to(a.begin());
	vector<char>::reverse_iterator itb_from(b.end());
	vector<char>::reverse_iterator itb_to(b.end());
	
	iter_type ita=ita_from.base();
	iter_type itb=itb_from.base();
	while(ita!=ita_to.base()&&itb!=itb_to.base())
	{
	    int tmp=*ita-'0'+*itb-'0'+carry;
	    result.push_back(tmp%10+'0');
	    carry=tmp/10;
	    ita++;
	    itb++;
	}
	while(ita!=ita_to.base())
	{
		int tmp=*ita-'0'+carry;
		result.push_back(tmp%10+'0');
		carry=tmp/10;
		ita++;
	}
	while(itb!=itb_to.base())
	{
		int tmp=b[j]-'0'+carry;
		result.push_back(tmp%10+'0');
		carry=tmp/10;
		itb++;
	}
	if(carry)result.push_back(carry+'0');
	reverse(result.begin(),result.end());
	return result;
}

