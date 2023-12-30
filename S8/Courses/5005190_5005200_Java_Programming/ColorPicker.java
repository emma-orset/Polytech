import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ColorPicker extends JPanel implements MouseListener{
    private final int width = 400;
    private final int height = 400;

    public ColorPicker() {
        addMouseListener(this);
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        //int width = getWidth();
        //int height = getHeight();

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

    // En fonction de la position du clic de la souris, écrire "Hello World" avec la couleur correspondante
    public void mouseClicked(MouseEvent e) {
        int x = e.getX();
        int y = e.getY();
        float h = (float) x / width;
        float s = (float) y / height;
        Color color = Color.getHSBColor(h, s, 1);
        Graphics g = getGraphics();
        g.setColor(color);
        g.setFont(new Font("impact", Font.BOLD, 40)); 
        g.drawString("Hello World", 30, 450);
    }

    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {} 
    public void mouseExited(MouseEvent e) {}  

    public static void main(String[] args) {
        JFrame frame = new JFrame("Color Picker");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new ColorPicker());
        frame.setSize(400,500);
        frame.setVisible(true);
    }
}
