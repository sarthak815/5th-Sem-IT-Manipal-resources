using System;
using System.Data;
using System.Data.OracleClient;
using System.Windows.Forms;
namespace Collegedb
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
        //ClickonClosebuttonshouldclosethecompleteapplication.
        private void Form1_FormClosing(object sender, FormClosingEventArgs e){
            DialogResult dr=MessageBox.Show("Are you sure you want to exit the Application?","Exit",MessageBoxButtons.YesNoCancel);
            if(dr==DialogResult.Yes)
                e.Cancel=true;
                Application.Exit();}

        [Obsolete]
        public void DB_Connect() { 
            String oradb = "Data Source = DESKTOP-22PH1K0 ; Persist Security Info = True; User ID = system; Password = orcl123; Unicode = True"; 
            conn = new OracleConnection(oradb); 
            conn.Open(); 
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            DB_Connect(); 
            int v = int.Parse(textBox2.Text);
            OracleCommand cm = new OracleCommand(); 
            cm.Connection = conn; 
            cm.CommandText = "updateinstructorsetsalary=:pbwheredeptname=:pdn"; 
            cm.CommandType = CommandType.Text;
            //UsesOracleParametertoreadtheparameterfromtheGUI
            OracleParameter pa1=new OracleParameter();
            pa1.ParameterName="pb"; 
            pa1.DbType=DbType.Int32;
            pa1.Value=v;
            OracleParameter pa2=new OracleParameter();
            pa2.ParameterName="pdn";
            pa2.DbType=DbType.String;
            pa2.Value=textBox1.Text;
            cm.Parameters.Add(pa1);
            cm.Parameters.Add(pa2);
            cm.ExecuteNonQuery(); 
            MessageBox.Show("updated"); 
            conn.Close();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            DB_Connect(); 
            comm = new OracleCommand(); 
            comm.CommandText = "select * from instructor";  
            comm.CommandType = CommandType.Text; 
            ds = new DataSet(); 
            da = new OracleDataAdapter(comm.CommandText, conn); 
            da.Fill(ds, "Tbl_instructor");
            dt = ds.Tables["Tbl_instructor"]; 
            int t = dt.Rows.Count; 
            MessageBox.Show(t.ToString()); 
            dr = dt.Rows[i]; 
            textBox1.Text = dr["id"].ToString();
            textBox2.Text = dr["name"].ToString(); 
            textBox3.Text = dr["dept_name"].ToString();
            textBox4.Text = dr["salary"].ToString(); 
            conn.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            i++; 
            if (i >= dt.Rows.Count) i = 0; 
            dr = dt.Rows[i]; textBox1.Text = dr["id"].ToString(); 
            textBox2.Text = dr["name"].ToString(); 
            textBox3.Text = dr["dept_name"].ToString(); 
            textBox4.Text = dr["salary"].ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            i--; 
            if (i < 0) i = dt.Rows.Count - 1; 
            dr = dt.Rows[i]; 
            textBox1.Text = dr["id"].ToString(); 
            textBox2.Text = dr["name"].ToString(); 
            textBox3.Text = dr["dept_name"].ToString();
            textBox4.Text = dr["salary"].ToString();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            DB_Connect(); 
            int sal = int.Parse(textBox4.Text); 
            OracleCommand cm = new OracleCommand();
            cm.Connection = conn;
            cm.CommandText = "insert into instructor values('" + textBox1.Text + "', '" + textBox2.Text + "','" + textBox3.Text + "','" + textBox4.Text + "')"; 
            cm.CommandType = CommandType.Text; 
            cm.ExecuteNonQuery();
            MessageBox.Show("Inserted!");
            conn.Close();
        }

        [Obsolete]
        private void button7_Click(object sender, EventArgs e)
        {
            DB_Connect(); 
            comm = new OracleCommand(); 
            comm.CommandText = "select * from instructor"; 
            comm.CommandType = CommandType.Text;
            ds = new DataSet(); 
            da = new OracleDataAdapter(comm.CommandText, conn); 
            da.Fill(ds, "Tbl_instructor");
            dt = ds.Tables["Tbl_instructor"];
            int t = dt.Rows.Count; 
            MessageBox.Show(t.ToString());
            dr = dt.Rows[i]; 
            dataGridView1.DataSource = ds.Tables[0];
            conn.Close();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
