using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_4_1
{
    public partial class Form1 : Form
    {
        SapperLogic sapper;
        int fieldSize = 30;

        public Form1()
        {
            InitializeComponent();
            sapper = new SapperLogic(8, 8, 10);

            generateBoardView();
            refreshBoard();
        }

        private void refreshBoard()
        {
            foreach(Control b in panelSapper.Controls)
            {
                if(b is Button)
                {
                    if (!sapper.isFieldCovered((Point)b.Tag))
                    {
                        if (sapper.getFieldType((Point)b.Tag) == SapperLogic.FieldTypeEnum.Bomb)
                        {
                            b.Text = "B";
                        }
                        else if(sapper.getFieldType((Point)b.Tag) == SapperLogic.FieldTypeEnum.Empty)
                        {
                            b.Text = sapper.getBombCount((Point)b.Tag).ToString();
                            b.BackColor = new Button().BackColor;
                        }
                        b.Enabled = false;
                    }
                }
            }
        }

        private void generateBoardView()
        {
            for(int x = 0; x < sapper.boardWidth; x++)
            {
                for(int y = 0; y < sapper.boardHeight; y++)
                {
                    Button b = new Button();
                    this.panelSapper.Controls.Add(b);
                    b.Size = new Size(fieldSize, fieldSize);
                    b.Location = new Point(x * fieldSize, y * fieldSize);
                    b.Tag = new Point(x, y);
                    b.Click += Button_Click;
                    b.MouseUp += Button_RightClick;
                }
            }
        }

        private void Button_RightClick(object sender, MouseEventArgs e)
        {
            if(sender is Button)
            {
                if (e.Button == MouseButtons.Right)
                {
                    (sender as Button).Text = "B";
                    (sender as Button).BackColor = Color.Red;
                }
            }
 
        }

        private void Button_Click(object sender ,EventArgs e)
        {
            if(sender is Button)
            {
                sapper.uncoverField((Point)(sender as Button).Tag);
                refreshBoard();
                if(sapper.State == SapperLogic.GameStateEnum.Lost)
                {
                    MessageBox.Show("LOST!");
                }

                if(sapper.State == SapperLogic.GameStateEnum.Won)
                {
                    MessageBox.Show("WON!!!");
                }
              
            }
        }


    }
}
