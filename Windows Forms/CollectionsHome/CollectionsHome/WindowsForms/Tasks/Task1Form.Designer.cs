namespace MaZaiPC.CollectionsHome.WindowsForms.Tasks
{
	partial class Task1Form
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
			this.stackProgress1 = new System.Windows.Forms.ProgressBar();
			this.stackProgress2 = new System.Windows.Forms.ProgressBar();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.btnSwitch = new System.Windows.Forms.Button();
			this.txtStack1 = new System.Windows.Forms.Label();
			this.txtStack2 = new System.Windows.Forms.Label();
			this.cheatActive = new System.Windows.Forms.CheckBox();
			this.SuspendLayout();
			// 
			// stackProgress1
			// 
			this.stackProgress1.Location = new System.Drawing.Point(56, 56);
			this.stackProgress1.MarqueeAnimationSpeed = 10;
			this.stackProgress1.Maximum = 10;
			this.stackProgress1.Name = "stackProgress1";
			this.stackProgress1.Size = new System.Drawing.Size(472, 32);
			this.stackProgress1.TabIndex = 0;
			// 
			// stackProgress2
			// 
			this.stackProgress2.Location = new System.Drawing.Point(56, 120);
			this.stackProgress2.MarqueeAnimationSpeed = 10;
			this.stackProgress2.Maximum = 10;
			this.stackProgress2.Name = "stackProgress2";
			this.stackProgress2.Size = new System.Drawing.Size(472, 32);
			this.stackProgress2.TabIndex = 0;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(56, 40);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(48, 13);
			this.label1.TabIndex = 1;
			this.label1.Text = "1-й стек";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(56, 104);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(48, 13);
			this.label2.TabIndex = 1;
			this.label2.Text = "2-й стек";
			// 
			// btnSwitch
			// 
			this.btnSwitch.Location = new System.Drawing.Point(392, 176);
			this.btnSwitch.Name = "btnSwitch";
			this.btnSwitch.Size = new System.Drawing.Size(136, 40);
			this.btnSwitch.TabIndex = 2;
			this.btnSwitch.Text = "Запуск моделирования";
			this.btnSwitch.UseVisualStyleBackColor = true;
			this.btnSwitch.Click += new System.EventHandler(this.btnSwitch_Click);
			// 
			// txtStack1
			// 
			this.txtStack1.AutoSize = true;
			this.txtStack1.Location = new System.Drawing.Point(56, 176);
			this.txtStack1.Name = "txtStack1";
			this.txtStack1.Size = new System.Drawing.Size(18, 13);
			this.txtStack1.TabIndex = 3;
			this.txtStack1.Text = "{ }";
			// 
			// txtStack2
			// 
			this.txtStack2.AutoSize = true;
			this.txtStack2.Location = new System.Drawing.Point(56, 208);
			this.txtStack2.Name = "txtStack2";
			this.txtStack2.Size = new System.Drawing.Size(18, 13);
			this.txtStack2.TabIndex = 3;
			this.txtStack2.Text = "{ }";
			// 
			// cheatActive
			// 
			this.cheatActive.AutoSize = true;
			this.cheatActive.Location = new System.Drawing.Point(272, 188);
			this.cheatActive.Name = "cheatActive";
			this.cheatActive.Size = new System.Drawing.Size(96, 17);
			this.cheatActive.TabIndex = 4;
			this.cheatActive.Text = "Все нечетные";
			this.cheatActive.UseVisualStyleBackColor = true;
			this.cheatActive.CheckedChanged += new System.EventHandler(this.cheatActive_CheckedChanged);
			// 
			// Task1Form
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(587, 284);
			this.Controls.Add(this.cheatActive);
			this.Controls.Add(this.txtStack2);
			this.Controls.Add(this.txtStack1);
			this.Controls.Add(this.btnSwitch);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.stackProgress2);
			this.Controls.Add(this.stackProgress1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Name = "Task1Form";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Задача 1";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.ProgressBar stackProgress1;
		private System.Windows.Forms.ProgressBar stackProgress2;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button btnSwitch;
		private System.Windows.Forms.Label txtStack1;
		private System.Windows.Forms.Label txtStack2;
		private System.Windows.Forms.CheckBox cheatActive;
	}
}