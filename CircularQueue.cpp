//not tested yet

class CircularQueue{
  private:
      int size;
      int count;
      int nextIn;
      int nextOut;
      mutex bar;
      int *p;
      static int a;

  public:
      initialize(int s)
      {
          p=new int[s];
          size=s;
          count=0;
          nextIn=0;
          nextOut=0;
      }

      bool enqueue(int item)
      {
          unique_lock<mutex> lck1(bar);
          if(size>count)
          {
              p[nextIn]=item;
              nextIn=(nextIn+1)%size;
              count++;
              return true;
          }
          return false;
      }

      int dequeue()
      {
          unique_lock<mutex> lck1(bar);
          if(size>0)
          {
              int toReturn=p[nextOut];
              nextOut=(nextOut+1)%size;
              count--;
              return toReturn;
          }
          else
          {
              throw 1;
          }
      }
};

void test_enqueue(CircularQueue cq)
{
  cq.enqueue(a++);
}

void test_dequeue(CircularQueue cq)
{
  cout<<cq.dequeue()<<endl;
}

void testCircularQueue_Normal()
{
  CircularQueue cq;
  cq.initialize(10);
  thread ta(test_enqueue, cq);
  thread tb(test_enqueue, cq);
  thread tc(test_enqueue, cq);
  thread td(test_dequeue, cq);
  thread te(test_dequeue, cq);

  ta.detach();
  tb.detach();
  tc.detach();
  td.detach();
  te.detach();
}

void testCircularQueue_SingleThread()
{
  CircularQueue cq;
  cq.initialize(1);
  assert(true==cq.enqueue(1));
  assert(1==cq.dequeue());
}

void testCircularQueue_SingleThreadZero()
{
  CircularQueue cq;
  cq.initialize(0);
  assert(false==cq.enqueue(1));
  assert(cq.dequeue());
}