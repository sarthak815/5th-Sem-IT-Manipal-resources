using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Data_Collection
{
    public partial class Form1 : Form
    {
        String msg = "";
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            msg += "DBMS";
            toolStripStatusLabel1.Text = "DBMS selected";
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "Gender selected";
        }

        private void statusStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void toolStripStatusLabel1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "Name box";
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "RegNo box";

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "Selecting Branch";
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "Entering dob";
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            msg += " CNP";
            toolStripStatusLabel1.Text = "CNP selected";
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            msg += " OOP";
            toolStripStatusLabel1.Text = "OOP selected";
        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {
            msg += " OS";
            toolStripStatusLabel1.Text = "OS Selected";
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            msg += " DSA";
            toolStripStatusLabel1.Text = "DSA selected";
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "Gender selected";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Name: " + textBox1.Text + "\nReg No: " + textBox2.Text + "\nBranch: " + comboBox1.SelectedItem + "Courses Selected: " + msg);
        }

        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {
            toolStripStatusLabel1.Text = "Entering dob";
        }
    }
}
