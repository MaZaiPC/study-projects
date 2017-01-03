using System.Windows.Forms;

namespace MaZaiPC.TrafficViolationManager
{
	public partial class LauncherForm : Form
	{
		public LauncherForm()
		{
			TopMost = true;
			InitializeComponent();
		}
		
		private void btnRunApp_Click(object sender, System.EventArgs e)
		{
			Visible = false;
			new MainForm().ShowDialog();
			Application.Exit();
		}

		private void btnHelp_Click(object sender, System.EventArgs e)
		{
			// TODO: Сделать форму Helper-а.
			MessageBox.Show("Пока не реализовано.", "Увы :(", MessageBoxButtons.OK, MessageBoxIcon.Warning);
		}

		private void btnAbout_Click(object sender, System.EventArgs e)
		{
			TopMost = false;
			new AboutForm().ShowDialog();
			TopMost = true;
		}

		private void btnExit_Click(object sender, System.EventArgs e)
		{
			Application.Exit();
		}
	}
}
