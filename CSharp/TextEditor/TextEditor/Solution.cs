using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Moreniell.TextFiles.Entities;

namespace Moreniell.TextFiles
{
	static class Solution
	{
		public static void RunTextEditor()
		{
			TextEditor mpEdit = new TextEditor(Path.GetTempPath() + "\\new_note.txt");

			mpEdit.Handler();
		}
	}
}
