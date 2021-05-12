using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DatabaseWorkers
{
    public partial class UserControlReprimand : UserControl
    {
        private Reprimand reprimand;
        private bool removed = false;

        public UserControlReprimand()
        {
            InitializeComponent();
        }

        public UserControlReprimand(Reprimand reprimand)
        {
            InitializeComponent();
            this.reprimand = reprimand;

            groupBox1.Text = "Reprimand";
            dateTimePicker1.Value = reprimand.Date;
            richTextBoxDescription.Text = reprimand.Description;
            numericUpDownPenaltyPoints.Value = reprimand.PenaltyPoints;
            
        }

        internal void updateData()
        {
            if(Visible)
            {
                reprimand.Date = dateTimePicker1.Value;
                reprimand.PenaltyPoints = (int)numericUpDownPenaltyPoints.Value;
                reprimand.Description = richTextBoxDescription.Text;
            } else
            {
                Form1.DatabaseDC.Reprimand.DeleteOnSubmit(reprimand);
            }
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            Visible = false;
            removed = true;
        }

        internal int getPoints()
        {
            if(!removed)
            {
                return reprimand.PenaltyPoints;
            } else
            {
                return 0;
            }
        }
    }
}
