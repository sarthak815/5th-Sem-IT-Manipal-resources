using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication3
{
    public partial class Form1 : Form
    {
        String op = "";
        String s1 = "";
        public Form1()
        {
            InitializeComponent();
        }

        private void button11_Click(object sender, EventArgs e)
        {

        }

        private void button15_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("1");
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("2");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("3");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("4");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("5");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("6");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("7");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("8");
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("9");
        }

        private void button17_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("0");
        }

        private void button11_Click_1(object sender, EventArgs e)
        {   

            s1 = textBox1.Text;
            textBox1.Clear();
            op = "+";

        }

        private void button12_Click(object sender, EventArgs e)
        {
            s1 = textBox1.Text;
            textBox1.Clear();
            op = "-";
        }

        private void button13_Click(object sender, EventArgs e)
        {
            s1 = textBox1.Text;
            textBox1.Clear();
            op = "*";
        }

        private void button14_Click(object sender, EventArgs e)
        {
            s1 = textBox1.Text;
            textBox1.Clear();
            op = "/";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            double a = Convert.ToDouble(s1);
            double b = Convert.ToDouble(textBox1.Text);
            textBox1.Clear();
            double res = 0;
            Boolean bl= false;
            switch (op) { 
                case "+":
                    res = a + b;
                    break;
                case "-":
                    res = a - b;
                    break;
                case "/":
                    if (b == 0)
                    {
                        bl = true;
                    }
                    else
                        res = a / b;
                    break;
                case "*":
                    res = a * b;
                    break;
                case "":
                    res = b;
                    break;
                default:
                    break;
            }
            
            string ans = Convert.ToString(res);
            if (bl)
                ans = "Cannot divide by zero";
            textBox1.AppendText(ans);
        }

        private void button16_Click(object sender, EventArgs e)
        {
            textBox1.AppendText(".");
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
