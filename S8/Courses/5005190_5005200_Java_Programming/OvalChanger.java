import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class OvalChanger extends JPanel
                     implements KeyListener {
    private int h = 50, w = 50;

    public OvalChanger() {
        setPreferredSize(new Dimension(300, 300));
        setFocusable(true);
        addKeyListener(this);
    }

    

    public void keyTyped(KeyEvent e) {
        int k = e.getKeyChar();
        if (k == 't') {
           h += 10;
        } else if (k == 'T') {
           h += 50;
        } 
        else if (k == 's'){
            h -= 10;
        }
        else if (k == 'S'){
            h -= 50;
        }
        else if (k == 'w'){
            w += 10;
        }
        else if (k == 'W'){
            w += 50;
        }
        else if (k == 'n'){
            w -= 10;
        }
        else if (k == 'N'){
            w -= 50;
        }

        System.err.printf("key = %d%n", k);
        repaint();
    }
    public void keyReleased(KeyEvent e) {}
    public void keyPressed(KeyEvent e) {}

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        int cntrX = getWidth()/2;
        int cntrY = getHeight()/2;

        g.setColor(Color.BLUE);
        g.fillOval(cntrX-w/2, cntrY-h/2, w, h);

    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Oval Changer");
            frame.add(new OvalChanger());
            frame.pack();
            frame.setVisible(true);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        });
    }
}