	cin.ignore();

		for(int j=0;j<lines;j++)
		{
			getline(cin,x);
			stringstream check1(x);
			string tokens;
		    while(getline(check1, tokens, ' '))
		    {
		    	if(tokens=="import")
		    		continue;
	