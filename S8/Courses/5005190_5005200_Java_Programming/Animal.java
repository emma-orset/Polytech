import javax.swing.*;
import java.awt.*;
import static java.awt.Color.*;


public class Animal extends JPanel {
    public Animal() {
        setPreferredSize(new Dimension(400, 400));
    }

    @Override
    public void paintComponent(Graphics g) {
        // ((Graphics2D)g).setRenderingHint(
        //      RenderingHints.KEY_ANTIALIASING,
        //      RenderingHints.VALUE_ANTIALIAS_ON);
        super.paintComponent(g);
        int[] xs = {110, 108, 120};
        int[] ys = {  90,   109,  101};

        int[] xt = {150, 153, 140};
        int[] yt = {  90,   111,  101};

        int[] xn = {125, 130, 135};
        int[] yn = {  130,   135,  130};

        String msg = "NYAN NYAN!";
        g.setColor(Color.BLUE);
        g.setFont(new Font(Font.SERIF,
                           Font.PLAIN, 14));
        g.drawString(msg, 150, 40);

        g.setColor(BLACK);
        g.drawOval(100, 100, 60, 60);
        g.fillOval(112, 115, 10, 10);
        g.fillOval(136, 115, 10, 10);
        g.fillRect(150, 150, 100, 50);
        g.fillPolygon(xs, ys, 3);
        g.fillPolygon(xt, yt, 3);
        g.fillPolygon(xn, yn, 3);
        g.drawLine(160, 200, 160, 240);
        g.drawLine(170, 200, 170, 235);
        g.drawLine(230, 200, 210, 240);
        g.drawLine(240, 200, 220, 235);
        //g.drawLine(250, 150, 280, 115);
        g.drawArc(200, 55, 100, 100,0, -90);
        g.drawLine(95, 135, 117, 140);
        g.drawLine(90, 145, 117, 145);
        g.drawLine(95, 155, 117, 150);
        g.drawLine(162, 135, 140, 140);
        g.drawLine(167, 145, 140, 145);
        g.drawLine(162, 155, 140, 150);


        g.setColor(PINK);
        g.fillOval(124, 140, 10, 15);

        
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Animal");
            frame.add(new Animal());
            frame.pack();
            frame.setVisible(true);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        });
    }
}


