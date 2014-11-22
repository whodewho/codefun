enum TriangleType{DENGYAO, DENGBIAN, XIE, ERROR}

TriangleType triangle(int a, int b, int c)
{
    if(a<=0||b<=0||c<=0)return ERROR;
    if(a==b&&b==c)return DENGBIAN;
    if(a==b||b==c||a==c)return DENGYAO;
    if(long(a)+long(b)<＝c||long(b)+long(c)<＝a||long(a)+long(c)<＝b)return ERROR;
    return XIE;
}

void testtriangle_Normal()
{
	assert(triangle(1,1,1)==DENGBIAN);
	assert(triangle(2,2,1)==DENGYAO);
	assert(triangle(2,3,4)==XIEBIAN);
}

void testtriangle_NegativeZero()
{
	assert(triangle(-1,1,1)==ERROR);
	assert(triangle(-1,-1,1)==ERROR);
	assert(triangle(1,1,-1)==ERROR);
	assert(triangle(0,1,1)==ERROR);
}

void testtriangle_Overflow()
{
	assert(triangle(INT_MAX, INT_MAX, INT_MAX)==DENGBIAN);
	assert(triangle(INT_MAX, 1, INT_MAX-1)==ERROR);
	assert(triangle(INT_MAX, 1, INT_MAX)==DENGYAO);
	assert(triangle(INT_MAX, 2, INT_MAX-1)==XIE);
}

