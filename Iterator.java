package savetime;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

class JumpIterator<T> implements Iterator<T>{
    private final Iterator<T> iterator;
    
    public JumpIterator(Iterator<T> iterator)
    {
        this.iterator=iterator;
    }
    
    public boolean hasNext()
    {
        return iterator.hasNext();
    }
    
    public T next()
    {
        if(iterator.hasNext())
        {
            T toreturn=iterator.next();
            if(iterator.hasNext())
            {
                iterator.next();
            }
            return toreturn;
        }
        
        throw (new NoSuchElementException("Iterator has no elements left."));
    }
    
    public void remove()
    {
        throw new UnsupportedOperationException();
    }
}

public class PeekIterator<T> implements Iterator<T> {

    private final Iterator<T> iterator;
    private T nextitem;

    public PeekIterator(Iterator<T> iterator) {
        this.iterator = iterator;
    }

    public boolean hasNext() {
        if (nextitem != null) {
            return true;
        }

        if (iterator.hasNext()) {
            nextitem = iterator.next();
        }

        return nextitem != null;
    }

    public T next() {
        if (!hasNext()) {
            throw (new NoSuchElementException("Iterator has no elements left."));
        }

        T toReturn = nextitem;
        nextitem = null;
        return toReturn;
    }

    public T peek() {
        if (!hasNext()) {
            throw (new NoSuchElementException("Iterator has no elements left."));
        }

        return nextitem;
    }

    public void remove() {
        throw new UnsupportedOperationException();
    }
    
    public static void main(String[] args)
    {
        List<Integer> l=new ArrayList<Integer>();
        for(int i=0;i<3;i++)
            l.add(i);
    
        PeekIterator<Integer> pI=new PeekIterator<Integer>(l.iterator());
        System.out.println(pI.hasNext());
        System.out.println(pI.hasNext());
        System.out.println(pI.peek());
        System.out.println(pI.peek());
        System.out.println(pI.next());
        System.out.println(pI.hasNext());
        System.out.println(pI.hasNext());
        System.out.println(pI.peek());
        System.out.println(pI.peek());
        System.out.println(pI.next());
        
        System.out.println("--------------------");
        
        JumpIterator<Integer> jI=new JumpIterator<Integer>(l.iterator());
        System.out.println(jI.hasNext());
        System.out.println(jI.hasNext());
        System.out.println(jI.next());
        System.out.println(jI.hasNext());
        System.out.println(jI.hasNext());
        System.out.println(jI.next());
        System.out.println(jI.hasNext());
        System.out.println(jI.hasNext());
        System.out.println(jI.next());
        System.out.println("end");
    }
}