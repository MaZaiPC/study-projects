namespace MaZaiPC.CollectionsHome.WindowsForms.Tasks
{
	partial class Task4Form
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
			this.queueProgress1 = new System.Windows.Forms.ProgressBar();
			this.queueProgress2 = new System.Windows.Forms.ProgressBar();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.btnSwitch = new System.Windows.Forms.Button();
			this.txtStack1 = new System.Windows.Forms.Label();
			this.txtStack2 = new System.Windows.Forms.Label();
			this.queueProgress3 = new System.Windows.Forms.ProgressBar();
			this.txtStack3 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// queueProgress1
			// 
			this.queueProgress1.Location = new System.Drawing.Point(40, 56);
			this.queueProgress1.MarqueeAnimationSpeed = 5;
			this.queueProgress1.Maximum = 5;
			this.queueProgress1.Name = "queueProgress1";
			this.queueProgress1.Size = new System.Drawing.Size(248, 32);
			this.queueProgress1.TabIndex = 0;
			// 
			// queueProgress2
			// 
			this.queueProgress2.Location = new System.Drawing.Point(296, 56);
			this.queueProgress2.MarqueeAnimationSpeed = 5;
			this.queueProgress2.Maximum = 5;
			this.queueProgress2.Name = "queueProgress2";
			this.queueProgress2.Size = new System.Drawing.Size(248, 32);
			this.queueProgress2.TabIndex = 0;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(40, 40);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(66, 13);
			this.label1.TabIndex = 1;
			this.label1.Text = "1-я очередь";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(296, 40);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(66, 13);
			this.label2.TabIndex = 1;
			this.label2.Text = "2-я очередь";
			// 
			// btnSwitch
			// 
			this.btnSwitch.Location = new System.Drawing.Point(408, 202);
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
			this.txtStack1.Location = new System.Drawing.Point(48, 64);
			this.txtStack1.Name = "txtStack1";
			this.txtStack1.Size = new System.Drawing.Size(18, 13);
			this.txtStack1.TabIndex = 3;
			this.txtStack1.Text = "{ }";
			// 
			// txtStack2
			// 
			this.txtStack2.AutoSize = true;
			this.txtStack2.Location = new System.Drawing.Point(304, 64);
			this.txtStack2.Name = "txtStack2";
			this.txtStack2.Size = new System.Drawing.Size(18, 13);
			this.txtStack2.TabIndex = 3;
			this.txtStack2.Text = "{ }";
			// 
			// queueProgress3
			// 
			this.queueProgress3.Location = new System.Drawing.Point(40, 120);
			this.queueProgress3.MarqueeAnimationSpeed = 10;
			this.queueProgress3.Maximum = 10;
			this.queueProgress3.Name = "queueProgress3";
			this.queueProgress3.Size = new System.Drawing.Size(504, 32);
			this.queueProgress3.TabIndex = 0;
			// 
			// txtStack3
			// 
			this.txtStack3.AutoSize = true;
			this.txtStack3.Location = new System.Drawing.Point(48, 128);
			this.txtStack3.Name = "txtStack3";
			this.txtStack3.Size = new System.Drawing.Size(18, 13);
			this.txtStack3.TabIndex = 3;
			this.txtStack3.Text = "{ }";
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(40, 104);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(104, 13);
			this.label4.TabIndex = 1;
			this.label4.Text = "Результат слияния";
			// 
			// Task4Form
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(587, 305);
			this.Controls.Add(this.txtStack3);
			this.Controls.Add(this.txtStack2);
			this.Controls.Add(this.txtStack1);
			this.Controls.Add(this.btnSwitch);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.queueProgress2);
			this.Controls.Add(this.queueProgress3);
			this.Controls.Add(this.queueProgress1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Name = "Task4Form";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Задача 4";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.ProgressBar queueProgress1;
		private System.Windows.Forms.ProgressBar queueProgress2;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button btnSwitch;
		private System.Windows.Forms.Label txtStack1;
		private System.Windows.Forms.Label txtStack2;
		private System.Windows.Forms.ProgressBar queueProgress3;
		private System.Windows.Forms.Label txtStack3;
		private System.Windows.Forms.Label label4;
	}
}