using System.Windows.Forms;

namespace Moreniell.CaseManager.WindowsForms
{
	public partial class MainForm : Form
	{
		private readonly WorkerForm _workerForm;
		private readonly HelperForm _helperForm;
		private readonly AboutForm _aboutForm;
		
		public MainForm()
		{
			InitializeComponent();
			_helperForm =  new HelperForm();
			_workerForm = new WorkerForm(_helperForm);
			_aboutForm  =  new AboutForm();

			btnWorker.Click += (sender, e) => _workerForm.ShowDialog();
			btnHelp  .Click += (sender, e) => _helperForm.ShowDialog();
			btnAbout .Click += (sender, e) => _aboutForm.ShowDialog();
			btnExit  .Click += (sender, e) => Application.Exit();
		}
	}
}
