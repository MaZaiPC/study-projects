namespace MaZaiPC.CaseManager.WindowsForms
{
	partial class MainForm
	{
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		/// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Код, автоматически созданный конструктором форм Windows

		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		private void InitializeComponent()
		{
			this.btnWorker = new System.Windows.Forms.Button();
			this.btnHelp = new System.Windows.Forms.Button();
			this.btnAbout = new System.Windows.Forms.Button();
			this.btnExit = new System.Windows.Forms.Button();
			this.txtHeader = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// btnWorker
			// 
			this.btnWorker.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnWorker.Location = new System.Drawing.Point(32, 96);
			this.btnWorker.Name = "btnWorker";
			this.btnWorker.Size = new System.Drawing.Size(216, 32);
			this.btnWorker.TabIndex = 0;
			this.btnWorker.Text = "Начать работу";
			this.btnWorker.UseVisualStyleBackColor = true;
			// 
			// btnHelp
			// 
			this.btnHelp.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnHelp.Location = new System.Drawing.Point(32, 152);
			this.btnHelp.Name = "btnHelp";
			this.btnHelp.Size = new System.Drawing.Size(216, 32);
			this.btnHelp.TabIndex = 1;
			this.btnHelp.Text = "Помощь";
			this.btnHelp.UseVisualStyleBackColor = true;
			// 
			// btnAbout
			// 
			this.btnAbout.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnAbout.Location = new System.Drawing.Point(32, 208);
			this.btnAbout.Name = "btnAbout";
			this.btnAbout.Size = new System.Drawing.Size(216, 32);
			this.btnAbout.TabIndex = 2;
			this.btnAbout.Text = "О программе";
			this.btnAbout.UseVisualStyleBackColor = true;
			// 
			// btnExit
			// 
			this.btnExit.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnExit.Location = new System.Drawing.Point(32, 264);
			this.btnExit.Name = "btnExit";
			this.btnExit.Size = new System.Drawing.Size(216, 32);
			this.btnExit.TabIndex = 3;
			this.btnExit.Text = "Выход";
			this.btnExit.UseVisualStyleBackColor = true;
			// 
			// txtHeader
			// 
			this.txtHeader.Font = new System.Drawing.Font("Times New Roman", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txtHeader.ForeColor = System.Drawing.Color.White;
			this.txtHeader.Location = new System.Drawing.Point(32, 24);
			this.txtHeader.Name = "txtHeader";
			this.txtHeader.Size = new System.Drawing.Size(216, 48);
			this.txtHeader.TabIndex = 4;
			this.txtHeader.Text = "Вариант 13\r\nРабота с регистром";
			this.txtHeader.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.Teal;
			this.ClientSize = new System.Drawing.Size(284, 321);
			this.Controls.Add(this.txtHeader);
			this.Controls.Add(this.btnExit);
			this.Controls.Add(this.btnAbout);
			this.Controls.Add(this.btnHelp);
			this.Controls.Add(this.btnWorker);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MaximizeBox = false;
			this.MaximumSize = new System.Drawing.Size(300, 360);
			this.MinimumSize = new System.Drawing.Size(300, 360);
			this.Name = "MainForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Case Manager";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button btnWorker;
		private System.Windows.Forms.Button btnHelp;
		private System.Windows.Forms.Button btnAbout;
		private System.Windows.Forms.Button btnExit;
		private System.Windows.Forms.Label txtHeader;
	}
}

