RenSharp currently supports .NET 4.7.2, CPU architecture x86.

To set your target architecture to x86 do the following for a newly created .NET class library:
	- Click the 'Solution Platforms' dropdown-list (where it says 'Any CPU')
	- Click 'Configuration Manager...'
	- Click the 'Platform' dropdown-list on the row where 'Project' is the name of your project
	- Click '<New...>'
	- Select 'x86' in the 'New platform:' dropdown-list and select 'Any CPU' in the 'Copy settings from:' dropdown-list. Leave 'Create new solution platform' checked
	- Click 'OK'
	- Click '<Edit...>' in the 'Active solution platform:' dropdown-list
	- Select 'Any CPU' and click 'Remove'
	- Click 'Close'
	- Click the 'Platform' dropdown-list on the row where 'Project' is the name of your project
	- Click '<Edit...>'
	- Select 'Any CPU' and click 'Remove'
	- Click 'Close'