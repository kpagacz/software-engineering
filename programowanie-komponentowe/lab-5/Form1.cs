using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace lab_5
{
    public partial class Form1 : Form
    {
        Graphics graphics;
        Point tempPosition;
        Pen paintPen;
        SolidBrush paintBrush;
        Color fillColor;
        private string fileName;
        private ImageFormat imageFormat;

        public Form1()
        {
            InitializeComponent();
            openFileDialog.Filter = "BMP|*.bmp|PNG|*.png|JPG|*.jpg|JPEG|*.jpeg";
            saveFileDialog.Filter = "BMP|*.bmp|PNG|*.png|JPG|*.jpg|JPEG|*.jpeg";
            paintPen = new Pen(Color.Black, (float)numericUpDownLineWidth.Value);
            paintPen.EndCap = paintPen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            fillColor = Color.Black;
            paintBrush = new SolidBrush(fillColor);

            newToolStripMenuItem_Click(null, null);
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(openFileDialog.ShowDialog() == DialogResult.OK)
            {
                Image opened_image = Image.FromFile(openFileDialog.FileName);
                pictureBox.Image = new Bitmap(opened_image);
                graphics = Graphics.FromImage(pictureBox.Image);
                opened_image.Dispose();

                fileName = openFileDialog.FileName;
                string extension = Path.GetExtension(fileName);
                imageFormat = ImageFormat.Bmp;
                switch (extension)
                {
                    case ".png":
                        imageFormat = ImageFormat.Png;
                        break;
                    case ".jpg":
                        imageFormat = ImageFormat.Jpeg;
                        break;
                    case ".jpeg":
                        imageFormat = ImageFormat.Jpeg;
                        break;
                }
                Text = fileName;
            }
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                string extension = Path.GetExtension(saveFileDialog.FileName);
                ImageFormat imageFormat = ImageFormat.Bmp;
                switch(extension)
                {
                    case ".png":
                        imageFormat = ImageFormat.Png;
                        break;
                    case ".jpg":
                        imageFormat = ImageFormat.Jpeg;
                        break;
                    case ".jpeg":
                        imageFormat = ImageFormat.Jpeg;
                        break;
                }
                pictureBox.Image.Save(saveFileDialog.FileName, imageFormat);

                fileName = saveFileDialog.FileName;
                this.imageFormat = imageFormat;
                Text = fileName;
            }
        }

        private void pictureBox_MouseDown(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                tempPosition = e.Location;
            }
        }

        private void pictureBox_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                if(radioButtonCurve.Checked)
                {
                    graphics.DrawLine(paintPen, tempPosition, e.Location);
                    pictureBox.Refresh();
                    tempPosition = e.Location;
                }
            }
        }

        private void pictureBox_MouseUp(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                if(radioButtonCurve.Checked)
                {
                    graphics.DrawLine(paintPen, tempPosition, e.Location);
                }
                else if (radioButtonLine.Checked)
                {
                    graphics.DrawLine(paintPen, tempPosition, e.Location);
                }
                else if (radioButtonRectangle.Checked)
                {
                    graphics.DrawRectangle(
                        paintPen,
                        Math.Min(tempPosition.X, e.X),
                        Math.Min(tempPosition.Y, e.Y),
                        Math.Abs(tempPosition.X - e.X),
                        Math.Abs(tempPosition.Y - e.Y));
                    if(checkBoxEnableFill.Checked)
                    {
                        paintBrush.Color = fillColor;
                        graphics.FillRectangle(
                            paintBrush,
                            Math.Min(tempPosition.X, e.X),
                            Math.Min(tempPosition.Y, e.Y),
                            Math.Abs(tempPosition.X - e.X),
                            Math.Abs(tempPosition.Y - e.Y));
                    }
                }
                else if (radioButtonEllipse.Checked)
                {
                    graphics.DrawEllipse(
                        paintPen,
                        Math.Min(tempPosition.X, e.X),
                        Math.Min(tempPosition.Y, e.Y),
                        Math.Abs(tempPosition.X - e.X),
                        Math.Abs(tempPosition.Y - e.Y));
                    if(checkBoxEnableFill.Checked)
                    {
                        paintBrush.Color = fillColor;
                        graphics.FillEllipse(
                            paintBrush,
                            Math.Min(tempPosition.X, e.X),
                            Math.Min(tempPosition.Y, e.Y),
                            Math.Abs(tempPosition.X - e.X),
                            Math.Abs(tempPosition.Y - e.Y));
                    }
                }
                pictureBox.Refresh();
            }
        }

        private void numericUpDownLineWidth_ValueChanged(object sender, EventArgs e)
        {
            paintPen.Width = (float)numericUpDownLineWidth.Value;
        }

        private void buttonLineColor_Click(object sender, EventArgs e)
        {
            if(colorDialogLineColor.ShowDialog() == DialogResult.OK)
            {
                buttonLineColor.BackColor = colorDialogLineColor.Color;
                paintPen.Color = colorDialogLineColor.Color;
            }
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            pictureBox.Image = new Bitmap(tableLayoutPanel.Width - 150, tableLayoutPanel.Height);
            graphics = Graphics.FromImage(pictureBox.Image);
            graphics.Clear(Color.White);

            fileName = "";
            imageFormat = ImageFormat.Bmp;
            Text = "New file";
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(fileName != "")
            {
                pictureBox.Image.Save(fileName, imageFormat);
            } else
            {
                saveAsToolStripMenuItem_Click(null, null);
            }
        }

        private void buttonFillColor_Click(object sender, EventArgs e)
        {
            if(colorDialogFill.ShowDialog() == DialogResult.OK)
            {
                buttonFillColor.BackColor = colorDialogFill.Color;
                fillColor = colorDialogFill.Color;
            }
        }
    }
}
