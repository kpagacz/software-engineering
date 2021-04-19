using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_7
{
    public partial class Form1 : Form
    {
        PacManGame game;
        Graphics drawer;
        public Form1()
        {
            InitializeComponent();

            game = new PacManGame();
            pictureBoxGame.Image = new Bitmap(pictureBoxGame.Width, pictureBoxGame.Height);
            drawer = Graphics.FromImage(pictureBoxGame.Image);
            drawGame();
        }

        private void drawGame()
        {
            SolidBrush brush = new SolidBrush(Color.White);
            drawer.Clear(Color.White);
            int field_width = pictureBoxGame.Width / game.Board.GetLength(1);
            int field_height = pictureBoxGame.Height / game.Board.GetLength(0);

            for (int i = 0; i < game.Board.GetLength(0); i++)
            {
                for (int j = 0; j < game.Board.GetLength(1); j++)
                {
                    switch (game.Board[i, j])
                    {
                        case PacManGame.Field.Empty:
                            brush.Color = Color.White;
                            drawer.FillRectangle(brush, j * field_width, i * field_height, field_width, field_height);
                            break;
                        case PacManGame.Field.Wall:
                            brush.Color = Color.Brown;
                            drawer.FillRectangle(brush, j * field_width, i * field_height, field_width, field_height);
                            break;
                        case PacManGame.Field.Coin:
                            brush.Color = Color.Gold;
                            drawer.FillEllipse(brush, j * field_width + field_width / 4, i * field_height + field_height / 4, field_width / 2, field_height / 2);
                            break;
                    }
                }
            }

            brush.Color = Color.Black;
            drawer.DrawString("Points: " + game.Score, new Font(FontFamily.GenericSerif, 12), brush, new Point(0, 0));

            brush.Color = Color.Green;
            drawer.FillEllipse(brush, game.PacMan.Y * field_width, game.PacMan.X * field_height, field_width, field_height);

            brush.Color = Color.Purple;
            foreach(Point ghost in game.Ghosts)
            {
                drawer.FillEllipse(brush, ghost.Y * field_width, ghost.X * field_height, field_width, field_height);
            }

            pictureBoxGame.Refresh();
        }
    
        private void timerGame_Tick(object sender, EventArgs e)
        {
            game.movePackMan();
            drawGame();
            if(game.State == PacManGame.GameState.Lost)
            {
                timerGame.Stop();
                timerGhosts.Stop();
                MessageBox.Show("You lost!");
            }

            if(game.State == PacManGame.GameState.Won)
            {
                timerGame.Stop();
                timerGhosts.Stop();
                MessageBox.Show("You won!");
            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch(e.KeyCode)
            {
                case Keys.Left:
                    game.PacManDirection = PacManGame.Direction.Left;
                    break;
                case Keys.Right:
                    game.PacManDirection = PacManGame.Direction.Right;
                    break;
                case Keys.Up:
                    game.PacManDirection = PacManGame.Direction.Up;
                    break;
                case Keys.Down:
                    game.PacManDirection = PacManGame.Direction.Down;
                    break;
            }
        }

        private void timerGhosts_Tick(object sender, EventArgs e)
        {
            game.moveGhosts();
            drawGame();
            if (game.State == PacManGame.GameState.Lost)
            {
                timerGame.Stop();
                timerGhosts.Stop();
                MessageBox.Show("You lost!");
            }


        }
    }
}
