enum Direction{STOP,UP,DOWN,LEFT,RIGHT}

vector<int> longestIncreasingSequence(vector<vector<int> > matrix)
{
    vector<int> result;
    int m=matrix.size();
    if(!m)return result;
    int n=matrix[0].size();
    if(!n)return result;
    
    vector<vector<int> > longest(m, vector<int>(n, 0));
    vector<vector<Direction> > prevNode(m, vector<Direction>(n,STOP));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(longest[i][j]==0)
        {
            longest[i][j]=1;
            longestIncreasingSequenceHelper(matrix, longest, prevNode, m, n, i, j);
        }

     int startI=0, startJ=0;
     for(int i=0;i<m;i++)
         for(int j=0;j<n;j++)
         {
      	      if(longest[i][j]>longest[startI][startJ])
             {
                startI=i;
                startJ=i;
             }
         }
     
     while(prevNode[startI][startJ]!=STOP)
     {
         result.push_back(matrix[startI][startJ]);
         if(prevNode[startI][startJ]==UP)startI-=1;
         else if(prevNode[startI][startJ]==DOWN)startI+=1;
         else if(prevNode[startI][startJ]==LEFT)startJ-=1;
         else if(prevNode[startI][startJ]==RIGHT)startJ+=1;
     }
     reverse(result.begin(), result.end());
     return result;
}

void longestIncreasingSequenceHelper(vector<vector<int> > matrix, vector<vector<int> > &longest, vector<vector<Direction> > &prevNode, int m, int n, int i, int j)
{
    if(i+1<m&&matrix[i+1][j]==matrix[i][j]+1&&longest[i][j]+1>longest[i+1][j])
    {
        longest[i+1][j]=longest[i][j]+1;
        prevNode[i+1][j]=UP;
        longestIncerasingSequenceHelper(matrix, longest, prevNode, m, n, i+1, j);
    }
    
    if(i-1>=0&&matrix[i-1][j]==matrix[i][j]+1&&longest[i][j]+1>longest[i-1][j])
    {
        longest[i-1][j]=longest[i][j]+1;
        prevNode[i-1][j]=DOWN;
        longestIncreasingSequenceHelper(matrix, longest, prevNode, m, n, i-1, j);
    }
    
    if(j+1<n&&matrix[i][j+1]==matrix[i][j]+1&&longest[i][j]+1>longest[i][j+1])
    {
        longest[i][j+1]=longest[i][j]+1;
        prevNode[i][j+1]=LEFT;
        longestIncreasingSequenceHelper(matrix, longest, prevNode, m, n, i, j+1);
    }
    
    if(j-1>=0&&matrix[i][j-1]==matrix[i][j]+1&&longest[i][j]+1>longest[i][j-1])
    {
        longest[i][j-1]=longest[i][j]+1;
        prevNode[i][j-1]=RIGHT;
        longestIncreasingSequenceHelper(matrix, longest, prevNode, m, n, i, j-1);
    }
}
