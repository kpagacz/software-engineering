using System;
using System.Drawing;
using System.Windows.Forms;

namespace lab_8
{
    public partial class UserControlClock : UserControl
    {
        private bool isDigital;
        private Graphics drawer;
        public UserControlClock()
        {
            InitializeComponent();
            IsDigital = false;
            pictureBoxClock_SizeChanged(null, null);
        }

        public bool IsDigital {
            get
            {
                return isDigital;
            }
            set 
            {
                isDigital = value; 
                if(isDigital)
                {
                    labelClock.Visible = true;
                    pictureBoxClock.Visible = false;
                } else
                {
                    labelClock.Visible = false;
                    pictureBoxClock.Visible = true;
                }
            } 
        }

        private void TimerClock_Tick(object sender, EventArgs e)
        {
            if(IsDigital)
            {
                labelClock.Text = DateTime.Now.ToString();
            } else
            {
                drawer.Clear(this.BackColor);
                int side = Math.Min(pictureBoxClock.Width, pictureBoxClock.Height);
                drawer.DrawEllipse(new Pen(this.ForeColor, 2), -side / 2, -side / 2, side - 1, side - 1);
                drawLine(side, 2 * Math.PI * (DateTime.Now.Second - 15) / 60 , 1, 1);
                drawLine(side, 2 * Math.PI * (DateTime.Now.Minute - 15 + DateTime.Now.Second / 60.0) / 60, 2, 1);
                drawLine(side, 2 * Math.PI * (DateTime.Now.Hour - 3 + DateTime.Now.Minute / 60.0) / 12, 2, (float)0.75);
                drawHours(side);

                pictureBoxClock.Refresh();
            }
        }

        private void drawLine(int side, double angle, int lineThickness, float length)
        {
            float x = (float)(side / 2 * Math.Cos(angle));
            float y = (float)(side / 2 * Math.Sin(angle));
            drawer.DrawLine(new Pen(this.ForeColor, lineThickness), 0, 0, x * length, y * length);
        }

        private void drawHours(int side)
        {
            for(int i = 0; i < 12; i++)
            {
                float x = (float)(side / 2 * Math.Cos(2 * Math.PI * i / 12.0));
                float y = (float)(side / 2 * Math.Sin(2 * Math.PI * i / 12.0));
                drawer.DrawLine(new Pen(this.ForeColor, 1), (float)0.9 * x, (float)0.9 * y, x, y);
            }
        }

        private void analogToolStripMenuItemAnalog_Click(object sender, EventArgs e)
        {
            IsDigital = false;
        }

        private void digitalToolStripMenuItemDigital_Click(object sender, EventArgs e)
        {
            IsDigital = true;
        }

        private void pictureBoxClock_SizeChanged(object sender, EventArgs e)
        {
            pictureBoxClock.Image = new Bitmap(pictureBoxClock.Width, pictureBoxClock.Height);
            drawer = Graphics.FromImage(pictureBoxClock.Image);
            drawer.TranslateTransform(pictureBoxClock.Width / 2, pictureBoxClock.Height / 2);
            drawer.ScaleTransform(0.9F, 0.9F);
            drawer.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
        }
    }
}
