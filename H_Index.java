
public static int findH(int[] a) {
        int[] c = new int[a.length];
        for (int i = 0; i < a.length; i++) {
                if (a[i] > a.length - 1)
                        c[a.length - 1]++;
                else
                        c[a[i] - 1]++;
        }
        int total=0;
        for (int i = c.length - 1; i >= 0; i--) {
                total += c[i];
                if (i + 1 <= total)
                        return i + 1;
        }
        return -1;
}


public static int findH(int[] a) {
        // sort the array first (can use bucket sort)
        Arrays.sort(a);
        int max = 0;
        int n = a.length;
        for (int i = 0, h = 1; h <= n - i; h++) {
            if (n - i >= h)
                max = h;
            while (h >= a[i])
                i++;
        }
        return max;
}

