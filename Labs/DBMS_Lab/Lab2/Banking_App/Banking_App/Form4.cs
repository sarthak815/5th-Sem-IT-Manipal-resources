using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Banking_App
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string amount = textBox2.Text;
            int am = Int32.Parse(amount);
            if (am > 50000)
            {
                MessageBox.Show("Insufficient Funds");

            }
            else {

                MessageBox.Show("Amount transferred: " + amount + "\nRemaining Balance: " + (50000 - am));
                this.Close();
            }
        }
    }
}
