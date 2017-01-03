namespace MaZaiPC.CaseManager.WindowsForms
{
	partial class WorkerForm
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
			this.domainUpDown1 = new System.Windows.Forms.DomainUpDown();
			this.btnManage = new System.Windows.Forms.Button();
			this.btnClear = new System.Windows.Forms.Button();
			this.button3 = new System.Windows.Forms.Button();
			this.radioUpperCase = new System.Windows.Forms.RadioButton();
			this.radioLowerCase = new System.Windows.Forms.RadioButton();
			this.radioCapital = new System.Windows.Forms.RadioButton();
			this.checkReverse = new System.Windows.Forms.CheckBox();
			this.linkHelp = new System.Windows.Forms.LinkLabel();
			this.SuspendLayout();
			// 
			// domainUpDown1
			// 
			this.domainUpDown1.Location = new System.Drawing.Point(32, 48);
			this.domainUpDown1.Name = "domainUpDown1";
			this.domainUpDown1.Size = new System.Drawing.Size(264, 20);
			this.domainUpDown1.TabIndex = 1;
			this.domainUpDown1.Text = "Введите текст...";
			this.domainUpDown1.SelectedItemChanged += new System.EventHandler(this.domainUpDown1_SelectedItemChanged);
			this.domainUpDown1.GotFocus += new System.EventHandler(this.domainUpDown1_GotFocus);
			this.domainUpDown1.LostFocus += new System.EventHandler(this.domainUpDown1_LostFocus);
			// 
			// btnManage
			// 
			this.btnManage.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnManage.Location = new System.Drawing.Point(384, 48);
			this.btnManage.Name = "btnManage";
			this.btnManage.Size = new System.Drawing.Size(160, 23);
			this.btnManage.TabIndex = 0;
			this.btnManage.Text = "Выполнить";
			this.btnManage.UseVisualStyleBackColor = true;
			this.btnManage.Click += new System.EventHandler(this.btnManage_Click);
			// 
			// btnClear
			// 
			this.btnClear.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnClear.Location = new System.Drawing.Point(384, 80);
			this.btnClear.Name = "btnClear";
			this.btnClear.Size = new System.Drawing.Size(160, 23);
			this.btnClear.TabIndex = 2;
			this.btnClear.Text = "Очистка";
			this.btnClear.UseVisualStyleBackColor = true;
			this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
			// 
			// button3
			// 
			this.button3.Cursor = System.Windows.Forms.Cursors.Hand;
			this.button3.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.button3.Location = new System.Drawing.Point(384, 246);
			this.button3.Name = "button3";
			this.button3.Size = new System.Drawing.Size(160, 23);
			this.button3.TabIndex = 3;
			this.button3.Text = "Закрыть";
			this.button3.UseVisualStyleBackColor = true;
			// 
			// radioUpperCase
			// 
			this.radioUpperCase.AutoSize = true;
			this.radioUpperCase.Checked = true;
			this.radioUpperCase.Location = new System.Drawing.Point(32, 80);
			this.radioUpperCase.Name = "radioUpperCase";
			this.radioUpperCase.Size = new System.Drawing.Size(129, 17);
			this.radioUpperCase.TabIndex = 4;
			this.radioUpperCase.TabStop = true;
			this.radioUpperCase.Text = "ВЕРХНИЙ РЕГИСТР";
			this.radioUpperCase.UseVisualStyleBackColor = true;
			// 
			// radioLowerCase
			// 
			this.radioLowerCase.AutoSize = true;
			this.radioLowerCase.Location = new System.Drawing.Point(32, 104);
			this.radioLowerCase.Name = "radioLowerCase";
			this.radioLowerCase.Size = new System.Drawing.Size(106, 17);
			this.radioLowerCase.TabIndex = 4;
			this.radioLowerCase.TabStop = true;
			this.radioLowerCase.Text = "нижний регистр";
			this.radioLowerCase.UseVisualStyleBackColor = true;
			// 
			// radioCapital
			// 
			this.radioCapital.AutoSize = true;
			this.radioCapital.Location = new System.Drawing.Point(32, 128);
			this.radioCapital.Name = "radioCapital";
			this.radioCapital.Size = new System.Drawing.Size(143, 17);
			this.radioCapital.TabIndex = 4;
			this.radioCapital.TabStop = true;
			this.radioCapital.Text = "Начинать С Прописных";
			this.radioCapital.UseVisualStyleBackColor = true;
			// 
			// checkReverse
			// 
			this.checkReverse.AutoSize = true;
			this.checkReverse.Enabled = false;
			this.checkReverse.Location = new System.Drawing.Point(184, 80);
			this.checkReverse.Name = "checkReverse";
			this.checkReverse.Size = new System.Drawing.Size(63, 17);
			this.checkReverse.TabIndex = 5;
			this.checkReverse.Text = "Реверс";
			this.checkReverse.UseVisualStyleBackColor = true;
			this.checkReverse.CheckStateChanged += new System.EventHandler(this.checkReverse_CheckStateChanged);
			// 
			// linkHelp
			// 
			this.linkHelp.AutoSize = true;
			this.linkHelp.Cursor = System.Windows.Forms.Cursors.Hand;
			this.linkHelp.Location = new System.Drawing.Point(32, 252);
			this.linkHelp.Name = "linkHelp";
			this.linkHelp.Size = new System.Drawing.Size(50, 13);
			this.linkHelp.TabIndex = 6;
			this.linkHelp.TabStop = true;
			this.linkHelp.Text = "Помощь";
			// 
			// WorkerForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(585, 289);
			this.Controls.Add(this.linkHelp);
			this.Controls.Add(this.checkReverse);
			this.Controls.Add(this.radioCapital);
			this.Controls.Add(this.radioLowerCase);
			this.Controls.Add(this.radioUpperCase);
			this.Controls.Add(this.button3);
			this.Controls.Add(this.btnClear);
			this.Controls.Add(this.btnManage);
			this.Controls.Add(this.domainUpDown1);
			this.Name = "WorkerForm";
			this.Text = "Обработка";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.DomainUpDown domainUpDown1;
		private System.Windows.Forms.Button btnManage;
		private System.Windows.Forms.Button btnClear;
		private System.Windows.Forms.Button button3;
		private System.Windows.Forms.RadioButton radioUpperCase;
		private System.Windows.Forms.RadioButton radioLowerCase;
		private System.Windows.Forms.RadioButton radioCapital;
		private System.Windows.Forms.CheckBox checkReverse;
		private System.Windows.Forms.LinkLabel linkHelp;
	}
}