namespace Moreniell.TextAnalyzer
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
            if (disposing && (components != null)) {
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
			this.mnuMain = new System.Windows.Forms.MenuStrip();
			this.mniFile = new System.Windows.Forms.ToolStripMenuItem();
			this.mniFileOpen = new System.Windows.Forms.ToolStripMenuItem();
			this.mniFileSep1 = new System.Windows.Forms.ToolStripSeparator();
			this.mniFileExit = new System.Windows.Forms.ToolStripMenuItem();
			this.mniAnalyze = new System.Windows.Forms.ToolStripMenuItem();
			this.mniWordsCount = new System.Windows.Forms.ToolStripMenuItem();
			this.mniLetterOccurrence = new System.Windows.Forms.ToolStripMenuItem();
			this.mniHelp = new System.Windows.Forms.ToolStripMenuItem();
			this.mniHelpAbout = new System.Windows.Forms.ToolStripMenuItem();
			this.tstMain = new System.Windows.Forms.ToolStrip();
			this.tsbOpenText = new System.Windows.Forms.ToolStripButton();
			this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.tsbWordsCount = new System.Windows.Forms.ToolStripButton();
			this.tsbLetterOccurrence = new System.Windows.Forms.ToolStripButton();
			this.tsSep1 = new System.Windows.Forms.ToolStripSeparator();
			this.tsbAbout = new System.Windows.Forms.ToolStripButton();
			this.tsbExit = new System.Windows.Forms.ToolStripButton();
			this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
			this.splitContainer1 = new System.Windows.Forms.SplitContainer();
			this.btnStart = new System.Windows.Forms.Button();
			this.charBox1 = new System.Windows.Forms.TextBox();
			this.labelCounter = new System.Windows.Forms.Label();
			this.richTextBox1 = new System.Windows.Forms.RichTextBox();
			this.mnuMain.SuspendLayout();
			this.tstMain.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
			this.splitContainer1.Panel1.SuspendLayout();
			this.splitContainer1.Panel2.SuspendLayout();
			this.splitContainer1.SuspendLayout();
			this.SuspendLayout();
			// 
			// mnuMain
			// 
			this.mnuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniFile,
            this.mniAnalyze,
            this.mniHelp});
			this.mnuMain.Location = new System.Drawing.Point(0, 0);
			this.mnuMain.Name = "mnuMain";
			this.mnuMain.Size = new System.Drawing.Size(556, 24);
			this.mnuMain.TabIndex = 0;
			this.mnuMain.Text = "menuStrip1";
			// 
			// mniFile
			// 
			this.mniFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniFileOpen,
            this.mniFileSep1,
            this.mniFileExit});
			this.mniFile.Name = "mniFile";
			this.mniFile.Size = new System.Drawing.Size(48, 20);
			this.mniFile.Tag = "0";
			this.mniFile.Text = "&Файл";
			// 
			// mniFileOpen
			// 
			this.mniFileOpen.Image = global::Moreniell.TextAnalyzer.Properties.Resources.file;
			this.mniFileOpen.Name = "mniFileOpen";
			this.mniFileOpen.Size = new System.Drawing.Size(159, 22);
			this.mniFileOpen.Tag = "2";
			this.mniFileOpen.Text = "Загрузить текст";
			this.mniFileOpen.Click += new System.EventHandler(this.mniOpenText_Click);
			// 
			// mniFileSep1
			// 
			this.mniFileSep1.Name = "mniFileSep1";
			this.mniFileSep1.Size = new System.Drawing.Size(156, 6);
			// 
			// mniFileExit
			// 
			this.mniFileExit.Image = global::Moreniell.TextAnalyzer.Properties.Resources.door_exit;
			this.mniFileExit.Name = "mniFileExit";
			this.mniFileExit.Size = new System.Drawing.Size(159, 22);
			this.mniFileExit.Tag = "4";
			this.mniFileExit.Text = "Выход";
			this.mniFileExit.Click += new System.EventHandler(this.mniFileExit_Click);
			// 
			// mniAnalyze
			// 
			this.mniAnalyze.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniWordsCount,
            this.mniLetterOccurrence});
			this.mniAnalyze.Name = "mniAnalyze";
			this.mniAnalyze.Size = new System.Drawing.Size(59, 20);
			this.mniAnalyze.Tag = "5";
			this.mniAnalyze.Text = "Анализ";
			// 
			// mniWordsCount
			// 
			this.mniWordsCount.Image = global::Moreniell.TextAnalyzer.Properties.Resources.numbered_list_style;
			this.mniWordsCount.Name = "mniWordsCount";
			this.mniWordsCount.Size = new System.Drawing.Size(197, 22);
			this.mniWordsCount.Tag = "7";
			this.mniWordsCount.Text = "Кол-во слов";
			this.mniWordsCount.Click += new System.EventHandler(this.mniWordsCount_Click);
			// 
			// mniLetterOccurrence
			// 
			this.mniLetterOccurrence.Image = global::Moreniell.TextAnalyzer.Properties.Resources.ic_format_shapes_black_36dp;
			this.mniLetterOccurrence.Name = "mniLetterOccurrence";
			this.mniLetterOccurrence.Size = new System.Drawing.Size(197, 22);
			this.mniLetterOccurrence.Tag = "8";
			this.mniLetterOccurrence.Text = "Повторяемость буквы";
			this.mniLetterOccurrence.Click += new System.EventHandler(this.mniLetterOccurrence_Click);
			// 
			// mniHelp
			// 
			this.mniHelp.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniHelpAbout});
			this.mniHelp.Name = "mniHelp";
			this.mniHelp.Size = new System.Drawing.Size(65, 20);
			this.mniHelp.Tag = "9";
			this.mniHelp.Text = "Справка";
			// 
			// mniHelpAbout
			// 
			this.mniHelpAbout.Image = global::Moreniell.TextAnalyzer.Properties.Resources.luggage_information;
			this.mniHelpAbout.Name = "mniHelpAbout";
			this.mniHelpAbout.Size = new System.Drawing.Size(158, 22);
			this.mniHelpAbout.Tag = "10";
			this.mniHelpAbout.Text = "О программе...";
			this.mniHelpAbout.Click += new System.EventHandler(this.mniAbout_Click);
			// 
			// tstMain
			// 
			this.tstMain.ImageScalingSize = new System.Drawing.Size(24, 24);
			this.tstMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbOpenText,
            this.toolStripSeparator1,
            this.tsbWordsCount,
            this.tsbLetterOccurrence,
            this.tsSep1,
            this.tsbAbout,
            this.tsbExit});
			this.tstMain.Location = new System.Drawing.Point(0, 24);
			this.tstMain.Name = "tstMain";
			this.tstMain.Size = new System.Drawing.Size(556, 31);
			this.tstMain.TabIndex = 1;
			// 
			// tsbOpenText
			// 
			this.tsbOpenText.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.tsbOpenText.Image = global::Moreniell.TextAnalyzer.Properties.Resources.file;
			this.tsbOpenText.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.tsbOpenText.Margin = new System.Windows.Forms.Padding(6, 1, 0, 2);
			this.tsbOpenText.Name = "tsbOpenText";
			this.tsbOpenText.Size = new System.Drawing.Size(28, 28);
			this.tsbOpenText.Text = "toolStripButton1";
			this.tsbOpenText.ToolTipText = "Загрузить текст";
			this.tsbOpenText.Click += new System.EventHandler(this.mniOpenText_Click);
			// 
			// toolStripSeparator1
			// 
			this.toolStripSeparator1.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
			this.toolStripSeparator1.Name = "toolStripSeparator1";
			this.toolStripSeparator1.Size = new System.Drawing.Size(6, 31);
			// 
			// tsbWordsCount
			// 
			this.tsbWordsCount.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.tsbWordsCount.Image = global::Moreniell.TextAnalyzer.Properties.Resources.numbered_list_style;
			this.tsbWordsCount.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.tsbWordsCount.Name = "tsbWordsCount";
			this.tsbWordsCount.Size = new System.Drawing.Size(28, 28);
			this.tsbWordsCount.Text = "toolStripButton2";
			this.tsbWordsCount.ToolTipText = "Подсчитать кол-во слов";
			this.tsbWordsCount.Click += new System.EventHandler(this.mniWordsCount_Click);
			// 
			// tsbLetterOccurrence
			// 
			this.tsbLetterOccurrence.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.tsbLetterOccurrence.Image = global::Moreniell.TextAnalyzer.Properties.Resources.ic_format_shapes_black_36dp;
			this.tsbLetterOccurrence.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.tsbLetterOccurrence.Name = "tsbLetterOccurrence";
			this.tsbLetterOccurrence.Size = new System.Drawing.Size(28, 28);
			this.tsbLetterOccurrence.Text = "toolStripButton3";
			this.tsbLetterOccurrence.ToolTipText = "Определить повторяемость буквы";
			this.tsbLetterOccurrence.Click += new System.EventHandler(this.mniLetterOccurrence_Click);
			// 
			// tsSep1
			// 
			this.tsSep1.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
			this.tsSep1.Name = "tsSep1";
			this.tsSep1.Size = new System.Drawing.Size(6, 31);
			// 
			// tsbAbout
			// 
			this.tsbAbout.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.tsbAbout.Image = global::Moreniell.TextAnalyzer.Properties.Resources.luggage_information;
			this.tsbAbout.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.tsbAbout.Name = "tsbAbout";
			this.tsbAbout.Size = new System.Drawing.Size(28, 28);
			this.tsbAbout.Text = "toolStripButton7";
			this.tsbAbout.ToolTipText = "О программе";
			this.tsbAbout.Click += new System.EventHandler(this.mniAbout_Click);
			// 
			// tsbExit
			// 
			this.tsbExit.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.tsbExit.Image = global::Moreniell.TextAnalyzer.Properties.Resources.door_exit;
			this.tsbExit.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.tsbExit.Name = "tsbExit";
			this.tsbExit.Size = new System.Drawing.Size(28, 28);
			this.tsbExit.Text = "toolStripButton8";
			this.tsbExit.ToolTipText = "Выход";
			this.tsbExit.Click += new System.EventHandler(this.mniFileExit_Click);
			// 
			// openFileDialog
			// 
			this.openFileDialog.Filter = "Текстовые файлы(*.txt)|*.txt";
			// 
			// splitContainer1
			// 
			this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.splitContainer1.Location = new System.Drawing.Point(0, 55);
			this.splitContainer1.Name = "splitContainer1";
			this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this.splitContainer1.Panel1.Controls.Add(this.btnStart);
			this.splitContainer1.Panel1.Controls.Add(this.charBox1);
			this.splitContainer1.Panel1.Controls.Add(this.labelCounter);
			// 
			// splitContainer1.Panel2
			// 
			this.splitContainer1.Panel2.BackColor = System.Drawing.Color.White;
			this.splitContainer1.Panel2.Controls.Add(this.richTextBox1);
			this.splitContainer1.Size = new System.Drawing.Size(556, 306);
			this.splitContainer1.SplitterDistance = 189;
			this.splitContainer1.TabIndex = 2;
			// 
			// btnStart
			// 
			this.btnStart.Location = new System.Drawing.Point(232, 104);
			this.btnStart.Name = "btnStart";
			this.btnStart.Size = new System.Drawing.Size(75, 23);
			this.btnStart.TabIndex = 2;
			this.btnStart.Text = "Старт!";
			this.btnStart.UseVisualStyleBackColor = true;
			this.btnStart.Visible = false;
			this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
			// 
			// charBox1
			// 
			this.charBox1.Location = new System.Drawing.Point(363, 64);
			this.charBox1.MaxLength = 1;
			this.charBox1.Name = "charBox1";
			this.charBox1.Size = new System.Drawing.Size(24, 20);
			this.charBox1.TabIndex = 1;
			this.charBox1.Visible = false;
			this.charBox1.TextChanged += new System.EventHandler(this.charBox1_TextChanged);
			// 
			// labelCounter
			// 
			this.labelCounter.AutoSize = true;
			this.labelCounter.Location = new System.Drawing.Point(147, 67);
			this.labelCounter.Name = "labelCounter";
			this.labelCounter.Size = new System.Drawing.Size(211, 13);
			this.labelCounter.TabIndex = 0;
			this.labelCounter.Text = "Введите букву для подсчета вхождений:";
			this.labelCounter.Visible = false;
			// 
			// richTextBox1
			// 
			this.richTextBox1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.richTextBox1.Location = new System.Drawing.Point(0, 0);
			this.richTextBox1.Name = "richTextBox1";
			this.richTextBox1.ReadOnly = true;
			this.richTextBox1.Size = new System.Drawing.Size(556, 113);
			this.richTextBox1.TabIndex = 0;
			this.richTextBox1.Text = "";
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.Turquoise;
			this.ClientSize = new System.Drawing.Size(556, 361);
			this.Controls.Add(this.splitContainer1);
			this.Controls.Add(this.tstMain);
			this.Controls.Add(this.mnuMain);
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MainMenuStrip = this.mnuMain;
			this.Name = "MainForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Анализатор текста";
			this.mnuMain.ResumeLayout(false);
			this.mnuMain.PerformLayout();
			this.tstMain.ResumeLayout(false);
			this.tstMain.PerformLayout();
			this.splitContainer1.Panel1.ResumeLayout(false);
			this.splitContainer1.Panel1.PerformLayout();
			this.splitContainer1.Panel2.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
			this.splitContainer1.ResumeLayout(false);
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip mnuMain;
        private System.Windows.Forms.ToolStripMenuItem mniFile;
        private System.Windows.Forms.ToolStrip tstMain;
        private System.Windows.Forms.ToolStripMenuItem mniFileOpen;
        private System.Windows.Forms.ToolStripSeparator mniFileSep1;
        private System.Windows.Forms.ToolStripMenuItem mniFileExit;
        private System.Windows.Forms.ToolStripMenuItem mniAnalyze;
        private System.Windows.Forms.ToolStripMenuItem mniWordsCount;
        private System.Windows.Forms.ToolStripMenuItem mniLetterOccurrence;
        private System.Windows.Forms.ToolStripMenuItem mniHelp;
        private System.Windows.Forms.ToolStripMenuItem mniHelpAbout;
        private System.Windows.Forms.ToolStripButton tsbOpenText;
        private System.Windows.Forms.ToolStripButton tsbWordsCount;
        private System.Windows.Forms.ToolStripButton tsbLetterOccurrence;
        private System.Windows.Forms.ToolStripSeparator tsSep1;
        private System.Windows.Forms.ToolStripButton tsbAbout;
        private System.Windows.Forms.ToolStripButton tsbExit;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
		private System.Windows.Forms.OpenFileDialog openFileDialog;
		private System.Windows.Forms.SplitContainer splitContainer1;
		private System.Windows.Forms.RichTextBox richTextBox1;
		private System.Windows.Forms.Button btnStart;
		private System.Windows.Forms.TextBox charBox1;
		private System.Windows.Forms.Label labelCounter;
	}
}

