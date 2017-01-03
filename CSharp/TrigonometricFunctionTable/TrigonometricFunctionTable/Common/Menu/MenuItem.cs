namespace MaZaiPC.TrigonometricFunctionTable.Common.Menu
{
	struct MenuItem
	{
		/// <summary> Название пункта меню. </summary>
		public string Name { get; set; }
		
		/// <summary> Подсказка для пункта. </summary>
		public string Tooltip { get; set; }

		/// <summary> Можно ли выбрать этот пункт. </summary>
		public bool Active { get; set; }
		
		public MenuItem(string name, string tooltip = "", bool active = true)
		{
			Name = name;
			Tooltip = tooltip.Replace("\n", "\n   ");
			Active = active;
		}
	}
}