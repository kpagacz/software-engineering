using System;
using System.Windows.Forms;

namespace lab_2_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void LabButton1_Click_Swap(object sender, EventArgs e)
        {
            // validation
            try
            {
                this.ResultBox.Text = (int.Parse(this.textBox1.Text) + int.Parse(this.textBox2.Text)).ToString();
            }
            catch
            {
                this.ResultBox.Text = "Error in input.";
            }

            // another option
            if (int.TryParse(this.textBox1.Text, out int liczba1) &&
                int.TryParse(this.textBox2.Text, out int liczba2))
            {
                this.ResultBox.Text = (liczba1 + liczba2).ToString();
            }
            else
            {
                // Message box!
                MessageBox.Show("Only numbers accepted!");
            }

        }
    }
}
