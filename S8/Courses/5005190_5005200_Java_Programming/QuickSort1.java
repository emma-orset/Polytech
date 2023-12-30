import java.util.Arrays;

public class QuickSort1 {
    private static void swap(int[] v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }

    private static void qsort(int[] v, int left, int right) {
        if (left >= right) return;
        int i = left, j = right;
        int pivot = v[i + (j - i) / 2];
        while (true) {
            while (v[i] < pivot) i++;
            while (pivot < v[j]) j--;
            if (i >= j) break;
            swap(v, i, j);
            i++;
            j--;
            drawAnimation(v); 
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        qsort(v, left, i - 1);
        qsort(v, j + 1, right);
    }

    private static void drawAnimation(int[] v) {
        System.out.println(Arrays.toString(v));
    }

    private static int data[] = {1, 3, 11, 4, 9, 2, 5, 8, 10, 7, 6, 0, 12};

    public static void main(String args[]) {
        for (int i = 0; i < data.length; i++) {
            System.out.printf("%d ", data[i]);
        }
        System.out.println();
        qsort(data, 0, data.length - 1);
        for (int i = 0; i < data.length; i++) {
            System.out.printf("%d ", data[i]);
        }
        System.out.println();
    }
}
