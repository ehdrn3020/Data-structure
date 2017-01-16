package test;

import java.util.*;

public class mergeSort {
	static void Merge(int data[], int p, int q, int r) {
		int i = p, j = q + 1, k = p;
		int[] tmp = new int[data.length];

		while (i <= q && j <= r) {
			if (data[i] <= data[j])
				tmp[k++] = data[i++];
			else
				tmp[k++] = data[j++];
		}
		while (i <= q)
			tmp[k++] = data[i++];
		while (j <= r)
			tmp[k++] = data[j++];

		for (i = p; i <= r; i++)
			data[i] = tmp[i];
	}

	static void mergeSort(int A[], int p, int r) {
		if (p < r) {
			int q = (p + r) / 2;
			mergeSort(A, p, q);
			mergeSort(A, q + 1, r);
			Merge(A, p, q, r);
		}

	}

	public static void main(String[] args) {
		int[] A = { 2, 5, 4, 9, 6, 3, 8, 0, 1, 7 };
		mergeSort(A, 0, 9);
		for (int i = 0; i < 10; i++)
			System.out.println(A[i]);
	}
}