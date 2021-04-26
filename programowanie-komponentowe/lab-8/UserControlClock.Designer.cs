
namespace lab_8
{
    partial class UserControlClock
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.timerClock = new System.Windows.Forms.Timer(this.components);
            this.labelClock = new System.Windows.Forms.Label();
            this.pictureBoxClock = new System.Windows.Forms.PictureBox();
            this.contextMenuStripClock = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.analogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.digitalToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxClock)).BeginInit();
            this.contextMenuStripClock.SuspendLayout();
            this.SuspendLayout();
            // 
            // timerClock
            // 
            this.timerClock.Enabled = true;
            this.timerClock.Interval = 1000;
            this.timerClock.Tick += new System.EventHandler(this.TimerClock_Tick);
            // 
            // labelClock
            // 
            this.labelClock.AutoSize = true;
            this.labelClock.Location = new System.Drawing.Point(85, 90);
            this.labelClock.Name = "labelClock";
            this.labelClock.Size = new System.Drawing.Size(35, 13);
            this.labelClock.TabIndex = 0;
            this.labelClock.Text = "label1";
            // 
            // pictureBoxClock
            // 
            this.pictureBoxClock.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBoxClock.Location = new System.Drawing.Point(0, 0);
            this.pictureBoxClock.Name = "pictureBoxClock";
            this.pictureBoxClock.Size = new System.Drawing.Size(213, 206);
            this.pictureBoxClock.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBoxClock.TabIndex = 1;
            this.pictureBoxClock.TabStop = false;
            this.pictureBoxClock.SizeChanged += new System.EventHandler(this.pictureBoxClock_SizeChanged);
            // 
            // contextMenuStripClock
            // 
            this.contextMenuStripClock.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.analogToolStripMenuItem,
            this.digitalToolStripMenuItem});
            this.contextMenuStripClock.Name = "contextMenuStripClock";
            this.contextMenuStripClock.Size = new System.Drawing.Size(113, 48);
            // 
            // analogToolStripMenuItem
            // 
            this.analogToolStripMenuItem.Name = "analogToolStripMenuItem";
            this.analogToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.analogToolStripMenuItem.Text = "Analog";
            this.analogToolStripMenuItem.Click += new System.EventHandler(this.analogToolStripMenuItemAnalog_Click);
            // 
            // digitalToolStripMenuItem
            // 
            this.digitalToolStripMenuItem.Name = "digitalToolStripMenuItem";
            this.digitalToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.digitalToolStripMenuItem.Text = "Digital";
            this.digitalToolStripMenuItem.Click += new System.EventHandler(this.digitalToolStripMenuItemDigital_Click);
            // 
            // UserControlClock
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ContextMenuStrip = this.contextMenuStripClock;
            this.Controls.Add(this.labelClock);
            this.Controls.Add(this.pictureBoxClock);
            this.Name = "UserControlClock";
            this.Size = new System.Drawing.Size(213, 206);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxClock)).EndInit();
            this.contextMenuStripClock.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer timerClock;
        private System.Windows.Forms.Label labelClock;
        private System.Windows.Forms.PictureBox pictureBoxClock;
        private System.Windows.Forms.ContextMenuStrip contextMenuStripClock;
        private System.Windows.Forms.ToolStripMenuItem analogToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem digitalToolStripMenuItem;
    }
}
