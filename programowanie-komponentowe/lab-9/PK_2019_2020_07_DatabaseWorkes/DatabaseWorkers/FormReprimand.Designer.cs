
namespace DatabaseWorkers
{
    partial class FormReprimands
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
            this.flowLayoutPanelReprimand = new System.Windows.Forms.FlowLayoutPanel();
            this.SuspendLayout();
            // 
            // flowLayoutPanelReprimand
            // 
            this.flowLayoutPanelReprimand.AutoSize = true;
            this.flowLayoutPanelReprimand.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanelReprimand.Location = new System.Drawing.Point(0, 0);
            this.flowLayoutPanelReprimand.Name = "flowLayoutPanelReprimand";
            this.flowLayoutPanelReprimand.Size = new System.Drawing.Size(800, 450);
            this.flowLayoutPanelReprimand.TabIndex = 0;
            // 
            // FormReprimands
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.flowLayoutPanelReprimand);
            this.MaximizeBox = false;
            this.Name = "FormReprimands";
            this.Text = "Reprimands";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormReprimands_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanelReprimand;
    }
}