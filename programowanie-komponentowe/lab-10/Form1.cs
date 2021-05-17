using System.Linq;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace lab_10
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            buttonAdd_Click(null, null);
        }

        private void RedrawSeries(UserControlFunction o)
        {
            chart1.Series.Remove(o.S);
            o.S.Points.Clear();
            foreach (int x in Enumerable.Range(-10, 21).ToArray())
            {
                o.S.Points.AddXY(x, o.calculateValue(x));
            }
            chart1.Series.Add(o.S);
      
            chart1.ChartAreas.First().RecalculateAxesScale();
        }

        private void removeSeries(UserControlFunction ucf)
        {
            chart1.Series.Remove(ucf.S);
            chart1.ChartAreas.First().RecalculateAxesScale();
            flowLayoutPanel1.Controls.Remove(ucf);
        }

        private void buttonAdd_Click(object sender, System.EventArgs e)
        {
            UserControlFunction new_chart = new UserControlFunction();
            new_chart.Width = flowLayoutPanel1.Width;
            new_chart.FunctionChanged += RedrawSeries;
            new_chart.RemoveUcf += removeSeries;
            flowLayoutPanel1.Controls.Add(new_chart);
            RedrawSeries(new_chart);
        }
    }
}
