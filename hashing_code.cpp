#include <iostream>
using namespace std;

class Hashing{
	private:
		int Items;
		int *array = new int [Items];
		int counter ;
		int value ;
		int halfing;
		int Item2 ;
	public:

		Hashing()
		{
			cout << "Enter the Total Number of Node " << endl;
			cin >> Items;
			halfing = Items;
			Item2 =0; 
			counter = 0;
			value = 0;
			for (int i =0; i<Items; i++)
			{
				array[i] = -1;
			}
		}
		int main_function(int *array)
		{
			//cout << "Main function is called " << endl;
			
			int storing_index =0;
			//cout << "Counter is " << counter << endl;
			if (counter == (halfing/2))
			{

				extending_array(array);
				counter = 0;
				return 0;
			}

			cout << "Enter the value" << endl;
			cin >> value;
			storing_index = value %Items;

			if (array[storing_index] == -1)
			{
				array[storing_index] = value;
				cout << array[storing_index] << endl;
				counter++;
				return 0;
			} 

			if(array[storing_index] != -1)
			{
			//	cout <<"inside the loop" << endl;
				while(array[storing_index] != -1)
				{
					cout << array[storing_index]<< endl;
					storing_index++;
					
					if(storing_index >= (Items-1))
					{
						storing_index = 0;
					}
				}
				array[storing_index] = value;
				cout << array[storing_index] << endl;
				counter++;
				return 0;
			}

		}

		int extending_array(int *array)
		{
			//cout << "Extending array is called " << endl;
			Item2 = Items * 2;
			cout << "Items2 " << Item2 << endl; 

			while(4)
			{
				if (prime_function(Item2) == 1)
				{
					break;
				}
				else
				{
					Item2++;
				}
			}
			int *array2 = new int [Item2];
			for(int i =0; i<Item2; i++)
			{
				array2[i] = -1;
			}
			halfing = Item2;
			copying_array(array2,array);


			main_function(array2);
			printing(array2);

		}

		int prime_function(int value)
		{
			//cout << "Prime function is called " << endl;
			int i=2;
			int flag = 1;

			while(i < value)
			{
				if(value % i == 0)
				{
					flag = 0;
				}
				i++;
			}

			if(flag == 1)
			{
				return 0;
			}

			else
			{
				return 1;
			}
		}

		int copying_array(int *array2, int *array)
		{
			//cout << "Copying array function is called " << endl;
			for(int i=0; i < (Items / 2); i++)
			{
				if(array[i] != -1)
				{
					int storing_index = array[i] % Items;

					array2[storing_index] = array[i];

					// Check Mission
				}
			}
		}

		int Calling_function()
		{
				for(int i =0;i < Items; i++)
				{
						main_function(array);
				}
		}
		int printing(int *array)
		{
			for (int i = 0; i < Item2; ++i)
			{
				cout << array[i] << " ";
			}
		}
};


int main(){
	
	Hashing h;
	h.Calling_function();



	return 0;
}

