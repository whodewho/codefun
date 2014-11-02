bool littleEndian()
{
	int a=1;
	return (int)(char*)(&a)==1
}