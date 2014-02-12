const string stringLongDivision(string & str,const NumericSystem system, unsigned char pch[], const unsigned long int length, const unsigned long int iterator)
{
	string quotient = "";
	if (str == "0")
	{
		return quotient="0";
	}

	//����� ������� ��������� �������
	string partDivider = "";
	unsigned long int i = 0;
	do
	{
		std::stringstream ss;
		ss << str[i];
		partDivider.append(ss.str());
		i++;
	}
	while ((strtoul(partDivider.c_str(),NULL,system) < global_base) && (i < str.length()));

	//���� ����� �� ������ ������� (��� ��� ����� �� ������� � �� ���������� ��� ����� � �� �����)
	if (strtoul(partDivider.c_str(),NULL,system) < global_base)
	{
		pch[length-1 -iterator] = static_cast<char>(strtoul(partDivider.c_str(),NULL,system));
		return quotient = "0";
	}

	//������ � partDivider � ����� � ��������� 
	quotient.append(numberToString(strtoul(partDivider.c_str(),NULL,system) / global_base));
	partDivider = numberToString(strtoul(partDivider.c_str(),NULL,system) % global_base);

	//���� ����� ��� �� ����� ���� �� ���� � ���������� ��� �� �������� ���� ������ �� ���� �� �����
	if (i == str.length())
	{
		////quotient.append(numberToString(strtoul(partDivider.c_str(),NULL,system) / global_base));
		////partDivider = numberToString(strtoul(partDivider.c_str(),NULL,system) % global_base);
		pch[length-1 -iterator] = static_cast<char>(strtoul(partDivider.c_str(),NULL,system));
		return quotient = "0";
	}

	do
	{
		unsigned long long pd = 0;
		unsigned long int k = 0;
		unsigned long int param = 0;
		bool condition;
		do
		{
			std::stringstream ss;
			ss << str[i];

			//����!!!����� ��� �� �������� �� ��������ί(��� ������ �������� ��������� int) ����ײ ����! ��� �������� ����� ������������� ������� Ĳ���� � �� � ������� �� � ��� ��в��!!!
			if (system != DEC)
			{
				partDivider = convertToBasicSystem(partDivider, system);
			}

			partDivider.append(ss.str());
			k++;//�������� ���� ������ � ���� ����� ���� � ���� ��� ����� �� ��� ���� ���������� ���� � ������
			i++;
			if (k > 1)
			{ 
				quotient.append("0");//������� ��� ����
			}
			pd = strtoul(partDivider.c_str(),NULL,system);//������ ����� pd �� ����� �������� �� ��������� �����
			condition = (pd < global_base) && (i < str.length());// seems that not(A)&&not(B) = not A||B 
		}
		while (condition);
		k = 0;
		if (i == str.length())
		{
			if (pd >= global_base)
			{
				quotient.append(numberToString (pd / global_base));
				partDivider = numberToString (pd % global_base);
			}
			pch[length-1 -iterator] = static_cast<char>(strtoul(partDivider.c_str(),NULL,system)); //we do not loose smth unless we are in 256 global_base
			return quotient; // ���� ������� optimizedBase �� ���������� ������ ������ ������������ �� � ������� (convertToBasicSystem(quotient, system))
		}
		else
		{
			quotient.append(numberToString(strtoul(partDivider.c_str(),NULL,system) / global_base));
			partDivider = numberToString(strtoul(partDivider.c_str(),NULL,system) % global_base);
		}
	}
	while (i < str.length());
	//std::cout<<partDivider<<" <- that is partDivider variable"<<'\n';
	return quotient = "-0";//If we are here that's an ERROR!!!unreal and unbelivable error
}