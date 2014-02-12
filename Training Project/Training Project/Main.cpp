#include "Training.h"
 


enum SerieA
{
	 Juve = 1, Roma, Napoli, Fio, Inter, Verona, Torino, Parma
};

void out()
{
	for (int i = Juve; i < Parma; i++)
	{
		cout << i <<'\t';
	}
}




int main()
{
	out(); 
	cout << endl;
    return 0;
}

