import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class PieChart extends JPanel implements ActionListener {
    private double[] is = {};
    private JTextField input;
    private final Color[] cs = {
        Color.MAGENTA, Color.YELLOW, Color.CYAN
    };
    
    public PieChart() {
        setPreferredSize(new Dimension(200, 240));
        input = new JTextField("", 16);
        input.addActionListener(this);
        setLayout(new FlowLayout());
        add(input);
    } 

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        int i;
        int n = is.length;

        int x = 100;
        int y = 140;
        int radius = 90;
        int startAngle = 90;
        g.drawOval(x - radius, y - radius, radius * 2, radius * 2);

        for (i = 0; i < n; i++) {
            g.setColor(cs[i % 3]);
            int arcAngle = (int) (is[i] / 100 * -360);
            g.fillArc(x - radius, y - radius, radius * 2, radius * 2, startAngle, arcAngle);
            startAngle += arcAngle;
        }
    }

    public void actionPerformed(ActionEvent e) {
        String[] args = input.getText().split(" ");
        int n = args.length;
        is = new double[n];

        int i;
        for (i = 0; i < n; i++) {
        try {

            double r = Double.parseDouble(args[i]);
            if (r >= 0 && r <= 100) {
                is[i] = r;
            }
            else {
                input.setText("Error");
            }
        } catch (NumberFormatException ex) {
            input.setText("Error");
        }
    }

        repaint();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Pie Chart");
            frame.add(new PieChart());
            frame.pack();
            frame.setVisible(true);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        });
    }
}