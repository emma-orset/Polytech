import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class HSBGradiation extends JPanel {
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        int width = getWidth();
        int height = getHeight();

        for (int y = 0; y < height; y++) {
            float s = (float) y / height;

            for (int x = 0; x < width; x++) {
                float h = (float) x / width;

                Color color = Color.getHSBColor(h, s, 1);
                g.setColor(color);
                g.fillRect(x, y, 1, 1);
            }
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("HSB 2D Gradient");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new HSBGradiation());
        frame.setSize(400, 400);
        frame.setVisible(true);
    }
}
