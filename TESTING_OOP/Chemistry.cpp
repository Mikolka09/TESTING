#include "Chemistry.h"

//���� �� �����
void Chemistry::menu_chem_user(string const& log)
{
	while (true)
	{

		Organic org;
		Inorganic in;
		Tested tes;
		tes.load_results();
		org.load_test_or();
		system("cls");
		cout << "���� ������ �� ����� ��� ������������\n" << endl;
		cout << "��������� ������ �� �����:" << endl;
		cout << "1. ����� ����� �� ������������\n" << "2. ����� ����� �� ��������������\n"
			<< "3. ������� � ���������� ����" << endl;
		int var;
		bool v = true;
		while (v)
		{
			cin >> var;
			cin.ignore();
			if (var < 1 || var > 3)    // �������� �����
				cout << "�������!!! ���������� ��� ���!!!" << endl;
			else
				v = false;
		}
		switch (var)
		{
		case 1:
		{
			if (tes.get_base_results().empty())
				org.passing_test_or(log);
			else
			{
				//string cat = "�������";
				if ((*tes.get_base_results().find(log)).second.front()->get_cat() == org.cat_or_)     //�������� ���� �� � ���� ����������� ���������
				{
					cout << "���� �� ������������ �������, �������� ������ ����!!!" << endl;
					Sleep(2500);
				}

				else
					org.passing_test_or(log);
			}
			break;
		}
		case 2:
		{
			if (tes.get_base_results().empty())
				in.passing_test_in(log);
			else
			{
				//string cat = "���������";
				if ((*tes.get_base_results().find(log)).second.front()->get_cat() == in.cat_in_)    //�������� ���� �� � ���� ����������� ���������
				{
					cout << "���� �� �������������� �������, �������� ������ ����!!!" << endl;
					Sleep(2500);
				}
				else
					in.passing_test_in(log);
			}
			break;
		}
		case 3:
			tes.new_testing(log);
			break;
		default:;
		}
	}
}


//���� �� ����� ��� ��������������
void Chemistry::menu_chem_admin()
{
	while (true)
	{
		Admin ad;
		Organic org;
		Inorganic in;
		org.load_test_or();
		in.load_test_in();
		system("cls");
		cout << "���� ������ �� ����� ��� ��������������\n" << endl;
		cout << "���� ��������:" << endl;
		cout << "1. �������� ������ �� ������������\n" << "2. �������� ������ �� ��������������\n"
			<< "3. �������������� ������ �� ������������\n" << "4. �������������� ������ �� ��������������\n"
			<< "5. ������ �� ����� ������ �� ������������\n" << "6. ������ �� ����� ������ �� ��������������\n"
			<< "7. ������� � ���������� ����" << endl;
		int var;
		bool v = true;
		while (v)
		{
			cin >> var;
			cin.ignore();
			if (var < 1 || var > 5)    // �������� �����
				cout << "�������!!! ���������� ��� ���!!!" << endl;
			else
				v = false;
		}
		switch (var)
		{
		case 1:
			org.creature_test_or();
			break;
		case 2:
			in.creature_test_in();
			break;
		case 3:
			org.edit_test_or();
			break;
		case 4:
			in.edit_test_in();
			break;
		case 5:
			org.print_test_all_or();
			break;
		case 6:
			in.print_test_all_in();
			break;
		case 7:
			ad.control_tests();
			break;
		default:;
		}
	}
}


Organic::Organic(const Organic& ob)
{
	cat_or_ = ob.cat_or_;
	list<Tests*> t;
	t = ob.base_or_;
	base_or_ = t;
}

Organic& Organic::operator=(const Organic& ob)
{
	cat_or_ = ob.cat_or_;
	list<Tests*> t;
	t = ob.base_or_;
	base_or_ = t;
	return *this;
}

//����������� ����� �� ������������
void Organic::passing_test_or(string const& log)
{
	system("cls");
	cout << "����� ������ �� ������������\n" << endl;
	Tested tes;
	Tests ts;
	string lg = log;
	int count_u = 0;                                     //���������� ��������� �������
	int bal_u = 0;                                       //���������� ��������� ����� �� ����
	auto it = base_or_.begin();
	for (; it != base_or_.end(); ++it)
	{
		cout << (*it);
		cout << endl;
		cout << "������� ����� ������: ";
		int nom;
		cin >> nom;
		if ((*it)->get_right_answer() == nom)            //�������� �� ������������ ������
		{
			bal_u += (*it)->get_balls();
			count_u++;
		}
	}
	Results* res = new Results;
	res->set_log(lg);
	int size = base_or_.size();
	res->set_cat(cat_or_);
	res->set_kol_que((count_u / size) * 100);
	res->set_kol_righ_ans(count_u);
	res->set_kol_bal(bal_u);
	tes.get_res_base(res);
	system("cls");
	cout << "���� �������!!!" << endl;
	Sleep(2500);
}

//�������� ����� �� ������������
void Organic::creature_test_or()
{
	Tests* tes = new Tests;
	tes->set_category(cat_or_);
	//print_test_alg();                     //�� ��������
	//Sleep(2500);
	int idd = 0;
	bool p = true;
	while (p)
	{
		system("cls");
		cout << "�������� ����� �� ������������:\n" << endl;
		cout << "������� ����� �����: ";
		cin >> idd;
		if (base_or_.empty())
		{
			tes->set_id(idd);
			p = false;
		}
		else
		{
			auto it = base_or_.begin();
			for (; it != base_or_.end(); ++it)
			{
				if ((*it)->get_id() == idd)
				{
					cout << "����� ����� ��� �����, ���������� ������!!!" << endl;
					Sleep(2500);
					p = true;
				}
				else
					p = false;
			}
		}
	}
	tes->set_id(idd);
	string q;
	bool w = true;
	while (w)
	{
		system("cls");
		cout << "�������� ����� �� ������������:\n" << endl;
		cout << "������� ����� �������: " << endl;;
		char* str = new char;
		cin.ignore();
		cin.getline(str, 1200);
		q = str;
		if (base_or_.empty())
		{
			tes->set_question(q);
			w = false;
		}
		else
		{
			auto it = base_or_.begin();
			for (; it != base_or_.end(); ++it)
			{
				string que = (*it)->get_question();
				if (que == q)
				{
					cout << "����� ������ ��� ����, ���������� ��� ���!!!" << endl;
					Sleep(2500);
					w = true;
				}
				else
					w = false;
			}
		}
	}
	tes->set_question(q);
	string an;
	system("cls");
	cout << "�������� ����� �� ������������:\n" << endl;
	cout << "������� �������� ������� ����� ������: " << endl;
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	tes->set_answer(an);
	int v = 0, b = 0;
	system("cls");
	cout << "�������� ����� �� ������������:\n" << endl;
	cout << "������� ����� ����������� ������: ";
	cin >> v;
	tes->set_right_answer(v);
	cout << endl;
	cout << "������� ���������� ����� �� �����: ";
	cin >> b;
	tes->set_balls(b);
	base_or_.push_back(tes);
	system("cls");
	cout << "����� ���� �� ������� ������!!!" << endl;
	Sleep(2500);
	print_test_or();
	save_test_or();
}

//�������������� ������ �� ������������
void Organic::edit_test_or()
{
	system("cls");
	cout << "�������������� ����� �� ������������:\n" << endl;
	cout << "������� ����� �����: ";
	int idd = 0;
	cin >> idd;
	bool set = true;
	if (base_or_.empty())
	{
		cout << "���� ������ �� ������� �����!!!" << endl;
		Sleep(2500);
	}
	else
	{
		auto it = base_or_.begin();
		for (; it != base_or_.end(); ++it)
		{
			if ((*it)->get_id() != idd)
			{
				cout << "����� ����� ����� �����������!!!" << endl;
				Sleep(2500);
				set = false;
			}
			else
				set = true;
		}
	}
	if (set)
	{
		while (true)
		{
			load_test_or();
			system("cls");
			int var;
			cout << "�������������� ������ �� ������������:\n" << endl;
			cout << "1. ������������� ������\n" << "2. ������������� ������\n"
				<< "3. ������������� ����� ����������� ������\n"
				<< "4. ������������� �����\n" << "5. ������� � ���������� ����\n" << endl;
			bool v = true;
			while (v)
			{
				cin >> var;
				cin.ignore();
				if (var < 1 || var > 5)    // �������� �����
					cout << "�������!!! ���������� ��� ���!!!" << endl;
				else
					v = false;
			}
			switch (var)
			{
			case 1:
			{
				system("cls");
				cout << "�������������� �������:\n" << endl;
				cout << "������� ����� ����� �������: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_or_.begin();
				for (; it != base_or_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_question(q);
				}
				cout << endl;
				cout << "������ �������!!!" << endl;
				Sleep(2500);
				save_test_or();
				break;
			}
			case 2:
			{
				system("cls");
				cout << "�������������� ������� �� ������:\n" << endl;
				cout << "������� ����� ����� ������� ����� ������: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_or_.begin();
				for (; it != base_or_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_answer(q);
				}
				cout << endl;
				cout << "������ ��������!!!" << endl;
				Sleep(2500);
				save_test_or();
				break;
			}
			case 3:
			{
				system("cls");
				cout << "�������������� ������ ����������� ������:\n" << endl;
				cout << "������� ����� ����� ����������� ������: " << endl;
				int an = 0;
				auto it = base_or_.begin();
				for (; it != base_or_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_right_answer(an);
				}
				cout << endl;
				cout << "����� ����������� ������ �������!!!" << endl;
				Sleep(2500);
				save_test_or();
				break;
			}
			case 4:
			{
				system("cls");
				cout << "�������������� ������:\n" << endl;
				cout << "������� ����� ���������� ������: " << endl;
				int bl = 0;
				auto it = base_or_.begin();
				for (; it != base_or_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_balls(bl);
				}
				cout << endl;
				cout << "����� ��������!!!" << endl;
				Sleep(2500);
				save_test_or();
				break;
			}
			case 5:
				menu_chem_admin();
				break;
			default:;
			}
		}
	}
}


//���������� ������ �� ������������
void Organic::save_test_or()
{
	ofstream out("BaseTestsOrganic.txt", ios::out);
	Tests* tes = new Tests;
	while (true)
	{
		tes = base_or_.front();
		out << "\n";
		out << tes->get_category() << endl;
		out << tes->get_id() << endl;
		out << tes->get_question() << endl;
		out << tes->get_answer() << endl;
		out << tes->get_right_answer() << endl;
		out << tes->get_balls() << endl;
		base_or_.pop_front();
		if (base_or_.empty())
			break;
	}
	delete tes;
	out.close();

	/*ofstream out("BaseTestsAlgebra.bin", ios::binary | ios::out);
	int length = base_alg_.size();
	out.write(reinterpret_cast<char*>(&length), sizeof(int));
	for (int i = 0; i < length; i++)
	{
		Tests* test = base_alg_.front();
		int l_c = test->get_category().size() + 1;
		out.write(reinterpret_cast<char*>(&l_c), sizeof(int));
		out.write(const_cast<char*>(test->get_category().c_str()), l_c);
		int id = test->get_id();
		out.write(reinterpret_cast<char*>(&id), sizeof(int));
		int l_q = test->get_question().size() + 1;
		out.write(reinterpret_cast<char*>(&l_q), sizeof(int));
		out.write(const_cast<char*>(test->get_question().c_str()), l_q);
		int l_an = test->get_answer().size() + 1;
		out.write(reinterpret_cast<char*>(&l_an), sizeof(int));
		out.write(const_cast<char*>(test->get_answer().c_str()), l_an);
		int an_r = test->get_right_answer();
		out.write(reinterpret_cast<char*>(&an_r), sizeof(int));
		int bl = test->get_balls();
		out.write(reinterpret_cast<char*>(&bl), sizeof(int));
		base_alg_.pop_front();
	}
	out.close();*/
}

//�������� ������ �� �������
void Organic::load_test_or()
{
	ifstream in("BaseTestsOrganic.txt", ios::in);
	base_or_.clear();
	if (in.is_open())
	{
		while (true)
		{
			Tests* tes = new Tests;
			char lc[50];
			in >> lc;
			int l_lc = strlen(lc) + 1;
			char* buff = new char(l_lc + 1);
			strcpy(buff, lc);
			tes->set_category(buff);
			int id;
			in >> id;
			in.get();
			tes->set_id(id);
			char lq[1000];
			in.getline(lq, 1000);
			int l_lq = strlen(lq) + 1;
			char* buff1 = new char(l_lq + 1);
			strcpy(buff1, lq);
			tes->set_question(buff1);
			char la[1000];
			in.getline(la, 1000);
			int l_la = strlen(la) + 1;
			char* buff2 = new char(l_lq + 1);
			strcpy(buff2, la);
			tes->set_question(buff2);
			int ra;
			in >> ra;
			in.get();
			tes->set_id(ra);
			int b;
			in >> b;
			in.get();
			tes->set_id(b);
			base_or_.push_back(tes);
			in.get();
			if (in.eof())
				break;
		}
	}
	in.close();


	/*ifstream in("BaseTestsAlgebra.bin", ios::binary | ios::in);
	int length = 0;
	in.read(reinterpret_cast<char*>(&length), sizeof(int));
	base_alg_.clear();
	for (int i = 0; i < length; i++)
	{
		Tests* test = new Tests;
		int l_c = 0;
		in.read(reinterpret_cast<char*>(&l_c), sizeof(int));
		char* buff = new char(l_c + 1);
		in.read(const_cast<char*>(buff), l_c);
		test->set_category(buff);
		int id = 0;
		in.read(reinterpret_cast<char*>(&id), sizeof(int));
		test->set_id(id);
		int l_q = 0;
		in.read(reinterpret_cast<char*>(&l_q), sizeof(int));
		char* buff1 = new char(l_q + 1);
		in.read(const_cast<char*>(buff1), l_q);
		test->set_question(buff1);
		int l_an = 0;
		in.read(reinterpret_cast<char*>(&l_an), sizeof(int));
		char* buff2 = new char(l_an + 1);
		in.read(const_cast<char*>(buff2), l_an);
		test->set_answer(buff2);
		int an_r = 0;
		in.read(reinterpret_cast<char*>(&an_r), sizeof(int));
		test->set_right_answer(an_r);
		int bl = 0;
		in.read(reinterpret_cast<char*>(&bl), sizeof(int));
		test->set_balls(bl);

		base_alg_.push_back(test);
	}
	in.close();*/
}

//������ �� ����� ����� �� ������������
void Organic::print_test_or() const
{
	system("cls");
	int idd = 0;
	cout << "������ ����� �� ������:\n" << endl;
	cout << "������� ����� �����: ";
	cin >> idd;
	auto it = base_or_.begin();
	system("cls");
	cout << "������ ����� �� ������:\n" << endl;
	for (; it != base_or_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
			cout << "���� � ����� ����� �����������!!!" << endl;
	}
	system("pause");
}

//������ �� ����� ���� ������ �� ������������
void Organic::print_test_all_or() const
{
	system("cls");
	int idd = 0;
	auto it = base_or_.begin();
	system("cls");
	cout << "������ ���� ������ �� ������������:\n" << endl;
	for (; it != base_or_.end(); ++it)
	{
		cout << (*it);

	}
	system("pause");
}


Inorganic::Inorganic(const Inorganic& ob)
{
	cat_in_ = ob.cat_in_;
	list<Tests*> t;
	t = ob.base_in_;
	base_in_ = t;
}

Inorganic& Inorganic::operator=(const Inorganic& ob)
{
	cat_in_ = ob.cat_in_;
	list<Tests*> t;
	t = ob.base_in_;
	base_in_ = t;
	return *this;
}

//����������� ����� �� ��������������
void Inorganic::passing_test_in(string const& log)
{
	system("cls");
	cout << "����� ������ �� ��������������\n" << endl;
	Tested tes;
	Tests ts;
	string lg = log;
	int count_u = 0;                                     //���������� ��������� �������
	int bal_u = 0;                                       //���������� ��������� ����� �� ����
	auto it = base_in_.begin();
	for (; it != base_in_.end(); ++it)
	{
		cout << (*it);
		cout << endl;
		cout << "������� ����� ������: ";
		int nom;
		cin >> nom;
		if ((*it)->get_right_answer() == nom)            //�������� �� ������������ ������
		{
			bal_u += (*it)->get_balls();
			count_u++;
		}
	}
	Results* res = new Results;
	res->set_log(lg);
	int size = base_in_.size();
	res->set_cat(cat_in_);
	res->set_kol_que((count_u / size) * 100);
	res->set_kol_righ_ans(count_u);
	res->set_kol_bal(bal_u);
	tes.get_res_base(res);
	system("cls");
	cout << "���� �������!!!" << endl;
	Sleep(2500);
}

//�������� ����� �� ���������
void Inorganic::creature_test_in()
{
	Tests* tes = new Tests;
	tes->set_category(cat_in_);
	int idd = 0;
	bool p = true;
	while (p)
	{
		system("cls");
		cout << "�������� ����� �� ��������������:\n" << endl;
		cout << "������� ����� �����: ";
		cin >> idd;
		if (base_in_.empty())
		{
			tes->set_id(idd);
			p = false;
		}
		else
		{
			auto it = base_in_.begin();
			for (; it != base_in_.end(); ++it)
			{
				if ((*it)->get_id() == idd)
				{
					cout << "����� ����� ��� �����, ���������� ������!!!" << endl;
					Sleep(2500);
					p = true;
				}
				else
					p = false;
			}
		}
	}
	tes->set_id(idd);
	string q;
	bool w = true;
	while (w)
	{
		system("cls");
		cout << "�������� ����� �� ��������������:\n" << endl;
		cout << "������� ����� �������: " << endl;;
		char* buff = new char;
		cin.getline(buff, 1200);
		q = buff;
		if (base_in_.empty())
		{
			tes->set_question(q);
			w = false;
		}
		else
		{
			auto it = base_in_.begin();
			for (; it != base_in_.end(); ++it)
			{
				string que = (*it)->get_question();
				if (que == q)
				{
					cout << "����� ������ ��� ����, ���������� ��� ���!!!" << endl;
					Sleep(2500);
					w = true;
				}
				else
					w = false;
			}
		}
	}
	tes->set_question(q);
	string an;
	system("cls");
	cout << "�������� ����� �� ��������������:\n" << endl;
	cout << "������� �������� ������� ����� ������: " << endl;
	char* buff1 = new char;
	cin.getline(buff1, 1200);
	an = buff1;
	tes->set_answer(an);
	int v = 0, b = 0;
	system("cls");
	cout << "�������� ����� �� ��������������:\n" << endl;
	cout << "������� ����� ����������� ������: ";
	cin >> v;
	tes->set_right_answer(v);
	cout << endl;
	cout << "������� ���������� ����� �� �����: ";
	cin >> b;
	tes->set_balls(b);
	base_in_.push_back(tes);
	system("cls");
	cout << "����� ���� �� ��������� ������!!!" << endl;
	Sleep(2500);
	print_test_in();
	save_test_in();

}

//�������������� ������ �� ��������������
void Inorganic::edit_test_in()
{
	system("cls");
	cout << "�������������� ����� �� ��������������:\n" << endl;
	cout << "������� ����� �����: ";
	int idd = 0;
	cin >> idd;
	bool set = true;
	if (base_in_.empty())
	{
		cout << "���� ������ �� �������������� �����!!!" << endl;
		Sleep(2500);
	}
	else
	{
		auto it = base_in_.begin();
		for (; it != base_in_.end(); ++it)
		{
			if ((*it)->get_id() != idd)
			{
				cout << "����� ����� ����� �����������!!!" << endl;
				Sleep(2500);
				set = false;
			}
			else
				set = true;
		}
	}
	if (set)
	{
		while (true)
		{
			load_test_in();
			system("cls");
			int var;
			cout << "�������������� ������ �� ��������������:\n" << endl;
			cout << "1. ������������� ������\n" << "2. ������������� ������\n"
				<< "3. ������������� ����� ����������� ������\n"
				<< "4. ������������� �����\n" << "5. ������� � ���������� ����\n" << endl;
			bool v = true;
			while (v)
			{
				cin >> var;
				cin.ignore();
				if (var < 1 || var > 5)    // �������� �����
					cout << "�������!!! ���������� ��� ���!!!" << endl;
				else
					v = false;
			}
			switch (var)
			{
			case 1:
			{
				system("cls");
				cout << "�������������� �������:\n" << endl;
				cout << "������� ����� ����� �������: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_in_.begin();
				for (; it != base_in_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_question(q);
				}
				cout << endl;
				cout << "������ �������!!!" << endl;
				Sleep(2500);
				save_test_in();
				break;
			}
			case 2:
			{
				system("cls");
				cout << "�������������� ������� �� ������:\n" << endl;
				cout << "������� ����� ����� ������� ����� ������: " << endl;
				string q;
				char* buff = new char;
				cin.ignore();
				cin.getline(buff, 1200);
				q = buff;
				auto it = base_in_.begin();
				for (; it != base_in_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_answer(q);
				}
				cout << endl;
				cout << "������ ��������!!!" << endl;
				Sleep(2500);
				save_test_in();
				break;
			}
			case 3:
			{
				system("cls");
				cout << "�������������� ������ ����������� ������:\n" << endl;
				cout << "������� ����� ����� ����������� ������: " << endl;
				int an = 0;
				auto it = base_in_.begin();
				for (; it != base_in_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_right_answer(an);
				}
				cout << endl;
				cout << "����� ����������� ������ �������!!!" << endl;
				Sleep(2500);
				save_test_in();
				break;
			}
			case 4:
			{
				system("cls");
				cout << "�������������� ������:\n" << endl;
				cout << "������� ����� ���������� ������: " << endl;
				int bl = 0;
				auto it = base_in_.begin();
				for (; it != base_in_.end(); ++it)
				{
					if ((*it)->get_id() == idd)
						(*it)->set_balls(bl);
				}
				cout << endl;
				cout << "����� ��������!!!" << endl;
				Sleep(2500);
				save_test_in();
				break;
			}
			case 5:
				menu_chem_admin();
				break;
			default:;
			}
		}
	}
}


//���������� ������ �� ��������������
void Inorganic::save_test_in()
{
	ofstream out("BaseTestsInorganic.txt", ios::out);
	Tests* tes = new Tests;
	while (true)
	{
		tes = base_in_.front();
		out << "\n";
		out << tes->get_category() << endl;
		out << tes->get_id() << endl;
		out << tes->get_question() << endl;
		out << tes->get_answer() << endl;
		out << tes->get_right_answer() << endl;
		out << tes->get_balls() << endl;
		base_in_.pop_front();
		if (base_in_.empty())
			break;
	}
	delete tes;
	out.close();


	/*ofstream out("BaseTestsGeometry.bin", ios::binary | ios::out);
	int length = base_geo_.size();
	out.write(reinterpret_cast<char*>(&length), sizeof(int));
	for (int i = 0; i < length; i++)
	{
		Tests* test = base_geo_.front();
		int l_c = test->get_category().size() + 1;
		out.write(reinterpret_cast<char*>(&l_c), sizeof(int));
		out.write(const_cast<char*>(test->get_category().c_str()), l_c);
		int id = test->get_id();
		out.write(reinterpret_cast<char*>(&id), sizeof(int));
		int l_q = test->get_question().size() + 1;
		out.write(reinterpret_cast<char*>(&l_q), sizeof(int));
		out.write(const_cast<char*>(test->get_question().c_str()), l_q);
		int l_an = test->get_answer().size() + 1;
		out.write(reinterpret_cast<char*>(&l_an), sizeof(int));
		out.write(const_cast<char*>(test->get_answer().c_str()), l_an);
		int an_r = test->get_right_answer();
		out.write(reinterpret_cast<char*>(&an_r), sizeof(int));
		int bl = test->get_balls();
		out.write(reinterpret_cast<char*>(&bl), sizeof(int));
		base_geo_.pop_front();
	}
	out.close();*/
}

//�������� ������ �� ��������������
void Inorganic::load_test_in()
{
	ifstream in("BaseTestsInorganic.txt", ios::in);
	base_in_.clear();
	if (in.is_open())
	{
		while (true)
		{
			Tests* tes = new Tests;
			char lc[50];
			in >> lc;
			int l_lc = strlen(lc) + 1;
			char* buff = new char(l_lc + 1);
			strcpy(buff, lc);
			tes->set_category(buff);
			int id;
			in >> id;
			in.get();
			tes->set_id(id);
			char lq[1000];
			in.getline(lq, 1000);
			int l_lq = strlen(lq) + 1;
			char* buff1 = new char(l_lq + 1);
			strcpy(buff1, lq);
			tes->set_question(buff1);
			char la[1000];
			in.getline(la, 1000);
			int l_la = strlen(la) + 1;
			char* buff2 = new char(l_lq + 1);
			strcpy(buff2, la);
			tes->set_question(buff2);
			int ra;
			in >> ra;
			in.get();
			tes->set_id(ra);
			int b;
			in >> b;
			in.get();
			tes->set_id(b);
			base_in_.push_back(tes);
			in.get();
			if (in.eof())
				break;
		}
	}
	in.close();



	/*ifstream in("BaseTestsGeometry.bin", ios::binary | ios::in);
	int length = 0;
	in.read(reinterpret_cast<char*>(&length), sizeof(int));
	base_geo_.clear();
	for (int i = 0; i < length; i++)
	{
		Tests* test = new Tests;
		int l_c = 0;
		in.read(reinterpret_cast<char*>(&l_c), sizeof(int));
		char* buff = new char(l_c + 1);
		in.read(const_cast<char*>(buff), l_c);
		test->set_category(buff);
		int id = 0;
		in.read(reinterpret_cast<char*>(&id), sizeof(int));
		test->set_id(id);
		int l_q = 0;
		in.read(reinterpret_cast<char*>(&l_q), sizeof(int));
		char* buff1 = new char(l_q + 1);
		in.read(const_cast<char*>(buff1), l_q);
		test->set_question(buff1);
		int l_an = 0;
		in.read(reinterpret_cast<char*>(&l_an), sizeof(int));
		char* buff2 = new char(l_an + 1);
		in.read(const_cast<char*>(buff2), l_an);
		test->set_answer(buff2);
		int an_r = 0;
		in.read(reinterpret_cast<char*>(&an_r), sizeof(int));
		test->set_right_answer(an_r);
		int bl = 0;
		in.read(reinterpret_cast<char*>(&bl), sizeof(int));
		test->set_balls(bl);

		base_geo_.push_back(test);
	}
	in.close();*/
}

//���������� ������ ����� �� ��������������
void Inorganic::print_test_in() const
{
	system("cls");
	int idd = 0;
	cout << "������ ����� �� ������:\n" << endl;
	cout << "������� ����� �����: ";
	cin >> idd;
	auto it = base_in_.begin();
	for (; it != base_in_.end(); ++it)
	{
		if ((*it)->get_id() == idd)
			cout << (*it);
		else
			cout << "���� � ����� ����� �����������!!!" << endl;
	}
	system("pause");
}

//������ �� ����� ���� ������ �� ��������������
void Inorganic::print_test_all_in() const
{
	system("cls");
	int idd = 0;
	auto it = base_in_.begin();
	system("cls");
	cout << "������ ���� ������ �� ��������������:\n" << endl;
	for (; it != base_in_.end(); ++it)
	{
		cout << (*it);

	}
	system("pause");
}