import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class QuickSort2 extends JPanel implements Runnable, ActionListener {
    private int[] data = {1, 3, 11, 4, 9, 2, 5, 8, 10, 7, 6, 0, 12};
    private final Color[] cs = {Color.RED, Color.ORANGE, Color.GREEN, Color.BLUE};
    private volatile Thread thread = null;
    private int i, j;
    private volatile boolean threadSuspended = true;

    public QuickSort2() {
        setPreferredSize(new Dimension(320, 250));
        JButton step = new JButton("Step");
        step.addActionListener(this);
        setLayout(new FlowLayout());
        add(step);
        startThread();
    }

    private void startThread() {
        if (thread == null) {
            thread = new Thread(this);
            thread.start();
        }
    }

    public void run() {
        qsort(0, data.length - 1);
    }

    private void qsort(int left, int right) {
        if (left >= right) return;
        int i = left, j = right;
        int pivot = data[i + (j - i) / 2];
        while (true) {
            while (data[i] < pivot) i++;
            while (pivot < data[j]) j--;
            if (i >= j) break;
            swap(i, j);
            i++;
            j--;
            repaint();
            try {
                synchronized (this) {
                    while (threadSuspended) {
                        wait();
                    }
                    threadSuspended = true;
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        qsort(left, i - 1);
        qsort(j + 1, right);
    }

    private void swap(int i, int j) {
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }

    public synchronized void actionPerformed(ActionEvent e) {
        threadSuspended = false;
        notify();
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int k = 0; k < data.length; k++) {
            g.setColor(cs[k % cs.length]);
            g.fillRect(20, 50 + k * 10, data[k] * 5, 10);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("クイックソート");
            frame.add(new QuickSort2());
            frame.pack();
            frame.setVisible(true);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        });
    }
}
