using System.Windows.Forms;

namespace MaZaiPC.TrafficViolationManager
{
	partial class MainForm
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
			this.menuStrip = new System.Windows.Forms.MenuStrip();
			this.mniFileCategory = new System.Windows.Forms.ToolStripMenuItem();
			this.mniNewFile = new System.Windows.Forms.ToolStripMenuItem();
			this.mniOpenFile = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
			this.mniCloseFile = new System.Windows.Forms.ToolStripMenuItem();
			this.mniSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.mniSaveFile = new System.Windows.Forms.ToolStripMenuItem();
			this.mniSaveFileAs = new System.Windows.Forms.ToolStripMenuItem();
			this.mniSeparator2 = new System.Windows.Forms.ToolStripSeparator();
			this.mniExit = new System.Windows.Forms.ToolStripMenuItem();
			this.mniReferenceCategory = new System.Windows.Forms.ToolStripMenuItem();
			this.mniHelp = new System.Windows.Forms.ToolStripMenuItem();
			this.mniAbout = new System.Windows.Forms.ToolStripMenuItem();
			this.bindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
			this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
			this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
			this.btnNewFile = new System.Windows.Forms.ToolStripButton();
			this.btnOpenFile = new System.Windows.Forms.ToolStripButton();
			this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
			this.btnSaveFile = new System.Windows.Forms.ToolStripButton();
			this.btnSaveFileAs = new System.Windows.Forms.ToolStripButton();
			this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
			this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
			this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
			this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
			this.statusStrip = new System.Windows.Forms.StatusStrip();
			this.sbLeft = new System.Windows.Forms.ToolStripStatusLabel();
			this.sbRight = new System.Windows.Forms.ToolStripStatusLabel();
			this.tabControl = new System.Windows.Forms.TabControl();
			this.tabPage1 = new System.Windows.Forms.TabPage();
			this.gridViolations = new System.Windows.Forms.DataGridView();
			this.tabPage2 = new System.Windows.Forms.TabPage();
			this.gridHistory = new System.Windows.Forms.DataGridView();
			this.historySubjectTooltip = new System.Windows.Forms.Label();
			this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
			this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
			this.columnId1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.columnFamIO = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.columnCarModel1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.columnLastViolation = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.columnDate1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.columnPenaltySum1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.columnPaid1 = new System.Windows.Forms.DataGridViewCheckBoxColumn();
			this.columnTotalSumOfPaidPenalties = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.violatorBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.columnId2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.columnCarModel2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.columnViolationType = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.columnDate2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.columnPenaltySum2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.columnPaid2 = new System.Windows.Forms.DataGridViewCheckBoxColumn();
			this.violationBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.menuStrip.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.bindingNavigator)).BeginInit();
			this.bindingNavigator.SuspendLayout();
			this.statusStrip.SuspendLayout();
			this.tabControl.SuspendLayout();
			this.tabPage1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.gridViolations)).BeginInit();
			this.tabPage2.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.gridHistory)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.violatorBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.violationBindingSource)).BeginInit();
			this.SuspendLayout();
			// 
			// menuStrip
			// 
			this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniFileCategory,
            this.mniReferenceCategory});
			this.menuStrip.Location = new System.Drawing.Point(0, 0);
			this.menuStrip.Name = "menuStrip";
			this.menuStrip.Size = new System.Drawing.Size(934, 24);
			this.menuStrip.TabIndex = 0;
			this.menuStrip.Text = "menuStrip1";
			// 
			// mniFileCategory
			// 
			this.mniFileCategory.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniNewFile,
            this.mniOpenFile,
            this.toolStripMenuItem1,
            this.mniCloseFile,
            this.mniSeparator1,
            this.mniSaveFile,
            this.mniSaveFileAs,
            this.mniSeparator2,
            this.mniExit});
			this.mniFileCategory.Name = "mniFileCategory";
			this.mniFileCategory.Size = new System.Drawing.Size(48, 20);
			this.mniFileCategory.Text = "Файл";
			// 
			// mniNewFile
			// 
			this.mniNewFile.Name = "mniNewFile";
			this.mniNewFile.Size = new System.Drawing.Size(162, 22);
			this.mniNewFile.Text = "Создать...";
			this.mniNewFile.ToolTipText = "Создать новую таблицу";
			this.mniNewFile.Click += new System.EventHandler(this.newFile_Click);
			this.mniNewFile.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.mniNewFile.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// mniOpenFile
			// 
			this.mniOpenFile.Name = "mniOpenFile";
			this.mniOpenFile.Size = new System.Drawing.Size(162, 22);
			this.mniOpenFile.Text = "Открыть...";
			this.mniOpenFile.ToolTipText = "Открыть файл с данными о нарушителях";
			this.mniOpenFile.Click += new System.EventHandler(this.openFile_Click);
			this.mniOpenFile.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.mniOpenFile.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// toolStripMenuItem1
			// 
			this.toolStripMenuItem1.Name = "toolStripMenuItem1";
			this.toolStripMenuItem1.Size = new System.Drawing.Size(159, 6);
			// 
			// mniCloseFile
			// 
			this.mniCloseFile.Name = "mniCloseFile";
			this.mniCloseFile.Size = new System.Drawing.Size(162, 22);
			this.mniCloseFile.Text = "Закрыть";
			this.mniCloseFile.ToolTipText = "Закрыть таблицу";
			this.mniCloseFile.Click += new System.EventHandler(this.newFile_Click);
			this.mniCloseFile.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.mniCloseFile.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// mniSeparator1
			// 
			this.mniSeparator1.Name = "mniSeparator1";
			this.mniSeparator1.Size = new System.Drawing.Size(159, 6);
			// 
			// mniSaveFile
			// 
			this.mniSaveFile.Enabled = false;
			this.mniSaveFile.Name = "mniSaveFile";
			this.mniSaveFile.Size = new System.Drawing.Size(162, 22);
			this.mniSaveFile.Text = "Сохранить";
			this.mniSaveFile.ToolTipText = "Сохранить таблицу в файл";
			this.mniSaveFile.Click += new System.EventHandler(this.saveFile_Click);
			this.mniSaveFile.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.mniSaveFile.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// mniSaveFileAs
			// 
			this.mniSaveFileAs.Enabled = false;
			this.mniSaveFileAs.Name = "mniSaveFileAs";
			this.mniSaveFileAs.Size = new System.Drawing.Size(162, 22);
			this.mniSaveFileAs.Text = "Сохранить как...";
			this.mniSaveFileAs.ToolTipText = "Сохранить таблицу в указанный файл";
			this.mniSaveFileAs.Click += new System.EventHandler(this.saveFileAs_Click);
			this.mniSaveFileAs.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.mniSaveFileAs.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// mniSeparator2
			// 
			this.mniSeparator2.Name = "mniSeparator2";
			this.mniSeparator2.Size = new System.Drawing.Size(159, 6);
			// 
			// mniExit
			// 
			this.mniExit.Name = "mniExit";
			this.mniExit.Size = new System.Drawing.Size(162, 22);
			this.mniExit.Text = "Выход";
			this.mniExit.ToolTipText = "Выход из программы";
			this.mniExit.Click += new System.EventHandler(this.mniExit_Click);
			this.mniExit.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.mniExit.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// mniReferenceCategory
			// 
			this.mniReferenceCategory.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniHelp,
            this.mniAbout});
			this.mniReferenceCategory.Name = "mniReferenceCategory";
			this.mniReferenceCategory.Size = new System.Drawing.Size(65, 20);
			this.mniReferenceCategory.Text = "Справка";
			// 
			// mniHelp
			// 
			this.mniHelp.Name = "mniHelp";
			this.mniHelp.Size = new System.Drawing.Size(158, 22);
			this.mniHelp.Text = "Помощь...";
			this.mniHelp.ToolTipText = "Инструкция по использованию программы";
			this.mniHelp.Click += new System.EventHandler(this.mniHelp_Click);
			this.mniHelp.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.mniHelp.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// mniAbout
			// 
			this.mniAbout.Name = "mniAbout";
			this.mniAbout.Size = new System.Drawing.Size(158, 22);
			this.mniAbout.Text = "О программе...";
			this.mniAbout.ToolTipText = "О программе Traffic Violation Manager...";
			this.mniAbout.Click += new System.EventHandler(this.mniAbout_Click);
			this.mniAbout.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.mniAbout.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// bindingNavigator
			// 
			this.bindingNavigator.AddNewItem = null;
			this.bindingNavigator.BindingSource = this.violatorBindingSource;
			this.bindingNavigator.CountItem = this.bindingNavigatorCountItem;
			this.bindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
			this.bindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnNewFile,
            this.btnOpenFile,
            this.toolStripSeparator3,
            this.btnSaveFile,
            this.btnSaveFileAs,
            this.toolStripSeparator2,
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2,
            this.bindingNavigatorDeleteItem});
			this.bindingNavigator.Location = new System.Drawing.Point(0, 24);
			this.bindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
			this.bindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
			this.bindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
			this.bindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
			this.bindingNavigator.Name = "bindingNavigator";
			this.bindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
			this.bindingNavigator.Size = new System.Drawing.Size(934, 25);
			this.bindingNavigator.TabIndex = 2;
			this.bindingNavigator.Text = "bindingNavigator1";
			// 
			// bindingNavigatorCountItem
			// 
			this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
			this.bindingNavigatorCountItem.Size = new System.Drawing.Size(43, 22);
			this.bindingNavigatorCountItem.Text = "для {0}";
			this.bindingNavigatorCountItem.ToolTipText = "Общее число элементов";
			// 
			// bindingNavigatorDeleteItem
			// 
			this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorDeleteItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorDeleteItem.Image")));
			this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
			this.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorDeleteItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorDeleteItem.Text = "Удалить";
			this.bindingNavigatorDeleteItem.ToolTipText = "Удалить строку из таблицы";
			this.bindingNavigatorDeleteItem.Click += new System.EventHandler(this.bindingNavigatorDeleteItem_Click);
			this.bindingNavigatorDeleteItem.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.bindingNavigatorDeleteItem.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// btnNewFile
			// 
			this.btnNewFile.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.btnNewFile.Image = global::MaZaiPC.TrafficViolationManager.Properties.Resources._new;
			this.btnNewFile.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.btnNewFile.Margin = new System.Windows.Forms.Padding(3, 1, 0, 2);
			this.btnNewFile.Name = "btnNewFile";
			this.btnNewFile.Size = new System.Drawing.Size(23, 22);
			this.btnNewFile.Text = "btnNewFile";
			this.btnNewFile.ToolTipText = "Создать новую таблицу";
			this.btnNewFile.Click += new System.EventHandler(this.newFile_Click);
			this.btnNewFile.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.btnNewFile.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// btnOpenFile
			// 
			this.btnOpenFile.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.btnOpenFile.Image = global::MaZaiPC.TrafficViolationManager.Properties.Resources.open;
			this.btnOpenFile.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.btnOpenFile.Name = "btnOpenFile";
			this.btnOpenFile.Size = new System.Drawing.Size(23, 22);
			this.btnOpenFile.Text = "btnOpenFile";
			this.btnOpenFile.ToolTipText = "Открыть файл с данными о нарушителях";
			this.btnOpenFile.Click += new System.EventHandler(this.openFile_Click);
			this.btnOpenFile.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.btnOpenFile.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// toolStripSeparator3
			// 
			this.toolStripSeparator3.Name = "toolStripSeparator3";
			this.toolStripSeparator3.Size = new System.Drawing.Size(6, 25);
			// 
			// btnSaveFile
			// 
			this.btnSaveFile.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.btnSaveFile.Enabled = false;
			this.btnSaveFile.Image = global::MaZaiPC.TrafficViolationManager.Properties.Resources.save;
			this.btnSaveFile.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.btnSaveFile.Name = "btnSaveFile";
			this.btnSaveFile.Size = new System.Drawing.Size(23, 22);
			this.btnSaveFile.Text = "btnSaveFile";
			this.btnSaveFile.ToolTipText = "Сохранить таблицу в файл";
			this.btnSaveFile.Click += new System.EventHandler(this.saveFile_Click);
			this.btnSaveFile.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.btnSaveFile.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// btnSaveFileAs
			// 
			this.btnSaveFileAs.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.btnSaveFileAs.Enabled = false;
			this.btnSaveFileAs.Image = global::MaZaiPC.TrafficViolationManager.Properties.Resources.save_as;
			this.btnSaveFileAs.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.btnSaveFileAs.Name = "btnSaveFileAs";
			this.btnSaveFileAs.Size = new System.Drawing.Size(23, 22);
			this.btnSaveFileAs.Text = "btnSaveFileAs";
			this.btnSaveFileAs.ToolTipText = "Сохранить таблицу в указанный файл";
			this.btnSaveFileAs.Click += new System.EventHandler(this.saveFileAs_Click);
			this.btnSaveFileAs.MouseEnter += new System.EventHandler(this.toolStripItem_MouseEnter);
			this.btnSaveFileAs.MouseLeave += new System.EventHandler(this.toolStripItem_MouseLeave);
			// 
			// toolStripSeparator2
			// 
			this.toolStripSeparator2.Name = "toolStripSeparator2";
			this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
			// 
			// bindingNavigatorMoveFirstItem
			// 
			this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
			this.bindingNavigatorMoveFirstItem.Margin = new System.Windows.Forms.Padding(2, 1, 0, 2);
			this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
			this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorMoveFirstItem.Text = "Переместить в начало";
			// 
			// bindingNavigatorMovePreviousItem
			// 
			this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
			this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
			this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorMovePreviousItem.Text = "Переместить назад";
			// 
			// bindingNavigatorSeparator
			// 
			this.bindingNavigatorSeparator.Margin = new System.Windows.Forms.Padding(1, 0, 2, 0);
			this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
			this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 25);
			// 
			// bindingNavigatorPositionItem
			// 
			this.bindingNavigatorPositionItem.AccessibleName = "Положение";
			this.bindingNavigatorPositionItem.AutoSize = false;
			this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
			this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(47, 23);
			this.bindingNavigatorPositionItem.Text = "0";
			this.bindingNavigatorPositionItem.ToolTipText = "Текущее положение";
			// 
			// bindingNavigatorSeparator1
			// 
			this.bindingNavigatorSeparator1.Margin = new System.Windows.Forms.Padding(0, 0, 4, 0);
			this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator1";
			this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 25);
			// 
			// bindingNavigatorMoveNextItem
			// 
			this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
			this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
			this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorMoveNextItem.Text = "Переместить вперед";
			// 
			// bindingNavigatorMoveLastItem
			// 
			this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
			this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
			this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorMoveLastItem.Text = "Переместить в конец";
			// 
			// bindingNavigatorSeparator2
			// 
			this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator2";
			this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 25);
			// 
			// statusStrip
			// 
			this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.sbLeft,
            this.sbRight});
			this.statusStrip.Location = new System.Drawing.Point(0, 419);
			this.statusStrip.Name = "statusStrip";
			this.statusStrip.Size = new System.Drawing.Size(934, 22);
			this.statusStrip.TabIndex = 3;
			this.statusStrip.Text = "statusStrip1";
			// 
			// sbLeft
			// 
			this.sbLeft.AutoSize = false;
			this.sbLeft.Name = "sbLeft";
			this.sbLeft.Size = new System.Drawing.Size(250, 17);
			this.sbLeft.Text = "Готово";
			this.sbLeft.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// sbRight
			// 
			this.sbRight.Name = "sbRight";
			this.sbRight.Size = new System.Drawing.Size(669, 17);
			this.sbRight.Spring = true;
			this.sbRight.TextDirection = System.Windows.Forms.ToolStripTextDirection.Horizontal;
			// 
			// tabControl
			// 
			this.tabControl.Controls.Add(this.tabPage1);
			this.tabControl.Controls.Add(this.tabPage2);
			this.tabControl.Dock = System.Windows.Forms.DockStyle.Fill;
			this.tabControl.Location = new System.Drawing.Point(0, 49);
			this.tabControl.Name = "tabControl";
			this.tabControl.SelectedIndex = 0;
			this.tabControl.Size = new System.Drawing.Size(934, 370);
			this.tabControl.TabIndex = 4;
			// 
			// tabPage1
			// 
			this.tabPage1.Controls.Add(this.gridViolations);
			this.tabPage1.Location = new System.Drawing.Point(4, 22);
			this.tabPage1.Name = "tabPage1";
			this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
			this.tabPage1.Size = new System.Drawing.Size(926, 344);
			this.tabPage1.TabIndex = 0;
			this.tabPage1.Text = "Нарушители";
			this.tabPage1.UseVisualStyleBackColor = true;
			// 
			// gridViolations
			// 
			this.gridViolations.AutoGenerateColumns = false;
			this.gridViolations.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.gridViolations.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.columnId1,
            this.columnFamIO,
            this.columnCarModel1,
            this.columnLastViolation,
            this.columnDate1,
            this.columnPenaltySum1,
            this.columnPaid1,
            this.columnTotalSumOfPaidPenalties});
			this.gridViolations.DataSource = this.violatorBindingSource;
			this.gridViolations.Dock = System.Windows.Forms.DockStyle.Fill;
			this.gridViolations.Location = new System.Drawing.Point(3, 3);
			this.gridViolations.Name = "gridViolations";
			this.gridViolations.Size = new System.Drawing.Size(920, 338);
			this.gridViolations.TabIndex = 0;
			this.gridViolations.CellValueChanged += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_CellValueChanged);
			this.gridViolations.RowsAdded += new System.Windows.Forms.DataGridViewRowsAddedEventHandler(this.dataGridView_RowsAdded);
			this.gridViolations.RowValidating += new System.Windows.Forms.DataGridViewCellCancelEventHandler(this.dataGridView_RowValidating);
			this.gridViolations.SelectionChanged += new System.EventHandler(this.gridViolations_SelectionChanged);
			// 
			// tabPage2
			// 
			this.tabPage2.Controls.Add(this.gridHistory);
			this.tabPage2.Controls.Add(this.historySubjectTooltip);
			this.tabPage2.Location = new System.Drawing.Point(4, 22);
			this.tabPage2.Name = "tabPage2";
			this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
			this.tabPage2.Size = new System.Drawing.Size(926, 344);
			this.tabPage2.TabIndex = 1;
			this.tabPage2.Text = "История штрафов";
			this.tabPage2.UseVisualStyleBackColor = true;
			// 
			// gridHistory
			// 
			this.gridHistory.AutoGenerateColumns = false;
			this.gridHistory.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.gridHistory.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.columnId2,
            this.columnCarModel2,
            this.columnViolationType,
            this.columnDate2,
            this.columnPenaltySum2,
            this.columnPaid2});
			this.gridHistory.DataSource = this.violationBindingSource;
			this.gridHistory.Dock = System.Windows.Forms.DockStyle.Fill;
			this.gridHistory.Location = new System.Drawing.Point(3, 24);
			this.gridHistory.Name = "gridHistory";
			this.gridHistory.Size = new System.Drawing.Size(920, 317);
			this.gridHistory.TabIndex = 0;
			this.gridHistory.CellValueChanged += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_CellValueChanged);
			this.gridHistory.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.gridHistory_RowEnter);
			this.gridHistory.RowsAdded += new System.Windows.Forms.DataGridViewRowsAddedEventHandler(this.dataGridView_RowsAdded);
			this.gridHistory.RowValidating += new System.Windows.Forms.DataGridViewCellCancelEventHandler(this.dataGridView_RowValidating);
			// 
			// historySubjectTooltip
			// 
			this.historySubjectTooltip.BackColor = System.Drawing.Color.Teal;
			this.historySubjectTooltip.Dock = System.Windows.Forms.DockStyle.Top;
			this.historySubjectTooltip.Font = new System.Drawing.Font("Times New Roman", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.historySubjectTooltip.ForeColor = System.Drawing.Color.White;
			this.historySubjectTooltip.Location = new System.Drawing.Point(3, 3);
			this.historySubjectTooltip.Name = "historySubjectTooltip";
			this.historySubjectTooltip.Size = new System.Drawing.Size(920, 21);
			this.historySubjectTooltip.TabIndex = 1;
			this.historySubjectTooltip.Text = "Нарушитель не выбран.";
			this.historySubjectTooltip.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// saveFileDialog
			// 
			this.saveFileDialog.DefaultExt = "violators";
			this.saveFileDialog.FileName = "Unnamed-DS.violators";
			this.saveFileDialog.Filter = "Данные о нарушителях ПДД (*.violators)|*.violators|XML datastore (*.xml)|*.xml";
			// 
			// openFileDialog
			// 
			this.openFileDialog.DefaultExt = "violators";
			this.openFileDialog.Filter = "Данные о нарушителях ПДД (*.violators)|*.violators|XML datastore (*.xml)|*.xml";
			// 
			// columnId1
			// 
			this.columnId1.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.DisplayedCells;
			this.columnId1.DataPropertyName = "Id";
			this.columnId1.HeaderText = "ID";
			this.columnId1.Name = "columnId1";
			this.columnId1.ReadOnly = true;
			this.columnId1.Width = 43;
			// 
			// columnFamIO
			// 
			this.columnFamIO.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnFamIO.DataPropertyName = "FamIO";
			this.columnFamIO.HeaderText = "Фамилия И.О.";
			this.columnFamIO.MinimumWidth = 113;
			this.columnFamIO.Name = "columnFamIO";
			// 
			// columnCarModel1
			// 
			this.columnCarModel1.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnCarModel1.DataPropertyName = "CarModel";
			this.columnCarModel1.HeaderText = "Марка автомобиля";
			this.columnCarModel1.Name = "columnCarModel1";
			// 
			// columnLastViolation
			// 
			this.columnLastViolation.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnLastViolation.DataPropertyName = "LastViolation";
			this.columnLastViolation.DropDownWidth = 350;
			this.columnLastViolation.HeaderText = "Последнее нарушение";
			this.columnLastViolation.Items.AddRange(new object[] {
            "Разговор по мобильному телефону за рулем",
            "Движение по автомагистрали на маленькой скорости",
            "Не включил(а) поворотник",
            "Управление автомобилем без ближнего света",
            "Несоблюдение дистанции на дороге",
            "Внезапное изменение траектории движения на дороге",
            "Не уступил(а) дорогу велосипедисту",
            "Обгон тихоходного транспортного средства",
            "Езда по разделительной полосе",
            "Парковка в запрещенном месте",
            "Не соблюдение дорожных знаков"});
			this.columnLastViolation.MinimumWidth = 200;
			this.columnLastViolation.Name = "columnLastViolation";
			this.columnLastViolation.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.columnLastViolation.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// columnDate1
			// 
			this.columnDate1.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnDate1.DataPropertyName = "Date";
			this.columnDate1.HeaderText = "Дата нарушения";
			this.columnDate1.Name = "columnDate1";
			// 
			// columnPenaltySum1
			// 
			this.columnPenaltySum1.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnPenaltySum1.DataPropertyName = "PenaltySum";
			this.columnPenaltySum1.HeaderText = "Сумма штрафа";
			this.columnPenaltySum1.Name = "columnPenaltySum1";
			// 
			// columnPaid1
			// 
			this.columnPaid1.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
			this.columnPaid1.DataPropertyName = "Paid";
			this.columnPaid1.HeaderText = "Оплачено";
			this.columnPaid1.Name = "columnPaid1";
			this.columnPaid1.Width = 62;
			// 
			// columnTotalSumOfPaidPenalties
			// 
			this.columnTotalSumOfPaidPenalties.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnTotalSumOfPaidPenalties.DataPropertyName = "TotalSumOfPaidPenalties";
			this.columnTotalSumOfPaidPenalties.HeaderText = "Всего оплачено";
			this.columnTotalSumOfPaidPenalties.Name = "columnTotalSumOfPaidPenalties";
			this.columnTotalSumOfPaidPenalties.ReadOnly = true;
			// 
			// violatorBindingSource
			// 
			this.violatorBindingSource.DataSource = typeof(MaZaiPC.TrafficViolationManager.Model.Violator);
			// 
			// columnId2
			// 
			this.columnId2.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
			this.columnId2.DataPropertyName = "Id";
			this.columnId2.HeaderText = "ID";
			this.columnId2.Name = "columnId2";
			this.columnId2.ReadOnly = true;
			this.columnId2.Width = 43;
			// 
			// columnCarModel2
			// 
			this.columnCarModel2.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnCarModel2.DataPropertyName = "CarModel";
			this.columnCarModel2.HeaderText = "Марка автомобиля";
			this.columnCarModel2.Name = "columnCarModel2";
			// 
			// columnViolationType
			// 
			this.columnViolationType.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnViolationType.DataPropertyName = "ViolationType";
			this.columnViolationType.DropDownWidth = 350;
			this.columnViolationType.HeaderText = "Вид нарушения";
			this.columnViolationType.Items.AddRange(new object[] {
            "Разговор по мобильному телефону за рулем",
            "Движение по автомагистрали на маленькой скорости",
            "Не включил(а) поворотник",
            "Управление автомобилем без ближнего света",
            "Несоблюдение дистанции на дороге",
            "Внезапное изменение траектории движения на дороге",
            "Не уступил(а) дорогу велосипедисту",
            "Обгон тихоходного транспортного средства",
            "Езда по разделительной полосе",
            "Парковка в запрещенном месте",
            "Не соблюдение дорожных знаков"});
			this.columnViolationType.MinimumWidth = 200;
			this.columnViolationType.Name = "columnViolationType";
			this.columnViolationType.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.columnViolationType.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// columnDate2
			// 
			this.columnDate2.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnDate2.DataPropertyName = "Date";
			this.columnDate2.HeaderText = "Дата нарушения";
			this.columnDate2.Name = "columnDate2";
			// 
			// columnPenaltySum2
			// 
			this.columnPenaltySum2.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.columnPenaltySum2.DataPropertyName = "PenaltySum";
			this.columnPenaltySum2.HeaderText = "Сумма штрафа";
			this.columnPenaltySum2.Name = "columnPenaltySum2";
			// 
			// columnPaid2
			// 
			this.columnPaid2.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
			this.columnPaid2.DataPropertyName = "Paid";
			this.columnPaid2.HeaderText = "Оплачено";
			this.columnPaid2.Name = "columnPaid2";
			this.columnPaid2.Width = 62;
			// 
			// violationBindingSource
			// 
			this.violationBindingSource.DataSource = typeof(MaZaiPC.TrafficViolationManager.Model.Violation);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(934, 441);
			this.Controls.Add(this.tabControl);
			this.Controls.Add(this.statusStrip);
			this.Controls.Add(this.bindingNavigator);
			this.Controls.Add(this.menuStrip);
			this.MainMenuStrip = this.menuStrip;
			this.MinimumSize = new System.Drawing.Size(950, 480);
			this.Name = "MainForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Данные о нарушителях ПДД";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
			this.menuStrip.ResumeLayout(false);
			this.menuStrip.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.bindingNavigator)).EndInit();
			this.bindingNavigator.ResumeLayout(false);
			this.bindingNavigator.PerformLayout();
			this.statusStrip.ResumeLayout(false);
			this.statusStrip.PerformLayout();
			this.tabControl.ResumeLayout(false);
			this.tabPage1.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.gridViolations)).EndInit();
			this.tabPage2.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.gridHistory)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.violatorBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.violationBindingSource)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.MenuStrip menuStrip;
		private System.Windows.Forms.ToolStripMenuItem mniFileCategory;
		private System.Windows.Forms.ToolStripMenuItem mniNewFile;
		private System.Windows.Forms.ToolStripMenuItem mniOpenFile;
		private System.Windows.Forms.ToolStripSeparator mniSeparator1;
		private System.Windows.Forms.ToolStripMenuItem mniSaveFile;
		private System.Windows.Forms.ToolStripMenuItem mniSaveFileAs;
		private System.Windows.Forms.ToolStripSeparator mniSeparator2;
		private System.Windows.Forms.ToolStripMenuItem mniExit;
		private System.Windows.Forms.ToolStripMenuItem mniReferenceCategory;
		private System.Windows.Forms.ToolStripMenuItem mniAbout;
		private System.Windows.Forms.BindingNavigator bindingNavigator;
		private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
		private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
		private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
		private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
		private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
		private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
		private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
		private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
		private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
		private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;
		private System.Windows.Forms.StatusStrip statusStrip;
		private System.Windows.Forms.TabControl tabControl;
		private System.Windows.Forms.TabPage tabPage1;
		private System.Windows.Forms.TabPage tabPage2;
		private System.Windows.Forms.DataGridView gridViolations;
		private System.Windows.Forms.DataGridView gridHistory;
		private System.Windows.Forms.ToolStripButton btnNewFile;
		private System.Windows.Forms.ToolStripButton btnOpenFile;
		private System.Windows.Forms.ToolStripButton btnSaveFile;
		private System.Windows.Forms.ToolStripButton btnSaveFileAs;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
		private System.Windows.Forms.BindingSource violatorBindingSource;
		private System.Windows.Forms.BindingSource violationBindingSource;
		private System.Windows.Forms.Label historySubjectTooltip;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnId1;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnFamIO;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnCarModel1;
		private System.Windows.Forms.DataGridViewComboBoxColumn columnLastViolation;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnDate1;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnPenaltySum1;
		private System.Windows.Forms.DataGridViewCheckBoxColumn columnPaid1;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnTotalSumOfPaidPenalties;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnId2;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnCarModel2;
		private System.Windows.Forms.DataGridViewComboBoxColumn columnViolationType;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnDate2;
		private System.Windows.Forms.DataGridViewTextBoxColumn columnPenaltySum2;
		private System.Windows.Forms.DataGridViewCheckBoxColumn columnPaid2;
		private System.Windows.Forms.SaveFileDialog saveFileDialog;
		private System.Windows.Forms.OpenFileDialog openFileDialog;
		private ToolStripSeparator toolStripMenuItem1;
		private ToolStripMenuItem mniCloseFile;
		private ToolStripMenuItem mniHelp;
		private ToolStripStatusLabel sbLeft;
		private ToolStripStatusLabel sbRight;
	}
}