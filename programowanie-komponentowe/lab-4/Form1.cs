using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


// lab-4
namespace lab_4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            // button
            Button b = new Button();
            this.Controls.Add(b);

            b.Location = new Point(50, 50);
            b.Size = new Size(50, 50);
            b.Text = "B";
            b.BackColor = Color.Beige;
            b.ForeColor = Color.FromArgb(128, 0, 0, 255);

            b.Click += button_Click;

            // button2
            b = new Button();
            this.Controls.Add(b);

            b.Location = new Point(200, 200);
            b.Size = new Size(50, 50);
            b.Text = "C";
            b.BackColor = Color.Beige;
            b.ForeColor = Color.FromArgb(128, 0, 0, 255);

            b.Click += button_Click;
        }

        private void button_Click(object sender, EventArgs e)
        {
            // sender is a reference to the object, which was clicked!
            if(sender is Button)
            {
                String s = (sender as Button).Text;
                MessageBox.Show("Button clicked:" + s);
            } else
            {
                MessageBox.Show("Not a button!");
            }
        }
    }
}
