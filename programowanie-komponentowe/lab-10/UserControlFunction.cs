using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace lab_10
{
    public partial class UserControlFunction : UserControl
    {
        public delegate void delegateName(UserControlFunction ucf);
        public event delegateName FunctionChanged;
        public event delegateName RemoveUcf;

        private Series s;

        public Series S { get => s; set => s = value; }

        public UserControlFunction()
        {
            InitializeComponent();
            createSeries();
        }

        public double calculateValue(double x)
        {
            return (double)numericUpDownA.Value * x * x + (double)numericUpDownB.Value * x + (double)numericUpDownC.Value;
        }

        private void numericUpDownA_ValueChanged(object sender, EventArgs e)
        {
            renameSeries();
            FunctionChanged?.Invoke(this);
        }

        private void numericUpDownB_ValueChanged(object sender, EventArgs e)
        {
            renameSeries();
            FunctionChanged?.Invoke(this);
        }

        private void numericUpDownC_ValueChanged(object sender, EventArgs e)
        {
            renameSeries();
            FunctionChanged?.Invoke(this);
        }

        private void createSeries()
        {
            S = new Series();
            S.ChartType = SeriesChartType.Line;
            S.BorderWidth = 2;
            renameSeries();
        }

        private void buttonRemove_Click(object sender, EventArgs e)
        {
            RemoveUcf(this);
        }

        private void renameSeries()
        {
            S.LegendText = numericUpDownA.Value + " * x^2 + " + numericUpDownB.Value + " * x + " + numericUpDownC.Value;
        }
    }
}
