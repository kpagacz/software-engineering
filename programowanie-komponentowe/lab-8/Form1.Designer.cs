
namespace lab_8
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
            this.components = new System.ComponentModel.Container();
            this.userControlClock1 = new lab_8.UserControlClock();
            this.userControlClock2 = new lab_8.UserControlClock();
            this.SuspendLayout();
            // 
            // userControlClock1
            // 
            this.userControlClock1.IsDigital = false;
            this.userControlClock1.Location = new System.Drawing.Point(172, 78);
            this.userControlClock1.Name = "userControlClock1";
            this.userControlClock1.Size = new System.Drawing.Size(213, 206);
            this.userControlClock1.TabIndex = 0;
            // 
            // userControlClock2
            // 
            this.userControlClock2.IsDigital = true;
            this.userControlClock2.Location = new System.Drawing.Point(437, 78);
            this.userControlClock2.Name = "userControlClock2";
            this.userControlClock2.Size = new System.Drawing.Size(213, 206);
            this.userControlClock2.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.userControlClock2);
            this.Controls.Add(this.userControlClock1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private UserControlClock userControlClock1;
        private UserControlClock userControlClock2;
    }
}

