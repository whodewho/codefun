double getCubeRoot(double num, double epsilon)
{
	int sign=1;
	if(num<0)
	{
		sign=-1;
		num=-num;
	}
	double l,h;
	if(num<=1)
	{
		l=num;
		h=1;
	}
	else
	{
		l=0;
		h=num/2+1;
	}
	while(abs(h-l)>epsilon)
	{
		double m=l+(h-l)/2;
		double tmp=m*m*m;
		if(abs(tmp-num)<epsilon)
		{
			return sign*m;
		}
		else if(tmp>num)
		{
			h=m;
		}
		else
		{
			l=m;
		}
	}
}