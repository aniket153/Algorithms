#include <iostream>

using namespace std;

bool IsSafePlace(int i, int col, bool ** pgrid, int num)
{
	for (int j = 0; j < num; j++)
	{
		if (pgrid[i][j]) return false;

		if (pgrid[j][col]) return false;
	}

	int k = i, l = col;
	while (true)
	{
		if (k >= num || l >= num) break;
		if (pgrid[k++][l++]) return false;
	}

	k = i;
	l = col;
	while (true)
	{
		if (k < 0 || l < 0) break;
		if (pgrid[k--][l--]) return false;
	}

	k = i;
	l = col;
	while (true)
	{
		if (k < 0 || l >= num) break;
		if (pgrid[k--][l++]) return false;
	}

	k = i;
	l = col;
	while (true)
	{
		if (k >= num || l < 0) break;
		if (pgrid[k++][l--]) return false;
	}

	return true;
}

bool Puzzle(bool ** pgrid, int num, int col)
{
	if (col >= num) return true;

	for (int i = 0; i < num; i++)
	{
		if (!IsSafePlace(i, col, pgrid, num))
			continue;
		else
		{
			pgrid[i][col] = 1;
			if (Puzzle(pgrid, num, col + 1))
				return true;
			else
			{
				pgrid[i][col] = 0;
			}
		}
	}

	return false;
}

int main()
{
	int num;
	cin >> num;
	cout << "Input number is " << num << endl;

	bool  ** pgrid = new bool *[num];
	for (int i = 0; i < num; i++)
	{
		pgrid[i] = new bool[num];
		for (int j = 0; j < num; j++)
			pgrid[i][j] = 0;
	}

	bool stat = Puzzle(pgrid, num, 0);
	if (stat)
	{
		cout << "YES" << endl;

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				cout << pgrid[i][j] << " ";
			}

			cout << endl;
		}
	}
	else
		cout << "NO" << endl;

	// delete
	for (int i = 0; i < num; i++)
	{
		delete[] pgrid[i];
	}

	delete pgrid;
}



