namespace MaZaiPC.TrafficViolationManager
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
			this.label1 = new System.Windows.Forms.Label();
			this.btnExit = new System.Windows.Forms.Button();
			this.btnAbout = new System.Windows.Forms.Button();
			this.btnHelp = new System.Windows.Forms.Button();
			this.btnRunApp = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// txtHeader
			// 
			this.txtHeader.BackColor = System.Drawing.Color.Transparent;
			this.txtHeader.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.txtHeader.Font = new System.Drawing.Font("Script MT Bold", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txtHeader.ForeColor = System.Drawing.Color.Black;
			this.txtHeader.Location = new System.Drawing.Point(32, 24);
			this.txtHeader.Name = "txtHeader";
			this.txtHeader.Size = new System.Drawing.Size(216, 24);
			this.txtHeader.TabIndex = 4;
			this.txtHeader.Text = "Итоговая работа";
			this.txtHeader.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label1
			// 
			this.label1.BackColor = System.Drawing.Color.Transparent;
			this.label1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.label1.Font = new System.Drawing.Font("Monotype Corsiva", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.ForeColor = System.Drawing.Color.Black;
			this.label1.Location = new System.Drawing.Point(32, 48);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(216, 24);
			this.label1.TabIndex = 4;
			this.label1.Text = "Windows Forms";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btnExit
			// 
			this.btnExit.BackColor = System.Drawing.Color.Transparent;
			this.btnExit.BackgroundImage = global::MaZaiPC.TrafficViolationManager.Properties.Resources.button_exit;
			this.btnExit.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
			this.btnExit.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnExit.FlatAppearance.BorderSize = 0;
			this.btnExit.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnExit.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.btnExit.ForeColor = System.Drawing.Color.White;
			this.btnExit.Location = new System.Drawing.Point(32, 264);
			this.btnExit.Name = "btnExit";
			this.btnExit.Size = new System.Drawing.Size(216, 32);
			this.btnExit.TabIndex = 0;
			this.btnExit.Text = "Выход";
			this.btnExit.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			this.btnExit.UseVisualStyleBackColor = false;
			this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
			// 
			// btnAbout
			// 
			this.btnAbout.BackColor = System.Drawing.Color.Transparent;
			this.btnAbout.BackgroundImage = global::MaZaiPC.TrafficViolationManager.Properties.Resources.button_standart;
			this.btnAbout.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
			this.btnAbout.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnAbout.FlatAppearance.BorderSize = 0;
			this.btnAbout.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnAbout.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.btnAbout.ForeColor = System.Drawing.Color.White;
			this.btnAbout.Location = new System.Drawing.Point(32, 208);
			this.btnAbout.Name = "btnAbout";
			this.btnAbout.Size = new System.Drawing.Size(216, 32);
			this.btnAbout.TabIndex = 0;
			this.btnAbout.Text = "О программе";
			this.btnAbout.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			this.btnAbout.UseVisualStyleBackColor = false;
			this.btnAbout.Click += new System.EventHandler(this.btnAbout_Click);
			// 
			// btnHelp
			// 
			this.btnHelp.BackColor = System.Drawing.Color.Transparent;
			this.btnHelp.BackgroundImage = global::MaZaiPC.TrafficViolationManager.Properties.Resources.button_standart;
			this.btnHelp.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
			this.btnHelp.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnHelp.FlatAppearance.BorderSize = 0;
			this.btnHelp.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnHelp.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.btnHelp.ForeColor = System.Drawing.Color.White;
			this.btnHelp.Location = new System.Drawing.Point(32, 152);
			this.btnHelp.Name = "btnHelp";
			this.btnHelp.Size = new System.Drawing.Size(216, 32);
			this.btnHelp.TabIndex = 0;
			this.btnHelp.Text = "Помощь";
			this.btnHelp.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			this.btnHelp.UseVisualStyleBackColor = false;
			this.btnHelp.Click += new System.EventHandler(this.btnHelp_Click);
			// 
			// btnRunApp
			// 
			this.btnRunApp.BackColor = System.Drawing.Color.Transparent;
			this.btnRunApp.BackgroundImage = global::MaZaiPC.TrafficViolationManager.Properties.Resources.button_main;
			this.btnRunApp.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
			this.btnRunApp.Cursor = System.Windows.Forms.Cursors.Hand;
			this.btnRunApp.FlatAppearance.BorderSize = 0;
			this.btnRunApp.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnRunApp.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.btnRunApp.ForeColor = System.Drawing.Color.White;
			this.btnRunApp.Location = new System.Drawing.Point(32, 96);
			this.btnRunApp.Name = "btnRunApp";
			this.btnRunApp.Size = new System.Drawing.Size(216, 32);
			this.btnRunApp.TabIndex = 0;
			this.btnRunApp.Text = "Начать работу";
			this.btnRunApp.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			this.btnRunApp.UseVisualStyleBackColor = false;
			this.btnRunApp.Click += new System.EventHandler(this.btnRunApp_Click);
			// 
			// LauncherForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.SystemColors.ControlLight;
			this.ClientSize = new System.Drawing.Size(284, 321);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.txtHeader);
			this.Controls.Add(this.btnExit);
			this.Controls.Add(this.btnAbout);
			this.Controls.Add(this.btnHelp);
			this.Controls.Add(this.btnRunApp);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
			this.MaximizeBox = false;
			this.MaximumSize = new System.Drawing.Size(300, 360);
			this.MinimizeBox = false;
			this.MinimumSize = new System.Drawing.Size(300, 360);
			this.Name = "LauncherForm";
			this.ShowIcon = false;
			this.ShowInTaskbar = false;
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Меню запуска";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button btnRunApp;
		private System.Windows.Forms.Button btnHelp;
		private System.Windows.Forms.Button btnAbout;
		private System.Windows.Forms.Button btnExit;
		private System.Windows.Forms.Label txtHeader;
		private System.Windows.Forms.Label label1;
	}
}

