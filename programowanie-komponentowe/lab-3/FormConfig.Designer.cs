
namespace lab_3
{
    partial class FormConfig
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
            this.buttonFontColor = new System.Windows.Forms.Button();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.buttonAccept = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonBackColor = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.buttonFont = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonFontColor
            // 
            this.buttonFontColor.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.buttonFontColor.Location = new System.Drawing.Point(225, 31);
            this.buttonFontColor.Name = "buttonFontColor";
            this.buttonFontColor.Size = new System.Drawing.Size(152, 44);
            this.buttonFontColor.TabIndex = 0;
            this.buttonFontColor.UseVisualStyleBackColor = false;
            this.buttonFontColor.Click += new System.EventHandler(this.buttonFontColor_Click);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(27, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Font color";
            // 
            // buttonAccept
            // 
            this.buttonAccept.Location = new System.Drawing.Point(274, 291);
            this.buttonAccept.Name = "buttonAccept";
            this.buttonAccept.Size = new System.Drawing.Size(115, 47);
            this.buttonAccept.TabIndex = 3;
            this.buttonAccept.Text = "Confirm";
            this.buttonAccept.UseVisualStyleBackColor = true;
            this.buttonAccept.Click += new System.EventHandler(this.buttonAccept_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(27, 133);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(133, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "Background color";
            // 
            // buttonBackColor
            // 
            this.buttonBackColor.BackColor = System.Drawing.Color.White;
            this.buttonBackColor.Location = new System.Drawing.Point(225, 122);
            this.buttonBackColor.Name = "buttonBackColor";
            this.buttonBackColor.Size = new System.Drawing.Size(152, 44);
            this.buttonBackColor.TabIndex = 5;
            this.buttonBackColor.UseVisualStyleBackColor = false;
            this.buttonBackColor.Click += new System.EventHandler(this.buttonBackColor_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(27, 217);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(42, 20);
            this.label3.TabIndex = 6;
            this.label3.Text = "Font";
            // 
            // buttonFont
            // 
            this.buttonFont.BackColor = System.Drawing.Color.White;
            this.buttonFont.Location = new System.Drawing.Point(225, 206);
            this.buttonFont.Name = "buttonFont";
            this.buttonFont.Size = new System.Drawing.Size(152, 44);
            this.buttonFont.TabIndex = 7;
            this.buttonFont.Text = "Test";
            this.buttonFont.UseVisualStyleBackColor = false;
            this.buttonFont.Click += new System.EventHandler(this.buttonFont_Click);
            // 
            // FormConfig
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(417, 365);
            this.Controls.Add(this.buttonFont);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.buttonBackColor);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.buttonAccept);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonFontColor);
            this.Name = "FormConfig";
            this.Text = "FormConfig";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonFontColor;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonAccept;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonBackColor;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button buttonFont;
    }
}