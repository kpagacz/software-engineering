using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_3
{
    public partial class FormMain : Form
    {
        private string fileName = "";
        public FormMain()
        {
            InitializeComponent();
            newToolStripMenuItem_Click(null, null);
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox.Clear();
            fileName = "";
            this.Text = "New file";
        }

        private void closeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            fileName = "";
            this.Close();
            // Application.close();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog open_file = new OpenFileDialog();
            open_file.Filter = "Pliki tekstowe|*.txt";

            if (open_file.ShowDialog() == DialogResult.OK)
            {
                richTextBox.Text = File.ReadAllText(open_file.FileName);
                fileName = open_file.FileName;
                this.Text = open_file.FileName;
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(fileName != "")
            {
                File.WriteAllText(fileName, richTextBox.Text);
            }
            else    
            {
                saveAsToolStripMenuItem_Click(null, null);
            }

            this.Text = fileName;
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = "Pliki tekstowe|*.txt";

            if (sfd.ShowDialog() == DialogResult.OK)
            {
                this.Text = sfd.FileName;
                fileName = sfd.FileName;
                File.WriteAllText(sfd.FileName, richTextBox.Text);
            }
        }

        private void richTextBox_TextChanged(object sender, EventArgs e)
        {
            if(this.Text.Last<char>() != '*')
            {
                this.Text += "*";
            }
        }

        private void propertiesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormConfig fc = new FormConfig();
            fc.ConfigFontColor = richTextBox.ForeColor;
            fc.ConfigBackColor = richTextBox.BackColor;
            fc.ConfigFont = richTextBox.Font;

            if(fc.ShowDialog() == DialogResult.OK)
            {
                richTextBox.ForeColor = fc.ConfigFontColor;
                richTextBox.BackColor = fc.ConfigBackColor;
                richTextBox.Font = fc.ConfigFont;
            }
        }
    }
}
