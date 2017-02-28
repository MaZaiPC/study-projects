namespace Moreniell.TrigonometricFunctionTable.Entities
{
	public struct ColumnInfo
	{
		public string Header { get; set; }
		public TrigonometricFuncDelegate TrigonFunction { get; set; }

		public ColumnInfo(string header, TrigonometricFuncDelegate trigonFunction) : this()
		{
			Header = header;
			TrigonFunction = trigonFunction;
		}
	}
}