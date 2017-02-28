namespace Moreniell.CollectionsHome.WindowsForms
{
	partial class LauncherForm
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
			this.txtHeader = new System.Windows.Forms.Label();
			this.btnStart = new System.Windows.Forms.Button();
			this.btnExit = new System.Windows.Forms.Button();
			this.comboBox1 = new System.Windows.Forms.ComboBox();
			this.SuspendLayout();
			// 
			// txtHeader
			// 
			this.txtHeader.Font = new System.Drawing.Font("Times New Roman", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txtHeader.ForeColor = System.Drawing.Color.White;
			this.txtHeader.Location = new System.Drawing.Point(24, 32);
			this.txtHeader.Name = "txtHeader";
			this.txtHeader.Size = new System.Drawing.Size(408, 24);
			this.txtHeader.TabIndex = 4;
			this.txtHeader.Text = "Выберите задание из списка и нажмите кнопку \"Начать работу\"";
			this.txtHeader.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// btnStart
			// 
			this.btnStart.Location = new System.Drawing.Point(248, 112);
			this.btnStart.Name = "btnStart";
			this.btnStart.Size = new System.Drawing.Size(107, 23);
			this.btnStart.TabIndex = 3;
			this.btnStart.Text = "Начать работу";
			this.btnStart.UseVisualStyleBackColor = true;
			this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
			// 
			// btnExit
			// 
			this.btnExit.Location = new System.Drawing.Point(357, 112);
			this.btnExit.Name = "btnExit";
			this.btnExit.Size = new System.Drawing.Size(75, 23);
			this.btnExit.TabIndex = 1;
			this.btnExit.Text = "Выход";
			this.btnExit.UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.comboBox1.FormattingEnabled = true;
			this.comboBox1.Items.AddRange(new object[] {
            "Задача 1",
            "Задача 2",
            "Задача 3",
            "Задача 4"});
			this.comboBox1.Location = new System.Drawing.Point(24, 72);
			this.comboBox1.Name = "comboBox1";
			this.comboBox1.Size = new System.Drawing.Size(408, 21);
			this.comboBox1.TabIndex = 2;
			// 
			// LauncherForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.Teal;
			this.ClientSize = new System.Drawing.Size(459, 154);
			this.Controls.Add(this.comboBox1);
			this.Controls.Add(this.btnExit);
			this.Controls.Add(this.btnStart);
			this.Controls.Add(this.txtHeader);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MaximizeBox = false;
			this.Name = "LauncherForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Менеджер заданий";
			this.ResumeLayout(false);

		}

		#endregion
		private System.Windows.Forms.Label txtHeader;
		private System.Windows.Forms.Button btnStart;
		private System.Windows.Forms.Button btnExit;
		private System.Windows.Forms.ComboBox comboBox1;
	}
}

