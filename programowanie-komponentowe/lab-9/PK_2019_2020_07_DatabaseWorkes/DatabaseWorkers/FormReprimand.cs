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
    public partial class FormReprimands : Form
    {
        private Worker selectedWorker;
        public FormReprimands(Worker worker)
        {
            InitializeComponent();
            this.selectedWorker = worker;

            foreach (Reprimand r in selectedWorker.Reprimand)
            {
                UserControlReprimand ucr = new UserControlReprimand(r);
                flowLayoutPanelReprimand.Controls.Add(ucr);
            }
        }

        private void FormReprimands_FormClosing(object sender, FormClosingEventArgs e)
        {
            foreach(UserControlReprimand ucr in flowLayoutPanelReprimand.Controls)
            {
                ucr.updateData();
            }
        }

        internal string getPenaltyPoints()
        {
            int sum = 0;
            foreach(Object obj in flowLayoutPanelReprimand.Controls)
            {
                if(obj is UserControlReprimand)
                {
                    UserControlReprimand ucr = obj as UserControlReprimand;
                    sum += ucr.getPoints();
                }
            }

            return "Nagany: " + sum + " / 200";
        }
    }
}
