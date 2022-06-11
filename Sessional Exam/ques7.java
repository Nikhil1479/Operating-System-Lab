import java.awt.*;

public class ques7 extends java.applet.Applet {
    public void paint(Graphics g) {
        g.drawOval(80, 70, 150, 150);
        g.fillOval(120, 120, 15, 15);
        g.fillOval(170, 120, 15, 15);
        g.drawArc(130, 180, 50, 20, 180, 180);

        g.drawLine(100, 400, 300, 400);
        g.drawLine(100, 400, 70, 450);
        g.drawLine(300, 400, 350, 450);
        g.drawLine(300, 400, 250, 450);
        g.drawRect(70, 450, 280,100);
        g.drawLine(250, 450, 250, 550);
    }
}