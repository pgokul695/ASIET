import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class logic {
    boolean green, yellow, red;

    logic() {
        green = false;
        yellow = false;
        red = false;
    }

    boolean isGreen() {
        return green;
    }

    boolean isYellow() {
        return yellow;
    }

    boolean isRed() {
        return red;
    }

    void setGreen(boolean state) {
        if (!red && !yellow) {
            green = state;
        }
    }

    void setYellow(boolean state) {
        if (!red && !green) {
            yellow = state;
        }
    }

    void setRed(boolean state) {
        if (!green && !yellow) {
            red = state;
        }
    }

    void reset() {
        green = false;
        yellow = false;
        red = false;
    }
}

class TrafficLightUI extends JFrame implements ActionListener {
    logic light;
    JRadioButton greenButton, yellowButton, redButton;
    ButtonGroup group;

    TrafficLightUI() {
        light = new logic();

        setTitle("Traffic Light Simulation");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        greenButton = new JRadioButton("Green");
        yellowButton = new JRadioButton("Yellow");
        redButton = new JRadioButton("Red");

        group = new ButtonGroup();
        group.add(greenButton);
        group.add(yellowButton);
        group.add(redButton);

        greenButton.addActionListener(this);
        yellowButton.addActionListener(this);
        redButton.addActionListener(this);

        panel.add(greenButton);
        panel.add(yellowButton);
        panel.add(redButton);

        add(panel, BorderLayout.NORTH);
    }

    public void actionPerformed(ActionEvent e) {
        light.reset();

        if (greenButton.isSelected()) {
            light.setGreen(true);
        } else if (yellowButton.isSelected()) {
            light.setYellow(true);
        } else if (redButton.isSelected()) {
            light.setRed(true);
        }

        repaint();
    }

    public void paint(Graphics g) {
        super.paint(g);

        g.setColor(Color.BLACK);
        g.fillRect(100, 100, 100, 300);

        if (light.isGreen()) {
            g.setColor(Color.GREEN);
        } else {
            g.setColor(Color.GRAY);
        }
        g.fillOval(120, 120, 60, 60);

        if (light.isYellow()) {
            g.setColor(Color.YELLOW);
        } else {
            g.setColor(Color.GRAY);
        }
        g.fillOval(120, 200, 60, 60);

        if (light.isRed()) {
            g.setColor(Color.RED);
        } else {
            g.setColor(Color.GRAY);
        }
        g.fillOval(120, 280, 60, 60);
    }
}

class main{
    public static void main(String[] args) {
    	TrafficLightUI ui = new TrafficLightUI();
        ui.setVisible(true);
   }
}


