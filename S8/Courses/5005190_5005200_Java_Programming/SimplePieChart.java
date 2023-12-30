import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimplePieChart extends JPanel implements ActionListener {
    private JTextField input;
    private double percentage = 0;

    public SimplePieChart() {
        setPreferredSize(new Dimension(200, 240));
        input = new JTextField("0", 8);
        input.addActionListener(this);
        setLayout(new FlowLayout());
        add(input);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            double r = Double.parseDouble(input.getText());
            if (r >= 0 && r <= 100) {
                percentage = r;
            }
            else {
                input.setText("Error");
            }
        } catch (NumberFormatException ex) {
            input.setText("Error");
        }
        repaint(); // update the panel with the new percentage value
    }

    @Override
    public void paintComponent(Graphics g) {
      super.paintComponent(g);
      int x = 100;
      int y = 140;
      int radius = 90;
      int startAngle = 90;
      int arcAngle = (int) (percentage / 100 * -360);
  
      g.setColor(Color.BLUE);
      g.drawOval(x - radius, y - radius, radius * 2, radius * 2);
      g.fillArc(x - radius, y - radius, radius * 2, radius * 2, startAngle, arcAngle);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Simple Pie Chart");
            frame.add(new SimplePieChart());
            frame.pack();
            frame.setVisible(true);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        });
    }
}
