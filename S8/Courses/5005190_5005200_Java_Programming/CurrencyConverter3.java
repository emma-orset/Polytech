import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CurrencyConverter3 extends JPanel {
    private JTextField input1, input2;
    private int money1 = 0;
    private double money2 = 0;
    private String[] moneyStrings = {"USD", "EUR", "GBP", "CHF", "CNY"};
    private JComboBox<String> moneyList = new JComboBox<>(moneyStrings);

    public CurrencyConverter3() {
        setPreferredSize(new Dimension(300, 50));

        input1 = new JTextField(Integer.toString(money1), 8);
        input2 = new JTextField(Double.toString(money2), 8);

        moneyList.setSelectedIndex(1);

        ActionListener currencyListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Object source = e.getSource();

                String money = (String) moneyList.getSelectedItem();
                double jpy = change(money);

                try {
                    if (input1.getText().equals("")) {
                        money1 = 0;
                    } else {
                        money1 = Integer.parseInt(input1.getText());
                    }

                    if (input2.getText().equals("")) {
                        money2 = 0;
                    } else {
                        money2 = Double.parseDouble(input2.getText());
                    }

                    if (source == input1) {
                        money2 = money1 / jpy;
                        money2 = Math.floor(money2 * 1000) / 1000;
                        input2.setText(Double.toString(money2));
                    } else if (source == input2) {
                        money1 = (int) (money2 * jpy);
                        input1.setText(Integer.toString(money1));
                    } else if (source == moneyList) {
                        money2 = money1 / jpy;
                        money2 = Math.floor(money2 * 1000) / 1000;
                        input2.setText(Double.toString(money2));
                    }

                    if (Integer.parseInt(input1.getText()) < 0) {
                        input1.setText("0");
                    }
                    if (Double.parseDouble(input2.getText()) < 0) {
                        input2.setText("0");
                    }

                } catch (NumberFormatException ex) {
                    input1.setText("0");
                    input2.setText("0");
                }
            }
        };

        input1.addActionListener(currencyListener);
        input2.addActionListener(currencyListener);
        moneyList.addActionListener(currencyListener);

        setLayout(new FlowLayout());
        add(input1);
        add(new JLabel("JPY =  "));
        add(input2);
        add(moneyList);
    }

    private static double change(String money) {
        double jpy;
        switch (money) {
            case "USD":
                jpy = 138.57;
                break;
            case "EUR":
                jpy = 149.74;
                break;
            case "GBP":
                jpy = 172.26;
                break;
            case "CHF":
                jpy = 144.17;
                break;
            case "CNY":
                jpy = 19.66;
                break;
            default:
                jpy = 0;
                break;
        }
        return jpy;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Currency Converter");
            frame.add(new CurrencyConverter3());
            frame.pack();
            frame.setVisible(true);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        });
    }
}
