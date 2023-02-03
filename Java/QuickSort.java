import java.util.Random;

public class QuickSort {
	static void quick_sort_impl(int[] a, int start, int end) {
		int pivot;
		int w;
		int s, e;
		if (start >= end)
			return;
		if ((end - start) == 1) {
			if (a[start] > a[end]) {
				// swap a[start] and a[end]
				w = a[start];
				a[start] = a[end];
				a[end] = w;
			}
			return;
		}
		pivot = a[start];
		s = start - 1;
		e = end + 1;
		while (true) {
			while (true) {
				++s;
				if (a[s] >= pivot)
					break;
			}
			while (true) {
				--e;
				if (a[e] <= pivot)
					break;
			}
			if (s >= e)
				break;
			// swap a[s] and a[e]
			w = a[s];
			a[s] = a[e];
			a[e] = w;
		}
		if (s == e) {
			++s;
		}
		quick_sort_impl(a, start, e);
		quick_sort_impl(a, s, end);
	}

	static void quick_sort(int[] a) {
		if (a.length <= 1)
			return;
		quick_sort_impl(a, 0, a.length - 1);
	}
	public static void main(String[] args) {
		int[] arr = new Random().ints(100, 0, 100).toArray();
		quick_sort(arr);
		for (int i = 0; i < arr.length; ++i) {
			System.out.println(arr[i]);
		}
	}
}

