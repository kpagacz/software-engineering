using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_3
{

    public partial class FormConfig : Form
    {
        public Color ConfigFontColor
        {
            get
            {
                return buttonFontColor.BackColor;
            }
            set
            {
                buttonFontColor.BackColor = value;
                buttonFont.ForeColor = value;
            }
        }

        public Color ConfigBackColor
        {
            get
            {
                return buttonBackColor.BackColor;
            }
            set
            {
                buttonBackColor.BackColor = value;
                buttonFont.BackColor = value;
            }
        }

        public Font ConfigFont
        {
            get
            {
                return buttonFont.Font;
            }
            set
            {
                buttonFont.Font = value;
            }
        }

        public FormConfig()
        {
            InitializeComponent();
        }

        private void buttonFontColor_Click(object sender, EventArgs e)
        {
            ColorDialog cd = new ColorDialog();
            cd.Color = ConfigFontColor;

            if(cd.ShowDialog() == DialogResult.OK)
            {
                ConfigFontColor = cd.Color;
            }
        }
        private void buttonBackColor_Click(object sender, EventArgs e)
        {
            ColorDialog cd = new ColorDialog();
            cd.Color = ConfigBackColor;

            if (cd.ShowDialog() == DialogResult.OK)
            {
               ConfigBackColor = cd.Color;
            }
        }

        private void buttonAccept_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void buttonFont_Click(object sender, EventArgs e)
        {
            FontDialog fd = new FontDialog();
            fd.Font = ConfigFont;

            if(fd.ShowDialog() == DialogResult.OK)
            {
                ConfigFont = fd.Font;
            }
        }
    }
}
