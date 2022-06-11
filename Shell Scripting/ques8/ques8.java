package ques8;

import java.io.*;
import java.awt.*;
import java.applet.*;

public class ques8 extends Applet {
    public void paint(Graphics g) {
        g.drawString(".html path : "+(getDocumentBase()).toString(), 10, 20);
        g.drawString(".class path : " + (getCodeBase()).toString(), 10, 50);
    }
}