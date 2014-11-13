void toggle(vector<int> num)
{
	bool desc=false;
	for(int i=0;i<num.size()-1;i++)
	{
		if(desc)
		{
			if(num[i]<num[i+1])
			{
				swap(num[i],num[i+1]);
			}
		}
		else
		{
			if(num[i]>num[i+1])
			{
				swap(num[i],num[i+1]);
			}
		}
		desc=!desc;
	}
}
