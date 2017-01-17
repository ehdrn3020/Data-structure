package test;

public class quickSort {

	public static void main(String[] args) {
		int data[] = {1,3,5,2,8,7,4,9,6,10};
		quickSort(data, 0, data.length-1);

		for(int c : data)
			System.out.print(c+" ");
		}

	public static void quickSort(int data[], int start, int end) {
		if(start < end) {
			int pivotIdx = getPivot(data, start, end);
			/*
			for(int c : data)
				System.out.print(c+" ");
			System.out.println(" "+pivotIdx);
				*/
			quickSort(data, start, pivotIdx-1);
			quickSort(data, pivotIdx + 1, end);
		}
	}

	public static int getPivot(int data[], int start, int end) {
		int i = start-1;
		int pivot = data[end];

	for(int j=start; j<=end-1; j++) {
		if(data[j] <= pivot) {
			int temp = data[++i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	int temp = data[i + 1];
	data[i + 1] = data[end];
	data[end] = temp;
	return i + 1;
	}
}