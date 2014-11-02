class NAryTree{
	int N;

	list<int> *adj;

	void getMinIterUtil(int v, int minIter[]);
public:
	NAryTree(int N);

	void addChild(int v, int w);

	int getMinIter();
};

NAryTree::NAryTree(int N)
{
	this->N=N;
	adj=new List<int>[N];
}

void NAryTree::addChild(int v, int w)
{
	adj[v].push_back(w);
}

void NAryTree::getMinIterUtil(int u, int minIter[])
{
	minIter[u]=adj[u].size();
	int maxChildItr=0;
	int noOfMaxChildItr=0;

	list<int>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();++i)
	{
		getMinIterUtil(*i, minIter);
		if(minIter[*i]>maxChildItr){
			maxChildItr=minIter[*i];
			noOfMaxChildItr=1;
		}
		else if(minIter[*i]==maxChildItr)
			noOfMaxChildItr++;
	}
	minIter[u]=max(minIter[u], maxChildItr+noOfMaxChildItr);
}

int NAryTree::getMinIter()
{
	int *minIter=new int[N];

	for(int i=0;i<N;i++)
		minIter[i]=0;

	getMinIterUtil(0, minIter);
	return minIter[0];
}