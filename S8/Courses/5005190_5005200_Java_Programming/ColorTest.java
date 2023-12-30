import javax.swing.*;
import java.awt.*;


public class ColorTest extends JPanel {
    public ColorTest() {
        setPreferredSize(new Dimension(150, 100));    
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        //  ((Graphics2D)g).setRenderingHint(
        //      RenderingHints.KEY_ANTIALIASING,
        //      RenderingHints.VALUE_ANTIALIAS_ON);
        String msg = "Hello, World!";
        g.setColor(Color.BLUE);
        g.setFont(new Font(Font.SERIF,
                           Font.PLAIN, 14));
        g.drawString(msg, 20, 25);
        g.setColor(Color.ORANGE);
        g.setFont(new Font(Font.SERIF,
                           Font.BOLD, 14));
        g.drawString(msg, 20, 50);
        g.setColor(Color.RED);
        g.setFont(new Font(Font.SERIF,
                           Font.ITALIC, 14));
        g.drawString(msg, 20, 75);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("ColorTest");
            frame.add(new ColorTest());
            frame.pack();
            frame.setVisible(true);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        });
    }
}

