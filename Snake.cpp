struct Node
{
	int x;
	int y;
};

enum Direction{LEFT,RIGHT,UP,DOWN};

class SnakeGame
{
    int height,width;
    deque<Node> snake;
    vector<vector<bool> > board;
    Direction autoDirection;

    bool autoMove()
    {
        int n1,nj;
        Node head=snake.front();
        if(autoDirection==RIGHT)
        {
            ni=head.i;
            nj=head.j+1;
        }
        else if(autoDirection==DONW)
        {
            ni=head.i+1;
            nj=head.j;
        }
        else if(autoDirection==LEFT)
        {
            ni=head.i;
            nj=head.j-1;
        }
        else
        {
            ni=head.i-1;
            nj=head.j;
        }

        if(ni<0||ni>=height||nj<0||nj>=width||board[ni][nj]==false)
        {
            return false;
        }

        Node newHead(ni,nj);
        board[ni][nj]=false;
        snake.push_front(newHead);
        snake.pop_back();
    }

    bool changeDirection(Direction d)
    {

    }  
}
