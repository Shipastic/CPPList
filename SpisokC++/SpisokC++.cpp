//---------------------------------------------------------------------------
#include <iostream>
#include <locale>

using namespace std;

struct Spis1 {
	int info;
	Spis1 *next;
};

//---------------------------------------------------------------------------
void View(Spis1 *b) {
	Spis1 *t = new Spis1;
	t = b;
	while (t != NULL) {
		cout << " " << t->info << endl;
		t = t->next;
	}
}

//---------------------------------------------------------------------------
Spis1* Del_All(Spis1 *b) {
	Spis1 *t = NULL;
	while (b != NULL) {
		t = b;
		b = b->next;
	}
	delete t;
	return b;

}

void Create(Spis1 **b, Spis1 **e, int in) {
	Spis1 *t = new Spis1;
	t->info = in;
	t->next = NULL;
	if (*b == NULL)
		*b = *e = t;
	else {
		(*e)->next = t;
		*e = t;
	}
}
//---------------------------------------------------------------------------

void Funk(Spis1 *p, int n) 
{
	Spis1 *_begin = new Spis1;
	Spis1 *t = _begin;
	Spis1 *max = _begin;
	Spis1 *min = _begin;
	t->next = p;
	int avg = t->info;
	while (t->next != NULL) 
	{
		if (t->next->info > max->info)
			max = t->next;
		else
			if (t->next < min)
			min = t->next;
			else
			{
				t = t->next;
			}
		//avg+= t->info;
	}
	cout << "max = " << max->info << endl;
	cout << "min = " << min->info << endl;
	//cout << "������� �������������� = " << double(avg / n) << endl;
	/*t = p;
	while (t != NULL) 
	{
		if (t->next == max) {
			t->next->next = min;
			while (t->next->next != min) {
				cout << "max = " << max->info << endl;
			}
			break;
		}
		else if (t->next == min) {
			t->next->next = max;
			while (t->next->next != max) {
				cout << "min = " << min->info << endl;
			}
			break;
		}
		t = t->next;
	}*/
}

//---------------------------------------------------------------------------
void main()
{
	setlocale(LC_ALL, "Russian");
	Spis1 *_begin = NULL, *_end = NULL;
	int  in, n, kod;
	//srand(time(0));
	while (true) {
		cout << "�������� ������ ����� ���� ����� ������� ��������������� �����" << endl
			<< "������� - 1." << endl
			<< "�������� - 2." << endl
			<< "�������� - 3." << endl
			<< "������� - 4." << endl
			<< "����� ������������� � ������������ �������� ������ - 5." << endl
			<< "����� - 0." << endl
			<< "~~~~~~~~~~~~" << endl;
		cin >> kod;
		switch (kod) {

		case 1: case 2:
			if (kod == 1 && _begin != NULL) {
				cout << "������ �������!" << endl;
				break;
			}
			cout << "������� ����������� = ";
			cin >> n;
			cout << "������� �������� ������: "<< endl;
			for (int i = 0; i < n; i++) {
				cin >> in ;
				Create(&_begin, &_end, in);
			}
			break;

		case 3:
			cout << "~~~~~~~~~~~~"<< endl;
			if (!_begin) {
				cout << "������ ����!" << endl;
				break;
			}
			cout << "~~~~~~~~~~~~"<< endl;
			cout << "---������---" << endl;
			View(_begin);
			cout << endl;
			break;

		case 4:
			cout << "~~~~~~~~~~~~"<< endl;
			_begin = Del_All(_begin);
			cout << "������ �������!" << endl;
			break;

		case 5:
			cout << "~~~~~~~~~~~~"<<endl;
			Funk(_begin, n);
			break;

		case 0:
			if (_begin != NULL)
				_begin = Del_All(_begin);
			return;
		}
	}
}

