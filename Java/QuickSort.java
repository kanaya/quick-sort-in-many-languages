public class QuickSort {
	static void quick_sort(int[] a, int start, int end) {
		int pivot;
		int w;
		int s, e;
		if (start >= end)
			return;
		if (1 == (end - start)) {
			if (a[start] > a[end]) {
				w = a[start];
				a[start] = a[end];
				a[end] = w;
			}
			return;
		}
		pivot = a[start];
		s = start - 1;
		e = end + 1;
		for ( ; ; ) {
			for ( ; ; ) {
				++s;
				if (a[s] >= pivot)
					break;
			}
			for ( ; ; ) {
				--e;
				if (a[e] <= pivot)
					break;
			}
			if (s >= e)
				break;
			w = a[s];
			a[s] = a[e];
			a[e] = w;
		}
		if (s == e)
			++s;
		quick_sort(a, start, e);
		quick_sort(a, s, end);
	}

	static void quick_sort(int[] a) {
		if (1 >= a.length)
			return;
		quick_sort(a, 0, a.length - 1);
	}
	public static void main(String[] args) {
		int[] a;
		a = new int[10];
		a[ 0 ] =  4;
		a[ 1 ] = 20;
		a[ 2 ] = 15;
		a[ 3 ] =  0;
		a[ 4 ] = 12;
		a[ 5 ] = 10;
		a[ 6 ] =  7;
		a[ 7 ] = 13;
		a[ 8 ] =  8;
		a[ 9 ] =  9;
		quick_sort(a);
		for (int i = 0; i < a.length; ++i) {
			System.out.println(a[i]);
		}
	}
}

