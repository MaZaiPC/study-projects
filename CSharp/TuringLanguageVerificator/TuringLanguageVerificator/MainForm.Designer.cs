using System;

namespace MaZaiPC.CourseWork
{
    partial class MainForm
    {
        /// <summary>
        /// Требуется переменная конструктора.
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
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
			System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
			System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
			this.inputWord = new System.Windows.Forms.MaskedTextBox();
			this.buttonCheckWord = new System.Windows.Forms.Button();
			this.listBoxResult = new System.Windows.Forms.ListBox();
			this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
			this.feedback = new System.Windows.Forms.Label();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.mniFile = new System.Windows.Forms.ToolStripMenuItem();
			this.mniProtocol = new System.Windows.Forms.ToolStripMenuItem();
			this.mniSaveAs = new System.Windows.Forms.ToolStripMenuItem();
			this.mniSeparator = new System.Windows.Forms.ToolStripSeparator();
			this.mniExit = new System.Windows.Forms.ToolStripMenuItem();
			this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
			((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
			this.menuStrip1.SuspendLayout();
			this.SuspendLayout();
			// 
			// inputWord
			// 
			this.inputWord.BackColor = System.Drawing.SystemColors.Window;
			this.inputWord.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.inputWord.ForeColor = System.Drawing.SystemColors.InfoText;
			this.inputWord.ImeMode = System.Windows.Forms.ImeMode.NoControl;
			this.inputWord.Location = new System.Drawing.Point(55, 34);
			this.inputWord.Name = "inputWord";
			this.inputWord.Size = new System.Drawing.Size(216, 21);
			this.inputWord.TabIndex = 0;
			this.inputWord.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.maskedTextBox1_KeyPress);
			// 
			// buttonCheckWord
			// 
			this.buttonCheckWord.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.buttonCheckWord.Location = new System.Drawing.Point(278, 34);
			this.buttonCheckWord.Name = "buttonCheckWord";
			this.buttonCheckWord.Size = new System.Drawing.Size(96, 23);
			this.buttonCheckWord.TabIndex = 1;
			this.buttonCheckWord.Text = "Проверить";
			this.buttonCheckWord.UseVisualStyleBackColor = true;
			this.buttonCheckWord.Click += new System.EventHandler(this.buttonCheckWord_Click);
			// 
			// listBoxResult
			// 
			this.listBoxResult.Cursor = System.Windows.Forms.Cursors.Arrow;
			this.listBoxResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.listBoxResult.FormattingEnabled = true;
			this.listBoxResult.HorizontalScrollbar = true;
			this.listBoxResult.ItemHeight = 18;
			this.listBoxResult.Location = new System.Drawing.Point(55, 72);
			this.listBoxResult.Name = "listBoxResult";
			this.listBoxResult.ScrollAlwaysVisible = true;
			this.listBoxResult.Size = new System.Drawing.Size(319, 364);
			this.listBoxResult.TabIndex = 2;
			// 
			// chart1
			// 
			chartArea1.AxisX.LineColor = System.Drawing.Color.Gray;
			chartArea1.AxisX.MajorGrid.LineColor = System.Drawing.Color.Gray;
			chartArea1.AxisX.MinorGrid.LineColor = System.Drawing.Color.Gray;
			chartArea1.AxisX.Title = "n - длина слова";
			chartArea1.AxisY.LineColor = System.Drawing.Color.Gray;
			chartArea1.AxisY.MajorGrid.LineColor = System.Drawing.Color.Gray;
			chartArea1.AxisY.MinorGrid.LineColor = System.Drawing.Color.Gray;
			chartArea1.AxisY.Title = "T(n) - количество тактов";
			chartArea1.Name = "ChartArea1";
			chartArea1.Position.Auto = false;
			chartArea1.Position.Height = 85F;
			chartArea1.Position.Width = 94F;
			chartArea1.Position.X = 3F;
			chartArea1.Position.Y = 3F;
			this.chart1.ChartAreas.Add(chartArea1);
			legend1.LegendStyle = System.Windows.Forms.DataVisualization.Charting.LegendStyle.Row;
			legend1.Name = "Legend1";
			legend1.Position.Auto = false;
			legend1.Position.Height = 8.365019F;
			legend1.Position.Width = 100F;
			legend1.Position.Y = 90F;
			this.chart1.Legends.Add(legend1);
			this.chart1.Location = new System.Drawing.Point(376, 72);
			this.chart1.Name = "chart1";
			this.chart1.Size = new System.Drawing.Size(464, 364);
			this.chart1.TabIndex = 5;
			this.chart1.Text = "chartTimeComplexity";
			// 
			// feedback
			// 
			this.feedback.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.feedback.Location = new System.Drawing.Point(400, 24);
			this.feedback.Name = "feedback";
			this.feedback.Size = new System.Drawing.Size(432, 48);
			this.feedback.TabIndex = 6;
			this.feedback.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
			// 
			// menuStrip1
			// 
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniFile});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(430, 24);
			this.menuStrip1.TabIndex = 7;
			this.menuStrip1.Text = "menuStrip1";
			// 
			// mniFile
			// 
			this.mniFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniProtocol,
            this.mniSeparator,
            this.mniExit});
			this.mniFile.Name = "mniFile";
			this.mniFile.Size = new System.Drawing.Size(48, 20);
			this.mniFile.Text = "Файл";
			// 
			// mniProtocol
			// 
			this.mniProtocol.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniSaveAs});
			this.mniProtocol.Name = "mniProtocol";
			this.mniProtocol.Size = new System.Drawing.Size(129, 22);
			this.mniProtocol.Text = "Протокол";
			// 
			// mniSaveAs
			// 
			this.mniSaveAs.Enabled = false;
			this.mniSaveAs.Name = "mniSaveAs";
			this.mniSaveAs.Size = new System.Drawing.Size(162, 22);
			this.mniSaveAs.Text = "Сохранить как...";
			this.mniSaveAs.Click += new System.EventHandler(this.mniSaveAs_Click);
			// 
			// mniSeparator
			// 
			this.mniSeparator.Name = "mniSeparator";
			this.mniSeparator.Size = new System.Drawing.Size(126, 6);
			// 
			// mniExit
			// 
			this.mniExit.Name = "mniExit";
			this.mniExit.Size = new System.Drawing.Size(129, 22);
			this.mniExit.Text = "Выход";
			// 
			// saveFileDialog
			// 
			this.saveFileDialog.Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
			this.BackColor = System.Drawing.SystemColors.Window;
			this.ClientSize = new System.Drawing.Size(430, 472);
			this.Controls.Add(this.feedback);
			this.Controls.Add(this.chart1);
			this.Controls.Add(this.listBoxResult);
			this.Controls.Add(this.buttonCheckWord);
			this.Controls.Add(this.inputWord);
			this.Controls.Add(this.menuStrip1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MainMenuStrip = this.menuStrip1;
			this.MaximizeBox = false;
			this.Name = "MainForm";
			this.Text = "МТ";
			((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

	    #endregion

        private System.Windows.Forms.Button buttonCheckWord;
        private System.Windows.Forms.ListBox listBoxResult;
        private System.Windows.Forms.MaskedTextBox inputWord;
		private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
		private System.Windows.Forms.Label feedback;
		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.ToolStripMenuItem mniFile;
		private System.Windows.Forms.ToolStripMenuItem mniProtocol;
		private System.Windows.Forms.ToolStripSeparator mniSeparator;
		private System.Windows.Forms.ToolStripMenuItem mniExit;
		private System.Windows.Forms.SaveFileDialog saveFileDialog;
		private System.Windows.Forms.ToolStripMenuItem mniSaveAs;
	}
}

