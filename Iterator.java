package savetime;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

class PrevIterator<T> implements Iterator<T> {

    Iterator<T> iterator;
    T prevItem;

    public PrevIterator(Iterator<T> iterator) {
        this.iterator = iterator;
    }

    public boolean hasNext() {
        return iterator.hasNext();
    }

    public T next() {
        if (!hasNext()) {
            throw new NoSuchElementException("");
        }

        prevItem = iterator.next();
        return prevItem;
    }

    public void remove() {
        throw new UnsupportedOperationException("");
    }

    public T previous() {
        try {
            if (prevItem == null)
                throw new NoSuchElementException("");
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return prevItem;
    }
}

class EvenIterator<T> implements Iterator<T> {
    public Iterator<T> iterator;
    T evenItem;

    public EvenIterator(Iterator<T> iterator) {
        this.iterator = iterator;
    }

    public boolean hasNext() {
        if (evenItem != null)
            return true;
        else {
            if (iterator.hasNext()) {
                iterator.next();
                if (iterator.hasNext()) {
                    evenItem = iterator.next();
                    return true;
                }
            }
            return false;
        }
    }

    public T next() {
        if (evenItem == null) {
            throw (new NoSuchElementException("Iterator has no elements left."));
        }

        T toreturn = evenItem;
        evenItem = null;
        if (iterator.hasNext()) {
            iterator.next();
            if (iterator.hasNext())
                evenItem = iterator.next();
        }
        return toreturn;
    }

    public void remove() {
        throw new UnsupportedOperationException();
    }
}

class RotateIterator<T> implements Iterator<T> {

    public List<Iterator<T>> lit;
    int index;

    public RotateIterator(List<Iterator<T>> lit) {
        this.lit = lit;
        index = 0;
    }

    public boolean hasNext() {
        if (lit.size() == 0) {
            throw (new NoSuchElementException("Iterator has no elements left."));
        }

        int origin = index;
        do {
            if (lit.get(index).hasNext()) {
                return true;
            }
            index = (index + 1) % (lit.size());
        } while (index != origin);
        return false;
    }

    public T next() {
        if (!hasNext()) {
            throw (new NoSuchElementException("Iterator has no elements left."));
        }

        T toreturn = lit.get(index).next();
        index = (index + 1) % (lit.size());
        return toreturn;
    }

    public void remove() {
        throw new UnsupportedOperationException();
    }
}

class JumpIterator<T> implements Iterator<T> {
    private final Iterator<T> iterator;

    public JumpIterator(Iterator<T> iterator) {
        this.iterator = iterator;
    }

    public boolean hasNext() {
        return iterator.hasNext();
    }

    public T next() {
        if (iterator.hasNext()) {
            T toreturn = iterator.next();
            if (iterator.hasNext()) {
                iterator.next();
            }
            return toreturn;
        }

        throw (new NoSuchElementException("Iterator has no elements left."));
    }

    public void remove() {
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

    public static void main(String[] args) {
        List<Integer> l = new ArrayList<Integer>();
        for (int i = 0; i < 9; i++)
            l.add(i);
        //
        // PeekIterator<Integer> pI=new PeekIterator<Integer>(l.iterator());
        // while (pI.hasNext()) {
        // System.out.println(pI.hasNext());
        // System.out.println(pI.hasNext());
        // System.out.println(pI.next());
        // }
        //
        // System.out.println("--------------------");
        //
        // JumpIterator<Integer> jI=new JumpIterator<Integer>(l.iterator());
        // while (jI.hasNext()) {
        // System.out.println(jI.hasNext());
        // System.out.println(jI.hasNext());
        // System.out.println(jI.next());
        // }
        //
        // System.out.println("--------------------");

        // List<Iterator<Integer>> lit = new ArrayList<Iterator<Integer>>();
        // int count = 1;
        // for (int i = 0; i < 4; i++) {
        // List<Integer> tmp = new ArrayList<Integer>();
        // for (int j = 0; j < 3; j++)
        // tmp.add(count++);
        // lit.add(tmp.iterator());
        // }
        // RotateIterator<Integer> rI = new RotateIterator<Integer>(lit);
        // while (rI.hasNext()) {
        // System.out.println(rI.next());
        // }

        // System.out.println("--------------------");
        //
        // EvenIterator<Integer> eI = new EvenIterator<Integer>(l.iterator());
        // while (eI.hasNext()) {
        // System.out.println(eI.hasNext());
        // System.out.println(eI.hasNext());
        // System.out.println(eI.next());
        // }

        System.out.println("--------------------");

        PrevIterator<Integer> pI = new PrevIterator<Integer>(l.iterator());
        while (pI.hasNext()) {
            System.out.println(pI.hasNext());
            System.out.println(pI.previous());
            System.out.println(pI.next());
        }
        System.out.println("end");
    }
}