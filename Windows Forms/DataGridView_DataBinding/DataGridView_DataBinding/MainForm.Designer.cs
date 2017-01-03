namespace DataGridView_DataBinding
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
			this.components = new System.ComponentModel.Container();
			System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
			System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
			this.dgvMain = new System.Windows.Forms.DataGridView();
			this.dgcId = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dgcSurname = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dgcGender = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.dgcBirthDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dgcCourse = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dgcGroup = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.dgcScholarship = new System.Windows.Forms.DataGridViewCheckBoxColumn();
			this.bnsDataGrid = new System.Windows.Forms.BindingSource(this.components);
			this.mnuMain = new System.Windows.Forms.MenuStrip();
			this.mniFile = new System.Windows.Forms.ToolStripMenuItem();
			this.mniNew = new System.Windows.Forms.ToolStripMenuItem();
			this.mniLoad = new System.Windows.Forms.ToolStripMenuItem();
			this.mniSave = new System.Windows.Forms.ToolStripMenuItem();
			this.mniSep1 = new System.Windows.Forms.ToolStripSeparator();
			this.mniExit = new System.Windows.Forms.ToolStripMenuItem();
			this.statusStrip1 = new System.Windows.Forms.StatusStrip();
			this.tslMain = new System.Windows.Forms.ToolStripStatusLabel();
			this.toolStrip1 = new System.Windows.Forms.ToolStrip();
			this.sfdStudents = new System.Windows.Forms.SaveFileDialog();
			this.ofdStudents = new System.Windows.Forms.OpenFileDialog();
			this.bnvMain = new System.Windows.Forms.BindingNavigator(this.components);
			this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
			this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
			this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
			this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
			((System.ComponentModel.ISupportInitialize)(this.dgvMain)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.bnsDataGrid)).BeginInit();
			this.mnuMain.SuspendLayout();
			this.statusStrip1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.bnvMain)).BeginInit();
			this.bnvMain.SuspendLayout();
			this.SuspendLayout();
			// 
			// dgvMain
			// 
			this.dgvMain.AllowUserToResizeRows = false;
			this.dgvMain.AutoGenerateColumns = false;
			this.dgvMain.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
			dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
			dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
			dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
			dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
			dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
			dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
			this.dgvMain.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this.dgvMain.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dgvMain.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dgcId,
            this.dgcSurname,
            this.dgcGender,
            this.dgcBirthDate,
            this.dgcCourse,
            this.dgcGroup,
            this.dgcScholarship});
			this.dgvMain.DataSource = this.bnsDataGrid;
			this.dgvMain.Dock = System.Windows.Forms.DockStyle.Fill;
			this.dgvMain.Location = new System.Drawing.Point(0, 74);
			this.dgvMain.Name = "dgvMain";
			this.dgvMain.Size = new System.Drawing.Size(884, 345);
			this.dgvMain.TabIndex = 0;
			this.dgvMain.CellValidating += new System.Windows.Forms.DataGridViewCellValidatingEventHandler(this.dgvMain_CellValidating);
			this.dgvMain.CurrentCellDirtyStateChanged += new System.EventHandler(this.dgvMain_CurrentCellDirtyStateChanged);
			this.dgvMain.RowValidating += new System.Windows.Forms.DataGridViewCellCancelEventHandler(this.dgvMain_RowValidating);
			// 
			// dgcId
			// 
			this.dgcId.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.dgcId.DataPropertyName = "Id";
			dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.GrayText;
			dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.GrayText;
			this.dgcId.DefaultCellStyle = dataGridViewCellStyle2;
			this.dgcId.HeaderText = "Номер";
			this.dgcId.Name = "dgcId";
			this.dgcId.ReadOnly = true;
			this.dgcId.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			// 
			// dgcSurname
			// 
			this.dgcSurname.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.dgcSurname.DataPropertyName = "Surname";
			this.dgcSurname.FillWeight = 300F;
			this.dgcSurname.HeaderText = "Фамилия И.О.";
			this.dgcSurname.Name = "dgcSurname";
			// 
			// dgcGender
			// 
			this.dgcGender.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.dgcGender.DataPropertyName = "Gender";
			this.dgcGender.FillWeight = 70F;
			this.dgcGender.HeaderText = "Пол";
			this.dgcGender.Items.AddRange(new object[] {
            "М",
            "Ж"});
			this.dgcGender.Name = "dgcGender";
			this.dgcGender.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dgcGender.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// dgcBirthDate
			// 
			this.dgcBirthDate.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.dgcBirthDate.DataPropertyName = "BirthDate";
			this.dgcBirthDate.FillWeight = 150F;
			this.dgcBirthDate.HeaderText = "Дата рождения";
			this.dgcBirthDate.Name = "dgcBirthDate";
			// 
			// dgcCourse
			// 
			this.dgcCourse.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.dgcCourse.DataPropertyName = "Course";
			this.dgcCourse.FillWeight = 60F;
			this.dgcCourse.HeaderText = "Курс";
			this.dgcCourse.Name = "dgcCourse";
			this.dgcCourse.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			// 
			// dgcGroup
			// 
			this.dgcGroup.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.dgcGroup.DataPropertyName = "Group";
			this.dgcGroup.FillWeight = 110F;
			this.dgcGroup.HeaderText = "Группа";
			this.dgcGroup.Items.AddRange(new object[] {
            "ПСУ 1-27",
            "ПСД 1-29",
            "ПСУ 1-31",
            "ПСД 1-31",
            "ЕКО 15-П91",
            "ЕКО 14-П81",
            "ЕКО 15-Д91",
            "ЕКО 15-А91",
            "ЕКО 14-Д81",
            "ЕКО 14-А81",
            ""});
			this.dgcGroup.Name = "dgcGroup";
			this.dgcGroup.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dgcGroup.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// dgcScholarship
			// 
			this.dgcScholarship.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.dgcScholarship.DataPropertyName = "Scholarship";
			this.dgcScholarship.HeaderText = "Стипендия";
			this.dgcScholarship.Name = "dgcScholarship";
			// 
			// bnsDataGrid
			// 
			this.bnsDataGrid.DataSource = typeof(DataGridView_DataBinding.Student);
			// 
			// mnuMain
			// 
			this.mnuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniFile});
			this.mnuMain.Location = new System.Drawing.Point(0, 0);
			this.mnuMain.Name = "mnuMain";
			this.mnuMain.Size = new System.Drawing.Size(884, 24);
			this.mnuMain.TabIndex = 1;
			this.mnuMain.Text = "menuStrip1";
			// 
			// mniFile
			// 
			this.mniFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mniNew,
            this.mniLoad,
            this.mniSave,
            this.mniSep1,
            this.mniExit});
			this.mniFile.Name = "mniFile";
			this.mniFile.Size = new System.Drawing.Size(48, 20);
			this.mniFile.Text = "Файл";
			this.mniFile.Click += new System.EventHandler(this.mniFile_Click);
			// 
			// mniNew
			// 
			this.mniNew.Name = "mniNew";
			this.mniNew.Size = new System.Drawing.Size(152, 22);
			this.mniNew.Text = "Новый";
			this.mniNew.Click += new System.EventHandler(this.mniNew_Click);
			// 
			// mniLoad
			// 
			this.mniLoad.Name = "mniLoad";
			this.mniLoad.Size = new System.Drawing.Size(152, 22);
			this.mniLoad.Text = "Загрузить...";
			this.mniLoad.Click += new System.EventHandler(this.mniLoad_Click);
			// 
			// mniSave
			// 
			this.mniSave.Name = "mniSave";
			this.mniSave.Size = new System.Drawing.Size(152, 22);
			this.mniSave.Text = "Сохранить...";
			this.mniSave.Click += new System.EventHandler(this.mniSave_Click);
			// 
			// mniSep1
			// 
			this.mniSep1.Name = "mniSep1";
			this.mniSep1.Size = new System.Drawing.Size(149, 6);
			// 
			// mniExit
			// 
			this.mniExit.Name = "mniExit";
			this.mniExit.Size = new System.Drawing.Size(152, 22);
			this.mniExit.Text = "Выход";
			this.mniExit.Click += new System.EventHandler(this.mniExit_Click);
			// 
			// statusStrip1
			// 
			this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tslMain});
			this.statusStrip1.Location = new System.Drawing.Point(0, 419);
			this.statusStrip1.Name = "statusStrip1";
			this.statusStrip1.Size = new System.Drawing.Size(884, 22);
			this.statusStrip1.TabIndex = 2;
			this.statusStrip1.Text = "statusStrip1";
			// 
			// tslMain
			// 
			this.tslMain.Name = "tslMain";
			this.tslMain.Size = new System.Drawing.Size(45, 17);
			this.tslMain.Text = "Готово";
			// 
			// toolStrip1
			// 
			this.toolStrip1.Location = new System.Drawing.Point(0, 24);
			this.toolStrip1.Name = "toolStrip1";
			this.toolStrip1.Size = new System.Drawing.Size(884, 25);
			this.toolStrip1.TabIndex = 3;
			this.toolStrip1.Text = "toolStrip1";
			// 
			// sfdStudents
			// 
			this.sfdStudents.Filter = "Данные студентов (*.students)|*.students|Все файлы (*.*)|*.*";
			// 
			// ofdStudents
			// 
			this.ofdStudents.Filter = "Данные студентов (*.students)|*.students|Все файлы (*.*)|*.*";
			// 
			// bnvMain
			// 
			this.bnvMain.AddNewItem = this.bindingNavigatorAddNewItem;
			this.bnvMain.BindingSource = this.bnsDataGrid;
			this.bnvMain.CountItem = this.bindingNavigatorCountItem;
			this.bnvMain.DeleteItem = this.bindingNavigatorDeleteItem;
			this.bnvMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2,
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem});
			this.bnvMain.Location = new System.Drawing.Point(0, 49);
			this.bnvMain.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
			this.bnvMain.MoveLastItem = this.bindingNavigatorMoveLastItem;
			this.bnvMain.MoveNextItem = this.bindingNavigatorMoveNextItem;
			this.bnvMain.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
			this.bnvMain.Name = "bnvMain";
			this.bnvMain.PositionItem = this.bindingNavigatorPositionItem;
			this.bnvMain.Size = new System.Drawing.Size(884, 25);
			this.bnvMain.TabIndex = 4;
			this.bnvMain.Text = "bindingNavigator1";
			// 
			// bindingNavigatorAddNewItem
			// 
			this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorAddNewItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorAddNewItem.Image")));
			this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
			this.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorAddNewItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorAddNewItem.Text = "Добавить";
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
			// 
			// bindingNavigatorMoveFirstItem
			// 
			this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
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
			this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
			this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 25);
			// 
			// bindingNavigatorPositionItem
			// 
			this.bindingNavigatorPositionItem.AccessibleName = "Положение";
			this.bindingNavigatorPositionItem.AutoSize = false;
			this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
			this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 23);
			this.bindingNavigatorPositionItem.Text = "0";
			this.bindingNavigatorPositionItem.ToolTipText = "Текущее положение";
			// 
			// bindingNavigatorSeparator1
			// 
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
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(884, 441);
			this.Controls.Add(this.dgvMain);
			this.Controls.Add(this.bnvMain);
			this.Controls.Add(this.toolStrip1);
			this.Controls.Add(this.mnuMain);
			this.Controls.Add(this.statusStrip1);
			this.MainMenuStrip = this.mnuMain;
			this.Name = "MainForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Данные о студентах";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
			((System.ComponentModel.ISupportInitialize)(this.dgvMain)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.bnsDataGrid)).EndInit();
			this.mnuMain.ResumeLayout(false);
			this.mnuMain.PerformLayout();
			this.statusStrip1.ResumeLayout(false);
			this.statusStrip1.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.bnvMain)).EndInit();
			this.bnvMain.ResumeLayout(false);
			this.bnvMain.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dgvMain;
        private System.Windows.Forms.BindingSource bnsDataGrid;
        private System.Windows.Forms.MenuStrip mnuMain;
        private System.Windows.Forms.ToolStripMenuItem mniFile;
        private System.Windows.Forms.ToolStripMenuItem mniExit;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel tslMain;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripMenuItem mniNew;
        private System.Windows.Forms.ToolStripMenuItem mniLoad;
        private System.Windows.Forms.ToolStripMenuItem mniSave;
        private System.Windows.Forms.ToolStripSeparator mniSep1;
        private System.Windows.Forms.SaveFileDialog sfdStudents;
        private System.Windows.Forms.OpenFileDialog ofdStudents;
        private System.Windows.Forms.BindingNavigator bnvMain;
        private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
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
        private System.Windows.Forms.DataGridViewTextBoxColumn dgcId;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgcSurname;
        private System.Windows.Forms.DataGridViewComboBoxColumn dgcGender;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgcBirthDate;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgcCourse;
        private System.Windows.Forms.DataGridViewComboBoxColumn dgcGroup;
        private System.Windows.Forms.DataGridViewCheckBoxColumn dgcScholarship;
    }
}

