
namespace lab_5
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox = new System.Windows.Forms.PictureBox();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.panelLineConfig = new System.Windows.Forms.Panel();
            this.groupBoxShape = new System.Windows.Forms.GroupBox();
            this.radioButtonEllipse = new System.Windows.Forms.RadioButton();
            this.radioButtonRectangle = new System.Windows.Forms.RadioButton();
            this.radioButtonLine = new System.Windows.Forms.RadioButton();
            this.radioButtonCurve = new System.Windows.Forms.RadioButton();
            this.groupBox = new System.Windows.Forms.GroupBox();
            this.buttonLineColor = new System.Windows.Forms.Button();
            this.labelLineColor = new System.Windows.Forms.Label();
            this.labelLineWidth = new System.Windows.Forms.Label();
            this.numericUpDownLineWidth = new System.Windows.Forms.NumericUpDown();
            this.colorDialogLineColor = new System.Windows.Forms.ColorDialog();
            this.groupBoxFill = new System.Windows.Forms.GroupBox();
            this.checkBoxEnableFill = new System.Windows.Forms.CheckBox();
            this.buttonFillColor = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.colorDialogFill = new System.Windows.Forms.ColorDialog();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.menuStrip.SuspendLayout();
            this.tableLayoutPanel.SuspendLayout();
            this.panelLineConfig.SuspendLayout();
            this.groupBoxShape.SuspendLayout();
            this.groupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownLineWidth)).BeginInit();
            this.groupBoxFill.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox
            // 
            this.pictureBox.Location = new System.Drawing.Point(168, 3);
            this.pictureBox.Name = "pictureBox";
            this.pictureBox.Size = new System.Drawing.Size(568, 469);
            this.pictureBox.TabIndex = 0;
            this.pictureBox.TabStop = false;
            this.pictureBox.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox_MouseDown);
            this.pictureBox.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox_MouseMove);
            this.pictureBox.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pictureBox_MouseUp);
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "openFileDialog1";
            // 
            // menuStrip
            // 
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(756, 24);
            this.menuStrip.TabIndex = 1;
            this.menuStrip.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.openToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.saveToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.newToolStripMenuItem.Text = "New";
            this.newToolStripMenuItem.Click += new System.EventHandler(this.newToolStripMenuItem_Click);
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.openToolStripMenuItem.Text = "Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // saveAsToolStripMenuItem
            // 
            this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
            this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.saveAsToolStripMenuItem.Text = "Save as";
            this.saveAsToolStripMenuItem.Click += new System.EventHandler(this.saveAsToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // tableLayoutPanel
            // 
            this.tableLayoutPanel.ColumnCount = 2;
            this.tableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 165F));
            this.tableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel.Controls.Add(this.pictureBox, 1, 0);
            this.tableLayoutPanel.Controls.Add(this.panelLineConfig, 0, 0);
            this.tableLayoutPanel.Location = new System.Drawing.Point(12, 27);
            this.tableLayoutPanel.Name = "tableLayoutPanel";
            this.tableLayoutPanel.RowCount = 1;
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel.Size = new System.Drawing.Size(739, 475);
            this.tableLayoutPanel.TabIndex = 2;
            // 
            // panelLineConfig
            // 
            this.panelLineConfig.Controls.Add(this.groupBoxFill);
            this.panelLineConfig.Controls.Add(this.groupBoxShape);
            this.panelLineConfig.Controls.Add(this.groupBox);
            this.panelLineConfig.Location = new System.Drawing.Point(3, 3);
            this.panelLineConfig.Name = "panelLineConfig";
            this.panelLineConfig.Size = new System.Drawing.Size(159, 469);
            this.panelLineConfig.TabIndex = 1;
            // 
            // groupBoxShape
            // 
            this.groupBoxShape.Controls.Add(this.radioButtonEllipse);
            this.groupBoxShape.Controls.Add(this.radioButtonRectangle);
            this.groupBoxShape.Controls.Add(this.radioButtonLine);
            this.groupBoxShape.Controls.Add(this.radioButtonCurve);
            this.groupBoxShape.Location = new System.Drawing.Point(4, 120);
            this.groupBoxShape.Name = "groupBoxShape";
            this.groupBoxShape.Size = new System.Drawing.Size(155, 110);
            this.groupBoxShape.TabIndex = 1;
            this.groupBoxShape.TabStop = false;
            this.groupBoxShape.Text = "Shape";
            // 
            // radioButtonEllipse
            // 
            this.radioButtonEllipse.AutoSize = true;
            this.radioButtonEllipse.Location = new System.Drawing.Point(7, 89);
            this.radioButtonEllipse.Name = "radioButtonEllipse";
            this.radioButtonEllipse.Size = new System.Drawing.Size(55, 17);
            this.radioButtonEllipse.TabIndex = 3;
            this.radioButtonEllipse.Text = "Ellipse";
            this.radioButtonEllipse.UseVisualStyleBackColor = true;
            // 
            // radioButtonRectangle
            // 
            this.radioButtonRectangle.AutoSize = true;
            this.radioButtonRectangle.Location = new System.Drawing.Point(7, 66);
            this.radioButtonRectangle.Name = "radioButtonRectangle";
            this.radioButtonRectangle.Size = new System.Drawing.Size(74, 17);
            this.radioButtonRectangle.TabIndex = 2;
            this.radioButtonRectangle.TabStop = true;
            this.radioButtonRectangle.Text = "Rectangle";
            this.radioButtonRectangle.UseVisualStyleBackColor = true;
            // 
            // radioButtonLine
            // 
            this.radioButtonLine.AutoSize = true;
            this.radioButtonLine.Location = new System.Drawing.Point(7, 43);
            this.radioButtonLine.Name = "radioButtonLine";
            this.radioButtonLine.Size = new System.Drawing.Size(45, 17);
            this.radioButtonLine.TabIndex = 1;
            this.radioButtonLine.TabStop = true;
            this.radioButtonLine.Text = "Line";
            this.radioButtonLine.UseVisualStyleBackColor = true;
            // 
            // radioButtonCurve
            // 
            this.radioButtonCurve.AutoSize = true;
            this.radioButtonCurve.Checked = true;
            this.radioButtonCurve.Location = new System.Drawing.Point(7, 20);
            this.radioButtonCurve.Name = "radioButtonCurve";
            this.radioButtonCurve.Size = new System.Drawing.Size(53, 17);
            this.radioButtonCurve.TabIndex = 0;
            this.radioButtonCurve.TabStop = true;
            this.radioButtonCurve.Text = "Curve";
            this.radioButtonCurve.UseVisualStyleBackColor = true;
            // 
            // groupBox
            // 
            this.groupBox.Controls.Add(this.buttonLineColor);
            this.groupBox.Controls.Add(this.labelLineColor);
            this.groupBox.Controls.Add(this.labelLineWidth);
            this.groupBox.Controls.Add(this.numericUpDownLineWidth);
            this.groupBox.Location = new System.Drawing.Point(4, 4);
            this.groupBox.Name = "groupBox";
            this.groupBox.Size = new System.Drawing.Size(155, 109);
            this.groupBox.TabIndex = 0;
            this.groupBox.TabStop = false;
            this.groupBox.Text = "Line";
            // 
            // buttonLineColor
            // 
            this.buttonLineColor.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.buttonLineColor.Location = new System.Drawing.Point(53, 55);
            this.buttonLineColor.Name = "buttonLineColor";
            this.buttonLineColor.Size = new System.Drawing.Size(75, 23);
            this.buttonLineColor.TabIndex = 3;
            this.buttonLineColor.UseVisualStyleBackColor = false;
            this.buttonLineColor.Click += new System.EventHandler(this.buttonLineColor_Click);
            // 
            // labelLineColor
            // 
            this.labelLineColor.AutoSize = true;
            this.labelLineColor.Location = new System.Drawing.Point(10, 60);
            this.labelLineColor.Name = "labelLineColor";
            this.labelLineColor.Size = new System.Drawing.Size(37, 13);
            this.labelLineColor.TabIndex = 2;
            this.labelLineColor.Text = "Colour";
            // 
            // labelLineWidth
            // 
            this.labelLineWidth.AutoSize = true;
            this.labelLineWidth.Location = new System.Drawing.Point(7, 25);
            this.labelLineWidth.Name = "labelLineWidth";
            this.labelLineWidth.Size = new System.Drawing.Size(35, 13);
            this.labelLineWidth.TabIndex = 1;
            this.labelLineWidth.Text = "Width";
            // 
            // numericUpDownLineWidth
            // 
            this.numericUpDownLineWidth.Location = new System.Drawing.Point(48, 23);
            this.numericUpDownLineWidth.Maximum = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.numericUpDownLineWidth.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownLineWidth.Name = "numericUpDownLineWidth";
            this.numericUpDownLineWidth.Size = new System.Drawing.Size(73, 20);
            this.numericUpDownLineWidth.TabIndex = 0;
            this.numericUpDownLineWidth.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownLineWidth.ValueChanged += new System.EventHandler(this.numericUpDownLineWidth_ValueChanged);
            // 
            // groupBoxFill
            // 
            this.groupBoxFill.Controls.Add(this.label1);
            this.groupBoxFill.Controls.Add(this.buttonFillColor);
            this.groupBoxFill.Controls.Add(this.checkBoxEnableFill);
            this.groupBoxFill.Location = new System.Drawing.Point(4, 233);
            this.groupBoxFill.Name = "groupBoxFill";
            this.groupBoxFill.Size = new System.Drawing.Size(152, 117);
            this.groupBoxFill.TabIndex = 2;
            this.groupBoxFill.TabStop = false;
            this.groupBoxFill.Text = "Fill";
            // 
            // checkBoxEnableFill
            // 
            this.checkBoxEnableFill.AutoSize = true;
            this.checkBoxEnableFill.Location = new System.Drawing.Point(13, 19);
            this.checkBoxEnableFill.Name = "checkBoxEnableFill";
            this.checkBoxEnableFill.Size = new System.Drawing.Size(88, 17);
            this.checkBoxEnableFill.TabIndex = 0;
            this.checkBoxEnableFill.Text = "Enable Filling";
            this.checkBoxEnableFill.UseVisualStyleBackColor = true;
            // 
            // buttonFillColor
            // 
            this.buttonFillColor.BackColor = System.Drawing.SystemColors.ControlText;
            this.buttonFillColor.Location = new System.Drawing.Point(71, 42);
            this.buttonFillColor.Name = "buttonFillColor";
            this.buttonFillColor.Size = new System.Drawing.Size(75, 23);
            this.buttonFillColor.TabIndex = 1;
            this.buttonFillColor.UseVisualStyleBackColor = false;
            this.buttonFillColor.Click += new System.EventHandler(this.buttonFillColor_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 47);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Fill Color";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(756, 505);
            this.Controls.Add(this.tableLayoutPanel);
            this.Controls.Add(this.menuStrip);
            this.MainMenuStrip = this.menuStrip;
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.tableLayoutPanel.ResumeLayout(false);
            this.panelLineConfig.ResumeLayout(false);
            this.groupBoxShape.ResumeLayout(false);
            this.groupBoxShape.PerformLayout();
            this.groupBox.ResumeLayout(false);
            this.groupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownLineWidth)).EndInit();
            this.groupBoxFill.ResumeLayout(false);
            this.groupBoxFill.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel;
        private System.Windows.Forms.Panel panelLineConfig;
        private System.Windows.Forms.GroupBox groupBox;
        private System.Windows.Forms.Label labelLineWidth;
        private System.Windows.Forms.NumericUpDown numericUpDownLineWidth;
        private System.Windows.Forms.Button buttonLineColor;
        private System.Windows.Forms.Label labelLineColor;
        private System.Windows.Forms.ColorDialog colorDialogLineColor;
        private System.Windows.Forms.GroupBox groupBoxShape;
        private System.Windows.Forms.RadioButton radioButtonEllipse;
        private System.Windows.Forms.RadioButton radioButtonRectangle;
        private System.Windows.Forms.RadioButton radioButtonLine;
        private System.Windows.Forms.RadioButton radioButtonCurve;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.GroupBox groupBoxFill;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonFillColor;
        private System.Windows.Forms.CheckBox checkBoxEnableFill;
        private System.Windows.Forms.ColorDialog colorDialogFill;
    }
}

