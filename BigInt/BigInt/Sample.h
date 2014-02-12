const string stringLongDivision(string & str,const NumericSystem system, unsigned char pch[], const unsigned long int length, const unsigned long int iterator)
{
	string quotient = "";
	if (str == "0")
	{
		return quotient="0";
	}

	//пошук першого неповного дільника
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

	//якшо число на стільки коротке (хоч для таких ця функція і не призначина але тестю і на таких)
	if (strtoul(partDivider.c_str(),NULL,system) < global_base)
	{
		pch[length-1 -iterator] = static_cast<char>(strtoul(partDivider.c_str(),NULL,system));
		return quotient = "0";
	}

	//остачу в partDivider і цифру в результат 
	quotient.append(numberToString(strtoul(partDivider.c_str(),NULL,system) / global_base));
	partDivider = numberToString(strtoul(partDivider.c_str(),NULL,system) % global_base);

	//якшо число уже на свому кінці то цикл з постумовою нам не годиться тому зловим цю подію до нього
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

			//ОТУТ!!!ПЕРЕД ТИМ ЯК ДОПИСАТИ ДО ДЕСЯТКОВОЇ(так завжди подається результат int) ОСТАЧІ ЩОСЬ! ЩОБ ЗАПАХАЛО ТРЕБА ПЕРЕТВОРЮВАТИ НЕПОВНЕ ДІЛЕНЕ В ТУ Ж СИСТЕМУ ШО І САМ СТРІНГ!!!
			if (system != DEC)
			{
				partDivider = convertToBasicSystem(partDivider, system);
			}

			partDivider.append(ss.str());
			k++;//ітератор того скільки я разів підряд буду в циклі щоб знати чи вже пора даписувати нуль в частку
			i++;
			if (k > 1)
			{ 
				quotient.append("0");//дописуєм цей нуль
			}
			pd = strtoul(partDivider.c_str(),NULL,system);//заради тесту pd дає змогу слікувати за значенням змінної
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
			return quotient; // отут завдяки optimizedBase не доведеться робити жопські перетворення як я подумав (convertToBasicSystem(quotient, system))
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