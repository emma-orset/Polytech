import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ColorPickerDraw extends JPanel implements MouseListener{
    private Color color = Color.RED;
    private int x1 = 0;
    private int y1 = 0;
    private int x2 = 0;
    private int y2 = 0;
    private final int width = 256;
    private final int height = 256;

    public ColorPickerDraw() {
        addMouseListener(this);
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);

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

    public void mouseClicked(MouseEvent e) {
        x2 = e.getX();
        y2 = e.getY();
        
        Graphics g = getGraphics();

        if (x2 < 256){
            float h = (float) x2 / width;
            float s = (float) y2 / height;
            color = Color.getHSBColor(h, s, 1);   
        }

        if (x2 > 256 && x1 == 0){
            x1 = x2;
            y1 = y2;
        }
        else if (x2 > 256 && x1 != 0){
            g.setColor(color);
            g.drawLine(x1, y1, x2, y2);
            x1 = x2;
            y1 = y2;
        }       
    }

    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {} 
    public void mouseExited(MouseEvent e) {}  

    public static void main(String[] args) {
        JFrame frame = new JFrame("Color Picker");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new ColorPickerDraw());
        frame.setSize(512,256);
        frame.setVisible(true);
    }
}
