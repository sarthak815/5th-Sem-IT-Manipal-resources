using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OracleClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace agent
{   
    public partial class Form1 : Form
    {
        OracleConnection conn;
        OracleCommand comm;
        OracleDataAdapter da;
        DataSet ds;
        DataTable dt;
        DataRow dr;
        int i=0;
        public Form1()
        {
            InitializeComponent();
        }
        public void DB_Connect() {
            String oradb = "Data Source = DESKTOP-22PH1K0 ; Persist Security Info = True; User ID = system; Password = orcl123; Unicode = True";
            conn = new OracleConnection(oradb);
            conn.Open();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            DB_Connect();
            comm = new OracleCommand();
            comm.CommandText = "select * from agents";
            comm.CommandType = CommandType.Text;
            ds = new DataSet();
            da = new OracleDataAdapter(comm.CommandText, conn);
            da.Fill(ds, "Tbl_Agents");
            dt = ds.Tables["Tbl_Agents"];
            int t = dt.Rows.Count;
            MessageBox.Show(t.ToString());
            dr = dt.Rows[i];
            textBox1.Text = dr["AGENT_CODE"].ToString();
            textBox2.Text = dr["AGENT_NAME"].ToString();
            textBox3.Text = dr["WORKING_AREA"].ToString();
            textBox4.Text = dr["COMMISSION"].ToString();
            textBox5.Text = dr["PHONE_NO"].ToString();
            textBox6.Text = dr["COUNTRY"].ToString();
            conn.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DB_Connect();
            OracleCommand cm = new OracleCommand();
            cm.Connection = conn;
            cm.CommandText = "insert into agents values('" + textBox1.Text + "','" + textBox2.Text + "','" + textBox3.Text + "','" +
                textBox4.Text + "','" + textBox5.Text + "','" + textBox6.Text + "')";
            cm.CommandType = CommandType.Text;
            cm.ExecuteNonQuery();
            MessageBox.Show("Values Inserted");
            conn.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            i++;
            if (i >= dt.Rows.Count) i = 0;
            dr = dt.Rows[i];
            textBox1.Text = dr["AGENT_CODE"].ToString();
            textBox2.Text = dr["AGENT_NAME"].ToString();
            textBox3.Text = dr["WORKING_AREA"].ToString();
            textBox4.Text = dr["COMMISSION"].ToString();
            textBox5.Text = dr["PHONE_NO"].ToString();
            textBox6.Text = dr["COUNTRY"].ToString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            i--;
            if (i<0) i = dt.Rows.Count-1;
            dr = dt.Rows[i];
            textBox1.Text = dr["AGENT_CODE"].ToString();
            textBox2.Text = dr["AGENT_NAME"].ToString();
            textBox3.Text = dr["WORKING_AREA"].ToString();
            textBox4.Text = dr["COMMISSION"].ToString();
            textBox5.Text = dr["PHONE_NO"].ToString();
            textBox6.Text = dr["COUNTRY"].ToString();
        }
    }
}
