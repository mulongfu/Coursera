#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Warrior {
private:
	int hp, attack;
	string name;

public:
	int get_hp() {
		return hp;
	}
	int get_attack() {
		return attack;
	}
	Warrior(int _hp, string _name, int _attack = 0) {
		hp = _hp;
		name = _name;
		attack = _attack;
	}

};

class Red {
private:
	int id;
	int Life_Elements;
	int total_iceman;
	int total_lion;
	int total_wolf;
	int total_ninja;
	int total_dragon;
	Warrior iceman, lion, wolf, ninja, dragon;

public:
	Red(int n, int a, int b, int c, int d, int e, int _id = 1, int _total_iceman = 0, int _total_lion = 0, int _total_wolf = 0, int _total_ninja = 0, int _total_dragon = 0) : Life_Elements(n),
		id(_id), total_iceman(_total_iceman), total_lion(_total_lion), total_wolf(_total_wolf), total_ninja(_total_ninja), total_dragon(_total_dragon), iceman(a, "iceman"), lion(b, "lion"), wolf(c, "wolf"),
		ninja(d, "ninja"), dragon(e, "dragon") {}

	void decrease_life_elements(int n) {
		Life_Elements -= n;
	}

	void set_total_iceman() {
		total_iceman++;
	}

	void set_total_lion() {
		total_lion++;
	}
	void set_total_wolf() {
		total_wolf++;
	}
	void set_total_ninja() {
		total_ninja++;
	}
	void set_total_dragon() {
		total_dragon++;
	}

	void set_id() {
		id++;
	}

	int get_total_iceman() {
		return total_iceman;
	}
	int get_total_lion() {
		return total_lion;
	}
	int get_total_wolf() {
		return total_wolf;
	}
	int get_total_ninja() {
		return total_ninja;
	}
	int get_total_dragon() {
		return total_dragon;
	}
	int get_life_elements() {
		return Life_Elements;
	}
	int get_id() {
		return id;
	}
	int get_warrior_hp(string s) {
		if (s == "dragon")
			return dragon.get_hp();
		else if (s == "ninja")
			return ninja.get_hp();
		else if (s == "iceman")
			return iceman.get_hp();
		else if (s == "lion")
			return lion.get_hp();
		else
			return wolf.get_hp();
	}
};

class Blue {
private:
	int id;
	int Life_Elements;
	int total_lion;
	int total_dragon;
	int total_ninja;
	int total_iceman;
	int total_wolf;
	Warrior lion, dragon, ninja, iceman, wolf;

public:
	Blue(int n, int a, int b, int c, int d, int e, int _id = 1, int _total_lion = 0, int _total_dragon = 0, int _total_ninja = 0, int _total_iceman = 0, int _total_wolf = 0) : Life_Elements(n), id(_id)
		, total_lion(_total_lion), total_dragon(_total_dragon), total_ninja(_total_ninja), total_iceman(_total_iceman)
		, total_wolf(_total_wolf)
		, lion(a, "lion"), dragon(b, "dragon"),	ninja(c, "ninja"), iceman(d, "iceman"), wolf(e, "wolf") {}

	void decrease_life_elements(int n) {
		Life_Elements -= n;
	}

	void set_total_iceman() {
		total_iceman++;
	}
	void set_total_lion() {
		total_lion++;
	}
	void set_total_wolf() {
		total_wolf++;
	}
	void set_total_ninja() {
		total_ninja++;
	}
	void set_total_dragon() {
		total_dragon++;
	}
	void set_id() {
		id++;
	}
	int get_total_iceman() {
		return total_iceman;
	}
	int get_total_lion() {
		return total_lion;
	}
	int get_total_wolf() {
		return total_wolf;
	}
	int get_total_ninja() {
		return total_ninja;
	}
	int get_total_dragon() {
		return total_dragon;
	}

	int get_life_elements() {
		return Life_Elements;
	}
	int get_id() {
		return id;
	}
	int get_warrior_hp(string s) {
		if (s == "dragon")
			return dragon.get_hp();
		else if (s == "ninja")
			return ninja.get_hp();
		else if (s == "iceman")
			return iceman.get_hp();
		else if (s == "lion")
			return lion.get_hp();
		else
			return wolf.get_hp();
	}
};

int main() {
	int n, m, init_hp[5], min;
	string r_order[5] = { "iceman", "lion", "wolf", "ninja", "dragon" };
	string b_order[5] = { "lion", "dragon", "ninja", "iceman", "wolf" };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int rorder = 0, border = 0, timer = 0;
		bool flag = 0, rlast = 0, blast = 0;
		cin >> m;	//M?�ͩR��
		cin >> init_hp[0] >> init_hp[1] >> init_hp[2] >> init_hp[3] >> init_hp[4];	//dragon, ninja, iceman, lion, wolf
		min = *min_element(init_hp, init_hp + 5);
		Red r(m, init_hp[2], init_hp[3], init_hp[4], init_hp[1], init_hp[0]);	//Init
		Blue b(m, init_hp[3], init_hp[0], init_hp[1], init_hp[2], init_hp[4]);	//Init
		cout << "Case:" << i << endl;

		while ((r.get_life_elements() >= min) || (b.get_life_elements() >= min) || rlast == 0 || blast == 0) {

			if (blast == 1)
				flag = 0;


			while (r.get_life_elements() >= min && flag == 0) {

				while (r.get_life_elements() < r.get_warrior_hp(r_order[rorder])) {
					if (rorder == 4)
						rorder = 0;
					else
						rorder++;
				}

				switch (rorder) {
				case 0:
					r.set_total_iceman();	//+1
					cout << setw(3) << setfill('0') << timer << " red iceman " << r.get_id() << " born with strength " << r.get_warrior_hp("iceman") << "," << r.get_total_iceman() << " iceman in red headquarter" << endl;
					r.decrease_life_elements(r.get_warrior_hp("iceman"));
					rorder++;
					r.set_id();
					flag = 1;
					if (blast == 1)
						timer++;
					break;

				case 1:
					r.set_total_lion();	//+1
					cout << setw(3) << setfill('0') << timer << " red lion " << r.get_id() << " born with strength " << r.get_warrior_hp("lion") << "," << r.get_total_lion() << " lion in red headquarter" << endl;
					r.decrease_life_elements(r.get_warrior_hp("lion"));
					rorder++;
					r.set_id();
					flag = 1;
					if (blast == 1)
						timer++;
					break;

				case 2:
					r.set_total_wolf();	//+1
					cout << setw(3) << setfill('0') << timer << " red wolf " << r.get_id() << " born with strength " << r.get_warrior_hp("wolf") << "," << r.get_total_wolf() << " wolf in red headquarter" << endl;
					r.decrease_life_elements(r.get_warrior_hp("wolf"));
					rorder++;
					r.set_id();
					flag = 1;
					if (blast == 1)
						timer++;
					break;

				case 3:
					r.set_total_ninja();	//+1
					cout << setw(3) << setfill('0') << timer << " red ninja " << r.get_id() << " born with strength " << r.get_warrior_hp("ninja") << "," << r.get_total_ninja() << " ninja in red headquarter" << endl;
					r.decrease_life_elements(r.get_warrior_hp("ninja"));
					rorder++;
					r.set_id();
					flag = 1;
					if (blast == 1)
						timer++;
					break;

				case 4:
					r.set_total_dragon();	//+1
					cout << setw(3) << setfill('0') << timer << " red dragon " << r.get_id() << " born with strength " << r.get_warrior_hp("dragon") << "," << r.get_total_dragon() << " dragon in red headquarter" << endl;
					r.decrease_life_elements(r.get_warrior_hp("dragon"));
					rorder++;
					r.set_id();
					flag = 1;
					rorder = 0;
					if (blast == 1)
						timer++;
					break;

				default:
					break;
				}
			}

			if (r.get_life_elements() < min && flag == 0 && rlast == 0) {
				cout << setw(3) << setfill('0') << timer << " red headquarter stops making warriors" << endl;
				rlast = 1;
				flag = 1;
			}

			if (rlast == 1)
				flag = 1;

			while (b.get_life_elements() >= min && flag == 1) {
				while (b.get_life_elements() < b.get_warrior_hp(b_order[border])) {
					if (border == 4)
						border = 0;
					else
						border++;
				}
				switch (border) {
				case 3:
					b.set_total_iceman();	//+1
					cout << setw(3) << setfill('0') << timer << " blue iceman " << b.get_id() << " born with strength " << b.get_warrior_hp("iceman") << "," << b.get_total_iceman() << " iceman in blue headquarter" << endl;
					b.decrease_life_elements(b.get_warrior_hp("iceman"));
					border++;
					b.set_id();
					flag = 0;
					timer++;
					break;

				case 0:
					b.set_total_lion();	//+1
					cout << setw(3) << setfill('0') << timer << " blue lion " << b.get_id() << " born with strength " << b.get_warrior_hp("lion") << "," << b.get_total_lion() << " lion in blue headquarter" << endl;
					b.decrease_life_elements(b.get_warrior_hp("lion"));
					border++;
					b.set_id();
					flag = 0;
					timer++;
					break;

				case 4:
					b.set_total_wolf();	//+1
					cout << setw(3) << setfill('0') << timer << " blue wolf " << b.get_id() << " born with strength " << b.get_warrior_hp("wolf") << "," << b.get_total_wolf() << " wolf in blue headquarter" << endl;
					b.decrease_life_elements(b.get_warrior_hp("wolf"));
					border++;
					b.set_id();
					flag = 0;
					timer++;
					border = 0;
					break;

				case 2:
					b.set_total_ninja();	//+1
					cout << setw(3) << setfill('0') << timer << " blue ninja " << b.get_id() << " born with strength " << b.get_warrior_hp("ninja") << "," << b.get_total_ninja() << " ninja in blue headquarter" << endl;
					b.decrease_life_elements(b.get_warrior_hp("ninja"));
					border++;
					b.set_id();
					flag = 0;
					timer++;
					break;

				case 1:
					b.set_total_dragon();	//+1
					cout << setw(3) << setfill('0') << timer << " blue dragon " << b.get_id() << " born with strength " << b.get_warrior_hp("dragon") << "," << b.get_total_dragon() << " dragon in blue headquarter" << endl;
					b.decrease_life_elements(b.get_warrior_hp("dragon"));
					border++;
					b.set_id();
					flag = 0;
					timer++;
					break;

				default:
					break;
				}
			}
			if (b.get_life_elements() < min && flag == 1 && blast == 0) {
				cout << setw(3) << setfill('0') << timer << " blue headquarter stops making warriors" << endl;
				timer++;
				flag = 0;
				blast = 1;
			}
		}


	}
	return 0;
}
