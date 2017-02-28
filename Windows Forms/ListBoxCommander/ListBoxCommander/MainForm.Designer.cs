namespace Moreniell.ListBoxCommander
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
			this.listBox1 = new System.Windows.Forms.ListBox();
			this.listBox2 = new System.Windows.Forms.ListBox();
			this.textBox1 = new System.Windows.Forms.TextBox();
			this.btnWriteLine = new System.Windows.Forms.Button();
			this.btnCopy = new System.Windows.Forms.Button();
			this.btnMove = new System.Windows.Forms.Button();
			this.btnClear = new System.Windows.Forms.Button();
			this.btnClearBoth = new System.Windows.Forms.Button();
			this.btnExit = new System.Windows.Forms.Button();
			this.header1 = new System.Windows.Forms.ListBox();
			this.header2 = new System.Windows.Forms.ListBox();
			this.label1 = new System.Windows.Forms.Label();
			this.linkLabel1 = new System.Windows.Forms.LinkLabel();
			this.SuspendLayout();
			// 
			// listBox1
			// 
			this.listBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
			this.listBox1.FormattingEnabled = true;
			this.listBox1.Location = new System.Drawing.Point(0, 72);
			this.listBox1.MinimumSize = new System.Drawing.Size(340, 316);
			this.listBox1.Name = "listBox1";
			this.listBox1.Size = new System.Drawing.Size(340, 316);
			this.listBox1.TabIndex = 1;
			this.listBox1.Enter += new System.EventHandler(this.listBox1_Enter);
			// 
			// listBox2
			// 
			this.listBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.listBox2.FormattingEnabled = true;
			this.listBox2.Location = new System.Drawing.Point(344, 72);
			this.listBox2.MinimumSize = new System.Drawing.Size(340, 316);
			this.listBox2.Name = "listBox2";
			this.listBox2.Size = new System.Drawing.Size(340, 316);
			this.listBox2.TabIndex = 2;
			this.listBox2.Enter += new System.EventHandler(this.listBox2_Enter);
			// 
			// textBox1
			// 
			this.textBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.textBox1.Location = new System.Drawing.Point(0, 24);
			this.textBox1.MaxLength = 100;
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new System.Drawing.Size(684, 20);
			this.textBox1.TabIndex = 0;
			this.textBox1.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textBox1_KeyDown);
			// 
			// btnWriteLine
			// 
			this.btnWriteLine.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.btnWriteLine.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
			this.btnWriteLine.Location = new System.Drawing.Point(0, 404);
			this.btnWriteLine.Name = "btnWriteLine";
			this.btnWriteLine.Size = new System.Drawing.Size(114, 23);
			this.btnWriteLine.TabIndex = 3;
			this.btnWriteLine.Text = "Запись строки";
			this.btnWriteLine.UseVisualStyleBackColor = true;
			this.btnWriteLine.Click += new System.EventHandler(this.btnWriteLine_Click);
			// 
			// btnCopy
			// 
			this.btnCopy.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.btnCopy.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
			this.btnCopy.Location = new System.Drawing.Point(114, 404);
			this.btnCopy.Name = "btnCopy";
			this.btnCopy.Size = new System.Drawing.Size(114, 23);
			this.btnCopy.TabIndex = 4;
			this.btnCopy.Text = "Копирование";
			this.btnCopy.UseVisualStyleBackColor = true;
			this.btnCopy.Click += new System.EventHandler(this.btnCopy_Click);
			// 
			// btnMove
			// 
			this.btnMove.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.btnMove.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
			this.btnMove.Location = new System.Drawing.Point(228, 404);
			this.btnMove.Name = "btnMove";
			this.btnMove.Size = new System.Drawing.Size(114, 23);
			this.btnMove.TabIndex = 5;
			this.btnMove.Text = "Перемещение";
			this.btnMove.UseVisualStyleBackColor = true;
			this.btnMove.Click += new System.EventHandler(this.btnMove_Click);
			// 
			// btnClear
			// 
			this.btnClear.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.btnClear.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
			this.btnClear.Location = new System.Drawing.Point(342, 404);
			this.btnClear.Name = "btnClear";
			this.btnClear.Size = new System.Drawing.Size(114, 23);
			this.btnClear.TabIndex = 6;
			this.btnClear.Text = "Очистка";
			this.btnClear.UseVisualStyleBackColor = true;
			this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
			// 
			// btnClearBoth
			// 
			this.btnClearBoth.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.btnClearBoth.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
			this.btnClearBoth.Location = new System.Drawing.Point(456, 404);
			this.btnClearBoth.Name = "btnClearBoth";
			this.btnClearBoth.Size = new System.Drawing.Size(114, 23);
			this.btnClearBoth.TabIndex = 7;
			this.btnClearBoth.Text = "Очистить всё";
			this.btnClearBoth.UseVisualStyleBackColor = true;
			this.btnClearBoth.Click += new System.EventHandler(this.btnClearBoth_Click);
			// 
			// btnExit
			// 
			this.btnExit.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.btnExit.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
			this.btnExit.Location = new System.Drawing.Point(570, 404);
			this.btnExit.Name = "btnExit";
			this.btnExit.Size = new System.Drawing.Size(114, 23);
			this.btnExit.TabIndex = 8;
			this.btnExit.Text = "Выход";
			this.btnExit.UseVisualStyleBackColor = true;
			this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
			// 
			// header1
			// 
			this.header1.BackColor = System.Drawing.Color.Bisque;
			this.header1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.header1.FormattingEnabled = true;
			this.header1.Items.AddRange(new object[] {
            "Список 1"});
			this.header1.Location = new System.Drawing.Point(0, 56);
			this.header1.Name = "header1";
			this.header1.Size = new System.Drawing.Size(340, 17);
			this.header1.TabIndex = 9;
			this.header1.TabStop = false;
			// 
			// header2
			// 
			this.header2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.header2.BackColor = System.Drawing.Color.AntiqueWhite;
			this.header2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.header2.FormattingEnabled = true;
			this.header2.Items.AddRange(new object[] {
            "Список 2"});
			this.header2.Location = new System.Drawing.Point(344, 56);
			this.header2.Name = "header2";
			this.header2.Size = new System.Drawing.Size(340, 17);
			this.header2.TabIndex = 9;
			this.header2.TabStop = false;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(0, 8);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(173, 13);
			this.label1.TabIndex = 10;
			this.label1.Text = "Введите строку для добавления:";
			// 
			// linkLabel1
			// 
			this.linkLabel1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.linkLabel1.AutoSize = true;
			this.linkLabel1.Location = new System.Drawing.Point(624, 8);
			this.linkLabel1.Name = "linkLabel1";
			this.linkLabel1.Size = new System.Drawing.Size(50, 13);
			this.linkLabel1.TabIndex = 11;
			this.linkLabel1.TabStop = true;
			this.linkLabel1.Text = "Помощь";
			this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(684, 441);
			this.Controls.Add(this.linkLabel1);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.header2);
			this.Controls.Add(this.header1);
			this.Controls.Add(this.btnExit);
			this.Controls.Add(this.btnClearBoth);
			this.Controls.Add(this.btnClear);
			this.Controls.Add(this.btnMove);
			this.Controls.Add(this.btnCopy);
			this.Controls.Add(this.btnWriteLine);
			this.Controls.Add(this.textBox1);
			this.Controls.Add(this.listBox2);
			this.Controls.Add(this.listBox1);
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MinimumSize = new System.Drawing.Size(700, 480);
			this.Name = "MainForm";
			this.Text = "ListBox Commander";
			this.Resize += new System.EventHandler(this.MainForm_Resize);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.ListBox listBox1;
		private System.Windows.Forms.ListBox listBox2;
		private System.Windows.Forms.TextBox textBox1;
		private System.Windows.Forms.Button btnWriteLine;
		private System.Windows.Forms.Button btnCopy;
		private System.Windows.Forms.Button btnMove;
		private System.Windows.Forms.Button btnClear;
		private System.Windows.Forms.Button btnClearBoth;
		private System.Windows.Forms.Button btnExit;
		private System.Windows.Forms.ListBox header1;
		private System.Windows.Forms.ListBox header2;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.LinkLabel linkLabel1;
	}
}

